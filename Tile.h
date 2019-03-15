#ifndef _TILE_H_
#define _TILE_H_
#pragma once

constexpr int TILE_WIDTH = 4;
constexpr int TILE_NUM_MAX = 7;
constexpr int BACKGROUND_WIDTH = 10;
constexpr int BACKGROUND_HEIGHT = 20;
constexpr int RECT_SIZE = 18;



struct Point
{
	int x;
	int y;
};

class Tile : public sf::Drawable
{
public:
	Tile();
	~Tile();
	void Init();
	void Render(sf::RenderWindow& win);
	bool Check();
	void Move(int moveStride);
	void Rotate();
	void Update(sf::Keyboard::Key & key);
	void Tick(float& timer);
	void CheckLine();
	void Reset();
	void Display(float& timer);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Texture m_tiles;
	sf::Sprite  m_sTiles;
	Point       a[TILE_WIDTH] = {0};
	Point       b[TILE_WIDTH] = {0};

	int         field[BACKGROUND_HEIGHT][BACKGROUND_WIDTH] = { 0 };
	float       timer = 0; //magic number 
	float       delay = 0.3;
	int         colorNum = 1;
	bool        rotate = 0;
};
#endif // !_TILE_H_

