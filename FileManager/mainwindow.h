#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include "finderthread.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_find_clicked();
    void on_file_finded(const QString& file_name);

    void on_MainWindow_destroyed();

private:
    Ui::MainWindow* ui;
    QFileSystemModel* m_dirs;
    FinderThread m_finder_thread;
};
#endif // MAINWINDOW_H
