#include "animationActor.hpp"

animationActor::animationActor(sf::VertexArray *verticies) : m_verticies(verticies), m_animationFrameSpeed(0.f)
    {
    }

void animationActor::setFrameSpeed(float animationSpeed)
    {
        m_animationFrameSpeed = animationSpeed;
    }
