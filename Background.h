#ifndef _BACKGROUND_H_
#define _BACKGROUND_H_

#pragma once
class Background : public sf::Drawable
{
public:
	Background();
	void Init();
	~Background();
	void Render(sf::RenderWindow& window);
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
private:
	sf::Texture m_frame;
	sf::Texture m_background;

	sf::Sprite  m_sFrame;
	sf::Sprite  m_sBackground;

};

#endif // !_BACKGROUND_H_



