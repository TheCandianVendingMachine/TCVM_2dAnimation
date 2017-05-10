#include "animationActor.hpp"
#include "../time/clock.hpp"
#include <SFML/Graphics/VertexArray.hpp>

animationActor::animationActor(sf::VertexArray *verticies) :
    m_verticies(verticies),
    m_animationFrameSpeed(0.f),
    m_currentFrame(0),
    m_endFrame(0),
    m_startFrame(0),
    m_play(false)
    {
    }

void animationActor::play(bool value)
    {
        m_play = value;
        if (!m_play)
            {
                m_pauseTime = fe::clock::getTimeSinceEpoch();
            }
        else
            {
                m_lastCheckedTime += fe::clock::getTimeSinceEpoch() - m_pauseTime;
            }
    }

bool animationActor::isPlaying() const
    {
        return m_play;
    }

bool animationActor::needsUpdate(fe::time elapsedTime)
    {
        if (m_animationFrameSpeed == 0 || !m_play) return false;

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

void animationActor::setEndFrame(unsigned int maxFrames)
    {
        m_endFrame = maxFrames;
    }

unsigned int animationActor::getEndFrame()
    {
        return m_endFrame;
    }

void animationActor::setStartFrame(unsigned int frame)
    {
        m_startFrame = frame;
    }

unsigned int animationActor::getStartFrame()
    {
        return m_startFrame;
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
        setCurrentFrame(m_currentFrame + amount);
        if (m_currentFrame > m_endFrame && m_endFrame != 0)
            {
                setCurrentFrame(m_currentFrame % m_endFrame);
            }
        
        if (m_currentFrame < m_startFrame)
            {
                setCurrentFrame(m_startFrame);
            }
    }

void animationActor::updateVerticies(sf::Vector2u offset, sf::Vector2u size)
    {
        (*m_verticies)[0].texCoords = sf::Vector2f(offset.x, offset.y);
        (*m_verticies)[1].texCoords = sf::Vector2f(offset.x + size.x, offset.y);
        (*m_verticies)[2].texCoords = sf::Vector2f(offset.x + size.x, offset.y + size.y);
        (*m_verticies)[3].texCoords = sf::Vector2f(offset.x, offset.y + size.y);
    }