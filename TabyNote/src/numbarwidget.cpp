#include <QApplication>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>

#include "numbarwidget.h"


NumBarWidget::NumBarWidget() {}


int NumBarWidget::setNumBarWidth(int blocksCount)
{
    int digits = 1;
    int max = qMax(1, blocksCount);

    while (max >= 10) {
        max /= 10;
        ++digits;
    }
    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;

    return space;
}



QFont NumBarWidget::getPainterFont()
{
    return this->painterFont;
}


void NumBarWidget::setPainterFont(QFont font)
{
    this->painterFont = font;
}


int NumBarWidget::getLineCount()
{
       return this->lineCount;
}


void NumBarWidget::setLineCount(int lineCount)
{
    this->lineCount = lineCount;
}


void NumBarWidget::setNumRange(int minNumber, int maxNumber)
{
    this->lineNumberMin = minNumber;
    this->lineNumberMax = maxNumber;
}



void NumBarWidget::paintEvent(QPaintEvent* event)
{
    const QRect& rect = event->rect();
    QPainter numBarPainter(this);
    numBarPainter.setFont(this->painterFont);
    numBarPainter.eraseRect(rect);
    numBarPainter.setRenderHint(QPainter::Antialiasing);

    for (int i = this->lineNumberMin; i <= this->lineNumberMax; i++)
    {
        numBarPainter.drawText(
            10,
            (this->painterFont.pixelSize() + 3) * i,
            QString::number(i)
        );
    }
}
