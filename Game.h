#ifndef _GAME_H_
#define _GAME_H_

#pragma once
class Game
{
public:
	Game();
	~Game();
	void Run();
	void Render();
private:
	sf::Event  m_event;
	sf::Clock  m_clock;
	GameWindow m_gameWin;
	Background m_background;
	Tile       m_tile;
	float      m_time = 0.0f;;
	float      m_totalTime = 0.0f;

};

#endif // !_GAME_H_


