/********************************************************************************
** Form generated from reading UI file 'dialog_about.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ABOUT_H
#define UI_DIALOG_ABOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialog_about
{
public:
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *verticalWidget_1;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QWidget *tab_2;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *dialog_about)
    {
        if (dialog_about->objectName().isEmpty())
            dialog_about->setObjectName(QString::fromUtf8("dialog_about"));
        dialog_about->resize(489, 415);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dialog_about->sizePolicy().hasHeightForWidth());
        dialog_about->setSizePolicy(sizePolicy);
        dialog_about->setMinimumSize(QSize(489, 415));
        dialog_about->setMaximumSize(QSize(492, 415));
        QFont font;
        font.setFamily(QString::fromUtf8("Fira Code Retina"));
        font.setBold(false);
        font.setWeight(50);
        dialog_about->setFont(font);
        verticalLayout = new QVBoxLayout(dialog_about);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidget = new QTabWidget(dialog_about);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(0, 0, 0, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(57, 57, 57, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush1);
#endif
        tabWidget->setPalette(palette);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalWidget_1 = new QWidget(tab);
        verticalWidget_1->setObjectName(QString::fromUtf8("verticalWidget_1"));
        verticalWidget_1->setGeometry(QRect(9, 9, 451, 321));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalWidget_1->sizePolicy().hasHeightForWidth());
        verticalWidget_1->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(verticalWidget_1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, -1, -1);
        label_2 = new QLabel(verticalWidget_1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFrameShape(QFrame::StyledPanel);
        label_2->setTextFormat(Qt::AutoText);

        verticalLayout_3->addWidget(label_2);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalWidget_2 = new QWidget(tab_2);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        verticalWidget_2->setGeometry(QRect(10, 10, 451, 321));
        verticalLayout_4 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, -1, -1, -1);
        label = new QLabel(verticalWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::StyledPanel);
        label->setTextFormat(Qt::AutoText);
        label->setScaledContents(false);
        label->setOpenExternalLinks(true);

        verticalLayout_4->addWidget(label);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_2->addWidget(tabWidget);


        verticalLayout->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(dialog_about);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(dialog_about);
        QObject::connect(buttonBox, SIGNAL(accepted()), dialog_about, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), dialog_about, SLOT(reject()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(dialog_about);
    } // setupUi

    void retranslateUi(QDialog *dialog_about)
    {
        dialog_about->setWindowTitle(QCoreApplication::translate("dialog_about", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("dialog_about", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">\360\237\244\234\360\237\244\233</span><br/></p><p><span style=\" font-family:'Sans Serif';\">Ctrl + O - open file in new tab</span></p><p><span style=\" font-family:'Sans Serif';\">Ctrl + S - save current changes</span></p><p><span style=\" font-family:'Sans Serif';\">Ctrl + Shift + O - save *unsaved tab as ...</span></p><p><span style=\" font-family:'Sans Serif';\">Ctrl + Q - close the program</span></p><p><span style=\" font-family:'Sans Serif';\">----------------------------</span></p><p><span style=\" font-family:'Sans Serif';\">Ctrl + N - create new tab</span></p><p><span style=\" font-family:'Sans Serif';\">Ctrl + R - remove current tab</span></p><p><span style=\" font-family:'Sans Serif';\">----------------------------</span></p><p><span style=\" font-family:'Sans Serif';\">Ctrl + H - call &quot;about&quot; dialog</span></p><p><br/></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("dialog_about", "Shortcuts", nullptr));
        label->setText(QCoreApplication::translate("dialog_about", "<html><head/><body><p align=\"center\"><br/></p><p align=\"center\">My first Qt Project.</p><p align=\"center\">Made just for fun and learning Qt.</p><p align=\"center\"><br/></p><p align=\"center\">Telegram: @M_O_D_E_R</p><p align=\"center\">Icons from: https://icons8.com/</p><p align=\"center\"><br/><br/></p><p align=\"center\"><span style=\" font-size:14pt;\">\360\237\245\271\360\237\253\266\360\237\245\271</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("dialog_about", "Author", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dialog_about: public Ui_dialog_about {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ABOUT_H
