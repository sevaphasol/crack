// #include <SFML/Graphics.hpp>
// #include <SFML/Audio.hpp>
//
// #include "utils.hpp"
//
// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
//                             WINDOW_NAME);
//
//     //-------------------------------------------------------------------//
//
//     main_t main;
//     main_ctor(main);
//
//     //-------------------------------------------------------------------//
//
//     main.environment.sound.play();
//
//     //-------------------------------------------------------------------//
//
//     while (window.isOpen())
//     {
//         main_update(main);
//
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
//
//         window.clear();
//         main_draw(main, window);
//         window.display();
//     }
//
//     return 0;
// }
// #include <SFML/Graphics.hpp>
// #include <functional>
// #include "utils.hpp"
//
// int main()
// {
//     sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
//                             WINDOW_NAME);
//
//     //-------------------------------------------------------------------//
//
//     button_t button;
//     button_ctor(button,
//                 sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT),
//                 sf::Vector2f(BUTTON_X, BUTTON_Y),
//                 sf::Color::Blue,
//                 FONT_NAME,
//                 BUTTON_LABEL,
//                 24,
//                 sf::Color::White);
//
//     //-------------------------------------------------------------------//
//
//     while (window.isOpen())
//     {
//         sf::Event event;
//         while (window.pollEvent(event))
//         {
//             if (event.type == sf::Event::Closed)
//                 window.close();
//         }
//
//         window.clear();
//         button_update(button, window);
//         button_draw(button, window);
//         window.display();
//     }
//
//     return 0;
// }
#include <SFML/Graphics.hpp>
#include <string>
#include "utils.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
                            WINDOW_NAME);

    //-------------------------------------------------------------------//

    manager_t manager;
    manager_ctor(manager);
    manager.menu.environment.sound.setLoop(true);
    manager.menu.environment.sound.play();

    //-------------------------------------------------------------------//

    while (window.isOpen())
    {
        manager_update(manager, window);
        window.clear();
        manager_draw(manager, window);
        window.display();
    }

    return 0;
}
