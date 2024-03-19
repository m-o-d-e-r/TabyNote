#include <QApplication>
#include <QWheelEvent>
#include <QScrollBar>
#include <QFrame>

#include "texteditortab.h"


TextEditorTab::TextEditorTab()
{
    this->numBarWidget = new QLabel("1");
    this->numBarWidget->setAlignment(Qt::AlignTop);

    this->textEditorSpace = new QTextEdit;
    QFont editorWorkSpaceFont = this->textEditorSpace->currentFont();
    editorWorkSpaceFont.setPixelSize(12);
    this->textEditorSpace->setFont(editorWorkSpaceFont);
    this->textEditorSpace->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->textEditorSpace->verticalScrollBar()->setRange(0, 1000);
    //    this->textEditorSpace->verticalScrollBar()->setPageStep(100);
    connect(this->textEditorSpace->verticalScrollBar(), &QScrollBar::valueChanged, this, &TextEditorTab::on_editorScrollBar_valueChanged);

    this->fileOverView = new QTextEdit;
    this->fileOverView->setEnabled(false);
    QFont overViewtFont = this->fileOverView->currentFont();
    overViewtFont.setPixelSize(3);
    this->fileOverView->setFont(overViewtFont);
    QPalette overViewPalette;
    overViewPalette.setColor(QPalette::Text, Qt::black);
    this->fileOverView->setPalette(overViewPalette);
    this->fileOverView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->fileOverView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->fileOverView->setFixedWidth(textEditorSpace->width() * 0.2);
    this->fileOverView->setWordWrapMode(QTextOption::NoWrap);
    //    this->fileOverView->setFrameStyle(QFrame::Plain);

    QString t = QString::number(textEditorSpace->verticalScrollBar()->pageStep());

    this->tabEditorScrollbar = new QScrollBar;
    this->tabEditorScrollbar->setRange(0, 1000);
//    this->tabEditorScrollbar->set
    /*
    this->tabEditorScrollbar->setRange(
        this->textEditorSpace->verticalScrollBar()->minimum(),
        this->textEditorSpace->verticalScrollBar()->maximum()
    );*/
    connect(
        this->tabEditorScrollbar,
        &QScrollBar::valueChanged,
        this->textEditorSpace->verticalScrollBar(),
        &QScrollBar::setValue
    );
    connect(
        this->textEditorSpace->verticalScrollBar(),
        &QScrollBar::valueChanged,
        this->tabEditorScrollbar,
        &QScrollBar::setValue
    );

    QHBoxLayout* test = new QHBoxLayout;
    setLayout(test);

    test->addWidget(this->numBarWidget);
    test->addWidget(this->textEditorSpace);
    test->addWidget(this->fileOverView);
    test->addWidget(this->tabEditorScrollbar);
    test->setStretch(0, 0);
    test->setStretch(1, 1);
    test->setStretch(2, 0);
    test->setStretch(3, 0);
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

QTextEdit* TextEditorTab::getFileOverView()
{
    return this->fileOverView;
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

/*void TextEditorTab::wheelEvent(QWheelEvent* event)
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
}*/

void TextEditorTab::editWorkSpaceFontSize(int deltaSize)
{
    QFont currentFont = this->textEditorSpace->currentFont();

    if (currentFont.pixelSize() <= 10 && deltaSize < 0)
        return;

    currentFont.setPixelSize(currentFont.pixelSize() + deltaSize);
    this->textEditorSpace->setFont(currentFont);
}


void TextEditorTab::on_editorScrollBar_valueChanged()
{
    QScrollBar* scrollSender =  static_cast<QScrollBar*>(sender());

    this->fileOverView->verticalScrollBar()->setValue(
        scrollSender->value() * this->fileOverView->verticalScrollBar()->pageStep() / scrollSender->pageStep()
    );
}


