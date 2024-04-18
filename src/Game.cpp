#include "Game.h"

Game::Game() : m_window("Snake", sf::Vector2u(800, 600)),
    m_snake(m_world.GetBlockSize()), m_world(sf::Vector2u(800, 600)) {
    m_texture.loadFromFile("assets/test.png");
    m_sprite.setTexture(m_texture);
    m_sprite.setScale(sf::Vector2f(4.0f, 4.0f));
}

Game::~Game() {}
Window* Game::GetWindow() { return &m_window; }

void Game::ResetTime() {
    m_elapsed += m_clock.restart();
}

void Game::Update() {
    m_window.Update();
    float frametime = 1.0f / m_snake.GetSpeed(); // Update this for the snake.
    if (m_elapsed.asSeconds() >= frametime) {
        m_snake.Tick();
        m_world.Update(m_snake);
        if (m_snake.HasLost()) {
            m_snake.Reset();
        }
        m_elapsed -= sf::seconds(frametime);
    }
}

void Game::Render() {
    m_window.BeginDraw();
    m_world.Render(m_window.GetRenderWindow());
    m_snake.Render(m_window.GetRenderWindow());
    m_window.EndDraw();
}

void Game::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetDirection() != Direction::Down) {
        m_snake.SetDirection(Direction::Up);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetDirection() != Direction::Up) {
        m_snake.SetDirection(Direction::Down);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetDirection() != Direction::Right) {
        m_snake.SetDirection(Direction::Left);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetDirection() != Direction::Left) {
        m_snake.SetDirection(Direction::Right);
    }
}
