#include "customlistmodel.h"
#include"itemlist.h"

CustomListModel::CustomListModel(QObject *parent): IListModel()
{
}

int CustomListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid()|| !m_list)
        return 0;

    return (m_list)->items().size();

}

QVariant CustomListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !m_list )
        return QVariant();

    const myItem* item = (m_list)->items().at(index.row());

    switch (role) {
    case DoneRole: return QVariant(item->expandable);
    case DescriptionRole: return QVariant(item->description);
    }


    return QVariant();
}

bool CustomListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!m_list)
    {
        return false;
    }
    myItem* item = (m_list)->items().at(index.row());

    switch (role) {
    case DoneRole: item->expandable = value.toBool();
    case DescriptionRole: item->description = value.toString();

    }

    if (data(index, role) != value) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }

    if((m_list)->setItemAt(index.row(), item))
    {
        emit dataChanged(index,index, QVector<int>() << role );
        return true;
    }

    return false;
}

Qt::ItemFlags CustomListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> CustomListModel::roleNames() const
{
    QHash<int, QByteArray> hash1;
    hash1[DoneRole]="expandable";
    hash1[DescriptionRole]="description";
    return hash1;
}
ItemList *CustomListModel::list() const
{
    return m_list;
}

void CustomListModel::setList(ItemList *list)
{
    beginResetModel();
    if(m_list)
    {
        (m_list)->disconnect(this);
    }

    m_list = list;
    m_list->setParent(this);

    if(m_list)
    {
        connect(m_list,&ItemList::preItemAppended, this, [=](){
            const int index= (m_list)->items().size();
            beginInsertRows(QModelIndex(),index, index);
        });
        connect(m_list,&ItemList::postItemAppended, this, [=](){
            endInsertRows();
        });
        connect(m_list,&ItemList::preItemRemoved, this, [=](int index){
            beginRemoveRows(QModelIndex(), index,index);
        });
        connect(m_list,&ItemList::postItemRemoved, this, [=](){
            endRemoveRows();
        });
    }

    endResetModel();
}
