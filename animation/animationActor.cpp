#include "animationActor.hpp"
#include <SFML/Graphics/VertexArray.hpp>

animationActor::animationActor(sf::VertexArray *verticies) :
    m_verticies(verticies),
    m_animationFrameSpeed(0.f),
    m_currentFrame(0)
    {
    }

bool animationActor::needsUpdate(fe::time elapsedTime)
    {
        if (m_animationFrameSpeed == 0) return false;

        bool update = (int)(m_animationFrameSpeed - (elapsedTime - m_lastCheckedTime).asMilliseconds()) <= 0;
        if (update) 
            {
                m_lastCheckedTime = elapsedTime;
            }
        return update;
    }

void animationActor::setFrameSpeed(unsigned int animationSpeed)
    {
        m_animationFrameSpeed = animationSpeed;
    }

unsigned int animationActor::getFrameSpeed() const
    {
        return m_animationFrameSpeed;
    }

void animationActor::setCurrentFrame(unsigned int frame)
    {
        m_currentFrame = frame;
    }

unsigned int animationActor::getCurrentFrame() const
    {
        return m_currentFrame;
    }

void animationActor::iterateFrame(int amount)
    {
        m_currentFrame += amount;
    }

void animationActor::updateVerticies(sf::Vector2u offset, sf::Vector2u size)
    {
        (*m_verticies)[0].texCoords = sf::Vector2f(offset.x, offset.y);
        (*m_verticies)[1].texCoords = sf::Vector2f(offset.x + size.x, offset.y);
        (*m_verticies)[2].texCoords = sf::Vector2f(offset.x + size.x, offset.y + size.y);
        (*m_verticies)[3].texCoords = sf::Vector2f(offset.x, offset.y + size.y);
    }