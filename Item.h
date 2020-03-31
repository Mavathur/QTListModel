/**
 * @Author: Mavathur Pruthvi
 * @brief: Item is the base class for the SongItem and AlbumItem
 */
#ifndef ITEM_H
#define ITEM_H

#include<QString>
#include<QObject>
#include<QQuickItem>
/**
 * @brief The myItem struct - Provides two properties of the model
 * expandable -  This is intended to know if the item is expandable. it is currently dormant
 * description - Provides the string that is displayed on the album/Song
 */
class myItem:public QQuickItem
{
    Q_OBJECT
public:
    myItem(QObject *parent = nullptr);
public:
       bool expandable = true;
       QString description ;
};


#endif // ITEM_H
