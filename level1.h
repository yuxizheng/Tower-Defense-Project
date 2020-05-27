#ifndef LEVEL1_H
#define LEVEL1_H

#include <QMainWindow>

class Level1 : public QMainWindow
{
    Q_OBJECT
public:
    explicit Level1(QWidget *parent = nullptr);

signals:
    void chooseBack();
};

#endif // LEVEL1_H
