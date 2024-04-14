
#pragma once

#include "../headers/scene.h"

#include <QMenu>
#include <QLabel>
#include <QObject>
#include <QMenuBar>
#include <QStatusBar>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QSoundEffect>
#include <QApplication>

class Menu : public Scene
{
public:
    Menu(Interface* iface, std::string sceneName) : Scene(iface, sceneName)
	{ 
        layout = new QVBoxLayout();

        QMenuBar* menuBar = new QMenuBar();

        interface->setMenuBar(menuBar);

        QMenu* gameMenu = menuBar->addMenu(tr("Game"));

        QAction* aboutAction = gameMenu->addAction(tr("About"));
        QMenu* settingsMenu = gameMenu->addMenu(tr("Settings"));
        QAction* quitAction = gameMenu->addAction(tr("Quit"));

        for (int i = 1; i <= 5; ++i) {
            QString settingName = QString("Setting #%1").arg(i);
            QAction* settingAction = settingsMenu->addAction(settingName);
        }

        QList<QPushButton*> buttonList;

        QPushButton* playButton = new QPushButton("PLAY");
        QPushButton* settingsButton = new QPushButton("SETTINGS");
        QPushButton* quitButton = new QPushButton("QUIT");

        buttonList.append(playButton);
        buttonList.append(settingsButton);
        buttonList.append(quitButton);

        for (QPushButton* button : buttonList)
        {
            button->setFixedSize(160, 40);
            button->setStyleSheet(
                "QPushButton"
                "{"
                "   background-color: #AAA;"
                "   border-radius: 10px;"
                "   font-size: 16px;"
                "   font-weight: bold;"
                "}"
                "QPushButton:hover { background-color: #CCC; }"
                "QPushButton:pressed { background-color: #666; }"
            );
        }

        layout->addWidget(playButton);
        layout->addWidget(settingsButton);
        layout->addWidget(quitButton);

        layout->setAlignment(Qt::AlignHCenter);

        connect(playButton, &QPushButton::clicked, this, &Menu::playClicked);

        connect(aboutAction, &QAction::triggered, this, &Menu::about);
        connect(quitAction, &QAction::triggered, this, &Menu::quit);

    };

    ~Menu() {
        qDeleteAll(layout->children());
        delete layout;
    }

    QLayout* getSceneLayout() { return layout; }

public slots:
    void playClicked() { interface->loadScene(interface->getGame()); }

    void about() { QMessageBox::about(interface, tr("About"), tr("This is a simple game.")); }
    void quit() { qApp->quit(); }

private:
	QVBoxLayout* layout;

    QMediaPlayer* player;
    QMediaPlayer* alt;
    QAudioOutput* audioOut;
};


