#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QPointer>
#include <QPainter>
#include <QPixmap>
#include <QFont>
#include <memory>
#include <vector>
#include <sstream>

#include "Dealer.h"
#include "Player.h"
#include "Button.h"
#include "Chip.h"

#define FIRST_CHIP_X   350
#define CHIPS_HEIGHT   200
#define DEAL_TEXT_X    475
#define DEAL_TEXT_Y    100
#define BETTED_TEXT_X  50
#define BETTED_TEXT_Y  600
#define BALANCE_TEXT_X 700
#define BALANCE_TEXT_Y 600
#define FONT_SIZE      32

class GameSceneManager : public QObject {
    Q_OBJECT

public:
    GameSceneManager(QGraphicsScene *scene, int resolution_x, int resolution_y);
    ~GameSceneManager();

    void start();
    void clearDealScene();

private:
    QGraphicsScene          *_scene;
    std::vector <Chip*>      _chips;
    std::unique_ptr <Dealer> _dealer;
    std::unique_ptr <Player> _player;
    QPointer <Button>        _button_deal;
    int                      _resolution_x;
    int                      _resolution_y;
    int                      _bet_sum;

    std::unique_ptr <QFont>         _font;
    QGraphicsTextItem    *_deal_text;
    QGraphicsTextItem    *_balance_text;


    void addPlayerBalance();
    void addDealSceneItems();
    void initDealSceneButtons();
    void initDealSceneChips();

    void initButton(QPointer<Button> &button,
                    const char *button_text,
                    const int button_height);

    void setMessage(QGraphicsTextItem **textitem, 
                    const char *textmessage,
                    int x, int y);

private slots:
    void deal();
    void bet(int sum);
};

#endif // GAMEMANAGER_H