
#include "../headers/scene.h"

Scene::Scene(Interface* iface, std::string sceneName)
{
	name = sceneName;
	interface = iface;
}

std::string Scene::getSceneName() { return name; }
