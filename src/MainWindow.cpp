#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit_money->setMaximumHeight(70);

    connect(ui->horizontalSlider, &QSlider::valueChanged, this, &MainWindow::onSliderChanged);
    connect(ui->lineEdit_money, &QLineEdit::textChanged, this, &MainWindow::onLineEditChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSliderChanged(int value)
{
   ui->label_tip->setText(QString("Tip (%1%)").arg(value));
   if (ui->lineEdit_money->text() != "$0.00")
   {
       ui->label_tip_value->setText(QString("$%1").arg((ui->lineEdit_money->text().toDouble()) * value/100.0));
       ui->label_total_value->setText(QString("$%1").arg((ui->lineEdit_money->text().toDouble()) + (ui->lineEdit_money->text().toDouble()) * value/100.0));
   }
}

void MainWindow::onLineEditChanged(QString text)
{
    ui->label_total_value->setText("$" +QString::number(text.toDouble()));
}

