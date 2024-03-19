#include <QApplication>
#include <QWheelEvent>

#include "texteditortab.h"


TextEditorTab::TextEditorTab()
{
    this->numBarWidget = new QLabel("1");
    this->numBarWidget->setAlignment(Qt::AlignTop);

    this->textEditorSpace = new QTextEdit;
    QFont currentFont = this->textEditorSpace->currentFont();
    currentFont.setPixelSize(12);
    this->textEditorSpace->setFont(currentFont);


    QHBoxLayout* test = new QHBoxLayout;
    setLayout(test);

    test->addWidget(this->numBarWidget);
    test->addWidget(this->textEditorSpace);
}

TextEditorTab::TextEditorTab(QFile* file_, bool saved) : TextEditorTab()
{
    this->file = file_;
    this->isSaved = saved;
}

TextEditorTab::~TextEditorTab()
{
    if (this->file)
    {
        this->file->close();
        delete this->file;
    }
}


QTextEdit* TextEditorTab::getEditorSpace()
{
    return this->textEditorSpace;
}

void TextEditorTab::setFile(QFile* file)
{
    this->file = file;
}

void TextEditorTab::setStatus(bool status)
{
    this->isSaved = status;
}


QFile* TextEditorTab::getFile()
{
    return this->file;
}

bool TextEditorTab::getStatus()
{
    return this->isSaved;
}


void TextEditorTab::wheelEvent(QWheelEvent* event)
{
    Qt::KeyboardModifiers key = qApp->keyboardModifiers();
    if (key == Qt::ControlModifier)
    {
        int scarollValue = event->angleDelta().y();

        if (scarollValue > 0)
            this->editWorkSpaceFontSize(2);
        else if (scarollValue < 0)
            this->editWorkSpaceFontSize(-2);
    }
}

void TextEditorTab::editWorkSpaceFontSize(int deltaSize)
{
    QFont currentFont = this->textEditorSpace->currentFont();

    if (currentFont.pixelSize() <= 10 && deltaSize < 0)
        return;

    currentFont.setPixelSize(currentFont.pixelSize() + deltaSize);
    this->textEditorSpace->setFont(currentFont);
}
