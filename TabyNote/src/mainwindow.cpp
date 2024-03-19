#include <QTextCursor>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_about.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->actionSave->setDisabled(true);
    ui->actionSave_as->setDisabled(true);

    this->statusBar()->addPermanentWidget(this->currentCurrsorPositionLabel);
    this->statusBar()->addPermanentWidget(this->currentFileNameLabel);
    this->statusBar()->showMessage("Welcome)");
}

MainWindow::~MainWindow() {
    delete currentCurrsorPositionLabel;
    delete currentFileNameLabel;
    delete ui;
}



void MainWindow::on_actionOpen_triggered()
{
    QString fullPathToFile = QFileDialog::getOpenFileName();
    QString fileName = (new QFileInfo(fullPathToFile))->fileName();
    QFile* file = new QFile(fullPathToFile);

/*
    TextEditorTab* editor = nullptr;
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        editor =  static_cast<TextEditorTab*>(ui->tabWidget->widget(i));
        if (editor)
        {
            QFileInfo editorFileInfo(editor->getFile()->fileName());
            qDebug(editorFileInfo.fileName().toLocal8Bit().data());
        } else
        {
            qDebug("error");
        }
        editor = nullptr;
    }*/


    if (!file->open(QIODevice::Text | QIODevice::ReadWrite))
    {
        this->statusBar()->showMessage("Can't open file...");
        return;
    }

    TextEditorTab* currentEditor = new TextEditorTab(file, true);
    currentEditor->blockSignals(true);
    connect(currentEditor, &TextEditorTab::textChanged, this,
        [&]()
        {
            MainWindow::__on_change_text_editor_callback();
        }
    );
    connect(currentEditor, &TextEditorTab::cursorPositionChanged, this,
        [&]()
        {
            MainWindow::__on_cursor_position_changed_callback();
        }
    );


    currentEditor->setText(file->readAll());

    ui->tabWidget->addTab(currentEditor, fileName);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count()-1);

    this->statusBar()->showMessage("File opened");
    this->currentFileNameLabel->setText("File name: " + fileName);
}


void MainWindow::on_actionSave_as_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();

    TextEditorTab* currentEditor =  static_cast<TextEditorTab*>(ui->tabWidget->widget(currentIndex));
    if (!currentEditor) {return;}

    QString fullPathToFile = QFileDialog::getSaveFileName();
    QString fileName = (new QFileInfo(fullPathToFile))->fileName();
    QFile* file = new QFile(fullPathToFile);

    if (file->open(QIODevice::Text | QIODevice::ReadWrite))
    {
        QTextStream fileStream(file);
        fileStream << currentEditor->toPlainText();
    }

    ui->actionSave->setDisabled(false);
    ui->actionSave_as->setDisabled(true);

    currentEditor->setStatus(true);
    currentEditor->setFile(file);
    ui->tabWidget->setTabText(currentIndex, fileName);
}

void MainWindow::on_actionSave_triggered()
{
    int currentIndex = ui->tabWidget->currentIndex();

    TextEditorTab* currentEditor =  static_cast<TextEditorTab*>(ui->tabWidget->widget(currentIndex));
    if (!currentEditor) {return;}

    currentEditor->getFile()->close();
    if (!currentEditor->getFile()->open(QIODevice::Text | QIODevice::ReadWrite | QIODevice::Truncate)) {return;}

    currentEditor->getFile()->close();
    if (!currentEditor->getFile()->open(QIODevice::Text | QIODevice::ReadWrite)) {return;}

    QTextStream fileStream(currentEditor->getFile());
    fileStream << currentEditor->toPlainText();

    currentEditor->setStatus(true);
    ui->tabWidget->setTabText(currentIndex, (new QFileInfo(currentEditor->getFile()->fileName()))->fileName());
}


// operations with tabs
void MainWindow::on_actionNew_tab_triggered()
{
    TextEditorTab* tabEditor = new TextEditorTab;
//    tabEditor->setStyleSheet(*(new QString("background-color: #191e24; color: #90bcd2")));
    connect(tabEditor, &TextEditorTab::textChanged, this,
        [&]()
        {
            MainWindow::__on_change_text_editor_callback();
        }
    );
    connect(tabEditor, &TextEditorTab::cursorPositionChanged, this,
        [&]()
        {
            MainWindow::__on_cursor_position_changed_callback();
        }
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
    TextEditorTab* currentEditor = static_cast<TextEditorTab*>(ui->tabWidget->widget(index));
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

    TextEditorTab* currentEdit = static_cast<TextEditorTab*>(ui->tabWidget->widget(index));
    if (!currentEdit) {return;}

    if (currentEdit->getFile())
    {
        ui->actionSave->setDisabled(false);
        ui->actionSave_as->setDisabled(true);
    }
    else
    {
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
    TextEditorTab* editor = static_cast<TextEditorTab*>(ui->tabWidget->widget(currentIndex));

    if (!editor) {return;}

    if (editor->getStatus())
    {
        ui->tabWidget->setTabText(
            currentIndex,
            "* " + ui->tabWidget->tabText(currentIndex)
        );
        editor->setStatus(false);
    }
}

void MainWindow::__on_cursor_position_changed_callback()
{
    TextEditorTab* editor = static_cast<TextEditorTab*>(sender());

    if (editor)
    {
        QString cursorPositionString = "Pos: (%1, %2)";
        QTextCursor cursor = editor->textCursor();

        currentCurrsorPositionLabel->setText(
            cursorPositionString.arg(cursor.columnNumber()).arg(
                cursor.blockNumber()
            )
        );
    }
}
