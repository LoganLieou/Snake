#ifndef TETRIS_SNAKE_H
#define TETRIS_SNAKE_H

#include "../include/core.h"

struct SnakeSegment {
    SnakeSegment(int x, int y) : position(x, y) {}
    sf::Vector2i position;
};

using SnakeContainer = std::vector<SnakeSegment>;

enum class Direction {
    None,
    Up,
    Down,
    Left,
    Right
};

class Snake {
public:
    Snake(int l_blockSize);
    ~Snake();

    // Helper methods
    void SetDirection(Direction l_dir);
    Direction GetDirection();
    int GetSpeed();
    sf::Vector2i GetPosition();
    int GetLives();
    int GetScore();
    void IncreaseScore();
    bool HasLost();

    void Lose(); // Handle losing.

    void Extend(); // Grow the snake.
    void Reset(); // Reset to the starting position.

    void Move(); // Movement method.
    void Tick(); // Update method.
    void Cut(int l_segment); // Method for cutting snake
    void Render(sf::RenderWindow& l_window);
private:
    void CheckCollision(); // Checking for all collisions

    SnakeContainer m_snakeBody;
    int m_size;
    Direction m_dir;
    int m_speed;
    int m_lives;
    int m_score;
    bool m_lost;
    sf::RectangleShape m_bodyRect;
};


#endif //TETRIS_SNAKE_H
