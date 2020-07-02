#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    List starter();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    starter.Adding(ui->spinBox->value(),ui->spinBox->value(),ui->lineEdit->text(),ui->spinBox_3->value(), starter.TailPtr);
}

void MainWindow::on_pushButton_8_clicked()
{
    starter.Output(ui->spinBox->value());
}

void MainWindow::on_pushButton_9_clicked()
{
    starter.Input();
}

void MainWindow::on_pushButton_7_clicked()   //find
{
    if(starter.Find(ui->spinBox_4->value())==nullptr) {
    ui->label_17->setText("Элемент отсутствует");
    }
}


void MainWindow::on_pushButton_10_clicked()
{
    if(starter.FindPtr==nullptr) {
    ui->label_17->setText("Cначала найдите нужный элемент");
    } else {
    ui->label_6->setText(QString::number(starter.returnerDC(starter.FindPtr)));
    ui->label_7->setText(QString::number(starter.returnerDLN(starter.FindPtr)));
    ui->label_15->setText(starter.returnerNSP(starter.FindPtr));
    ui->label_16->setText(QString::number(starter.returnerTF(starter.FindPtr)));
    }
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_17->setText(starter.Deletion(ui->spinBox_4->value()));
}

void MainWindow::on_pushButton_3_clicked()  //cor DC
{
    starter.CorrcetDC(starter.FindPtr, ui->spinBox_5->value());
    ui->label_17->setText("Номер постановления измене");
}

void MainWindow::on_pushButton_4_clicked()
{
    starter.CorrcetDLN(starter.FindPtr, ui->spinBox_6->value());
    ui->label_17->setText("Номер водительских прав изменен");
}

void MainWindow::on_pushButton_5_clicked()
{
    starter.CorrcetNSP(starter.FindPtr, ui->lineEdit_2->text());
    ui->label_17->setText("ФИО изменены");
}

void MainWindow::on_pushButton_6_clicked()
{
    starter.CorrcetTF(starter.FindPtr, ui->spinBox_7->value());
    ui->label_17->setText("Сумма штрафа изменена");
}
