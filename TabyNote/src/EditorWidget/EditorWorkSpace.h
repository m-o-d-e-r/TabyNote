#ifndef EDITORWORKSPACE_H
#define EDITORWORKSPACE_H


#include <QPlainTextEdit>
#include <QTextBlock>


class EditorWorkSpace: public QPlainTextEdit
{
public:
    QTextBlock __firstVisibleBlock()
    {
        return firstVisibleBlock();
    }

    QRectF __blockBoundingGeometry(QTextBlock block)
    {
        return blockBoundingGeometry(block);
    }

    QRectF __blockBoundingRect(QTextBlock block)
    {
        return blockBoundingRect(block);
    }

    QPointF __contentOffset()
    {
        return contentOffset();
    }
};



#endif // EDITORWORKSPACE_H
