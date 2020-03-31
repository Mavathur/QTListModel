/**
 * @Author: Mavathur Pruthvi
 * @brief: It is derived from the CustomListModel as it also is an ListModel
 * @brief: It provides the Model to render the SongList
 */
#ifndef SONGMODEL_H
#define SONGMODEL_H

#include"customlistmodel.h"
#include"songlist.h"
class SongModel:public CustomListModel
{
    Q_OBJECT
    Q_PROPERTY(ItemList *list READ list WRITE setList)
public:
   explicit SongModel(QObject *parent = nullptr);

};

#endif // SONGMODEL_H
