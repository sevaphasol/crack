#ifndef UTILS_HPP__
#define UTILS_HPP__

//———————————————————————————————————————————————————————————————————//

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//———————————————————————————————————————————————————————————————————//

static const float     SECONDS_ALIVE = 46;

static const char*     WINDOW_NAME   = "CRACK";
static const float     WINDOW_WIDTH  = 1280.0f;
static const float     WINDOW_HEIGHT = 720.0f + 30;

static const char*     MENU_AUDO_FILE_NAME = "menu_audio.mp3";
static const char*     MAIN_AUDO_FILE_NAME = "main_audio.mp3";

static const char*     SPRITE_SHEET_NAME = "sprite_sheet1.png";
static const int       COLS = 40;
static const int       ROWS = 35;
static const int       FRAME_WIDTH    = 160;
static const int       FRAME_HEIGHT   = 120;
static const float     FPS            = 30.0f;

static const float     PROGRESS_BAR_X = 0;
static const float     PROGRESS_BAR_Y = 0;
static const float     PROGRESS_BAR_WIDTH = WINDOW_WIDTH;
static const float     PROGRESS_BAR_HEIGHT = 30;
static const sf::Color PROGRESS_BAR_BACKGROUND_COLOR = sf::Color(50, 50, 50);
static const sf::Color PROGRESS_BAR_FILL_COLOR = sf::Color(255, 0, 255);
static const float     PROGRESS_BAR_MAX_VALUE = 1.0f;

static const char*     FONT_NAME     = "font.ttf";
static const wchar_t*  TEXT_DATA     = L"ПРОИСХОДИТ ВЗЛОМ ЖОПЫ АРТЕМА";
static const float     TEXT_SIZE     = 40.0f;
static const float     TEXT_SPEED    = 200.0f;
static const float     TEXT_START_X  = 0.0f;
static const float     TEXT_START_Y  = WINDOW_HEIGHT - TEXT_SIZE;
static const sf::Color TEXT_COLOR    = sf::Color::White;

static const int       BUTTON_WIDTH  = 200;
static const int       BUTTON_HEIGHT = 50;
static const int       BUTTON_Y_CENTER_OFFSET = 150;
static const int       BUTTON_X      = (WINDOW_WIDTH - BUTTON_WIDTH) / 2;
static const int       BUTTON_Y      = (WINDOW_HEIGHT - BUTTON_HEIGHT) / 2 + BUTTON_Y_CENTER_OFFSET;
static const char*     BUTTON_LABEL  = "CRACK";
static const int       BUTTON_LABEL_CHAR_SIZE = 24;
static const float     BUTTON_OUTLINE_THICKNESS = 2;
static const sf::Color BUTTON_OUTLINE_COLOR    = sf::Color::White;
static const sf::Color BUTTON_FILL_COLOR    = sf::Color::Transparent;
static const sf::Color BUTTON_TEXT_COLOR    = sf::Color::White;

static const int       DIALOG_BOX_WIDTH  = 300;
static const int       DIALOG_BOX_HEIGHT = 50;
static const int       DIALOG_Y_BUTTON_OFFSET = BUTTON_HEIGHT + 30;
static const int       DIALOG_BOX_X      = (WINDOW_WIDTH - DIALOG_BOX_WIDTH) / 2;
static const int       DIALOG_BOX_Y      = BUTTON_Y + DIALOG_Y_BUTTON_OFFSET;
static const int       DIALOG_BOX_TEXT_CHAR_SIZE = 24;
static const float     DIALOG_BOX_OUTLINE_THICKNESS = 2;
static const int       DIALOG_BOX_TEXT_OFFSET    = 10;
static const sf::Color DIALOG_BOX_OUTLINE_COLOR    = sf::Color::White;
static const sf::Color DIALOG_BOX_FILL_COLOR    = sf::Color::Transparent;
static const sf::Color DIALOG_BOX_TEXT_COLOR    = sf::Color::White;
static const sf::Color DIALOG_BOX_CURSOR_FILL_COLOR = sf::Color::White;

static const char*     MENU_SPRITE_SHEET_NAME = "umnov_sprite_sheet.png";
static const float     MENU_SPRITE_SCALE_X = 0.5f;
static const float     MENU_SPRITE_SCALE_Y = 0.5f;
static const int       MENU_SPRITE_COLS       = 15;
static const int       MENU_SPRITE_ROWS       = 10;
static const int       MENU_SPRITE_FRAME_WIDTH            = 624;
static const int       MENU_SPRITE_FRAME_HEIGHT           = 832;
static const float     MENU_SPRITE_X = (WINDOW_WIDTH - MENU_SPRITE_FRAME_WIDTH*MENU_SPRITE_SCALE_X)/2;
static const float     MENU_SPRITE_Y = 30;
static const float     MENU_SPRITE_FPS                    = 30.0f;
static const float     MENU_SPRITE_OUTLINE_THICKNESS = 2;
static const sf::Color MENU_SPRITE_OUTLINE_COLOR = sf::Color::White;

static const char*        CONFIRMATION_DIALOG_BOX_FONT_NAME = "font.ttf";
static const unsigned int CONFIRMATION_DIALOG_BOX_CHARACTER_SIZE = 24;
static const float        CONFIRMATION_DIALOG_BOX_WIDTH = 400;
static const float        CONFIRMATION_DIALOG_BOX_HEIGHT = 200;
static const sf::Color    CONFIRMATION_DIALOG_FILL_COLOR = sf::Color(50, 50, 50);
static const float        CONFIRMATION_DIALOG_OUTLINE_THICKNESS = 2;
static const sf::Color    CONFIRMATION_DIALOG_OUTLINE_COLOR = sf::Color::White;
static const float        CONFIRMATION_DIALOG_BOX_X = (WINDOW_WIDTH - CONFIRMATION_DIALOG_BOX_WIDTH) / 2;
static const float        CONFIRMATION_DIALOG_BOX_Y = (WINDOW_HEIGHT - CONFIRMATION_DIALOG_BOX_HEIGHT) / 2;
static const char*        QUESTION_TEXT = "Do you want to quit?";
static const sf::Color    QUESTION_TEXT_FILL_COLOR = sf::Color::White;
static const float        QUESTION_TEXT_X = CONFIRMATION_DIALOG_BOX_X + 72;
static const float        QUESTION_TEXT_Y = CONFIRMATION_DIALOG_BOX_Y + 40;
static const float        YES_BUTTON_WIDTH = 100;
static const float        YES_BUTTON_HEIGHT = 40;
static const sf::Color    YES_BUTTON_FILL_COLOR = sf::Color::Green;
static const float        YES_BUTTON_X = CONFIRMATION_DIALOG_BOX_X + 50;
static const float        YES_BUTTON_Y = CONFIRMATION_DIALOG_BOX_Y + 120;
static const char*        YES_TEXT = "Yes";
static const sf::Color    YES_TEXT_FILL_COLOR = sf::Color::White;
static const float        YES_TEXT_X = YES_BUTTON_X + 30;
static const float        YES_TEXT_Y = YES_BUTTON_Y + 5;
static const float        NO_BUTTON_WIDTH = 100;
static const float        NO_BUTTON_HEIGHT = 40;
static const sf::Color    NO_BUTTON_FILL_COLOR = sf::Color::Red;
static const float        NO_BUTTON_X = CONFIRMATION_DIALOG_BOX_X + 250;
static const float        NO_BUTTON_Y = CONFIRMATION_DIALOG_BOX_Y + 120;
static const char*        NO_TEXT = "No";
static const sf::Color    NO_TEXT_FILL_COLOR = sf::Color::White;
static const float        NO_TEXT_X = NO_BUTTON_X + 30;
static const float        NO_TEXT_Y = NO_BUTTON_Y + 5;

//———————————————————————————————————————————————————————————————————//

enum screen_mode_t
{
    MENU = 1,
    MAIN = 2,
};

//———————————————————————————————————————————————————————————————————//

struct environment_t
{
    sf::Clock clock;
    float delta_time;
    float elapsed_time;
    sf::SoundBuffer buffer;
    const char* music_file_name;
    sf::Sound sound;
};

void environment_ctor(environment_t& environment,
                      const char*  music_file_name);
void environment_update(environment_t& environment);

//———————————————————————————————————————————————————————————————————//

struct progress_bar_t
{
    sf::RectangleShape background;
    sf::RectangleShape fill;
    float max_value;
    float progress;
};

void progress_bar_ctor   (progress_bar_t& bar,
                          const sf::Vector2f& position,
                          const sf::Vector2f& size,
                          const sf::Color& background_color,
                          const sf::Color& fill_color,
                          float maxValue);
void progress_bar_update(progress_bar_t& bar, float progress);
void progress_bar_draw   (const progress_bar_t& bar,
                          sf::RenderWindow& window);

//———————————————————————————————————————————————————————————————————//

struct cycle_text_t
{
    sf::Font  font;
    sf::Text  text1;
    sf::Text  text2;
    sf::Text* texts[2];
    int       cur_text;
};

void cycle_text_ctor(cycle_text_t& cycle_text,
                     const char* font_name,
                     const sf::Vector2f& position);
void cycle_text_update (cycle_text_t& cycle_text,
                        float delta_time);
void cycle_text_draw   (cycle_text_t& cycle_text,
                        sf::RenderWindow& window);

//———————————————————————————————————————————————————————————————————//

struct animated_sprite_t
{
    sf::Sprite sprite;
    sf::Texture sprite_sheet;
    float played_frames;
    int cur_col;
    int cur_row;
    int frame_width;
    int frame_height;
    int cols_in_sprite_sheet;
    int rows_in_sprite_sheet;
    float fps;
};

void animated_sprite_ctor(animated_sprite_t& animated_sprite,
                          const char* sprite_sheet_name,
                          const sf::IntRect& init_frame,
                          const sf::Vector2f& position,
                          const sf::Vector2f& scale,
                          int cols_in_sprite_sheet,
                          int rows_in_sprite_sheet,
                          int frame_width,
                          int frame_height,
                          float fps);
void animated_sprite_update (animated_sprite_t& animated_sprite,
                             float* elapsed_time);
void animated_sprite_draw(animated_sprite_t& animated_sprite,
                          sf::RenderWindow& window);

//———————————————————————————————————————————————————————————————————//

struct button_t
{
    sf::RectangleShape rect;
    sf::Font font;
    sf::Text text;
};

void button_ctor(button_t& button,
                 const sf::Vector2f& rect_size,
                 const sf::Vector2f& position,
                 const sf::Color rect_color,
                 const char* font_name,
                 const char* label,
                 int character_size,
                 const sf::Color text_color,
                 float outline_thickness,
                 const sf::Color outline_color);

struct manager_t;

void button_update(manager_t& manger,
                   const button_t& button,
                   sf::RenderWindow& window);
void button_draw(const button_t& button,
                 sf::RenderWindow& window);

//———————————————————————————————————————————————————————————————————//

struct dialog_box_t
{
    sf::RectangleShape box;
    sf::RectangleShape cursor;
    sf::Font font;
    sf::Text input_text;
    sf::Clock cursor_clock;
    std::string input_string;
};

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
                     sf::Vector2f cursor_position);

void dialog_box_update(dialog_box_t& dialog_box);

void dialog_box_parse_entered_text(dialog_box_t& dialog_box, sf::Event event);

void dialog_box_draw(dialog_box_t& dialog_box,
                     sf::RenderWindow& window);

//———————————————————————————————————————————————————————————————————//

struct confirmation_dialog_box_t
{
    sf::Font           font;
    sf::RectangleShape box;
    sf::Text           question_text;
    sf::RectangleShape yes_button;
    sf::Text           yes_text;
    sf::RectangleShape no_button;
    sf::Text           no_text;
};

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
                                  const sf::Vector2f& no_text_position);

bool confirmation_dialog_box_show(manager_t& manager, sf::RenderWindow& window);

void confirmation_dialog_box_draw(manager_t& manager,
                                  sf::RenderWindow& window);

//———————————————————————————————————————————————————————————————————//

struct menu_t
{
    environment_t environment;
    animated_sprite_t animated_sprite;
    sf::RectangleShape animated_sprite_border;
    button_t button;
    dialog_box_t dialog_box;
};

void menu_ctor(menu_t& menu);
void menu_update(manager_t& manager, sf::RenderWindow& window);
void menu_draw(manager_t& manager, sf::RenderWindow& window);

//———————————————————————————————————————————————————————————————————//

struct main_t
{
    environment_t environment;
    animated_sprite_t animated_sprite;
    progress_bar_t progress_bar;
    cycle_text_t cycle_text;
    confirmation_dialog_box_t confirmation_dialog_box;
};

void main_ctor(main_t& main);
void main_update(manager_t& manager, sf::RenderWindow& window);
void main_draw(manager_t& manager, sf::RenderWindow& window);

//———————————————————————————————————————————————————————————————————//

struct manager_t
{
    menu_t         menu;
    main_t         main;
    screen_mode_t mode;
    sf::Event      event;
};

void manager_ctor(manager_t& manager);
void manager_update(manager_t& manager, sf::RenderWindow& window);
void manager_draw(manager_t& manager, sf::RenderWindow& window);

//———————————————————————————————————————————————————————————————————//

#endif // UTILS_HPP__
