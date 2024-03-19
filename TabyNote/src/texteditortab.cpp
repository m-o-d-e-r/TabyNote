#include <QApplication>
#include <QWheelEvent>
#include <QScrollBar>
#include <QTextDocument>
#include <QFrame>
#include <QPainter>

#include "texteditortab.h"


TextEditorTab::TextEditorTab()
{
    setUpNumbarWidget();
    setUpTextEditor();
    setUpFileOverViewWidget();
    setUpTextEditorScrollbar();

    makeConnections();

    packMainComponents();
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


void TextEditorTab::setUpNumbarWidget()
{
    this->numBarWidget = new NumBarWidget(this);
}


void TextEditorTab::setUpTextEditor()
{
    this->textEditor = new EditorWorkSpace;
    QFont editorWorkSpaceFont = this->textEditor->font();
    editorWorkSpaceFont.setPixelSize(12);
    this->textEditor->setFont(editorWorkSpaceFont);
    this->textEditor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}


void TextEditorTab::setUpFileOverViewWidget()
{
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
    this->fileOverView->setFixedWidth(this->width() * 0.2);
    //this->fileOverView->setFrameStyle(QFrame::Plain);
}


void TextEditorTab::setUpTextEditorScrollbar()
{
    this->textEditorScrollbar = new QScrollBar;
    this->textEditorScrollbar->hide();
}


void TextEditorTab::makeConnections()
{
    connect(this->textEditor, &EditorWorkSpace::updateRequest, this, &TextEditorTab::updateNumBarWidget);
    connect(
        this->textEditor,
        &QPlainTextEdit::cursorPositionChanged,
        this,
        &TextEditorTab::textEditorCursorPositionChanged
    );
    /*connect(
        this->textEditorSpace,
        &QPlainTextEdit::updateRequest,
        this,
        &TextEditorTab::on_updates
    );*/
    connect(
        this->textEditor->verticalScrollBar(),
        &QScrollBar::valueChanged,
        this,
        &TextEditorTab::on_editorScrollBar_valueChanged
    );
    connect(
        this->textEditor->verticalScrollBar(),
        &QScrollBar::valueChanged,
        this->textEditorScrollbar,
        &QScrollBar::setValue
    );
    connect(
        this->textEditor->verticalScrollBar(),
        &QScrollBar::rangeChanged,
        this->textEditorScrollbar,
        [&](int min_, int max_)
        {
            this->textEditorScrollbar->setRange(min_, max_);
            this->textEditorScrollbar->show();
        }
    );
    connect(
        this->textEditorScrollbar,
        &QScrollBar::valueChanged,
        this->textEditor->verticalScrollBar(),
        &QScrollBar::setValue
    );
}


void TextEditorTab::packMainComponents()
{
    QHBoxLayout* baseLayout = new QHBoxLayout;
    setLayout(baseLayout);

    baseLayout->addWidget(this->numBarWidget       , 0);
    baseLayout->addWidget(this->textEditor         , 1);
    baseLayout->addWidget(this->fileOverView       , 0);
    baseLayout->addWidget(this->textEditorScrollbar, 0);
}


const EditorWorkSpace* TextEditorTab::getTextEditor()
{
    return this->textEditor;
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


void TextEditorTab::setSynchonizedText(QByteArray fileData)
{
    this->textEditor->setPlainText(fileData);
    this->fileOverView->setPlainText(fileData);
}


void TextEditorTab::setSynchonizedText()
{
    this->fileOverView->setPlainText(this->textEditor->toPlainText());
}


void TextEditorTab::numBarChangeVisibility(bool isChecked)
{
    if (isChecked)
        this->numBarWidget->show();
    else
        this->numBarWidget->hide();
}


void TextEditorTab::textEditorChangeWrapMode(bool isChecked)
{
    if (isChecked)
    {
        this->textEditor->setWordWrapMode(QTextOption::WrapAnywhere);
        this->fileOverView->setWordWrapMode(QTextOption::WrapAnywhere);
    } else {
        this->textEditor->setWordWrapMode(QTextOption::NoWrap);
        this->fileOverView->setWordWrapMode(QTextOption::NoWrap);
    }
}


void TextEditorTab::fileOverViewChangeVisibility(bool isChecked)
{
    if (isChecked)
        this->fileOverView->show();
    else
        this->fileOverView->hide();
}


void TextEditorTab::editWorkSpaceFontSize(int deltaSize)
{
    QFont currentFont = this->textEditor->font();

    if ((currentFont.pixelSize() + deltaSize) <= 10 || (currentFont.pixelSize() + deltaSize) >= 40)
        return;

    currentFont.setPixelSize(currentFont.pixelSize() + deltaSize);

    this->textEditor->setFont(currentFont);
    this->numBarWidget->setFont(currentFont);
}


void TextEditorTab::on_editorScrollBar_valueChanged()
{
    QScrollBar* scrollSender =  static_cast<QScrollBar*>(sender());

    this->fileOverView->verticalScrollBar()->setValue(
        scrollSender->value()
        * this->fileOverView->verticalScrollBar()->pageStep()
        / scrollSender->pageStep()
    );
}


void TextEditorTab::textEditorCursorPositionChanged()
{/*
    QTextCursor cursor = this->textEditor->textCursor();

    this->textEditorScrollbar->setValue(
        this->textEditorScrollbar->maximum()
        / this->textEditor->blockCount()
        * cursor.blockNumber()
    );*/
}


int TextEditorTab::getNumbarWidgth()
{
    int digits = 1;
    int max = qMax(1, this->textEditor->blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    return 3 + this->textEditor->fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
}


void TextEditorTab::updateNumBarWidget(const QRect& rect, int dy)
{
    if (dy)
        this->numBarWidget->scroll(0, dy);
    else
        this->numBarWidget->update(0, rect.y(), this->textEditor->width(), rect.height());

    this->numBarWidget->setFixedWidth(getNumbarWidgth());
}


void TextEditorTab::numbarPaintEvent(QPaintEvent *event)
{
    QPainter painter(this->numBarWidget);
    painter.fillRect(event->rect(), Qt::lightGray);

    QTextBlock block = this->textEditor->__firstVisibleBlock();

    int blockNumber = block.blockNumber();
    int top = qRound(
        this->textEditor->__blockBoundingGeometry(block).translated(
            this->textEditor->__contentOffset()
        ).top()
    );
    int bottom = top + qRound(this->textEditor->__blockBoundingRect(block).height());

    while (block.isValid() && top <= event->rect().bottom())
    {
        if (block.isVisible() && bottom >= event->rect().top())
        {
            QString number = QString::number(blockNumber + 1);
            painter.setPen(Qt::black);
            painter.drawText(
                0,
                top,
                this->numBarWidget->width(),
                this->textEditor->font().pixelSize(),
//                fontMetrics().height(),
                Qt::AlignRight,
                        number
            );
        }

        bottom = top + qRound(this->textEditor->__blockBoundingRect(block).height());
        ++blockNumber;
        block = block.next();
        top = bottom;
    }
}

