/**
 * @Author: Mavathur Pruthvi
 * @brief: AlbumList is QObject which holds the vector of myItems, inherited from the parent
 */

#include "albumlist.h"

/**
 * @brief AlbumList::AlbumList Constructor adds two Albums to the Album list a prior, this shall be destroyed by the user at will
 * @param parent - parent of the AlbumList. ItemList is the parent of the AlbumList
 */
AlbumList::AlbumList(QObject *parent):ItemList()
{
}
