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
            sf::Vector2u m_frameSize;
            sf::Vector2u m_framePosition;
            sf::Vector2u m_animationSize;

            unsigned int m_maxFrames;

            // If the strip is vertical or not
            bool m_vertical;

        public:
            animationTexture() {}
            animationTexture(const sf::Vector2u frameSize, const sf::Vector2u frameOffset, const sf::Vector2u animationSize, bool verticalStrip);
            std::pair<sf::Vector2u, sf::Vector2u> getTexture(animationActor *actor);

    };