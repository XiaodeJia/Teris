#include <sfml/Graphics.hpp>
#include "GameWindow.h"



GameWindow::GameWindow()
{
}


GameWindow::~GameWindow()
{
}

void GameWindow::Init(int width, int height, const char * title)
{
	m_window.create(sf::VideoMode(width, height), title);
}

sf::RenderWindow & GameWindow::GetWindow()
{
	// TODO: insert return statement here
	return m_window;
}

bool GameWindow::IsOpen()
{
	return m_window.isOpen();
}

void GameWindow::Close()
{
	m_window.close();
}

bool GameWindow::PollEvent(sf::Event& e)
{
	return m_window.pollEvent(e);
}

void GameWindow::WinRenderBegin()
{
	m_window.clear(sf::Color::White);
}

void GameWindow::WinRenderEnd()
{
	m_window.display();
}
