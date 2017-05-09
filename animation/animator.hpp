// animator.hpp
// allows the subscription to a animation with options
#pragma once
#include <unordered_map>
#include <vector>
#include <SFML/System/Vector2.hpp>

#include "../objectManagement/handleManager.hpp"
#include "../time/clock.hpp"

namespace sf
    {
        class Texture;
    }

class animationTexture;
class animationActor;
class animator : fe::handleManager<animationTexture>
    {
        private:
            std::unordered_map<fe::Handle, std::vector<animationActor*>> m_actors;
            fe::clock m_elapsedTime;

        public:
            fe::Handle addAnimation(sf::Vector2u frameSize, sf::Vector2u animationSize, sf::Vector2u texturePosition = sf::Vector2u(0, 0), bool vertical = true);
            void removeAnimation(fe::Handle handle);
                
            void subscribe(animationActor *actor, fe::Handle animation);
            void unsubscribe(animationActor *actor, fe::Handle anitmation);

            void updateTextures();
    };