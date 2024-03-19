#include <QTextCursor>
#include <QStyleFactory>
#include <QFontDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_about.h"

#include "EditorWidget/MainEditorArea.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->__load_theme(":style/taby_light.css");

    ui->actionSave->setDisabled(true);
    ui->actionSave_as->setDisabled(true);

    this->statusBar()->addPermanentWidget(this->currentCurrsorPositionLabel);
    this->statusBar()->addPermanentWidget(this->currentFileNameLabel);
    this->statusBar()->showMessage("Welcome)", 5000);    
}


MainWindow::~MainWindow() {
    delete currentCurrsorPositionLabel;
    delete currentFileNameLabel;
    delete ui;
}



void MainWindow::on_actionOpen_triggered()
{
    QString fullPathToFile = QFileDialog::getOpenFileName();
    QFile* file = new QFile(fullPathToFile);

    if (!file->open(QIODevice::Text | QIODevice::ReadWrite))
    {
        this->statusBar()->showMessage("Can't open file...");
        return;
    }

    MainEditorArea* currentEditor = new MainEditorArea(file, true);
    if (ui->tabWidget->count() > 0)
    {
        MainEditorArea* firstTabEditorWidget = static_cast<MainEditorArea*>(ui->tabWidget->widget(0));
        if (firstTabEditorWidget)
        {
            QFont currentFont = currentEditor->font();//currentFont();
            currentFont.setPixelSize(
                firstTabEditorWidget->font().pixelSize()//currentFont().pixelSize()
            );
            currentEditor->setFont(currentFont);
        }
    }
    currentEditor->numBarChangeVisibility(ui->actionRender_numbar->isChecked());
    currentEditor->textEditorChangeWrapMode(ui->actionWord_Wrap->isChecked());
    currentEditor->fileOverViewChangeVisibility(ui->actionFilemap->isChecked());

    connect(
        currentEditor->getTextEditor(), &QPlainTextEdit::textChanged, this,
        [&]() {MainWindow::__on_change_text_editor_callback();}
    );
    connect(
        currentEditor->getTextEditor(), &QPlainTextEdit::cursorPositionChanged, this,
        [&]() {MainWindow::__on_cursor_position_changed_callback();}
    );

    currentEditor->setSynchonizedText(file->readAll());


    QString fileName = (new QFileInfo(fullPathToFile))->fileName();
    ui->tabWidget->addTab(currentEditor, fileName);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);

    this->statusBar()->showMessage("File opened", 5000);
    this->currentFileNameLabel->setText("File name: " + fileName);
}



void MainWindow::on_actionSave_as_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();

    MainEditorArea* currentEditor =  static_cast<MainEditorArea*>(ui->tabWidget->widget(currentIndex));
    if (!currentEditor) {return;}

    QFileDialog fileDialog;
    fileDialog.setStyleSheet("");

    QString fullPathToFile = fileDialog.getSaveFileName();
    QFile* file = new QFile(fullPathToFile);

    if (file->open(QIODevice::Text | QIODevice::ReadWrite))
    {
        QTextStream fileStream(file);
        fileStream << currentEditor->getTextEditor()->toPlainText();
    }

    ui->actionSave->setDisabled(false);
    ui->actionSave_as->setDisabled(true);

    currentEditor->setStatus(true);
    currentEditor->setFile(file);
    ui->tabWidget->setTabText(currentIndex, (new QFileInfo(fullPathToFile))->fileName());
}


void MainWindow::on_actionSave_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();

    MainEditorArea* currentEditor =  static_cast<MainEditorArea*>(ui->tabWidget->widget(currentIndex));
    if (!currentEditor) {return;}

    currentEditor->getFile()->close();
    if (!currentEditor->getFile()->open(QIODevice::Text | QIODevice::ReadWrite | QIODevice::Truncate)) {return;}

    QTextStream fileStream(currentEditor->getFile());
    fileStream << currentEditor->getTextEditor()->toPlainText();

    currentEditor->setStatus(true);
    ui->tabWidget->setTabText(currentIndex, (new QFileInfo(currentEditor->getFile()->fileName()))->fileName());
}



// operations with tabs
void MainWindow::on_actionNew_tab_triggered()
{
    MainEditorArea* tabEditor = new MainEditorArea;
    tabEditor->numBarChangeVisibility(ui->actionRender_numbar->isChecked());
    tabEditor->textEditorChangeWrapMode(ui->actionWord_Wrap->isChecked());
    tabEditor->fileOverViewChangeVisibility(ui->actionFilemap->isChecked());

    connect(
        tabEditor->getTextEditor(), &QPlainTextEdit::textChanged, this,
        [&]() {MainWindow::__on_change_text_editor_callback();}
    );
    connect(
        tabEditor->getTextEditor(), &QPlainTextEdit::cursorPositionChanged, this,
        [&]() {MainWindow::__on_cursor_position_changed_callback();}
    );

    ui->tabWidget->addTab(tabEditor, "* Unsaved");
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);
}


void MainWindow::on_actionClose_tab_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();
    if (currentIndex >= 0)
    {
        on_tabWidget_tabCloseRequested(currentIndex);
    }
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    MainEditorArea* currentEditor = static_cast<MainEditorArea*>(ui->tabWidget->widget(index));
    currentEditor->deleteLater();
    ui->tabWidget->removeTab(index);

    if (ui->tabWidget->count() == 0)
    {
        __on_all_tabs_removed();
    }
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    QString newTitle = "Taby note(%1): %2";
    this->setWindowTitle(newTitle.arg(index).arg(ui->tabWidget->tabText(index)));

    MainEditorArea* currentEdit = static_cast<MainEditorArea*>(ui->tabWidget->widget(index));
    if (!currentEdit) {return;}

    if (currentEdit->getFile())
    {
        ui->actionSave->setDisabled(false);
        ui->actionSave_as->setDisabled(true);
    } else {
        ui->actionSave->setDisabled(true);
        ui->actionSave_as->setDisabled(false);
    }

    this->statusBar()->showMessage("");
    this->currentFileNameLabel->setText("File name: " + ui->tabWidget->tabText(index));
}
// end operations with tabs


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionAbout_triggered()
{
    dialog_about* about = new dialog_about;

    about->show();
}


void MainWindow::on_actionDark_triggered()
{
    if (ui->actionDark->isChecked())
    {
        this->__load_theme(":style/taby_dark.css");
    } else {
        this->__load_theme(":style/taby_light.css");
    }
}


void MainWindow::on_actionFilemap_triggered(bool checked)
{
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        static_cast<MainEditorArea*>(
            ui->tabWidget->widget(i)
        )->fileOverViewChangeVisibility(checked);
    }
}


void MainWindow::on_actionIncrease_font_size_triggered()
{
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        static_cast<MainEditorArea*>(ui->tabWidget->widget(i))->editWorkSpaceFontSize(2);
    }
}


void MainWindow::on_actionDecrease_font_size_triggered()
{
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        static_cast<MainEditorArea*>(ui->tabWidget->widget(i))->editWorkSpaceFontSize(-2);
    }
}


void MainWindow::on_actionWord_Wrap_triggered(bool checked)
{
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        static_cast<MainEditorArea*>(ui->tabWidget->widget(i))->textEditorChangeWrapMode(checked);
    }
}


void MainWindow::on_actionRender_numbar_triggered(bool checked)
{
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        static_cast<MainEditorArea*>(ui->tabWidget->widget(i))->numBarChangeVisibility(checked);
    }
}



// help methods
void MainWindow::__on_all_tabs_removed()
{
    this->statusBar()->showMessage("");
    this->currentFileNameLabel->setText("File name: None");
    this->setWindowTitle("Taby note");
    ui->actionSave->setDisabled(true);
    ui->actionSave_as->setDisabled(true);
}

void MainWindow::__on_change_text_editor_callback()
{
    int currentIndex = ui->tabWidget->currentIndex();
    MainEditorArea* editor = static_cast<MainEditorArea*>(ui->tabWidget->widget(currentIndex));

    if (!editor) {return;}

    editor->setSynchonizedText();

    if (editor->getStatus())
    {
        ui->tabWidget->setTabText(
            currentIndex,
            "* " + ui->tabWidget->tabText(currentIndex)
        );
        editor->setStatus(false);
    }
}

template<typename _TE_Object>
void MainWindow::__setUp_current_line_highlighting(_TE_Object* editobject)
{
    QTextCursor cursor = editobject->textCursor();

    QList<QTextEdit::ExtraSelection> extraSelectionsList;
    QTextEdit::ExtraSelection selections;

    selections.format.setBackground(QColor(166, 78, 76, 100));
    selections.format.setProperty(QTextFormat::FullWidthSelection, true);
    selections.cursor = cursor;
    selections.cursor.clearSelection();

    extraSelectionsList.append(selections);
    editobject->setExtraSelections(extraSelectionsList);
}

void MainWindow::__on_cursor_position_changed_callback()
{
    QPlainTextEdit* editor = static_cast<QPlainTextEdit*>(sender());
    QTextEdit* fileOverView = nullptr;

    MainEditorArea* temp = static_cast<MainEditorArea*>(
        ui->tabWidget->widget(ui->tabWidget->currentIndex())
    );
    if (temp)
        fileOverView = temp->getFileOverView();

    if (editor && fileOverView)
    {
        QTextCursor cursor = editor->textCursor();

        fileOverView->setTextCursor(cursor);

        __setUp_current_line_highlighting<QPlainTextEdit>(editor);
        __setUp_current_line_highlighting<QTextEdit>(fileOverView);

        QString cursorPositionString = "Pos: (%1, %2)";
        currentCurrsorPositionLabel->setText(
            cursorPositionString.arg(cursor.columnNumber()).arg(
                cursor.blockNumber() + 1
            )
        );
    }
}


void MainWindow::__load_theme(const char * theme_name)
{
    QFile themeFile(theme_name);
    if (themeFile.exists())
    {
        themeFile.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&themeFile);

        qApp->setStyleSheet(ts.readAll());
    }
}
