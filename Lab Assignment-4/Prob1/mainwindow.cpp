#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trie.h"

#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ReadCSV("/home/prateek/Documents/Dictionary/L4_P1_input.csv");
    ui->setupUi(this);
    ui->output->setReadOnly(true);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(OnSearch()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::OnSearch(){
    QString input = ui->input->text();
    std::string val = trie.search(input.toUtf8().constData());
    if(val == ""){
        val= "Invalid word";
    }
    ui->output->setText(QString::fromUtf8(val.c_str()));
}
void MainWindow::ReadCSV(QString filePath){
    QFile qfile(filePath);
    if (!qfile.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    while (!qfile.atEnd()) {
            QByteArray line = qfile.readLine();
            std::string l =line.toStdString();
            int firstDLocation = l.find(',');
            trie.insert(l.substr(0,firstDLocation),l.substr(firstDLocation+1,l.size()));
    }
}
