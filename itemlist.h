/**
 * @Author: Mavathur Pruthvi
 * @brief: It is the realisation of the interface IList
 * @brief: It is the base class for the SongList and AlbumList
 */
#ifndef ITEMLIST_H
#define ITEMLIST_H

#include <QObject>
#include"Item.h"
#include"IList.h"

class ItemList : public IList
{
    Q_OBJECT
public:
    explicit ItemList(QObject *parent = nullptr);
   // virtual ~ItemList() override =0;

    /**
     * @brief items
     * @return returns the vector of items/Songs that are present in the album
     */
    /**
     * @brief items
     * @return returns the vector of items/Songs that are present in the album
     */
    virtual QVector<myItem*> items()  override;
    /**
     * @brief setItemAt Sets the element at provided index
     * @param index
     * @param item
     * @return Returns the success of the insertion
     */

    virtual bool setItemAt(int index, myItem *item) override;


    void setMyItems(const QVector<myItem*> &myItems){m_myItems = myItems;}

signals:
    /**
     * @brief preItemAppended  emitted before appending the element to the vector
     */
    void preItemAppended() override;
    /**
     * @brief postItemAppended emitted after appending the element to the vector
     */
    void postItemAppended() override;
    /**
     * @brief preItemRemoved  emitted before removing the element to the vector
     * @param index Index of the element that has to be removed from the Vector
     */
    void preItemRemoved(int index) override;
    /**
     * @brief postItemRemoved  emitted after removing the element to the vector
     */
    void postItemRemoved() override;



  public slots:
    /**
     * @brief appendItem called from the qml to append the new item to the list
     */
    virtual void appendItem() override;
    /**
     * @brief removeCompletedItems called from the Qml to remove the items
     * Kept for future reference to remove entire songs if the album is cleared
     */
    virtual void removeCompletedItems() override;
    /**
     * @brief removeItems Removes the last item from the vector
     */
    virtual void removeItems() override;


protected:
      QVector<myItem*> m_myItems;
};
#endif
