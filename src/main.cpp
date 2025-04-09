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
