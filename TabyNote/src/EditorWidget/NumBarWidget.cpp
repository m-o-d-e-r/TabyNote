#include <QApplication>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>

#include "NumBarWidget.h"
#include "MainEditorArea.h"
#include "EditorWorkSpace.h"


NumBarWidget::NumBarWidget(MainEditorArea* editor)
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
