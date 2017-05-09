// animation system
// creating a good animation system for my engine
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "animation/animationActor.hpp"
#include "animation/animationTexture.hpp"
#include "animation/animator.hpp"

struct testObject : public animationActor
    {
        sf::VertexArray arr;
        testObject() : animationActor(&arr) {}
    };

int main()
    {
        testObject a;
        a.arr.setPrimitiveType(sf::PrimitiveType::Quads);
        a.arr.resize(4);

        a.arr[1].position = sf::Vector2f(100, 0);
        a.arr[2].position = sf::Vector2f(100, 100);
        a.arr[3].position = sf::Vector2f(0, 100);

        sf::Texture animation;
        animation.loadFromFile("testStrip.bmp");

        animator anim;
        anim.subscribe(&a, anim.addAnimation(&animation, sf::Vector2u(100, 100)));

        sf::RenderWindow app(sf::VideoMode(70 * 16, 70 * 9), "Animation", sf::Style::Close);
        //app.setFramerateLimit(60);
        while (app.isOpen())
            {
                sf::Event event;
                while (app.pollEvent(event))
                    {
                        switch (event.type)
                            {
                                case sf::Event::Closed:
                                    app.close();
                                    break;
                                default:
                                    break;
                            }
                    }

                anim.updateTextures();

                app.clear(sf::Color::White);
                app.draw(a.arr, sf::RenderStates(&animation));
                app.display();
            }


        return 0;
    }