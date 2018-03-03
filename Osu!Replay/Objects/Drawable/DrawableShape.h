#pragma once
#include <SFML/Graphics/Shape.hpp>

enum SHAPE_TYPES {
    SHAPE_CIRCLE,
    SHAPE_CONVEX
};

class DrawableShape : public sf::Shape {
public:
    DrawableShape(int type = SHAPE_CIRCLE) :
        m_type  (type)
    {
        if (type == SHAPE_CIRCLE)
        {
            setPointCount();
            setRadius();
        }
    };
    ~DrawableShape() {};

    std::size_t getPointCount() const { return m_points.size(); };
    void setPointCount(std::size_t count = 30)
    { 
        m_points.resize(count);
        update();
    };


    sf::Vector2f getPoint(std::size_t index) const {
        if (m_type == SHAPE_CIRCLE) {
            static const float pi = 3.141592654f;
            float angle = index * 2 * pi / m_points.size() - pi / 2;
            float x = std::cos(angle) * m_radius;
            float y = std::sin(angle) * m_radius;

            return sf::Vector2f(m_radius + x, m_radius + y);
        }
        else if (m_type == SHAPE_CONVEX) {
            return m_points[index];
        }
    };
    void setPoint(std::size_t index, const sf::Vector2f& point)
    {
        m_points[index] = point;
        update();
    }

    float getRadius() const { return m_radius; };
    void setRadius(float radius = 0) { m_radius = radius; };

private:
    std::vector<sf::Vector2f> m_points;
    float m_radius;
    std::size_t m_pointCount;
    int m_type;
};