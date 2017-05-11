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
        testObject b;

        a.arr.setPrimitiveType(sf::PrimitiveType::Quads);
        a.arr.resize(4);

        a.arr[1].position = sf::Vector2f(100, 0);
        a.arr[2].position = sf::Vector2f(100, 100);
        a.arr[3].position = sf::Vector2f(0, 100);

        b.arr.setPrimitiveType(sf::PrimitiveType::Quads);
        b.arr.resize(4);

        b.arr[0].position = sf::Vector2f(300, 300);
        b.arr[1].position = sf::Vector2f(400, 300);
        b.arr[2].position = sf::Vector2f(400, 400);
        b.arr[3].position = sf::Vector2f(300, 400);

        sf::Texture animation;
        animation.loadFromFile("testStrip.png");

        a.play(true);
        a.setFrameSpeed(1500);
        a.setStartFrame(0);
        a.setEndFrame(3);

        b.play(true);
        b.setFrameSpeed(500);

        animator anim;
        auto testStrip = anim.addAnimation(sf::Vector2u(100, 100), animation.getSize(), sf::Vector2u(6, 0));

        anim.subscribe(&a, testStrip);
        anim.subscribe(&b, testStrip);

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
                app.draw(a.arr, &animation);
                app.draw(b.arr, &animation);
                app.display();
            }


        return 0;
    }