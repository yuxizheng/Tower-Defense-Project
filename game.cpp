#include "game.h"
#include "enemy.h"
#include "buildfiretowericon.h"
#include "buildwatertowericon.h"
#include "buildicetowericon.h"
#include "enemyteam.h"
#include "towerposition.h"
#include "enemyteamcontroller.h"
#include "upgradeicon.h"
#include "removeicon.h"
#include "mywindow.h"

extern MyWindow * mainw;

Game::Game(QWidget* parent)
{

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);
    setScene(scene);

    init();

}

void Game::init()
{
    level = 1;
    enemyWaveRecorder = 0;

    back = new QGraphicsPixmapItem();
    back->setPixmap(QPixmap(":/background/Resources/background.png"));
    scene->addItem(back);
    back->setPos(0,0);

    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);

    score = new Score();
    scene->addItem(score);
    score->setPos(0,0);

    health = new Health();
    scene->addItem(health);
    health->setPos(0,20);

    upgrade = false;
    remove = false;

    BuildFireTowerIcon * FireIcon = new BuildFireTowerIcon();
    scene->addItem(FireIcon);
    FireIcon->setPos(720,0);

    BuildWaterTowerIcon * WaterIcon = new BuildWaterTowerIcon();
    scene->addItem(WaterIcon);
    WaterIcon->setPos(720,64);

    BuildIceTowerIcon * IceIcon = new BuildIceTowerIcon();
    scene->addItem(IceIcon);
    IceIcon->setPos(720,128);

    UpgradeIcon * upgrade_icon = new UpgradeIcon();
    scene->addItem(upgrade_icon);
    upgrade_icon->setPos(720,192);

    RemoveIcon * remove_icon = new RemoveIcon();
    scene->addItem(remove_icon);
    remove_icon->setPos(756,192);

    towerPositionVerify = false;

    QList<QPointF> points;
    points<< QPointF(0,0) << QPointF(600,450) <<QPointF(400,400)<< QPointF(0,600);
    EnemyTeamController * controller = new EnemyTeamController(10000,3,1,3000,3,60,points,":/enemy/Resources/enemy3.jpg");
    EnemyTeamController * controller2 = new EnemyTeamController(15000,2,2,3000,2,100,points,":/enemy/Resources/enemy2.jpg");

    position << QPoint(30,100) << QPoint(190,50)<<QPoint(250,255)<<QPoint(380,180)<<QPoint(450,260)<<QPoint(600,380)<<QPoint(400,425)<<QPoint(40,520)<<QPoint(60,370);
    setTowerPosition();
}

void Game::init2()
{
    level=2;
    enemyWaveRecorder = 0;

    back = new QGraphicsPixmapItem();
    back->setPixmap(QPixmap(":/background/Resources/backtwo.png"));
    scene->addItem(back);
    back->setPos(0,0);

    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);

    score = new Score();
    scene->addItem(score);
    score->setPos(0,0);

    health = new Health();
    scene->addItem(health);
    health->setPos(0,20);

    upgrade = false;
    remove = false;

    BuildFireTowerIcon * FireIcon = new BuildFireTowerIcon();
    scene->addItem(FireIcon);
    FireIcon->setPos(720,0);

    BuildWaterTowerIcon * WaterIcon = new BuildWaterTowerIcon();
    scene->addItem(WaterIcon);
    WaterIcon->setPos(720,64);

    BuildIceTowerIcon * IceIcon = new BuildIceTowerIcon();
    scene->addItem(IceIcon);
    IceIcon->setPos(720,128);

    UpgradeIcon * upgrade_icon = new UpgradeIcon();
    scene->addItem(upgrade_icon);
    upgrade_icon->setPos(720,192);

    RemoveIcon * remove_icon = new RemoveIcon();
    scene->addItem(remove_icon);
    remove_icon->setPos(756,192);

    towerPositionVerify = false;

    QList<QPointF> points;
    points<< QPointF(0,0) << QPointF(600,450) <<QPointF(400,400)<< QPointF(0,600);
    EnemyTeamController * controller = new EnemyTeamController(10000,3,1,3000,3,60,points,":/enemy/Resources/enemy.jpg");
    EnemyTeamController * controller2 = new EnemyTeamController(15000,2,2,3000,2,100,points,":/enemy/Resources/enemy2.jpg");
    EnemyTeamController * controller3 = new EnemyTeamController(20000,2,2,1000,2,150,points,":/enemy/Resources/enemy4.jpg");

    position << QPoint(30,100) << QPoint(190,50)<<QPoint(250,255)<<QPoint(380,180)<<QPoint(450,260)<<QPoint(600,380)<<QPoint(400,425)<<QPoint(40,520)<<QPoint(60,370);
    setTowerPosition();
}




void Game::setCursor(QString filename,QPoint p)
{
    if(cursor){
        scene->removeItem(cursor);
        cursor = nullptr;
    }
    else{
        cursor = new QGraphicsPixmapItem();
        cursor->setPixmap(QPixmap(filename));
        cursor->setPos(p);
        scene->addItem(cursor);
    }
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor){
        cursor->setPos(event->pos());
    }
}



void Game::positionClicked(QPointF p, int i)
{
    if(build){
        scene->addItem(build);
        build->setPos(p);
        build->setLocation(i);
        scene->removeItem(cursor);
        cursor = nullptr;
        build = nullptr;
        towerPositionVerify = false;
    }


}

void Game::setTowerPosition()
{
    int n = position.size();
    for(int i=0; i<n ; i++){
        TowerPosition * pos = new TowerPosition(position[i],i);
        tower_position.append(pos);
        scene->addItem(pos);
        pos->setPos(position[i]);
    }
}

void Game::resetPositionStatus(int i)
{
    tower_position[i]->clearTowerPosition();
}


void Game::resetTowerStatus()
{
    remove = false;
    upgrade = false;
}

void Game::recordWave()
{
    enemyWaveRecorder++;
    if(enemyWaveRecorder==18&&level==1){
        displayLeveltwoWindow();
    }
    if(enemyWaveRecorder==24&level==2){
        displayGameOverWindow("YOU WIN!");
    }
}

void Game::home()
{
    mainw = new MyWindow();
    mainw->show();
    this->close();
}

void Game::leveltwo()
{
    scene->clear();
    init2();
}


void Game::drawPanel(int x, int y, int width, int height, QColor color, double opacity){
    // draws a panel at the specified location with the specified properties
    QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(color);
    panel->setBrush(brush);
    panel->setOpacity(opacity);
    scene->addItem(panel);
}

void Game::displayGameOverWindow(QString textToDisplay){
    // disable all scene items
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setEnabled(false);
    }

    // pop up semi transparent panel
    drawPanel(0,0,800,600,Qt::black,0.65);

    // draw panel
    drawPanel(100,100,400,400,Qt::white,0.75);

    // create playAgain button
    Button* playAgain = new Button(QString("Back to Home"));
    playAgain->setPos(220,260);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(home()));

    // create quit button
    Button* quit = new Button(QString("Quit"));
    quit->setPos(220,180);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    // create text annoucning winner
    QGraphicsTextItem * overText = new QGraphicsTextItem(textToDisplay);
    overText->setPos(220,120);
    scene->addItem(overText);

}

void Game::displayLeveltwoWindow()
{
    for (size_t i = 0, n = scene->items().size(); i < n; i++){
        scene->items()[i]->setEnabled(false);
    }

    // pop up semi transparent panel
    drawPanel(0,0,800,600,Qt::black,0.65);

    // draw panel
    drawPanel(100,100,400,400,Qt::white,0.75);

    // create playAgain button
    Button* playAgain = new Button(QString("Level2"));
    playAgain->setPos(220,260);
    scene->addItem(playAgain);
    connect(playAgain,SIGNAL(clicked()),this,SLOT(leveltwo()));

    // create quit button
    Button* quit = new Button(QString("Quit"));
    quit->setPos(220,180);
    scene->addItem(quit);
    connect(quit,SIGNAL(clicked()),this,SLOT(close()));

    // create text annoucning winner
    QGraphicsTextItem * overText = new QGraphicsTextItem("Now you can go to level2");
    overText->setPos(220,120);
    scene->addItem(overText);
}



