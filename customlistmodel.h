/**
 * @Author: Mavathur Prurhvi
 * @brief: It is the base class for the Song Model and Album Model
 */
#ifndef CUSTOMLISTMODEL_H
#define CUSTOMLISTMODEL_H

#include<IListModel.h>
#include"itemlist.h"
#include<QAbstractListModel>

class CustomListModel: public IListModel
{

public:
    explicit CustomListModel(QObject *parent = nullptr);

    /** @Brief provides the enum for the two properties
     *  DoneRole specifies if it is expandable
     * Description Role specifies the text held by the song Item
     */
    enum{
        DoneRole= Qt::UserRole,
        DescriptionRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    /**
     * @brief roleNames Provides the hash to easen the look up process
     * @return returns the hash after hashing the Names with the Enums
     */
    virtual QHash<int, QByteArray> roleNames() const override;

    /**
     * @brief  It is the getter for fetching MyList as it is Provided for the list property of the model
     * @return MyList pointer
     */
    ItemList *list() const override;

    /**
     * @brief setList - Setter function for the list property
     * @param list: New Parameter that has to be set
     */
    void setList(ItemList *list) override;

protected:
    ItemList* m_list=nullptr;
};

#endif // CUSTOMLISTMODEL_H
