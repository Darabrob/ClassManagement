#ifndef CLASSMODEL_H
#define CLASSMODEL_H
#include <QAbstractItemModel>
#include "classitem.h"

class ClassModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit ClassModel(QObject *parent = nullptr);
    ~ClassModel();

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    void setupModelData(const QMap<QString, QStringList> &classes);
private:
    ClassItem *rootItem;
};

#endif // CLASSMODEL_H
