#include "animationTexture.hpp"
#include "animationActor.hpp"
#include <SFML/Graphics/Texture.hpp>

animationTexture::animationTexture(const sf::Texture *texture, const sf::Vector2u frameSize, const sf::Vector2u frameOffset, bool verticalStrip) :
    m_frameSize(frameSize),
    m_framePosition(frameOffset),
    m_vertical(verticalStrip)
    {
        m_animationSize = texture->getSize();
    }

std::pair<sf::Vector2u, sf::Vector2u> animationTexture::getTexture(animationActor *actor)
    {
        sf::Vector2u frameOffset(0, 0);
        if (m_vertical)
            {
                frameOffset.y += actor->getCurrentFrame() * m_frameSize.y;
                if (frameOffset.y >= m_framePosition.y + m_frameSize.y)
                    {
                        frameOffset.y = 0;
                        actor->setCurrentFrame(0);
                    }
            }
        else
            {
                frameOffset.x += actor->getCurrentFrame() * m_frameSize.x;
                if (frameOffset.x >= m_framePosition.x + m_frameSize.x)
                    {
                        frameOffset.x = 0;
                        actor->setCurrentFrame(0);
                    }
            }

        return std::make_pair(frameOffset, m_frameSize);
    }
