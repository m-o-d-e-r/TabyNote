#ifndef FILEOVERVIEWWIDGET_H
#define FILEOVERVIEWWIDGET_H

#include <QTextEdit>


class FileOverViewWidget: public QTextEdit
{
    Q_OBJECT

    int rowIndex;
    double difference;

public:
    FileOverViewWidget();

    void setEditorWorkSpaceRect(int, double);
    void paintEvent(QPaintEvent*) override;

};

#endif // FILEOVERVIEWWIDGET_H
