#ifndef MYSYNTAXHIGHLIGHTER_H
#define MYSYNTAXHIGHLIGHTER_H
#include <QSyntaxHighlighter>
#include <QTextDocument>

class MySyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT
public:
    explicit MySyntaxHighlighter(QTextDocument * parent = nullptr);

protected:
    void highlightBlock(const QString &text);   //重新实现该函数

};

#endif // MYSYNTAXHIGHLIGHTER_H
