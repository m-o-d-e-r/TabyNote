#include <QTextCursor>
#include <QStyleFactory>
#include <QFontDialog>

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

//    this->statusBar()->setStyleSheet("color: #3B675B;");
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

    if (!file->open(QIODevice::Text | QIODevice::ReadWrite))
    {
        this->statusBar()->showMessage("Can't open file...");
        return;
    }

    TextEditorTab* currentEditor = new TextEditorTab(file, true);
    if (ui->tabWidget->count() > 0)
    {
        TextEditorTab* firstTabEditorWidget = static_cast<TextEditorTab*>(ui->tabWidget->widget(0));
        if (firstTabEditorWidget)
        {
            QFont currentFont = currentEditor->getEditorSpace()->currentFont();
            currentFont.setPixelSize(
                firstTabEditorWidget->getEditorSpace()->currentFont().pixelSize()
            );
            currentEditor->getEditorSpace()->setFont(currentFont);
        }
    }
    if (ui->actionFilemap->isChecked())
        currentEditor->getFileOverView()->show();
    else
        currentEditor->getFileOverView()->hide();

    connect(
        currentEditor->getEditorSpace(), &QTextEdit::textChanged, this,
        [&]() {MainWindow::__on_change_text_editor_callback();}
    );
    connect(
        currentEditor->getEditorSpace(), &QTextEdit::cursorPositionChanged, this,
        [&]() {MainWindow::__on_cursor_position_changed_callback();}
    );


    currentEditor->getEditorSpace()->setText(file->readAll());
    currentEditor->getFileOverView()->setText(currentEditor->getEditorSpace()->toPlainText());

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

    QFileDialog fileDialog;
    fileDialog.setStyleSheet("");

    QString fullPathToFile = fileDialog.getSaveFileName();
    QString fileName = (new QFileInfo(fullPathToFile))->fileName();
    QFile* file = new QFile(fullPathToFile);

    if (file->open(QIODevice::Text | QIODevice::ReadWrite))
    {
        QTextStream fileStream(file);
        fileStream << currentEditor->getEditorSpace()->toPlainText();
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

    QTextStream fileStream(currentEditor->getFile());
    fileStream << currentEditor->getEditorSpace()->toPlainText();

    currentEditor->setStatus(true);
    ui->tabWidget->setTabText(currentIndex, (new QFileInfo(currentEditor->getFile()->fileName()))->fileName());
}



// operations with tabs
void MainWindow::on_actionNew_tab_triggered()
{
    TextEditorTab* tabEditor = new TextEditorTab;
    if (ui->actionFilemap->isChecked())
        tabEditor->getFileOverView()->show();
    else
        tabEditor->getFileOverView()->hide();

    //    tabEditor->setStyleSheet(*(new QString("background-color: #191e24; color: #90bcd2")));
    connect(
        tabEditor->getEditorSpace(), &QTextEdit::textChanged, this,
        [&]() {MainWindow::__on_change_text_editor_callback();}
    );
    connect(
        tabEditor->getEditorSpace(), &QTextEdit::cursorPositionChanged, this,
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
        QFile themeFile(":style/taby_dark.css");
        if (themeFile.exists())
        {
            themeFile.open(QFile::ReadOnly | QFile::Text);
            QTextStream ts(&themeFile);

            qApp->setStyleSheet(ts.readAll());
        }
    } else {
        qApp->setStyleSheet("");
    }
}



void MainWindow::on_actionOwn_editor_prametrs_triggered()
{
    bool isOk;

    QFont customFont = QFontDialog::getFont(&isOk);
    if (isOk)
        qApp->setFont(customFont);
    else
        this->statusBar()->showMessage("Can't set font options(");
}


void MainWindow::on_actionFilemap_triggered(bool checked)
{
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        if (checked)
            static_cast<TextEditorTab*>(ui->tabWidget->widget(i))->getFileOverView()->show();
        else
            static_cast<TextEditorTab*>(ui->tabWidget->widget(i))->getFileOverView()->hide();
    }
}


void MainWindow::on_actionIncrease_font_size_triggered()
{
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        static_cast<TextEditorTab*>(ui->tabWidget->widget(i))->editWorkSpaceFontSize(2);
    }
}


void MainWindow::on_actionDecrease_font_size_triggered()
{
    for (int i = 0; i < ui->tabWidget->count(); i++)
    {
        static_cast<TextEditorTab*>(ui->tabWidget->widget(i))->editWorkSpaceFontSize(-2);
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
    TextEditorTab* editor = static_cast<TextEditorTab*>(ui->tabWidget->widget(currentIndex));

    if (!editor) {return;}

    editor->getFileOverView()->setText(editor->getEditorSpace()->toPlainText());

    auto lineCount = editor->getEditorSpace()->document()->blockCount();
    /*for (uint8_t i = 0; i < lineCount; i++)
    {
    )*/



    if (editor->getStatus())
    {
        ui->tabWidget->setTabText(
            currentIndex,
            "* " + ui->tabWidget->tabText(currentIndex)
        );
        editor->setStatus(false);
    }
}

void MainWindow::__setUp_current_line_highlighting(QTextEdit* editobject)
{
    QTextCursor cursor = editobject->textCursor();

    QList<QTextEdit::ExtraSelection> extraSelectionsList;
    QTextEdit::ExtraSelection selections;

    selections.format.setBackground(Qt::darkCyan);
    selections.format.setProperty(QTextFormat::FullWidthSelection, true);
    selections.cursor = cursor;
    selections.cursor.clearSelection();

    extraSelectionsList.append(selections);
    editobject->setExtraSelections(extraSelectionsList);
}

void MainWindow::__on_cursor_position_changed_callback()
{
    QTextEdit* editor = static_cast<QTextEdit*>(sender());
    QTextEdit* fileOverView = nullptr;

    TextEditorTab* temp = static_cast<TextEditorTab*>(
        ui->tabWidget->widget(ui->tabWidget->currentIndex())
    );
    if (temp)
        fileOverView = temp->getFileOverView();

    if (editor && fileOverView)
    {
        QTextCursor cursor = editor->textCursor();

        fileOverView->setTextCursor(cursor);

        __setUp_current_line_highlighting(editor);
        __setUp_current_line_highlighting(fileOverView);

        QString cursorPositionString = "Pos: (%1, %2)";
        currentCurrsorPositionLabel->setText(
            cursorPositionString.arg(cursor.columnNumber()).arg(
                cursor.blockNumber()
            )
        );
    }
}
