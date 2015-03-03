#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
QFile file;
QFile mainCSV;
QTextStream fileStream(&file);
QTextStream CSVStream(&mainCSV);
QString root = "C:/Users/Arham/Documents/fakeRoot/";
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mainCSV.setFileName(root+"master.csv");
    mainCSV.open(QIODevice::Append | QIODevice::Text);
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   int some = 2;
   for(int i = 1;i<some; i++ ){
    if(file.exists(root+ QString::fromStdString(std::to_string((int)(i+1))) + ".csv")){
    some++;
    ui->textBrowser->append("File "+root+ QString::fromStdString(std::to_string((int)(i+1))) + ".csv"+"exists.");
    }
    else ui->textBrowser->append("File "+root+ QString::fromStdString(std::to_string((int)(i+1))) + ".csv"+"does not exist.");
    ui->textBrowser->append("Opening file "+root+QString::fromStdString(std::to_string((int)(i)))+".csv");
    file.setFileName(root+QString::fromStdString(std::to_string((int)(i)))+".csv");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    CSVStream << fileStream.readAll();
    file.flush();
    file.close();
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    fileStream<<"";
    file.flush();
    file.close();

   }
  mainCSV.close();
}
