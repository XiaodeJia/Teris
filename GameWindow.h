#ifndef _GAME_WINDOW_H_
#define _GAME_WINDOW_H_

#pragma once
class GameWindow
{
public:
	GameWindow();
	~GameWindow();
	void Init(int width, int height, const char* title);
	sf::RenderWindow& GetWindow();
	bool IsOpen();
	void Close();
	bool PollEvent(sf::Event& e);
	void WinRenderBegin();
	void WinRenderEnd();
private:
	sf::RenderWindow m_window;
};
#endif // !_GAME_WINDOW_H_

