#ifndef MAPMODEL_H
#define MAPMODEL_H

#include <QAbstractTableModel>

class Map;

class MapModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(Map *map READ map WRITE setMap)

public:
    explicit MapModel(QObject *parent = nullptr);

    enum {
        CellRole = Qt::UserRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    Map *map() const;
    void setMap(Map *map);

private:
    Map *mMap;
};

#endif // MAPMODEL_H
