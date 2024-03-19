#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMessageBox>
#include <QLabel>
#include <QTextStream>
#include <QString>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>

//#include "MainEditorArea.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Ui::MainWindow *ui;
    QLabel* currentCurrsorPositionLabel = new QLabel("Pos: (None, None)");
    QLabel* currentFileNameLabel = new QLabel("File name: None");

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();    // on open file
    void on_actionSave_as_triggered(); // on "save as" opration
    void on_actionSave_triggered();    // on "save" operation

    void on_actionNew_tab_triggered();              // create new tab
    void on_actionClose_tab_triggered();            // close opened tab
    void on_tabWidget_tabCloseRequested(int index); // close current tab by clicking criss
    void on_tabWidget_currentChanged(int index);    // change titles while changing current tab

    void on_actionQuit_triggered();

    void on_actionAbout_triggered();

    void on_actionDark_triggered();

    void on_actionFilemap_triggered(bool checked);

    void on_actionIncrease_font_size_triggered();

    void on_actionDecrease_font_size_triggered();

    void on_actionWord_Wrap_triggered(bool checked);

    void on_actionRender_numbar_triggered(bool checked);

signals:


private:
    void __on_all_tabs_removed();
    void __on_change_text_editor_callback();
    template<typename _TE_Object>
    void __setUp_current_line_highlighting(_TE_Object*);
    void __on_cursor_position_changed_callback();
    void __load_theme(const char *);

};
#endif // MAINWINDOW_H
