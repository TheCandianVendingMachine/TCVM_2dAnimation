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
        if (actor->getCurrentFrame() >= m_maxFrames)
            {
                actor->setCurrentFrame(0);
            }

        sf::Vector2u frameOffset(0, 0);
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
