
#include "../headers/interface.h"
#include "../headers/scene.h"

#include "../scenes/menu.h"
#include "../scenes/game.h"

#include <QPalette>

Interface::Interface(QWidget* parent) : QMainWindow(parent)
{
    setWindowTitle("Sample Window");
    setWindowFlag(Qt::MSWindowsFixedSizeDialogHint);
    
    QPalette pal = palette();
    pal.setColor(QPalette::Window, Qt::white);
    setAutoFillBackground(true);
    setPalette(pal);
    
    QIcon icon("data/icon.ico");
    setWindowIcon(icon);

    resize(720, 480);
}

void Interface::loadScene(Scene* scene)
{   
    printf("Loading scene '%s'\n", scene->getSceneName().c_str());

    QWidget* central = centralWidget();

    if (!central)
    { 
        central = new QWidget(this);
        setCentralWidget(central);   
    }

    else { qDeleteAll(central->children()); }

    central->setLayout(scene->getSceneLayout());
}

Scene* Interface::getGame() { return new Game(this, "gameScene"); }
Scene* Interface::getMenu() { return new Menu(this, "mainMenu"); }