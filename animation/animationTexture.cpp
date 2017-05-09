#include "animationTexture.hpp"
#include "animationActor.hpp"
#include <SFML/Graphics/Texture.hpp>

animationTexture::animationTexture(const sf::Texture *texture, const sf::Vector2u frameSize, const sf::Vector2u frameOffset, bool verticalStrip) :
    m_frameSize(frameSize),
    m_framePosition(frameOffset),
    m_vertical(verticalStrip)
    {
        m_animationSize = texture->getSize();
        m_maxFrames = m_vertical ? m_animationSize.y / m_frameSize.y : m_animationSize.x / m_frameSize.x;
    }

std::pair<sf::Vector2u, sf::Vector2u> animationTexture::getTexture(animationActor *actor)
    {
        unsigned int maxFrame = m_maxFrames;
        if (maxFrame > actor->getMaxFrame() && actor->getMaxFrame() != 0)
            {
                maxFrame = actor->getMaxFrame();
            }

        if (actor->getCurrentFrame() >= maxFrame)
            {
                actor->setCurrentFrame(actor->getCurrentFrame() % maxFrame);
            }
        
        if (actor->getCurrentFrame() < actor->getStartFrame())
            {
                actor->setCurrentFrame(actor->getStartFrame());
            }

        sf::Vector2u frameOffset = m_framePosition;
        if (m_vertical)
            {
                frameOffset.y += actor->getCurrentFrame() * m_frameSize.y;
            }
        else
            {
                frameOffset.x += actor->getCurrentFrame() * m_frameSize.x;
            }

        return std::make_pair(frameOffset, m_frameSize);
    }
