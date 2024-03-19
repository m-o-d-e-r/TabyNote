#include <QApplication>
#include <QWheelEvent>
#include <QScrollBar>
#include <QTextDocument>
#include <QFrame>
#include <QPainter>

#include "MainEditorArea.h"


MainEditorArea::MainEditorArea()
{
    setUpNumbarWidget();
    setUpTextEditor();
    setUpFileOverViewWidget();
    setUpTextEditorScrollbar();

    makeConnections();

    packMainComponents();
}


MainEditorArea::MainEditorArea(QFile* file_, bool saved) : MainEditorArea()
{
    this->file = file_;
    this->isSaved = saved;
}


MainEditorArea::~MainEditorArea()
{
    if (this->file)
    {
        this->file->close();
        delete this->file;
    }
}


void MainEditorArea::setUpNumbarWidget()
{
    this->numBarWidget = new NumBarWidget(this);
}


void MainEditorArea::setUpTextEditor()
{
    this->textEditor = new EditorWorkSpace;
    QFont editorWorkSpaceFont = this->textEditor->font();
    editorWorkSpaceFont.setPixelSize(12);
    this->textEditor->setFont(editorWorkSpaceFont);
    this->textEditor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}


void MainEditorArea::setUpFileOverViewWidget()
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


void MainEditorArea::setUpTextEditorScrollbar()
{
    this->textEditorScrollbar = new QScrollBar;
    this->textEditorScrollbar->hide();
}


void MainEditorArea::makeConnections()
{
    connect(this->textEditor, &EditorWorkSpace::updateRequest, this, &MainEditorArea::updateNumBarWidget);
    connect(
        this->textEditor,
        &QPlainTextEdit::cursorPositionChanged,
        this,
        &MainEditorArea::textEditorCursorPositionChanged
    );
    /*connect(
        this->textEditorSpace,
        &QPlainTextEdit::updateRequest,
        this,
        &MainEditorArea::on_updates
    );*/
    connect(
        this->textEditor->verticalScrollBar(),
        &QScrollBar::valueChanged,
        this,
        &MainEditorArea::on_editorScrollBar_valueChanged
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


void MainEditorArea::packMainComponents()
{
    QHBoxLayout* baseLayout = new QHBoxLayout;
    setLayout(baseLayout);

    baseLayout->addWidget(this->numBarWidget       , 0);
    baseLayout->addWidget(this->textEditor         , 1);
    baseLayout->addWidget(this->fileOverView       , 0);
    baseLayout->addWidget(this->textEditorScrollbar, 0);
}


const EditorWorkSpace* MainEditorArea::getTextEditor()
{
    return this->textEditor;
}


QTextEdit* MainEditorArea::getFileOverView()
{
    return this->fileOverView;
}


void MainEditorArea::setFile(QFile* file)
{
    this->file = file;
}

void MainEditorArea::setStatus(bool status)
{
    this->isSaved = status;
}


QFile* MainEditorArea::getFile()
{
    return this->file;
}

bool MainEditorArea::getStatus()
{
    return this->isSaved;
}


void MainEditorArea::setSynchonizedText(QByteArray fileData)
{
    this->textEditor->setPlainText(fileData);
    this->fileOverView->setPlainText(fileData);
}


void MainEditorArea::setSynchonizedText()
{
    this->fileOverView->setPlainText(this->textEditor->toPlainText());
}


void MainEditorArea::numBarChangeVisibility(bool isChecked)
{
    if (isChecked)
        this->numBarWidget->show();
    else
        this->numBarWidget->hide();
}


void MainEditorArea::textEditorChangeWrapMode(bool isChecked)
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


void MainEditorArea::fileOverViewChangeVisibility(bool isChecked)
{
    if (isChecked)
        this->fileOverView->show();
    else
        this->fileOverView->hide();
}


void MainEditorArea::editWorkSpaceFontSize(int deltaSize)
{
    QFont currentFont = this->textEditor->font();

    if ((currentFont.pixelSize() + deltaSize) <= 10 || (currentFont.pixelSize() + deltaSize) >= 40)
        return;

    currentFont.setPixelSize(currentFont.pixelSize() + deltaSize);

    this->textEditor->setFont(currentFont);
    this->numBarWidget->setFont(currentFont);
}


void MainEditorArea::on_editorScrollBar_valueChanged()
{
    QScrollBar* scrollSender =  static_cast<QScrollBar*>(sender());

    this->fileOverView->verticalScrollBar()->setValue(
        scrollSender->value()
        * this->fileOverView->verticalScrollBar()->pageStep()
        / scrollSender->pageStep()
    );
}


void MainEditorArea::textEditorCursorPositionChanged()
{/*
    QTextCursor cursor = this->textEditor->textCursor();

    this->textEditorScrollbar->setValue(
        this->textEditorScrollbar->maximum()
        / this->textEditor->blockCount()
        * cursor.blockNumber()
    );*/
}


int MainEditorArea::getNumbarWidgth()
{
    int digits = 1;
    int max = qMax(1, this->textEditor->blockCount());
    while (max >= 10) {
        max /= 10;
        ++digits;
    }

    return 3 + this->textEditor->fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
}


void MainEditorArea::updateNumBarWidget(const QRect& rect, int dy)
{
    if (dy)
        this->numBarWidget->scroll(0, dy);
    else
        this->numBarWidget->update(0, rect.y(), this->textEditor->width(), rect.height());

    this->numBarWidget->setFixedWidth(getNumbarWidgth());
}


void MainEditorArea::numbarPaintEvent(QPaintEvent *event)
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

