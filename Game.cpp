#include <sfml/Graphics.hpp>
#include "GameWindow.h"
#include "Tile.h"
#include "Background.h"
#include <iostream>
#include "Game.h"

Game::Game()
{
	m_gameWin.Init(320, 480, "Teris");
	m_background.Init();
	m_tile.Init();
}


Game::~Game()
{
	if (m_gameWin.IsOpen())
		m_gameWin.Close();
}

void Game::Run()
{

	while (m_gameWin.IsOpen())
	{
		m_time = m_clock.getElapsedTime().asSeconds();
		m_clock.restart();
		m_totalTime += m_time;

		//sf::Event e;
		while (m_gameWin.PollEvent(m_event))
		{
			if (m_event.type == sf::Event::Closed)
			{
				m_gameWin.Close();
			}

			if (m_event.type == sf::Event::KeyPressed)
			{
				m_tile.Update(m_event.key.code);
			}	
		}
		m_tile.Display(m_totalTime);
		Render();
	}
}

void Game::Render()
{
	m_gameWin.WinRenderBegin();
	m_background.Render(m_gameWin.GetWindow());
	m_tile.Render(m_gameWin.GetWindow());
	m_gameWin.WinRenderEnd();
}
