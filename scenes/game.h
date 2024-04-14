
#pragma once

#include "../headers/scene.h"

#include <QDir>
#include <QLabel>
#include <QObject>
#include <QPixmap>
#include <QVBoxLayout>
#include <QPushButton>
#include <QRandomGenerator>

class Game : public Scene
{
public:
    Game(Interface* iface, std::string sceneName) : Scene(iface, sceneName)
    {
        //
        layout = new QVBoxLayout();

        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);

        QWidget* main = new QWidget();

        main->setContentsMargins(20, 20, 20, 20);
        main->setFixedSize(720, 380);

        layout->addWidget(main);
        //

        QWidget* btnGrid = new QWidget();

        QHBoxLayout* gameLayout = new QHBoxLayout();
        QGridLayout* btnLayout = new QGridLayout();

        viewImage = new QLabel();
        viewImage->setFixedSize(440, 320);
        viewImage->setPixmap(QPixmap("data/image-1.jpg"));
        viewImage->setScaledContents(true);

        btnGrid->setFixedSize(120, 120);
        btnGrid->setContentsMargins(0, 0, 0, 0);
        btnGrid->setLayout(btnLayout);

        QPushButton* upButton = new QPushButton("⇧");
        QPushButton* downButton = new QPushButton("⇩");
        QPushButton* leftButton = new QPushButton("⇦");
        QPushButton* rightButton = new QPushButton("⇨");
        QPushButton* selectButton = new QPushButton("▫");

        QList<QPushButton*> buttonList;

        buttonList.append(upButton);
        buttonList.append(downButton);
        buttonList.append(leftButton);
        buttonList.append(rightButton);
        buttonList.append(selectButton);

        for (QPushButton* button : buttonList)
        {
            button->setFixedSize(40, 40);
            button->setFont(QFont("Arial", 24, QFont::Bold));
            button->setStyleSheet(
                "QPushButton"
                "{"
                "   background-color: rgba(0, 0, 0, 0);"
                "   font-size: 30px;"
                "}"
                "QPushButton:hover { font-size: 34px; }"
                "QPushButton:pressed { font-size: 26px; }"
            );
        }

        btnLayout->addWidget(upButton, 0, 1);
        btnLayout->addWidget(downButton, 2, 1);
        btnLayout->addWidget(leftButton, 1, 0);
        btnLayout->addWidget(rightButton, 1, 2);
        btnLayout->addWidget(selectButton, 1, 1);

        gameLayout->addWidget(viewImage);
        gameLayout->addWidget(btnGrid);

        main->setLayout(gameLayout);

        //
        squareLabel = new QLabel();
        squareLabel->setFixedSize(80, 80);
        squareLabel->setPixmap(QPixmap("data/square.jpg"));

        rectangleLabel = new QLabel();
        rectangleLabel->setFixedSize(640, 80);
        rectangleLabel->setAlignment(Qt::AlignCenter);
        rectangleLabel->setStyleSheet("border-image: url('data/rectangle.jpg')");

        QWidget* statusBar = new QWidget();
        statusBar->setContentsMargins(0, 0, 0, 0);

        QHBoxLayout* statusBarLayout = new QHBoxLayout();
        statusBarLayout->setSpacing(0);
        statusBarLayout->setContentsMargins(0, 0, 0, 0);
        statusBarLayout->addWidget(squareLabel);
        statusBarLayout->addWidget(rectangleLabel);

        statusBar->setLayout(statusBarLayout);

        interface->statusBar()->addWidget(statusBar);
        interface->statusBar()->setSizeGripEnabled(false);
        //

        connect(selectButton, &QPushButton::clicked, this, &Game::switchImage);

        imgCounter = 1;
    };

    ~Game() {
        qDeleteAll(layout->children());
        delete rectangleLabel;
        delete layout;
    }

    QLayout* getSceneLayout() { return layout; }

public slots:
    void switchImage()
    {
        if (imgCounter < 6) { imgCounter++; }
        else { imgCounter = 1; }

        viewImage->setPixmap(QString("data/image-%1.jpg").arg(imgCounter));
    }

private:
    QVBoxLayout* layout;
    QLabel* rectangleLabel;
    QLabel* squareLabel;
    QLabel* viewImage;

    int imgCounter;
};