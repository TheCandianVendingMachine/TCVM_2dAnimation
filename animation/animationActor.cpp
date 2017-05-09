#include "animationActor.hpp"
#include <SFML/Graphics/VertexArray.hpp>

animationActor::animationActor(sf::VertexArray *verticies, unsigned int maxFrames) :
    m_verticies(verticies),
    m_animationFrameSpeed(0.f),
    m_maxFrames(maxFrames),
    m_currentFrame(0)
    {
    }

void animationActor::setFrameSpeed(float animationSpeed)
    {
        m_animationFrameSpeed = animationSpeed;
    }

void animationActor::setCurrentFrame(unsigned int frame)
    {
        m_currentFrame = frame;
    }

unsigned int animationActor::getCurrentFrame()
    {
        return m_currentFrame;
    }

void animationActor::updateVerticies(sf::Vector2u offset, sf::Vector2u size)
    {
        (*m_verticies)[0].texCoords = sf::Vector2f(offset.x, offset.y);
        (*m_verticies)[1].texCoords = sf::Vector2f(offset.x + size.x, offset.y);
        (*m_verticies)[2].texCoords = sf::Vector2f(offset.x + size.x, offset.y + size.y);
        (*m_verticies)[3].texCoords = sf::Vector2f(offset.x, offset.y + size.y);
    }