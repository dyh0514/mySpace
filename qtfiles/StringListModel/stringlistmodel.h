#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H
#include <QModelIndex>
#include <QAbstractListModel>
#include <QStringList>
#include <QVariant>
class StringListModel : public QAbstractListModel//子类的构造函数就点进去基类的构造函数看，在子类中构造了就在基类中也构造了
{
    Q_OBJECT
public:
    explicit StringListModel(const QStringList &strings,QObject *parent = nullptr);

    bool insertRow(int postion , int rows , const QModelIndex &index = QModelIndex());
    bool deleteRow(int postion , int rows , const QModelIndex &index = QModelIndex());


    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const = 0;
    virtual int  rowCount (const QModelIndex &parent =QModelIndex())const =0;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole)const;
    virtual QVariant headerData(int section, Qt::Orientation orientation,
                                int role = Qt::DisplayRole) const ;


private:
    QStringList stringList;

};

#endif // STRINGLISTMODEL_H
