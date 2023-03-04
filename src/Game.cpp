#include "Game.h"

Game::Game(QWidget *parent) : QGraphicsView(parent) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(RESOLUTION_X, RESOLUTION_Y);
    setWindowTitle(GAME_NAME);
    initMenu();
}

void Game::play() {
    _scene->clear();

    setStyleSheet("background-image: url(:/background/game);");
}

void Game::initMenu() {
    initButtons();
    initScene();
    setStyleSheet("background-image: url(:/background/menu);");
}

void Game::initScene() {
    _scene = new QGraphicsScene();
    setScene(_scene.get());

    _scene->addItem(_button_quit.get());
    _scene->addItem(_button_play.get());
    _scene->setSceneRect(0, 0, RESOLUTION_X, RESOLUTION_Y);
}

void Game::initButtons() {
    initButton(_button_play, "Play", BUTTON_PLAY_POSITION);
    initButton(_button_quit, "Quit", BUTTON_QUIT_POSITION);
    connect(_button_play.get(), SIGNAL(clicked()), this, SLOT(play()));
    connect(_button_quit.get(), SIGNAL(clicked()), this, SLOT(close()));
}

void Game::initButton(QPointer<Button> &button,
                      const char *button_text,
                      const int button_height) {
    button = new Button(button_text);
    int button_width = this->width() / 2.0f - button->boundingRect().width() / 2.0f;
    button->setPos(button_width, button_height);
}
