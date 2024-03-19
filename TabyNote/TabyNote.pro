QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/EditorWidget/FileOverViewWidget.cpp \
    src/EditorWidget/MainEditorArea.cpp \
    src/EditorWidget/NumBarWidget.cpp \
    src/dialog_about.cpp \
    src/main.cpp \
    src/mainwindow.cpp

HEADERS += \
    src/EditorWidget/EditorWorkSpace.h \
    src/EditorWidget/FileOverViewWidget.h \
    src/EditorWidget/MainEditorArea.h \
    src/EditorWidget/NumBarWidget.h \
    src/dialog_about.h \
    src/mainwindow.h

FORMS += \
    src/dialog_about.ui \
    src/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
