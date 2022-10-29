#ifndef TEXTEDITORTAB_H
#define TEXTEDITORTAB_H

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QByteArray>
#include <QTextEdit>
#include <QLabel>
#include <QFile>

#include "numbarwidget.h"


class TextEditorTab : public QWidget
{
    Q_OBJECT

    NumBarWidget* numBarWidget;
    QPlainTextEdit* textEditor;
    QTextEdit* fileOverView;
    QScrollBar* textEditorScrollbar;

    QFile* file = nullptr;
    bool isSaved = false;

public:
    TextEditorTab();
    TextEditorTab(QFile*, bool);
    ~TextEditorTab();

    void setUpNumbarWidget();
    void setUpTextEditor();
    void setUpFileOverViewWidget();
    void setUpTextEditorScrollbar();

    void makeConnections();

    void packMainComponents();

    const QPlainTextEdit* getTextEditor();
    QTextEdit* getFileOverView();

    void setFile(QFile*);
    QFile* getFile();

    void setStatus(bool);
    bool getStatus();

    void setSynchonizedText(QByteArray);
    void setSynchonizedText();

    void numBarChangeVisibility(bool);
    void textEditorChangeWrapMode(bool);
    void fileOverViewChangeVisibility(bool);

    void editWorkSpaceFontSize(int);

public slots:
    void on_editorScrollBar_valueChanged();
    void textEditorCursorPositionChanged();

};

#endif // TEXTEDITORTAB_H
