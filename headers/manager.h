
#pragma once

#include "../headers/interface.h"
#include "../headers/scene.h"

#include "../scenes/menu.h"
#include "../scenes/game.h"

class Manager
{
public:
	Scene* getGame(Interface* interface) { return new Game(interface, "gameScene"); }
	Scene* getMenu(Interface* interface) { return new Menu(interface, "mainMenu"); }
};