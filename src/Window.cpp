#include "Window.h"

Window::Window() { Setup("Window", sf::Vector2u(800, 600)); }
Window::Window(const std::string& title, const sf::Vector2u& size) {
    Setup(title, size);
}
Window::~Window() { Destroy(); }

void Window::Setup(const std::string& title, const sf::Vector2u& size) {
    m_windowTitle = title;
    m_windowSize = size;
    m_isFullscreen = false;
    m_isDone = false;
    m_framerate = 144; // need to add option to change this
    Create();
}

void Window::Create() {
    auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create(sf::VideoMode(m_windowSize.x, m_windowSize.y),
                    m_windowTitle, style);
    m_window.setFramerateLimit(m_framerate);
}

void Window::Destroy() {
    m_window.close();
}

void Window::Update() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_isDone = true;
        }
        else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F) {
            ToggleFullscreen();
        }
    }
}

void Window::ToggleFullscreen() {
    m_isFullscreen = !m_isFullscreen;
    Destroy();
    Create();
}

void Window::BeginDraw() { m_window.clear(sf::Color(91, 92, 86)); }
void Window::EndDraw() { m_window.display(); }
void Window::SetFrameRate(unsigned int framerate) { m_framerate = framerate; }
bool Window::IsDone() { return m_isDone; }
bool Window::IsFullscreen() { return m_isFullscreen; }
sf::Vector2u Window::GetWindowSize() { return m_windowSize; }

void Window::Draw(sf::Drawable& drawable) {
    m_window.draw(drawable);
}

sf::RenderWindow& Window::GetRenderWindow() {
    return m_window;
}
