#ifndef FILEOVERVIEWWIDGET_H
#define FILEOVERVIEWWIDGET_H

#include <QTextEdit>


class FileOverViewWidget: public QTextEdit
{
    Q_OBJECT

    int rowIndex;
    double difference;

public:
    FileOverViewWidget() { setWordWrapMode(QTextOption::WrapAnywhere); }

    void setEditorWorkSpaceRect(int, double);
};

#endif // FILEOVERVIEWWIDGET_H
