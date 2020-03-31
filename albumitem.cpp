/**
 * @Author: Mavathur Pruthvi
 * @brief: Album Item is QuickItem which holds the songsList and SongModel
 */
#include "albumitem.h"
#include"Item.h"
AlbumItem::AlbumItem()
    :myItem()
{
    m_mysongModel= std::make_shared<SongModel>();
    m_mysongModel->setParent(this);
    m_mySongList = new SongList;
    m_mySongList->setParent(m_mysongModel.get());
    m_mysongModel->setList(m_mySongList);
}

void AlbumItem::addSongtoAlbum(){
    m_mySongList->appendItem();
    this->update();
}


void AlbumItem::deleteSongFromAlbum(){
    if(m_mySongList == nullptr){return;}
    m_mySongList->removeItems();
}
