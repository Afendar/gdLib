#include "Window.h"

namespace GDLib {
	Window::Window() {
		m_isInitialized = false;
		m_mouseMoved = true;
		m_isFocused = true;
	}

	Window::~Window() {
		m_window.close();
	}

	void Window::clear() {
		m_window.clear(sf::Color::Black);
	}

	void Window::display() {
		m_window.display();
	}

	sf::RenderWindow* Window::getRenderWindow() {
		return &m_window;
	}

	void Window::init(const std::string& title, const sf::Vector2u& size, const bool& isFullscreen) {
		m_windowTile = title;
		m_windowSize = size;
		m_isFullscreen = isFullscreen;
		m_isClosed = false;
		m_isFocused = false;
		m_isInitialized = true;

		create();
	}

	void Window::update() {
		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				close();
			}
		}
	}

	bool Window::isClosed() { return m_isClosed; }
	bool Window::isFullscreen() { return m_isFullscreen; }
	bool Window::isFocused() { return m_isFocused; }

	void Window::toggleFullscreen() {}

	void Window::close() {
		m_isClosed = true;
	}

	void Window::create() {
		sf::Uint32 style = sf::Style::Default;

		if (m_isFullscreen) {
			style = sf::Style::Fullscreen;
		}

		sf::ContextSettings context;
		context.depthBits = 24;
		context.stencilBits = 8;
		context.antialiasingLevel = 2;

		m_window.create(sf::VideoMode(m_windowSize.x, m_windowSize.y, 32), m_windowTile, style, context);
		m_window.setVerticalSyncEnabled(true);
	}
}