#include "animator.hpp"
#include "animationTexture.hpp"
#include "animationActor.hpp"
#include <algorithm>
#include <SFML/Graphics/VertexArray.hpp>

fe::Handle animator::addAnimation(sf::Vector2u frameSize, sf::Vector2u animationSize, sf::Vector2u texturePosition, bool vertical)
    {
        return addObject(animationTexture(frameSize, texturePosition, animationSize, vertical));
    }

void animator::removeAnimation(fe::Handle handle)
    {
        m_actors.erase(handle);
        removeObject(handle);
    }

void animator::subscribe(animationActor *actor, fe::Handle animation)
    {
        m_actors[animation].push_back(actor);
        auto textureOffset = getObject(animation).getTexture(actor);
        actor->updateVerticies(textureOffset.first, textureOffset.second);
        actor->setCurrentFrame(0);
    }

void animator::unsubscribe(animationActor *actor, fe::Handle animation)
    {
        auto &actorVector = m_actors[animation];
        actorVector.erase(std::remove(actorVector.begin(), actorVector.end(), actor), actorVector.end());
    }

void animator::updateTextures()
    {
        for (auto &animation : m_actors)
            {
                auto texture = getObject(animation.first);
                for (auto &actor : animation.second)
                    {
                        if (actor->needsUpdate(m_elapsedTime.getTime()))
                            {
                                auto textureOffset = texture.getTexture(actor);
                                actor->updateVerticies(textureOffset.first, textureOffset.second);
                                actor->iterateFrame(1);
                            }
                    }
            }
    }
