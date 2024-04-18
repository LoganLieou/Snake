#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H
#include "../include/core.h"
#include "Window.h"
#include "Snake.h"
#include "World.h"

class Game {
public:
    Game();
    ~Game();

    void HandleInput();
    void ResetTime();
    void Update();
    void Render();
    Window* GetWindow();

private:
    Window m_window;
    sf::Clock m_clock;
    sf::Time m_elapsed;
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    World m_world;
    Snake m_snake;
};

#endif //TETRIS_GAME_H
