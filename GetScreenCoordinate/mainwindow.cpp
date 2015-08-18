#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowState(Qt::WindowFullScreen);
    setMenuBar(NULL);
    setMouseTracking(true);
    setWindowOpacity(0.5);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    const int x = event->globalX(), y = event->globalY();
    ui->label->setGeometry(x, y, ui->label->width(), ui->label->height());
    QString text = "(" + QString::number(x) + "," + QString::number(y) + ")";
    ui->label->setText(text);
}
