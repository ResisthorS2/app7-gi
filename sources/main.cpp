
#include <QApplication>
#include <QStackedWidget>

#include "../headers/interface.h"
#include "../headers/scene.h"

#include "../scenes/menu.h"
#include "../scenes/game.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    Interface win;

    win.loadScene(win.getMenu());

    win.show();

    return app.exec();
}
