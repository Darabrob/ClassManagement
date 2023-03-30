#include "classmodel.h"

ClassModel::ClassModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new ClassItem({tr("Description"), tr("type")});
}

ClassModel::~ClassModel()
{
    delete rootItem;
}

QModelIndex ClassModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    ClassItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<ClassItem*>(parent.internalPointer());

    ClassItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}

QModelIndex ClassModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    ClassItem *childItem = static_cast<ClassItem*>(index.internalPointer());
    ClassItem *parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int ClassModel::rowCount(const QModelIndex &parent) const
{
    ClassItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<ClassItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int ClassModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<ClassItem*>(parent.internalPointer())->columnCount();
    return rootItem->columnCount();
}

QVariant ClassModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    ClassItem *item = static_cast<ClassItem*>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags ClassModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}

QVariant ClassModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

void ClassModel::setupModelData(const QMap<QString, QStringList> &classes)
{
    beginResetModel();
    delete rootItem;
    rootItem = new ClassItem({tr("Year"), tr("Description")});



    // ... fill extensions
    QMapIterator<QString, QStringList> i(classes);
    while (i.hasNext()) {
        i.next();
        qDebug() << i.key() << ": " << i.value();
        ClassItem* classItemYear = new ClassItem({i.key(),"Year"}, rootItem);
        rootItem->appendChild(classItemYear);
        for(int nIx=0; nIx < i.value().size(); nIx++) {
            ClassItem* classItemDescription = new ClassItem({i.value().at(nIx), "Class"}, classItemYear);
            classItemYear->appendChild(classItemDescription);
        }
    }




//    for(int nIx = 0; nIx<classes.count(); ++nIx )
//    {
//        QMap entry = classes[nIx];
//        ClassItem* classItemYear = new ClassItem({entry.keys().first()}, rootItem);
//        rootItem->appendChild(classItemYear);

//        for(int nIy=0; nIy<entry.values().length();nIy++) {
//            QStringList classList = entry.values().at(nIy);
//            for(int nIz = 0; nIz< classList.size(); nIz++) {
//                QString sClass =  classList.at(nIz);
//                ClassItem* classItemDescription = new ClassItem({sClass},classItemYear);
//                classItemYear->appendChild(classItemDescription);
//            }
//        }

//    }
    endResetModel();
}
