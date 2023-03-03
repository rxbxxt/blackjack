#include <QApplication>
#include <QFile>

#include "MainWindow.h"

void loadStyles(QApplication &application) {
    QFile qss(":/styles/styles.qss");
    qss.open(QFile::ReadOnly);

    auto styles = QString(qss.readAll());

    application.setStyleSheet(styles);
    qss.close();
}

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    loadStyles(application);

    MainWindow window;
    window.show();

    return application.exec();
}
