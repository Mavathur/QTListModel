#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include<albumlist.h>
#include"albummodel.h"
#include"songmodel.h"
#include<songlist.h>
#include<QQmlContext>
#include<QQuickStyle>

#include"albumitem.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    // Models and lists are registered with the respective C++ classes
    qmlRegisterUncreatableType<AlbumList>("Album", 1,0, "AlbumList",QStringLiteral("Don't Create MyAlbumList in Qml") );
    qmlRegisterType<AlbumModel>("Album", 1,0, "AlbumModel");
    qmlRegisterType<SongModel>("Me", 1,0, "MyModel");
    qmlRegisterUncreatableType<SongList>("Me",1,0,"MyList", QStringLiteral("Don't Create MyList in Qml"));

    // With material style functionality is not as per expectation
    //  QQuickStyle::setStyle("Material");

    QQmlApplicationEngine engine;

    AlbumList* list2 = new AlbumList;

    // Thus list as a context property will span throughout the qmls that are rendered by the provided engine
    engine.rootContext()->setContextProperty(QStringLiteral("myAlbumList"),list2);

    std::shared_ptr< AlbumItem> item =  std::make_shared<AlbumItem>();
    item->setParent(list2);
    // Thus list as a context property will span throughout the qmls that are rendered by the provided engine
    engine.rootContext()->setContextProperty(QStringLiteral("albumItem"),item.get());


    // A seperate URL is used for better modularity purpose.
    // Rendering will be simplified using a dedicated qml for Album rendering using ComboBox
    engine.rootContext()->setContextProperty(QStringLiteral("myList"),item->m_mysongModel->list());

    engine.rootContext()->setBaseUrl(QUrl(QStringLiteral("qrc:/Albums.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;


    return app.exec();
}
