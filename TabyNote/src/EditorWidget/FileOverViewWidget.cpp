#include <QPaintEvent>
#include <QPainter>
#include <QRect>

#include "FileOverViewWidget.h"


FileOverViewWidget::FileOverViewWidget() {}


void FileOverViewWidget::setEditorWorkSpaceRect(int rowIndex, double difference)
{
    this->rowIndex = rowIndex;
    this->difference = difference;
}



void FileOverViewWidget::paintEvent(QPaintEvent* event)
{
/*    QPainter painter(viewport());
    painter.setPen(QColor(74, 129, 165, 175));

    painter.eraseRect(viewport()->rect());
    painter.drawRect(
        0,
        rowIndex * 3,
//        textCursor().blockNumber() * 3,
        viewport()->width(),
        rect().height() / difference
    );*/
    QTextEdit::paintEvent(event);
}
