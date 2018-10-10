#include "mapmodel.h"
#include "map.h"

MapModel::MapModel(QObject *parent)
    : QAbstractListModel(parent),
      mMap(nullptr)
{
}

int MapModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mMap)
        return 0;

    return mMap->cells().size();
}

QVariant MapModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mMap)
        return QVariant();

    const Cell cell = mMap->cells()[index.row()];
    switch (role) {
    case CellRole:
        return QVariant(cell.grassLevel);
    }
    return QVariant();
}

bool MapModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mMap)
        return false;

    // FIXME: Don't need this until we can't modify cells from qml
    Cell cell = mMap->cells()[index.row()];
    switch (role) {
    case CellRole:
        cell.grassLevel = value.toInt();
        break;
    }

    if (mMap->setCellAt(index.row(), cell)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags MapModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> MapModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[CellRole] = "cell";
    return names;
}

Map *MapModel::map() const
{
    return mMap;
}

void MapModel::setMap(Map *map)
{
    beginResetModel();

    if (mMap)
        mMap->disconnect(this);

    mMap = map;

    if (mMap) {
        beginInsertRows(QModelIndex(), 0, mMap->cells().size());
        endInsertRows();
    }

    endResetModel();
}
