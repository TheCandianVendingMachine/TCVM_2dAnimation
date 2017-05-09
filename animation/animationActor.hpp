// animationActor.hpp
// holds a sf::VertexArray and anything relavent to animation
#pragma once
#include <SFML/System/Vector2.hpp>

namespace sf
    {
        class VertexArray;
    }

class animationActor
    {
        private:
            sf::VertexArray *m_verticies;
            float m_animationFrameSpeed; // how long it takes for a single frame to iterate in milliseconds

        public:
            animationActor(sf::VertexArray *verticies);

            // Set how long it takes a frame to iterate in milliseconds
            void setFrameSpeed(float animationSpeed);

    };