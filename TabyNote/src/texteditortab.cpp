#include "texteditortab.h"


TextEditorTab::TextEditorTab() {}

TextEditorTab::TextEditorTab(QFile* file_, bool saved): file(file_), isSaved(saved) {}

TextEditorTab::~TextEditorTab()
{
    if (this->file)
    {
        this->file->close();
        delete this->file;
    }
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
