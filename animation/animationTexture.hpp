// animationTexture.hpp
// an object that holds data relavent to animation textures
#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Image.hpp>

namespace sf
    {
        class Texture;
    }

class animationActor;
class animationTexture
    {
        private:
            const sf::Vector2u m_frameSize;
            const sf::Vector2u m_framePosition;
            sf::Vector2u m_animationSize;

            // If the strip is vertical or not
            bool m_vertical;

        public:
            animationTexture(const sf::Texture *texture, const sf::Vector2u frameSize, const sf::Vector2u frameOffset, bool verticalStrip);
            std::pair<sf::Vector2u, sf::Vector2u> getTexture(animationActor *actor);

    };