#include "albummodel.h"

/**
 * @brief AlbumModel::AlbumModel - Purpose of AlbumModel is to handle the properties specific to the model provided in the header.
 * @param parent - parent holding the AlbumModel
 */
AlbumModel::AlbumModel(QObject *parent)
    :CustomListModel(parent)
{
}
