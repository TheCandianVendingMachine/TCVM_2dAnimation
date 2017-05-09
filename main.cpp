// animation system
// creating a good animation system for my engine
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

int main()
    {
        sf::RenderWindow app(sf::VideoMode(70 * 16, 70 * 9), "Animation", sf::Style::Close);
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

                app.clear(sf::Color::White);

                app.display();
            }


        return 0;
    }