#pragma once
#include "SFML/Graphics.hpp"
#include "GL/glew.h"

#include "Reader/ReplayReader.h"
#include "Objects/Drawable/DrawableShape.h"

#include <queue>
#include <random>
#include <stdlib.h>

class VisualManager
{
public:
    VisualManager();
    ~VisualManager();

    void Initialize();
    bool Update();

    void RenderFrame();

    std::deque<DrawableShape> sprites;
    sf::RenderWindow *window;
    ReplayReader *reader;

    sf::Texture dummyCircle;
};

