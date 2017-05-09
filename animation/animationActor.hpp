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
            
            unsigned int m_maxFrames;
            unsigned int m_currentFrame;
     
        public:
            animationActor(sf::VertexArray *verticies, unsigned int maxFrames);

            // Set how long it takes a frame to iterate in milliseconds
            void setFrameSpeed(float animationSpeed);

            // Set the current frame the animation is at
            void setCurrentFrame(unsigned int frame);
            // Get the current frame the animation is at
            unsigned int getCurrentFrame();

            // Updates the verticies according to the texture
            void updateVerticies(sf::Vector2u offset, sf::Vector2u size);

    };