// animationActor.hpp
// holds a sf::VertexArray and anything relavent to animation
#pragma once
#include <SFML/System/Vector2.hpp>
#include "../time/time.hpp"

namespace sf
    {
        class VertexArray;
    }

class animationActor
    {
        private:
            sf::VertexArray *m_verticies;
            fe::time m_lastCheckedTime;
            unsigned int m_animationFrameSpeed; // how long it takes for a single frame to iterate in milliseconds
            
            unsigned int m_maxFrames;
            unsigned int m_startFrame;
            unsigned int m_currentFrame;
 
        public:
            animationActor(sf::VertexArray *verticies);

            // If the actor needs to update its texture this will return true
            bool needsUpdate(fe::time elapsedtime);

            // Set how long it takes a frame to iterate in milliseconds
            void setFrameSpeed(unsigned int animationSpeed);
            // Get how long it takes a frame to iterate in milliseconds
            unsigned int getFrameSpeed() const;

            // Set the maximum frame that the animation can play through
            void setMaxFrame(unsigned int maxFrames);
            // Get the maximum frame the animation can play through
            unsigned int getMaxFrame();

            // Set the first frame which the animation will uses
            void setStartFrame(unsigned int frame);
            // Get the first frame which the animation will use
            unsigned int getStartFrame();

            // Set the current frame the animation is at
            void setCurrentFrame(unsigned int frame);
            // Get the current frame the animation is at
            unsigned int getCurrentFrame() const;
            // Iterate the current frame by the amount specified
            void iterateFrame(int amount);

            // Updates the verticies according to the texture
            void updateVerticies(sf::Vector2u offset, sf::Vector2u size);

    };