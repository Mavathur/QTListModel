/**
 * @Author: Mavathur Pruthvi
 * @brief: It is derived from the ItemList, holding list of albumItems, as it also is an ItemList
 * @brief: It inherits the functionalities of ItemList
 */
#ifndef ALBUMLIST_H
#define ALBUMLIST_H
#include"itemlist.h"
#include"albumitem.h"

class AlbumList : public ItemList
{
public:
    explicit AlbumList(QObject *parent = nullptr);
    /**
     * @brief getItemName - Overrides getName function to provide the name as Album while appending the Item to the List
     * @return returns the category Album
     */
    QString getItemName() override{
        return QStringLiteral("Album");
    }

};

#endif // ALBUMLIST_H
