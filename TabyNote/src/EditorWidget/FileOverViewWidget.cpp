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
    QTextEdit::paintEvent(event);
}
