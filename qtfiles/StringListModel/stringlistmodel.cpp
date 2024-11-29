#include "stringlistmodel.h"

StringListModel::StringListModel(const QStringList &strings,QObject *parent)
    : QAbstractListModel(parent),stringList(strings)
{

}


//  QVariant StringListModel::data(const QModelIndex& index, int role) const {
//     if (!index.isValid()) {
//         return QVariant();
//     }

//     if (index.row() >= stringList.size()) {
//         return QVariant();
//     }

//     if (role == Qt::DisplayRole || role == Qt::EditRole) {
//         return QVariant(stringList.at(index.row()));  // 将 QString 转换为 QVariant
//     }

//     return QVariant();
// }
//  bool  setData (const QModelIndex& index,const QVariant &value,int role = Qt::EditRole){

//  }
//  int  StringListModel::rowCount (const QModelIndex &parent )const {

//  }
// QVariant StringListModel:: headData(int section ,Qt::Orientation orientation,int role  )const{

// }
// bool insertRow(int postion , int rows , const QModelIndex &index = QModelIndex()){

// }
// bool deleteRow(int postion , int rows , const QModelIndex &index = QModelIndex()) {

//}
