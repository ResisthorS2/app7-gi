
#pragma once

#include <QApplication>
#include <QMainWindow>

class Scene;

class Interface : public QMainWindow
{
public:
    Interface(QWidget* parent = nullptr);
    void loadScene(Scene* scene);

    Scene* getGame();
    Scene* getMenu();
};
