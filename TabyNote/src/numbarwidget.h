#ifndef NUMBARWIDGET_H
#define NUMBARWIDGET_H

#include <QWidget>
#include <QPlainTextEdit>


class TextEditorTab;


class NumBarWidget: public QWidget
{
private:
    TextEditorTab* editor;

public:
    NumBarWidget(TextEditorTab*);

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent* event) override;

};

#endif // NUMBARWIDGET_H
