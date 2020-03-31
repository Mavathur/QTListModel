/**
 * @Author: Mavathur Pruthvi
 * @brief: IListModel is the interface for the list model providing the desired functionalities of the list model
 * @brief: It is realised by the customListModel
 */
#ifndef ILISTMODEL_H
#define ILISTMODEL_H
#include<QAbstractListModel>
//#include"itemlist.h"
class ItemList;
class IListModel : public QAbstractListModel
{
public:

    // Basic functionality:
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const =0;

    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const =0;

    // Editable:
    virtual bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole)  =0;

    virtual Qt::ItemFlags flags(const QModelIndex& index) const =0;

    /**
     * @brief roleNames Provides the hash to easen the look up process
     * @return returns the hash after hashing the Names with the Enums
     */
    virtual QHash<int, QByteArray> roleNames() const =0;

    /**
     * @brief  It is the getter for fetching MyList as it is Provided for the list property of the model
     * @return MyList pointer
     */
    virtual ItemList *list() const =0;

    /**
     * @brief setList - Setter function for the list property
     * @param list: New Parameter that has to be set
     */
    virtual void setList(ItemList *list)=0;
};

#endif // ILISTMODEL_H
