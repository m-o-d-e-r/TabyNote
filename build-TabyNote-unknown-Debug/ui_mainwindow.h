/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionAbout;
    QAction *actionAuthor;
    QAction *actionSave_as;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionNew_tab;
    QAction *actionClose_tab;
    QAction *actionDark;
    QAction *actionFilemap;
    QAction *actionRender_numbar;
    QAction *actionOpen_Terminal;
    QAction *actionFont;
    QAction *actionFont_Size;
    QAction *actionOwn_editor_prametrs;
    QAction *actionIncrease_font_size;
    QAction *actionDecrease_font_size;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuInstruments;
    QMenu *menuView;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(716, 485);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(716, 485));
        QPalette palette;
        QBrush brush(QColor(197, 222, 229, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(197, 222, 229, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(190, 190, 190, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        MainWindow->setPalette(palette);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/quit_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/how_to_use_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon1);
        actionAuthor = new QAction(MainWindow);
        actionAuthor->setObjectName(QString::fromUtf8("actionAuthor"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/author_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAuthor->setIcon(icon2);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/save_as_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_as->setIcon(icon3);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/open_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon4);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/save_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon5);
        actionNew_tab = new QAction(MainWindow);
        actionNew_tab->setObjectName(QString::fromUtf8("actionNew_tab"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/add_new_tab_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_tab->setIcon(icon6);
        actionClose_tab = new QAction(MainWindow);
        actionClose_tab->setObjectName(QString::fromUtf8("actionClose_tab"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/close_tab_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose_tab->setIcon(icon7);
        actionDark = new QAction(MainWindow);
        actionDark->setObjectName(QString::fromUtf8("actionDark"));
        actionDark->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/turn_dark_icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDark->setIcon(icon8);
        actionFilemap = new QAction(MainWindow);
        actionFilemap->setObjectName(QString::fromUtf8("actionFilemap"));
        actionFilemap->setCheckable(true);
        actionRender_numbar = new QAction(MainWindow);
        actionRender_numbar->setObjectName(QString::fromUtf8("actionRender_numbar"));
        actionRender_numbar->setCheckable(true);
        actionOpen_Terminal = new QAction(MainWindow);
        actionOpen_Terminal->setObjectName(QString::fromUtf8("actionOpen_Terminal"));
        actionFont = new QAction(MainWindow);
        actionFont->setObjectName(QString::fromUtf8("actionFont"));
        actionFont_Size = new QAction(MainWindow);
        actionFont_Size->setObjectName(QString::fromUtf8("actionFont_Size"));
        actionOwn_editor_prametrs = new QAction(MainWindow);
        actionOwn_editor_prametrs->setObjectName(QString::fromUtf8("actionOwn_editor_prametrs"));
        actionIncrease_font_size = new QAction(MainWindow);
        actionIncrease_font_size->setObjectName(QString::fromUtf8("actionIncrease_font_size"));
        actionDecrease_font_size = new QAction(MainWindow);
        actionDecrease_font_size->setObjectName(QString::fromUtf8("actionDecrease_font_size"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        QPalette palette1;
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        tabWidget->setPalette(palette1);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        tabWidget->setTabBarAutoHide(false);

        horizontalLayout->addWidget(tabWidget);

        horizontalLayout->setStretch(0, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 716, 20));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        menubar->setPalette(palette2);
        menubar->setAutoFillBackground(true);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        menuInstruments = new QMenu(menubar);
        menuInstruments->setObjectName(QString::fromUtf8("menuInstruments"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setEnabled(true);
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush4);
        QBrush brush5(QColor(255, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush5);
        QBrush brush6(QColor(28, 164, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush6);
        statusbar->setPalette(palette3);
        statusbar->setAutoFillBackground(true);
        statusbar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        toolBar->setPalette(palette4);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuInstruments->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuHelp->addAction(actionAbout);
        menuInstruments->addAction(actionNew_tab);
        menuInstruments->addAction(actionClose_tab);
        menuInstruments->addSeparator();
        menuInstruments->addAction(actionOpen_Terminal);
        menuInstruments->addSeparator();
        menuInstruments->addAction(actionIncrease_font_size);
        menuInstruments->addAction(actionDecrease_font_size);
        menuView->addSeparator();
        menuView->addAction(actionOwn_editor_prametrs);
        menuView->addSeparator();
        menuView->addAction(actionFilemap);
        menuView->addAction(actionRender_numbar);
        menuView->addSeparator();
        menuView->addAction(actionDark);
        toolBar->addAction(actionOpen);
        toolBar->addSeparator();
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSave_as);
        toolBar->addSeparator();
        toolBar->addAction(actionNew_tab);
        toolBar->addAction(actionClose_tab);
        toolBar->addSeparator();
        toolBar->addAction(actionDark);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Taby note", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
#if QT_CONFIG(shortcut)
        actionAbout->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+H", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAuthor->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew_tab->setText(QCoreApplication::translate("MainWindow", "New Tab", nullptr));
#if QT_CONFIG(tooltip)
        actionNew_tab->setToolTip(QCoreApplication::translate("MainWindow", "New Tab", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionNew_tab->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose_tab->setText(QCoreApplication::translate("MainWindow", "Close Tab", nullptr));
#if QT_CONFIG(tooltip)
        actionClose_tab->setToolTip(QCoreApplication::translate("MainWindow", "Close Tab", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionClose_tab->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDark->setText(QCoreApplication::translate("MainWindow", "Dark", nullptr));
#if QT_CONFIG(shortcut)
        actionDark->setShortcut(QCoreApplication::translate("MainWindow", "Alt+Shift+D", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFilemap->setText(QCoreApplication::translate("MainWindow", "Filemap (NEED FIX)", nullptr));
        actionRender_numbar->setText(QCoreApplication::translate("MainWindow", "Render Numbar (TODO)", nullptr));
        actionOpen_Terminal->setText(QCoreApplication::translate("MainWindow", "Open Terminal (TODO)", nullptr));
        actionFont->setText(QCoreApplication::translate("MainWindow", "Font Family", nullptr));
        actionFont_Size->setText(QCoreApplication::translate("MainWindow", "Font Size", nullptr));
        actionOwn_editor_prametrs->setText(QCoreApplication::translate("MainWindow", "TabyNote global font", nullptr));
        actionIncrease_font_size->setText(QCoreApplication::translate("MainWindow", "Increase font size", nullptr));
#if QT_CONFIG(shortcut)
        actionIncrease_font_size->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+2", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDecrease_font_size->setText(QCoreApplication::translate("MainWindow", "Decrease font size", nullptr));
#if QT_CONFIG(shortcut)
        actionDecrease_font_size->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+1", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuInstruments->setTitle(QCoreApplication::translate("MainWindow", "Instruments", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
