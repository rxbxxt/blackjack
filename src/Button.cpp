#include "Button.h"

Button::Button(const char *name, QGraphicsItem *parent) : QGraphicsRectItem(parent) {
    setRect(0, 0, BUTTON_WIDTH, BUTTON_HEIGHT);
    initColor();
    initText(name);
}

void Button::initColor() {
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}

void Button::initText(const char *button_text) {
    _text = new QGraphicsTextItem(button_text, this);
    int x = rect().width() / 2 - _text->boundingRect().width() / 2;
    int y = rect().height() / 2 - _text->boundingRect().height() / 2;
    _text->setPos(x, y);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    emit clicked();
}
