/**
 * @Author: Mavathur Pruthvi
 * @brief: Album Item is QuickItem which holds the songsList and SongModel
 * @brief: It is derived from myItem as it is also item
 */
#ifndef ALBUMITEM_H
#define ALBUMITEM_H
#include"Item.h"
#include<memory>
#include<songlist.h>
#include<QObject>
#include"songmodel.h"
class AlbumItem:public myItem
{
    Q_OBJECT
public:
    AlbumItem();
public slots:
    /**
     * @brief addSongtoAlbum - Add songs to the Album
     */
    void addSongtoAlbum();
    /**
     * @brief deleteSongFromAlbum - Deletes song from the Album
     */
    void deleteSongFromAlbum();

public:
    SongList* m_mySongList=nullptr;
    std::shared_ptr<SongModel> m_mysongModel = nullptr;
};

#endif // ALBUMITEM_H
