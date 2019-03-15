#include "sfml/Graphics.hpp"
#include "Background.h"



Background::Background()
{
}

void Background::Init()
{
	m_frame.loadFromFile("images/frame.png");
	m_background.loadFromFile("images/background.png");
	
	m_sFrame.setTexture(m_frame);
	m_sBackground.setTexture(m_background);
	
}


Background::~Background()
{
}

void Background::Render(sf::RenderWindow& window)
{
	window.draw(m_sFrame);
	window.draw(m_sBackground);
}

void Background::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(m_sFrame);
	target.draw(m_sBackground);
}
