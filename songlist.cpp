#include "songlist.h"

SongList::SongList(QObject *parent):ItemList()
{
     m_myItems.setSharable(true);
}
