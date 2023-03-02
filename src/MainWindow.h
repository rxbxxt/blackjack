#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <sstream>
#include "ui_MainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


#define MENU_WIDGET_NAME "menuWidget"
#define GAME_NAME        "Blackjack"

#define RESOLUTION_X     1200
#define RESOLUTION_Y     675

#define BACKGROUND_TEXTURE "images/menu_background.png"


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;

    void __setBackgroundImage();
};

#endif // MAINWINDOW_H
