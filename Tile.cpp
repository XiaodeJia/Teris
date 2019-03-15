#include <sfml/Graphics.hpp>
#include "Tile.h"

int figures[TILE_NUM_MAX][TILE_WIDTH] =
{
	1,3,5,7, // I
	2,4,5,7, // Z
	3,5,4,6, // S
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5, // O
};

Tile::Tile()
{
}


Tile::~Tile()
{
}

void Tile::Init()
{
	m_tiles.loadFromFile("images/tiles.png");
	m_sTiles.setTexture(m_tiles);
}

void Tile::Render(sf::RenderWindow & win)
{
	//win.draw(m_sTiles);
	for (int i = 0; i < BACKGROUND_HEIGHT; i++)
	{
		for (int j = 0; j<BACKGROUND_WIDTH; j++)
		{
			if (field[i][j] == 0)
			{
				continue;
			}
			m_sTiles.setTextureRect(sf::IntRect(field[i][j] * RECT_SIZE, 0, RECT_SIZE, RECT_SIZE));
			m_sTiles.setPosition(j * 18, i * 18);
			m_sTiles.move(28, 31); //offset
			win.draw(m_sTiles);
		}
	}
	
	for (int i = 0; i< 4; i++)
	{
		m_sTiles.setTextureRect(sf::IntRect(colorNum * RECT_SIZE, 0, RECT_SIZE, RECT_SIZE));
		m_sTiles.setPosition(a[i].x * RECT_SIZE, a[i].y * RECT_SIZE);
		m_sTiles.move(28, 31); //offset
		win.draw(m_sTiles);
	}

}

bool Tile::Check()
{
	for (int i = 0; i < TILE_WIDTH; i++)
	{
		if (a[i].x < 0 || a[i].x >= BACKGROUND_WIDTH
			|| a[i].y >= BACKGROUND_HEIGHT
			|| field[a[i].y][a[i].x])
		{
			return false;
		}	
	}
	return true;
}

void Tile::Move(int moveStride)
{

	for (int i = 0; i < TILE_WIDTH; i++)
	{
		a[i].x += moveStride;
	}
}

void Tile::Rotate()
{
	Point p = a[1];
	for (int i = 0; i < TILE_WIDTH; i++)
	{
		int x = a[i].y - p.y;
		int y = a[i].x - p.x;
		a[i].x = p.x - x;
		a[i].y = p.y + y;
	}
}

void Tile::Update(sf::Keyboard::Key& key)
{
	for (int i = 0; i < TILE_WIDTH; i++)
	{
		b[i] = a[i];//backup
	}
	
	if (key == sf::Keyboard::Left || key == sf::Keyboard::Right)
	{
		//int moveStride = 0;
		int moveStride = (key == sf::Keyboard::Left ? -1:1);
		//move											 
		Move(moveStride);
	}
	else if (key == sf::Keyboard::Up)
	{
		Rotate();
	}
	else if (key == sf::Keyboard::Down)
	{
		delay = 0.05;
	}

	if (!Check())
	{
		for (int i = 0; i < TILE_WIDTH; i++)
		{
			a[i] = b[i];
		}
	}
}

void Tile::Tick(float& timer)
{
	if (timer > delay)
	{
		for (int i = 0; i< TILE_WIDTH; i++)
		{ 
			b[i] = a[i]; 
			a[i].y += 1; 
		}

		if (!Check())
		{
			for (int i = 0; i < TILE_WIDTH; i++)
			{
				field[b[i].y][b[i].x] = colorNum;
			}

			colorNum = 1 + rand() % TILE_NUM_MAX;
			int n = rand() % TILE_NUM_MAX;
			for (int i = 0; i< TILE_WIDTH; i++)
			{
				a[i].x = figures[n][i] % 2;
				a[i].y = figures[n][i] / 2;
			}
		}

		timer = 0;//reset
	}
}

void Tile::CheckLine()
{
	int k = BACKGROUND_HEIGHT - 1;
	for (int i = BACKGROUND_HEIGHT - 1; i>0; i--)
	{
		int count = 0;
		for (int j = 0; j < BACKGROUND_WIDTH; j++)
		{
			if (field[i][j]) count++;
			field[k][j] = field[i][j];
		}
		//if count == BACKGROUND_WIDTH indicates that the line is full.
		if (count < BACKGROUND_WIDTH)
		{
			k--;
		}
	}
}

void Tile::Reset()
{ 
	rotate = 0; 
	delay = 0.3;
}

void Tile::Display(float & timer)
{
	Tick(timer);
	CheckLine();
	Reset();
}


void Tile::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sTiles);
}
