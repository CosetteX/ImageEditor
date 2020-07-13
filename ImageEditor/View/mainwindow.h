#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class View;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    View *GetCurrentView() const;

private slots:
    void on_actionOpen_File_triggered();

    void on_actionSave_File_triggered();

    void on_actionSave_As_triggered();

    void on_actionGray_triggered();

    void on_actionBlur_triggered();

    void on_actionSharp_triggered();

    void on_actionRotate_90_triggered();

    void on_actionRotate_270_triggered();

    void on_actionRotate_180_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
