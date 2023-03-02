#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    setObjectName(MENU_WIDGET_NAME);
    setWindowTitle(GAME_NAME);
    setFixedSize(RESOLUTION_X, RESOLUTION_Y);
    __setBackgroundImage();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::__setBackgroundImage() {
    QString styles;
    QTextStream out(&styles);

    out << "#" << MENU_WIDGET_NAME 
        << " { background-image: url(:/" << BACKGROUND_TEXTURE << "); }";

    setStyleSheet(styles);
}
