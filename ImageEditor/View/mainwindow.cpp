#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

View *MainWindow::GetCurrentView() const
{
    return ui->view;
}

void MainWindow::on_actionOpen_File_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "Images(*.png *.jpg *.jpeg *.bmp)");
    if (fileName.isEmpty())
        return;

    GetCurrentView()->OpenFile(fileName);
}

void MainWindow::on_actionGray_triggered()
{
    GetCurrentView()->Gray();
}

void MainWindow::on_actionBlur_triggered()
{
    GetCurrentView()->Blur();
}

void MainWindow::on_actionSharp_triggered()
{
    GetCurrentView()->Sharp();
}
