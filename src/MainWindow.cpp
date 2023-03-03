#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle(GAME_NAME);
    setFixedSize(RESOLUTION_X, RESOLUTION_Y);
    initButtons();
    initLayout();
    initCentralWidget();
}

void MainWindow::initLayout() {
    _layout_buttons = std::make_unique<QHBoxLayout>();
    _layout_buttons->addWidget(_button_play.get());
    _layout_buttons->addWidget(_button_quit.get());
}

void MainWindow::initCentralWidget() {
    _central_widget = std::make_unique<QWidget>();
    _central_widget->setLayout(_layout_buttons.get());
    setCentralWidget(_central_widget.get());
}

void MainWindow::initButtons() {
    initButton(_button_play, "button_play", "Play");
    initButton(_button_quit, "button_quit", "Quit");
}

void MainWindow::initButton(std::unique_ptr<QPushButton> &button,
                            const char *object_name,
                            const char *button_text) {
    button = std::make_unique<QPushButton>();
    button->setObjectName(object_name);
    button->setText(button_text);
}
