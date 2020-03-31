/**
 * @Author: Mavathur Pruthvi
 * @brief: AlbumModel provides a model to render the list of Albums
 */
#ifndef ALBUMMODEL_H
#define ALBUMMODEL_H

#include"customlistmodel.h"
#include"albumlist.h"

class AlbumModel: public CustomListModel
{
    Q_OBJECT
    Q_PROPERTY(ItemList *list READ list WRITE setList)
public:
    AlbumModel(QObject *parent = nullptr);

};

#endif // ALBUMMODEL_H
