#ifndef TEXTEDITORTAB_H
#define TEXTEDITORTAB_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QFile>


class TextEditorTab : public QWidget
{
    Q_OBJECT

    QLabel* numBarWidget;
    QTextEdit* textEditorSpace;

    QFile* file = nullptr;
    bool isSaved = false;

public:
    TextEditorTab();
    TextEditorTab(QFile*, bool);
    ~TextEditorTab();

    QTextEdit* getEditorSpace();

    void setFile(QFile*);
    void setStatus(bool);

    QFile* getFile();
    bool getStatus();

    void wheelEvent(QWheelEvent *event) override;
    void editWorkSpaceFontSize(int);

};

#endif // TEXTEDITORTAB_H
