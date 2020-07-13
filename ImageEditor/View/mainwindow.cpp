#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

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

void MainWindow::on_actionSave_File_triggered()
{
    if (QMessageBox::question(this, tr("Question"), tr("Save File?")))
        GetCurrentView()->SaveFile();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As..."), "", "PNG(*.png);; JPG(*.jpg *.jpeg);; BMP(*.bmp)");
    if (fileName.isEmpty())
        return;

    GetCurrentView()->SaveFile(fileName);
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

void MainWindow::on_actionRotate_90_triggered()
{
    GetCurrentView()->Rotate(90);
}

void MainWindow::on_actionRotate_270_triggered()
{
    GetCurrentView()->Rotate(-90);
}

void MainWindow::on_actionRotate_180_triggered()
{
    GetCurrentView()->Rotate(180);
}

void MainWindow::on_actionZoomIn_triggered()
{
    GetCurrentView()->ZoomIn();
}

void MainWindow::on_actionZoomOut_triggered()
{
    GetCurrentView()->ZoomOut();
}

void MainWindow::on_actionResetZoom_triggered()
{
    GetCurrentView()->ResetZoom();
}
