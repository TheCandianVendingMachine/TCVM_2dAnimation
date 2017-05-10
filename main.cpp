// animation system
// creating a good animation system for my engine
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <iostream>

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
        animation.loadFromFile("testStrip.png");

        a.play(true);
        a.setFrameSpeed(200);
        a.setStartFrame(1);
        a.setEndFrame(3);

        animator anim;
        anim.subscribe(&a, anim.addAnimation(sf::Vector2u(100, 100), animation.getSize()));

        sf::RenderWindow app(sf::VideoMode(1280, 800), "Animation", sf::Style::Close);
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
                                case sf::Event::KeyReleased:
                                    if (event.key.code == sf::Keyboard::Space) 
                                        {
                                            a.play(!a.isPlaying());
                                            std::cout << std::boolalpha << "Playing: " << a.isPlaying() << "\n";
                                        }
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