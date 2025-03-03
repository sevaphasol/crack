#include <stdio.h>
#include <string.h>
#include "utils.hpp"

//———————————————————————————————————————————————————————————————————//

void manager_ctor(manager_t& manager)
{
    menu_ctor(manager.menu);
    main_ctor(manager.main);

    manager.mode = MENU;
}

//===================================================================//

void manager_update(manager_t& manager, sf::RenderWindow& window)
{
    switch (manager.mode)
    {
        case MENU: menu_update(manager, window); break;
        case MAIN: main_update(manager, window); break;
    }
}

//===================================================================//

void manager_draw(manager_t& manager, sf::RenderWindow& window)
{
    switch (manager.mode)
    {
        case MENU: menu_draw(manager, window); break;
        case MAIN: main_draw(manager, window); break;
    }
}

//———————————————————————————————————————————————————————————————————//

void menu_ctor(menu_t& menu)
{
    dialog_box_ctor(menu.dialog_box,
                    sf::Vector2f(DIALOG_BOX_WIDTH, DIALOG_BOX_HEIGHT),
                    sf::Vector2f(DIALOG_BOX_X, DIALOG_BOX_Y),
                    DIALOG_BOX_FILL_COLOR,
                    DIALOG_BOX_OUTLINE_THICKNESS,
                    DIALOG_BOX_OUTLINE_COLOR,
                    FONT_NAME,
                    DIALOG_BOX_TEXT_CHAR_SIZE,
                    DIALOG_BOX_TEXT_COLOR,
                    sf::Vector2f(DIALOG_BOX_X + DIALOG_BOX_TEXT_OFFSET, DIALOG_BOX_Y + DIALOG_BOX_TEXT_OFFSET),
                    sf::Vector2f(DIALOG_BOX_OUTLINE_THICKNESS, DIALOG_BOX_TEXT_CHAR_SIZE),
                    DIALOG_BOX_CURSOR_FILL_COLOR,
                    sf::Vector2f(DIALOG_BOX_X + DIALOG_BOX_TEXT_OFFSET, DIALOG_BOX_Y + DIALOG_BOX_TEXT_OFFSET));

    button_ctor(menu.button,
                sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT),
                sf::Vector2f(BUTTON_X, BUTTON_Y),
                BUTTON_FILL_COLOR,
                FONT_NAME,
                BUTTON_LABEL,
                BUTTON_LABEL_CHAR_SIZE,
                BUTTON_TEXT_COLOR,
                BUTTON_OUTLINE_THICKNESS,
                BUTTON_OUTLINE_COLOR);

    environment_ctor(menu.environment,
                     MENU_AUDO_FILE_NAME);

    animated_sprite_ctor(menu.animated_sprite,
                         MENU_SPRITE_SHEET_NAME,
                         sf::IntRect(0, 0, MENU_SPRITE_FRAME_WIDTH, MENU_SPRITE_FRAME_HEIGHT),
                         sf::Vector2f(MENU_SPRITE_X, MENU_SPRITE_Y),
                         sf::Vector2f(MENU_SPRITE_SCALE_X, MENU_SPRITE_SCALE_Y),
                         MENU_SPRITE_COLS,
                         MENU_SPRITE_ROWS,
                         MENU_SPRITE_FRAME_WIDTH,
                         MENU_SPRITE_FRAME_HEIGHT,
                         MENU_SPRITE_FPS);


    menu.animated_sprite_border.setSize(menu.animated_sprite.sprite.getGlobalBounds().getSize());
    menu.animated_sprite_border.setPosition(menu.animated_sprite.sprite.getGlobalBounds().getPosition());
    menu.animated_sprite_border.setFillColor(sf::Color::Transparent);
    menu.animated_sprite_border.setOutlineThickness(MENU_SPRITE_OUTLINE_THICKNESS);
    menu.animated_sprite_border.setOutlineColor(MENU_SPRITE_OUTLINE_COLOR);
}

//===================================================================//

void menu_update(manager_t& manager, sf::RenderWindow& window)
{
    while (window.pollEvent(manager.event))
    {
        if (manager.event.type == sf::Event::Closed)
            window.close();

        if (manager.event.type == sf::Event::TextEntered)
        {
            dialog_box_parse_entered_text(manager.menu.dialog_box, manager.event);
        }
    }

    environment_update(manager.menu.environment);
    animated_sprite_update(manager.menu.animated_sprite, &manager.menu.environment.elapsed_time);
    dialog_box_update(manager.menu.dialog_box);
    button_update(manager, manager.menu.button, window);
}

//===================================================================//

void menu_draw(manager_t& manager, sf::RenderWindow& window)
{
    button_draw(manager.menu.button, window);
    dialog_box_draw(manager.menu.dialog_box, window);
    animated_sprite_draw(manager.menu.animated_sprite, window);
    window.draw(manager.menu.animated_sprite_border);
}

//———————————————————————————————————————————————————————————————————//

void main_ctor(main_t& main)
{
    environment_ctor(main.environment,
                     MAIN_AUDO_FILE_NAME);

    cycle_text_ctor(main.cycle_text,
                    FONT_NAME,
                    sf::Vector2f(TEXT_START_X, TEXT_START_Y));

    animated_sprite_ctor(main.animated_sprite,
                         SPRITE_SHEET_NAME,
                         sf::IntRect(0, 0, FRAME_WIDTH, FRAME_HEIGHT),
                         sf::Vector2f(0, 30),
                         sf::Vector2f(WINDOW_WIDTH/FRAME_WIDTH,
                                     (WINDOW_HEIGHT - TEXT_SIZE -
                                      PROGRESS_BAR_SIZE)/FRAME_HEIGHT),
                         COLS,
                         ROWS,
                         FRAME_WIDTH,
                         FRAME_HEIGHT,
                         FPS);

    progress_bar_ctor(main.progress_bar,
                      sf::Vector2f(0, 0),
                      sf::Vector2f(WINDOW_WIDTH, PROGRESS_BAR_SIZE),
                      sf::Color(50, 50, 50),
                      sf::Color(255, 0, 255),
                      1.0f);

    confirmation_dialog_box_ctor(main.confirmation_dialog_box,
                                 CONFIRMATION_DIALOG_BOX_FONT_NAME,
                                 CONFIRMATION_DIALOG_BOX_CHARACTER_SIZE,
                                 sf::Vector2f(CONFIRMATION_DIALOG_BOX_WIDTH, CONFIRMATION_DIALOG_BOX_HEIGHT),
                                 CONFIRMATION_DIALOG_FILL_COLOR,
                                 CONFIRMATION_DIALOG_OUTLINE_THICKNESS,
                                 CONFIRMATION_DIALOG_OUTLINE_COLOR,
                                 sf::Vector2f(CONFIRMATION_DIALOG_BOX_X, CONFIRMATION_DIALOG_BOX_Y),
                                 QUESTION_TEXT,
                                 QUESTION_TEXT_FILL_COLOR,
                                 sf::Vector2f(QUESTION_TEXT_X, QUESTION_TEXT_Y),
                                 sf::Vector2f(YES_BUTTON_WIDTH, YES_BUTTON_HEIGHT),
                                 YES_BUTTON_FILL_COLOR,
                                 sf::Vector2f(YES_BUTTON_X, YES_BUTTON_Y),
                                 YES_TEXT,
                                 YES_TEXT_FILL_COLOR,
                                 sf::Vector2f(YES_TEXT_X, YES_TEXT_Y),
                                 sf::Vector2f(NO_BUTTON_WIDTH, NO_BUTTON_HEIGHT),
                                 NO_BUTTON_FILL_COLOR,
                                 sf::Vector2f(NO_BUTTON_X, NO_BUTTON_Y),
                                 NO_TEXT,
                                 NO_TEXT_FILL_COLOR,
                                 sf::Vector2f(NO_TEXT_X, NO_TEXT_Y));
}

//===================================================================//

void main_update(manager_t& manager, sf::RenderWindow& window)
{
    while (window.pollEvent(manager.event))
    {
        if (manager.event.type == sf::Event::Closed)
            if (confirmation_dialog_box_show(manager, window))
            {
                window.close();
            }
    }

    environment_update(manager.main.environment);
    animated_sprite_update(manager.main.animated_sprite, &manager.main.environment.elapsed_time);
    progress_bar_update(manager.main.progress_bar, manager.main.animated_sprite.played_frames / FPS / SECONDS_ALIVE);
    cycle_text_update(manager.main.cycle_text, manager.main.environment.delta_time);

    if (manager.main.animated_sprite.played_frames / FPS >= SECONDS_ALIVE)
    {
        manager.mode = MENU;
        manager.main.environment.sound.stop();
        manager.menu.environment.clock.restart();
        manager.menu.environment.sound.play();
    }
}

//===================================================================//

void main_draw(manager_t& manager, sf::RenderWindow& window)
{
    progress_bar_draw(manager.main.progress_bar, window);
    cycle_text_draw(manager.main.cycle_text, window);
    animated_sprite_draw(manager.main.animated_sprite, window);
}

//———————————————————————————————————————————————————————————————————//

void environment_ctor(environment_t& environment,
                      const char*  music_file_name)
{
    environment.elapsed_time = 0.0f;

    if (!environment.buffer.loadFromFile(music_file_name))
    {
        fprintf(stderr, "Error while loading the audio\n");
        return;
    }
    environment.sound.setBuffer(environment.buffer);
}

//===================================================================//

void environment_update(environment_t& environment)
{
    environment.delta_time= environment.clock.restart().asSeconds();
    environment.elapsed_time += environment.delta_time;
}

//———————————————————————————————————————————————————————————————————//

void progress_bar_ctor(progress_bar_t& bar,
                       const sf::Vector2f& position,
                       const sf::Vector2f& size,
                       const sf::Color& background_color,
                       const sf::Color& fill_color,
                       float max_value)
{
    bar.background.setSize(size);
    bar.background.setPosition(position);
    bar.background.setFillColor(background_color);

    bar.fill.setSize(size);
    bar.fill.setPosition(position);
    bar.fill.setFillColor(fill_color);

    bar.max_value = max_value;
    bar.progress  = 0.0f;
}

//===================================================================//

void progress_bar_update(progress_bar_t& bar, float progress)
{
    bar.progress = progress;

    if (bar.progress > bar.max_value) bar.progress = bar.max_value;
    if (bar.progress < 0.0f) bar.progress = 0.0f;

    bar.fill.setSize(sf::Vector2f((bar.progress / bar.max_value) *
                                  bar.background.getSize().x,
                     bar.background.getSize().y));
}
//===================================================================//

void progress_bar_draw(const progress_bar_t& bar,
                       sf::RenderWindow& window)
{
    window.draw(bar.background);
    window.draw(bar.fill);
}

//———————————————————————————————————————————————————————————————————//

void cycle_text_ctor(cycle_text_t& cycle_text,
                     const char* font_name,
                     const sf::Vector2f& position)
{
    if (!cycle_text.font.loadFromFile(font_name))
    {
        fprintf(stderr, "Error while loading the font\n");
        return;
    }

    cycle_text.text1.setFont(cycle_text.font);
    cycle_text.text1.setString(TEXT_DATA);
    cycle_text.text1.setCharacterSize(TEXT_SIZE);
    cycle_text.text1.setFillColor(TEXT_COLOR);
    cycle_text.text1.setPosition(TEXT_START_X, TEXT_START_Y);

    cycle_text.texts[0] = &cycle_text.text1;
    cycle_text.texts[1] = &cycle_text.text2;

    cycle_text.text2 = cycle_text.text1;
    cycle_text.text2.move(WINDOW_WIDTH, 0.0f);

    cycle_text.cur_text = 0;
}

//===================================================================//

void cycle_text_update(cycle_text_t& cycle_text,
                       float delta_time)
{
    cycle_text.text1.move(-TEXT_SPEED * delta_time, 0.0f);
    cycle_text.text2.move(-TEXT_SPEED * delta_time, 0.0f);

    if (cycle_text.texts[cycle_text.cur_text]->getPosition().x < -WINDOW_WIDTH)
    {
        cycle_text.texts[cycle_text.cur_text]->setPosition(WINDOW_WIDTH,
            cycle_text.texts[cycle_text.cur_text]->getPosition().y);
        cycle_text.cur_text = !cycle_text.cur_text;
    }
}

//===================================================================//

void cycle_text_draw(cycle_text_t& cycle_text,
                     sf::RenderWindow& window)
{
    window.draw(cycle_text.text1);
    window.draw(cycle_text.text2);
}

//———————————————————————————————————————————————————————————————————//

void animated_sprite_ctor(animated_sprite_t& animated_sprite,
                          const char* sprite_sheet_name,
                          const sf::IntRect& init_frame,
                          const sf::Vector2f& position,
                          const sf::Vector2f& scale,
                          int cols_in_sprite_sheet,
                          int rows_in_sprite_sheet,
                          int frame_width,
                          int frame_height,
                          float fps)
{
    if (!animated_sprite.sprite_sheet.loadFromFile(sprite_sheet_name))
    {
        fprintf(stderr, "Error while loading the sprite sheet\n");
        return;
    }

    animated_sprite.sprite.setTexture(animated_sprite.sprite_sheet);
    animated_sprite.sprite.setTextureRect(init_frame);
    animated_sprite.sprite.setPosition(position);
    animated_sprite.sprite.setScale(scale);

    animated_sprite.cols_in_sprite_sheet = cols_in_sprite_sheet;
    animated_sprite.rows_in_sprite_sheet = rows_in_sprite_sheet;
    animated_sprite.frame_width = frame_width;
    animated_sprite.frame_height = frame_height;
    animated_sprite.fps = fps;
    animated_sprite.cur_col = 0;
    animated_sprite.cur_row = 0;
    animated_sprite.played_frames = 0;
}

//===================================================================//

void animated_sprite_update (animated_sprite_t& animated_sprite,
                             float* elapsed_time)
{
    if (*elapsed_time >= 1/animated_sprite.fps)
    {
    *elapsed_time -= 1/animated_sprite.fps;

    animated_sprite.played_frames++;

    animated_sprite.cur_col++;
    if (animated_sprite.cur_col >= animated_sprite.cols_in_sprite_sheet) {
        animated_sprite.cur_col = 0;
        animated_sprite.cur_row++;
        if (animated_sprite.cur_row >= animated_sprite.rows_in_sprite_sheet)
        {
            animated_sprite.cur_row = 0;
        }
    }

    animated_sprite.sprite.setTextureRect(sf::IntRect(animated_sprite.cur_col * animated_sprite.frame_width,
                                                      animated_sprite.cur_row * animated_sprite.frame_height,
                                                      animated_sprite.frame_width,
                                                      animated_sprite.frame_height));
    }
}

//===================================================================//

void animated_sprite_draw(animated_sprite_t& animated_sprite,
                          sf::RenderWindow& window)
{
    window.draw(animated_sprite.sprite);
}

//———————————————————————————————————————————————————————————————————//

void button_ctor(button_t& button,
                 const sf::Vector2f& rect_size,
                 const sf::Vector2f& position,
                 const sf::Color rect_color,
                 const char* font_name,
                 const char* label,
                 int character_size,
                 const sf::Color text_color,
                 float outline_thickness,
                 const sf::Color outline_color)
{
    if (!button.font.loadFromFile(font_name))
    {
        fprintf(stderr, "Error while loading the font\n");
        return;
    }

    button.rect.setSize(rect_size);
    button.rect.setPosition(position);
    button.rect.setFillColor(rect_color);
    button.rect.setOutlineThickness(outline_thickness);
    button.rect.setOutlineColor(outline_color);

    button.text.setFont(button.font);
    button.text.setString(label);
    button.text.setCharacterSize(character_size);
    button.text.setFillColor(text_color);
    button.text.setPosition(position.x + (rect_size.x - button.text.getGlobalBounds().width) / 2,
                            position.y + (rect_size.y - (float) button.text.getCharacterSize()) / 2);
}

//===================================================================//

void button_update(manager_t& manager, const button_t& button, sf::RenderWindow& window)
{
    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    if (button.rect.getGlobalBounds().contains(mousePos) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        manager.mode = MAIN;
        manager.main.environment.clock.restart();

        manager.main.animated_sprite.played_frames = 0;
        manager.menu.environment.sound.stop();
        manager.main.environment.sound.play();
    }
}

//===================================================================//

void button_draw(const button_t& button,
                 sf::RenderWindow& window)
{
    window.draw(button.rect);
    window.draw(button.text);
}

//———————————————————————————————————————————————————————————————————//

void dialog_box_ctor(dialog_box_t& dialog_box,
                     sf::Vector2f box_size,
                     sf::Vector2f box_position,
                     sf::Color box_fill_color,
                     float outline_thickness,
                     sf::Color outline_color,
                     const char* font_name,
                     unsigned int character_size,
                     sf::Color text_fill_color,
                     sf::Vector2f text_position,
                     sf::Vector2f cursor_size,
                     sf::Color cursor_fill_color,
                     sf::Vector2f cursor_position)
{
    if (!dialog_box.font.loadFromFile(font_name))
    {
        fprintf(stderr, "Error while loading font\n");
        return;
    }

    dialog_box.input_text.setFont(dialog_box.font);
    dialog_box.input_text.setCharacterSize(character_size);
    dialog_box.input_text.setFillColor(text_fill_color);
    dialog_box.input_text.setPosition(text_position);

    dialog_box.box.setSize(box_size);
    dialog_box.box.setPosition(box_position);
    dialog_box.box.setFillColor(box_fill_color);
    dialog_box.box.setOutlineThickness(outline_thickness);
    dialog_box.box.setOutlineColor(outline_color);

    dialog_box.cursor.setSize(cursor_size);
    dialog_box.cursor.setFillColor(cursor_fill_color);
    dialog_box.cursor.setPosition(cursor_position);
}

//===================================================================//

void dialog_box_update(dialog_box_t& dialog_box)
{
    dialog_box.input_text.setString(dialog_box.input_string);
    dialog_box.cursor.setPosition(dialog_box.input_text.findCharacterPos(dialog_box.input_string.size()));

    if (dialog_box.cursor_clock.getElapsedTime().asSeconds() > 0.5f)
    {
        dialog_box.cursor_clock.restart();
        if (dialog_box.cursor.getFillColor() == sf::Color::White)
        {
            dialog_box.cursor.setFillColor(sf::Color::Transparent);
        }
        else
        {
            dialog_box.cursor.setFillColor(sf::Color::White);
        }
    }
}

//===================================================================//

void dialog_box_parse_entered_text(dialog_box_t& dialog_box, sf::Event event)
{
    if (event.text.unicode == '\b')
    {
        if (!dialog_box.input_string.empty())
            dialog_box.input_string.pop_back();
    }
    else if (event.text.unicode < 128 && dialog_box.input_string.length() < 18)
    {
        dialog_box.input_string += (char) event.text.unicode;
    }
}

//===================================================================//

void dialog_box_draw(dialog_box_t& dialog_box,
                     sf::RenderWindow& window)
{
    window.draw(dialog_box.box);
    window.draw(dialog_box.input_text);
    window.draw(dialog_box.cursor);
}

//———————————————————————————————————————————————————————————————————//

void confirmation_dialog_box_ctor(confirmation_dialog_box_t& dialog_box,
                                  const char* font_name,
                                  unsigned int character_size,
                                  const sf::Vector2f& box_size,
                                  const sf::Color& box_fill_color,
                                  float box_outline_thickness,
                                  const sf::Color& box_outline_color,
                                  const sf::Vector2f& box_position,
                                  const char* question_text,
                                  const sf::Color& question_text_fill_color,
                                  const sf::Vector2f& question_text_position,
                                  const sf::Vector2f& yes_button_size,
                                  const sf::Color& yes_button_fill_color,
                                  const sf::Vector2f& yes_button_position,
                                  const char* yes_text,
                                  const sf::Color& yes_text_fill_color,
                                  const sf::Vector2f& yes_text_position,
                                  const sf::Vector2f& no_button_size,
                                  const sf::Color& no_button_fill_color,
                                  const sf::Vector2f& no_button_position,
                                  const char* no_text,
                                  const sf::Color& no_text_fill_color,
                                  const sf::Vector2f& no_text_position)
{
    if (!dialog_box.font.loadFromFile(font_name))
    {
        fprintf(stderr, "Error while loading the font\n");
        return;
    }

    dialog_box.box.setSize(box_size);
    dialog_box.box.setFillColor(box_fill_color);
    dialog_box.box.setOutlineThickness(box_outline_thickness);
    dialog_box.box.setOutlineColor(box_outline_color);
    dialog_box.box.setPosition(box_position);

    dialog_box.question_text.setFont(dialog_box.font);
    dialog_box.question_text.setString(question_text);
    dialog_box.question_text.setCharacterSize(character_size);
    dialog_box.question_text.setFillColor(question_text_fill_color);
    dialog_box.question_text.setPosition(question_text_position);

    dialog_box.yes_button.setSize(yes_button_size);
    dialog_box.yes_button.setFillColor(yes_button_fill_color);
    dialog_box.yes_button.setPosition(yes_button_position);

    dialog_box.yes_text.setFont(dialog_box.font);
    dialog_box.yes_text.setString(yes_text);
    dialog_box.yes_text.setCharacterSize(character_size);
    dialog_box.yes_text.setFillColor(yes_text_fill_color);
    dialog_box.yes_text.setPosition(yes_text_position);

    dialog_box.no_button.setSize(no_button_size);
    dialog_box.no_button.setFillColor(no_button_fill_color);
    dialog_box.no_button.setPosition(no_button_position);

    dialog_box.no_text.setFont(dialog_box.font);
    dialog_box.no_text.setString(no_text);
    dialog_box.no_text.setCharacterSize(character_size);
    dialog_box.no_text.setFillColor(no_text_fill_color);
    dialog_box.no_text.setPosition(no_text_position);
}

bool confirmation_dialog_box_show(manager_t& manager, sf::RenderWindow& window)
{
    bool got_result = false;
    bool result     = false;

    manager.main.environment.sound.pause();

    while (window.isOpen())
    {
        while (window.pollEvent(manager.event))
        {
            if (manager.event.type == sf::Event::Closed)
            {
                window.close();
                return true;
            }

            if (manager.event.type ==  sf::Event::MouseButtonPressed &&
                manager.event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2f mouse_pos = window.mapPixelToCoords(sf::Mouse::getPosition(window));

                if (manager.main.confirmation_dialog_box.yes_button.getGlobalBounds().contains(mouse_pos))
                {
                    got_result = true;
                    result = true;
                }

                if (manager.main.confirmation_dialog_box.no_button.getGlobalBounds().contains(mouse_pos))
                {
                    got_result = true;
                    result = false;
                }
            }
        }

        // window.clear();

        confirmation_dialog_box_draw(manager, window);

        window.display();

        if (got_result) break;
    }

    manager.main.environment.sound.play();
    manager.main.environment.clock.restart();

    return result;
}

void confirmation_dialog_box_draw(manager_t& manager, sf::RenderWindow& window)
{
    window.draw(manager.main.confirmation_dialog_box.box);
    window.draw(manager.main.confirmation_dialog_box.question_text);
    window.draw(manager.main.confirmation_dialog_box.yes_button);
    window.draw(manager.main.confirmation_dialog_box.yes_text);
    window.draw(manager.main.confirmation_dialog_box.no_button);
    window.draw(manager.main.confirmation_dialog_box.no_text);
}

//———————————————————————————————————————————————————————————————————//
