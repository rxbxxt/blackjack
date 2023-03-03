#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>

#include <memory>


#define GAME_NAME        "Blackjack"
#define RESOLUTION_X     1200
#define RESOLUTION_Y     675


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    std::unique_ptr<QWidget>     _central_widget;
    std::unique_ptr<QHBoxLayout> _layout_buttons;
    std::unique_ptr<QPushButton> _button_play;
    std::unique_ptr<QPushButton> _button_quit;


    void initLayout();
    void initCentralWidget();
    void initButtons();
    void initButton(std::unique_ptr<QPushButton> &button,
                    const char *object_name,
                    const char *button_text);
};

#endif // MAINWINDOW_H
