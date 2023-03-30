#ifndef CLASSITEM_H
#define CLASSITEM_H
#include <QVariant>


class ClassItem
{
public:
    explicit ClassItem(const QList<QVariant> &data, ClassItem *parentItem = nullptr);
    ~ClassItem();

    void appendChild(ClassItem *child);

    ClassItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    ClassItem *parentItem();

private:
    QList<ClassItem *> m_childItems;
    QList<QVariant> m_itemData;
    ClassItem *m_parentItem;
};

#endif // CLASSITEM_H
