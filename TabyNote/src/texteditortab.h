#ifndef TEXTEDITORTAB_H
#define TEXTEDITORTAB_H

#include <QTextEdit>
#include <QFile>


class TextEditorTab : public QTextEdit
{
    Q_OBJECT

    QFile* file = nullptr;
    bool isSaved = false;

public:
    TextEditorTab();
    TextEditorTab(QFile*, bool);
    ~TextEditorTab();

    void setFile(QFile*);
    void setStatus(bool);

    QFile* getFile();
    bool getStatus();
};

#endif // TEXTEDITORTAB_H
