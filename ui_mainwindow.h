/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionAdd_New_Word;
    QAction *actionReset;
    QAction *actionHow_To_Use;
    QAction *actionAbout;
    QAction *actionChoose_Language;
    QAction *actionClear;
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *checkButton;
    QPushButton *caseButton;
    QPushButton *PunctButton;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QTextEdit *textEdit;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QPushButton *ignoreButton;
    QPushButton *replaceButton;
    QPushButton *AddToDicButton;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QListWidget *listWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuDictionary;
    QMenu *menuHelp;
    QMenu *menuLanguage;
    QMenu *menuSetings;
    QMenu *menuText;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(798, 575);
        MainWindow->setFocusPolicy(Qt::NoFocus);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionAdd_New_Word = new QAction(MainWindow);
        actionAdd_New_Word->setObjectName(QStringLiteral("actionAdd_New_Word"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QStringLiteral("actionReset"));
        actionHow_To_Use = new QAction(MainWindow);
        actionHow_To_Use->setObjectName(QStringLiteral("actionHow_To_Use"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionChoose_Language = new QAction(MainWindow);
        actionChoose_Language->setObjectName(QStringLiteral("actionChoose_Language"));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 421, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        checkButton = new QPushButton(layoutWidget);
        checkButton->setObjectName(QStringLiteral("checkButton"));

        horizontalLayout->addWidget(checkButton);

        caseButton = new QPushButton(layoutWidget);
        caseButton->setObjectName(QStringLiteral("caseButton"));

        horizontalLayout->addWidget(caseButton);

        PunctButton = new QPushButton(layoutWidget);
        PunctButton->setObjectName(QStringLiteral("PunctButton"));

        horizontalLayout->addWidget(PunctButton);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(30, 120, 741, 401));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        textEdit = new QTextEdit(layoutWidget1);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu"));
        font.setPointSize(14);
        textEdit->setFont(font);
        textEdit->setFrameShape(QFrame::Box);
        textEdit->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(textEdit, 1, 0, 1, 1);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(630, 30, 141, 95));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ignoreButton = new QPushButton(layoutWidget2);
        ignoreButton->setObjectName(QStringLiteral("ignoreButton"));

        verticalLayout->addWidget(ignoreButton);

        replaceButton = new QPushButton(layoutWidget2);
        replaceButton->setObjectName(QStringLiteral("replaceButton"));

        verticalLayout->addWidget(replaceButton);

        AddToDicButton = new QPushButton(layoutWidget2);
        AddToDicButton->setObjectName(QStringLiteral("AddToDicButton"));

        verticalLayout->addWidget(AddToDicButton);

        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(461, 11, 151, 111));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        listWidget = new QListWidget(layoutWidget3);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        listWidget->setFont(font1);
        listWidget->setFrameShape(QFrame::Box);

        verticalLayout_2->addWidget(listWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 798, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuDictionary = new QMenu(menubar);
        menuDictionary->setObjectName(QStringLiteral("menuDictionary"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuLanguage = new QMenu(menubar);
        menuLanguage->setObjectName(QStringLiteral("menuLanguage"));
        menuSetings = new QMenu(menubar);
        menuSetings->setObjectName(QStringLiteral("menuSetings"));
        menuText = new QMenu(menubar);
        menuText->setObjectName(QStringLiteral("menuText"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSetings->menuAction());
        menubar->addAction(menuDictionary->menuAction());
        menubar->addAction(menuLanguage->menuAction());
        menubar->addAction(menuText->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuDictionary->addAction(actionAdd_New_Word);
        menuDictionary->addAction(actionReset);
        menuHelp->addAction(actionHow_To_Use);
        menuHelp->addAction(actionAbout);
        menuLanguage->addAction(actionChoose_Language);
        menuText->addAction(actionClear);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "C-Spell", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionAdd_New_Word->setText(QApplication::translate("MainWindow", "Add New Word", 0));
        actionReset->setText(QApplication::translate("MainWindow", "Reset", 0));
        actionHow_To_Use->setText(QApplication::translate("MainWindow", "How To Use", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionChoose_Language->setText(QApplication::translate("MainWindow", "Choose Language", 0));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", 0));
        checkButton->setText(QApplication::translate("MainWindow", "Check Spelling", 0));
        caseButton->setText(QApplication::translate("MainWindow", "Fix Casing ", 0));
        PunctButton->setText(QApplication::translate("MainWindow", "Fix Punct. ", 0));
        label_2->setText(QApplication::translate("MainWindow", "Your Text Here :", 0));
        ignoreButton->setText(QApplication::translate("MainWindow", "Ignore", 0));
        replaceButton->setText(QApplication::translate("MainWindow", "Replace", 0));
        AddToDicButton->setText(QApplication::translate("MainWindow", "Add to Dictionary", 0));
        label->setText(QApplication::translate("MainWindow", "Suggestions :", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuDictionary->setTitle(QApplication::translate("MainWindow", "Dictionary", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
        menuLanguage->setTitle(QApplication::translate("MainWindow", "Language", 0));
        menuSetings->setTitle(QApplication::translate("MainWindow", "Settings", 0));
        menuText->setTitle(QApplication::translate("MainWindow", "Text", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
