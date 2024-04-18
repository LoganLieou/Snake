#ifndef TETRIS_WINDOW_H
#define TETRIS_WINDOW_H
#include "../include/core.h"
class Window {
public:
    Window();
    Window(const std::string& title, const sf::Vector2u& size);
    ~Window();

    void BeginDraw();
    void EndDraw();
    void Update();
    bool IsDone();
    bool IsFullscreen();
    sf::Vector2u GetWindowSize();
    void ToggleFullscreen();
    void Draw(sf::Drawable& drawable);
    void SetFrameRate(unsigned int framerate);
    sf::RenderWindow& GetRenderWindow();
private:
    void Setup(const std::string& title, const sf::Vector2u& size);
    void Destroy();
    void Create();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool m_isFullscreen;
    unsigned int m_framerate;
};


#endif //TETRIS_WINDOW_H
