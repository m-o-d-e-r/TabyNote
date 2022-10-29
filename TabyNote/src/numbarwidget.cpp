#include <QApplication>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>

#include "numbarwidget.h"
#include "texteditortab.h"
#include "EditorWorkSpace.h"


NumBarWidget::NumBarWidget(TextEditorTab* editor)
{
    this->editor = editor;
}

QSize NumBarWidget::sizeHint() const
{
    return QSize(editor->getNumbarWidgth(), 0);
}


void NumBarWidget::paintEvent(QPaintEvent* event)
{
    editor->numbarPaintEvent(event);
}
