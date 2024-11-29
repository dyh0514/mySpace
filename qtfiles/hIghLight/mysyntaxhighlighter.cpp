#include "mysyntaxhighlighter.h"
#include <QTextCharFormat>
#include <QFont>
#include <QRegularExpression>
    MySyntaxHighlighter::MySyntaxHighlighter(QTextDocument * parent ):QSyntaxHighlighter (parent)
{

}
    void MySyntaxHighlighter::highlightBlock(const QString &text)
{
    QTextCharFormat myFormat;
    myFormat.setFont(QFont("微软雅黑"));
    myFormat.setFontWeight(QFont::Bold);
    myFormat.setForeground(Qt::green);

    QString patten = "\\bchar\\b" ;
    //创建正则表达式
    QRegularExpression express (patten);
    int index = text.indexOf(express);
    while (index > 0){
        int matchLen = express.match
    }
}
