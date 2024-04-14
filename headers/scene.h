
#pragma once

#include <string>

#include "../headers/interface.h"


class Scene : public QObject
{
public:
    Scene(Interface* iface, std::string sceneName);
    std::string getSceneName();
    virtual QLayout* getSceneLayout() = 0;

protected:
    Interface* interface;
    std::string name;
};
