/**
 * @Author: Mavathur Pruthvi
 * @brief: IList is the interface for the List classes whch provides the desired functionalities
 */
#ifndef ILIST_H
#define ILIST_H
#include"Item.h"
#include<QObject>
#include"itemlist.h"
class IList:public QObject{
protected:
    /**
 * @brief items - provides the items that a List holds
 * @return -  returns the item list as a vector
 */
virtual QVector<myItem*> items() =0;
    /**
 * @brief setItemAt - inserts the item to the hierarchy
 * @param index - it is the index, where Item has to be inseted
 * @param item - Item that has to be inserted to the collection
 * @return
 */
virtual bool setItemAt(int index, myItem *item)=0;

protected:
     virtual QString getItemName()=0;
public slots:
  /**
   * @brief appendItem called from the qml to append the new item to the list
   */
  virtual void appendItem()=0 ;
  /**
   * @brief removeCompletedItems called from the Qml to remove the items
   * Kept for future reference to remove entire songs if the album is cleared
   */
  virtual void removeCompletedItems() =0;
  /**
   * @brief removeItems Removes the last item from the vector
   */
  virtual void removeItems()=0 ;

signals:
    /**
     * @brief preItemAppended  emitted before appending the element to the vector
     */
    virtual void preItemAppended()=0;
    /**
     * @brief postItemAppended emitted after appending the element to the vector
     */
    virtual void postItemAppended()=0;
    /**
     * @brief preItemRemoved  emitted before removing the element to the vector
     * @param index Index of the element that has to be removed from the Vector
     */
    virtual void preItemRemoved(int index)=0;
    /**
     * @brief postItemRemoved  emitted after removing the element to the vector
     */
    virtual void postItemRemoved()=0;




};
#endif // ILIST_H
