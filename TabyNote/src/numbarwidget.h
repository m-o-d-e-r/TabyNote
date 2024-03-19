#ifndef NUMBARWIDGET_H
#define NUMBARWIDGET_H

#include <QWidget>
#include <QPlainTextEdit>

class TextEditorTab;

class NumBarWidget: public QWidget
{
    TextEditorTab* editor;

    QFont painterFont;
    int lineCount = 0;
    int lineNumberMin = 1;
    int lineNumberMax = 1;

public:
    NumBarWidget();

    int setNumBarWidth(int);

    QFont getPainterFont();
    void setPainterFont(QFont);

    int getLineCount();

    void paintEvent(QPaintEvent *event) override;

public slots:
    void setLineCount(int);
    void setNumRange(int, int);

};

#endif // NUMBARWIDGET_H
