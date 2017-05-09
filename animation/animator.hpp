// animator.hpp
// allows the subscription to a animation with options
#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

#include "../objectManagement/handleManager.hpp"

namespace sf
    {
        class Texture;
    }

class animationActor;
class animator : fe::handleManager<sf::Texture*>
    {
        private:
            std::vector<animationActor*> m_actors;

        public:
            void addAnimation(const sf::Texture *texture, sf::Vector2u frameSize);
            void removeAnimation(const sf::Texture *texture);

            void subscribe(animationActor *actor);
            void unsubscribe(animationActor *actor);

            void updateTextures();
    };