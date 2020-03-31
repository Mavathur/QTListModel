#include "itemlist.h"

ItemList::ItemList(QObject *parent): IList()
{
    std::make_shared<QVector<myItem*>>(m_myItems);
}
QVector<myItem*> ItemList::items()
{
    return m_myItems;
}

bool ItemList::setItemAt(int index, myItem* item)
{
    if(index<0 || index >= m_myItems.size())
    {
        return false;
    }

    const myItem &oldItem = m_myItems.at(index);
    if(item->expandable==oldItem.expandable && item->description ==oldItem.description)
        return false;


    m_myItems.insert(index,item);
    return true;
}

void ItemList::appendItem()
{
    emit preItemAppended();
    myItem* item = new myItem;
    item->setParent(this);
    item->expandable=true;
    item->description= QString(getItemName()+QString::number(m_myItems.size()+1));
    m_myItems.append(item);
    emit postItemAppended();
}

void ItemList::removeCompletedItems()
{
    if(m_myItems.size()<1)
    {
        return;
    }
    emit preItemRemoved(m_myItems.size()-1);
    m_myItems.removeAt(m_myItems.size()-1);
    emit postItemRemoved();
}

void ItemList::removeItems()
{
    removeCompletedItems();
}

