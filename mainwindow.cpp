#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),
                                                    QString(),tr("Text Files (*.txt"));

    if(!fileName.isEmpty()) {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadWrite)) {
            QMessageBox::critical(this,tr("Error"),tr("Error Opening File!"));
            return;
        }

        QTextStream in(&file);
        ui->textEdit->setText(in.readAll());
        file.close();
    }
}
