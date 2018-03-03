#include "VisualManager.h"



VisualManager::VisualManager()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;
    window = new sf::RenderWindow(sf::VideoMode(640, 480), "Replay", sf::Style::Default, settings);
    window->setFramerateLimit(60);
    reader = new ReplayReader();
    dummyCircle.loadFromFile("hitcircle.png");
}


VisualManager::~VisualManager()
{
}

void VisualManager::Initialize()
{
    reader->SetMap((char *)"test.osu");
}

bool VisualManager::Update()
{
    if (window->isOpen())
    {
        sf::Event e;
        while (window->pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window->close();
                return false;
            }
        }
        std::deque<DrawableHitObject> _toDraw;
        _toDraw = *reader->GetUpcomingObjects();
        if (_toDraw.size() > 0) {
            double scale = (1.0f - 0.7f * (reader->beatmap.CircleSize - 5) / 5) / 2;

            for (DrawableHitObject drawable : _toDraw)
            {
                DrawableShape s;
                s.setTexture(&dummyCircle);
                s.setRadius(64.0f);
                s.setPointCount(30);
                s.setScale(scale, scale);
                s.setPosition(drawable.Position());
                float _o = drawable.Opacity();
                s.setFillColor(sf::Color(155, 155, 155, (_o * 255)));
                //s.setOutlineColor(sf::Color(170, 20, 20));
                //s.setOutlineThickness(3.0f);
                sprites.push_back(s);
                _toDraw.pop_front();
            }
        }
        RenderFrame();
    }
    return true;
}

void VisualManager::RenderFrame()
{
    window->clear(sf::Color::Black);
    //printf("%d\n", time(0));
    for (DrawableShape shape : sprites) {
        window->draw(shape);
        sprites.pop_front();
    }
    window->display();
}

