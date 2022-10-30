#ifndef NUMBARWIDGET_H
#define NUMBARWIDGET_H

#include <QWidget>
#include <QPlainTextEdit>


class MainEditorArea;


class NumBarWidget: public QWidget
{
private:
    MainEditorArea* editor;

public:
    NumBarWidget(MainEditorArea*);

    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent* event) override;

};

#endif // NUMBARWIDGET_H
