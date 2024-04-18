#ifndef TETRIS_WORLD_H
#define TETRIS_WORLD_H

#include "../include/core.h"
#include "Snake.h"

class World {
public:
    World(sf::Vector2u l_windowSize);
    ~World();

    int GetBlockSize();

    void RespawnApple();

    void Update(Snake &l_player);
    void Render(sf::RenderWindow &l_window);
private:
    sf::Vector2u m_windowSize;
    sf::Vector2i m_item;
    int m_blockSize;

    sf::CircleShape m_appleShape;
    sf::RectangleShape m_bounds[4];
};


#endif //TETRIS_WORLD_H
