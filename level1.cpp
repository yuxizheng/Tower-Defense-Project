#include "level1.h"
#include "button.h"

Level1::Level1(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(800,600);

    Button* home = new Button(":/back1/image/icons8-home-50.png");
    home->setParent(this);
    home->move(40,40);
    connect(home,&Button::clicked,this,[=]{
        emit chooseBack();
    });
}
