#include <QPaintEvent>
#include <QPainter>
#include <QRect>

#include "FileOverViewWidget.h"


void FileOverViewWidget::setEditorWorkSpaceRect(int rowIndex, double difference)
{
    this->rowIndex = rowIndex;
    this->difference = difference;
}
