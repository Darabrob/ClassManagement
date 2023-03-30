#include "classitem.h"

ClassItem::ClassItem(const QList<QVariant> &data, ClassItem *parent)
    : m_itemData(data), m_parentItem(parent)
{

}

ClassItem::~ClassItem()
{
    qDeleteAll(m_childItems);
}

void ClassItem::appendChild(ClassItem *item)
{
    m_childItems.append(item);
}

ClassItem *ClassItem::child(int row)
{
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

int ClassItem::childCount() const
{
    return m_childItems.count();
}

int ClassItem::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<ClassItem*>(this));

    return 0;
}

int ClassItem::columnCount() const
{
    return m_itemData.count();
}

QVariant ClassItem::data(int column) const
{
    if (column < 0 || column >= m_itemData.size())
        return QVariant();
    return m_itemData.at(column);
}

ClassItem *ClassItem::parentItem()
{
    return m_parentItem;
}
