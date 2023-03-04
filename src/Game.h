#ifndef GAME_H 
#define GAME_H

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointer>

#include "Button.h"


#define GAME_NAME        "Blackjack"
#define RESOLUTION_X     1200
#define RESOLUTION_Y     675

#define BUTTON_PLAY_POSITION 475 
#define BUTTON_QUIT_POSITION 550 


class Game: public QGraphicsView {
    Q_OBJECT

public slots:
    void play();

public:
    Game(QWidget *parent = nullptr);

private:
    QPointer <QGraphicsScene> _scene;

    QPointer <Button> _button_play;
    QPointer <Button> _button_quit;

    void initMenu();
    void initScene();
    void initButtons();
    void initButton(QPointer<Button> &button,
                    const char *button_text,
                    const int button_height);
};

#endif // GAME_H 
