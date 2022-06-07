#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_dirs(new QFileSystemModel(this)),
    m_finder_thread(this)
{
    ui->setupUi(this);
    m_dirs->setRootPath("");
    ui->treeView->setModel(m_dirs);

    connect(&m_finder_thread, &FinderThread::findedFile, this, &MainWindow::on_file_finded);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_button_find_clicked()
{
    if(m_finder_thread.isRunning())
        m_finder_thread.terminate();
    ui->list_widget_find->clear();
    m_finder_thread.search_string = ui->line_edit_find->text();
    m_finder_thread.start();
}

void MainWindow::on_file_finded(const QString& file_name)
{
    ui->list_widget_find->addItem(file_name);
}


void MainWindow::on_MainWindow_destroyed()
{
    if(m_finder_thread.isRunning())
        m_finder_thread.terminate();
}

