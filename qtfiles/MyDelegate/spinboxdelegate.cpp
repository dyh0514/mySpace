#include "spinboxdelegate.h"
#include <QSpinBox>

SpinBoxDelegate::SpinBoxDelegate(QObject * parent):QItemDelegate(parent)
{

}
QWidget * SpinBoxDelegate::createEditor(QWidget *parent,
                      const QStyleOptionViewItem &option,
                      const QModelIndex &index)const
{
    QSpinBox * editer = new QSpinBox(parent);
    editer->setMinimum(0);
    editer->setMaximum(100);
    return editer;
}

void SpinBoxDelegate:: setEditorData(QWidget *editor, const QModelIndex &index)const
{
    int value=index.model()->data(index,Qt::EditRole).toInt();
    auto * spinbox = static_cast<QSpinBox*>(editor);
    spinbox->setValue(value);
}

void SpinBoxDelegate:: setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    auto * spinbox = static_cast<QSpinBox*>(editor);
    spinbox->interpretText();//如果是spinbox，就要加这句话刷新
    int value = spinbox->value();
    model->setData(index,value,Qt::EditRole);
}

//更新显示的spinbox的显示区域
void SpinBoxDelegate:: updateEditorGeometry(QWidget *editor,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index)const
{
    editor->setGeometry(option.rect);//更新矩形区域
}
