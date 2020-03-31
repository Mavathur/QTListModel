/**
 * @Author: Mavathur Pruthvi
 * @brief: It is derived from the ItemList as it also is an ItemList
 */
#ifndef SONGLIST_H
#define SONGLIST_H

#include <QObject>
#include"Item.h"
#include"itemlist.h"
#include"songitem.h"

class SongList : public ItemList
{
    Q_OBJECT
public:
    explicit SongList(QObject *parent = nullptr);
    /**
     * @brief getItemName - Overrides getName function to provide the name as Song while appending the Item to the List
     * @return returns the category string, Song
     */
    QString getItemName() override{

        return QStringLiteral("Song");
    }
};

#endif // SONGLIST_H
