#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "button.h"
#include "level1.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setFixedSize(800,600);
    ui->setupUi(this);

    Button* btn = new Button(":/back1/image/icons8-play-100.png");
    Level1* scene1=new Level1;
    btn->setParent(this);
    btn->move(300,400);
    connect(btn,&Button::clicked,this,[=](){
        this->close();
        scene1->show();
    });
    connect(scene1,&Level1::chooseBack,this,[=]{
        scene1->hide();
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, this->width(),this->height(),QPixmap(":/back1/image/gameofthrones.jpg"));
}



