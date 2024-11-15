#include "Debug.h"

#include "GameManager.h"

#include <SFML/Graphics/RenderWindow.hpp>



#include <string>

Debug* Debug::Get()
{
	static Debug mInstance;

	return &mInstance;
}

void Debug::Draw(sf::RenderWindow* pRenderWindow)
{

	for (sf::RectangleShape& rectangle : mRectangle)
	{
		pRenderWindow->draw(rectangle);
	}

	mRectangle.clear();

	for (Line& line : mLines)
	{
		pRenderWindow->draw(&line.start, 2, sf::Lines);
	}

	mLines.clear();

	for (sf::Text& text : mTexts)
	{
		pRenderWindow->draw(text);
	}

	mTexts.clear();

	for (sf::CircleShape& circle : mCircles)
	{
		pRenderWindow->draw(circle);
	}

	mCircles.clear();


	
}

void Debug::DrawLine(float x1, float y1, float x2, float y2, const sf::Color& color)
{
	Line line;

	line.start = sf::Vertex(sf::Vector2f(x1, y1));
	line.start.color = color;

	line.end = sf::Vertex(sf::Vector2f(x2, y2));
	line.end.color = color;

	Debug::Get()->mLines.push_back(line);
}

void Debug::DrawRectangle(float x, float y, float width, float height, const sf::Color& color)
{
	DrawLine(x, y, x + width, y, color);
	DrawLine(x + width, y, x + width, y + height, color);
	DrawLine(x + width, y + height, x, y + height, color);
	DrawLine(x, y + height, x, y, color);
}

void Debug::DrawCircle(float x, float y, float radius, const sf::Color& color)
{
	sf::CircleShape circle;

	circle.setRadius(radius);
	circle.setFillColor(color);
	circle.setPosition(x - radius, y - radius);

	Debug::Get()->mCircles.push_back(circle);
}

void Debug::DrawText(float x, float y, const std::string& text, const sf::Color& color)
{
	DrawText(x, y, text, 0.f, 0.f, color);
}

void Debug::DrawText(float x, float y, const std::string& text, float ratioX, float ratioY, const sf::Color& color)
{
	_ASSERT(ratioX >= 0.f && ratioX <= 1.f);
	_ASSERT(ratioY >= 0.f && ratioY <= 1.f);

	sf::Text sfText;

	sfText.setFont(GameManager::Get()->GetFont());
	sfText.setString(text);
	sfText.setCharacterSize(20);
	sfText.setFillColor(color);
	sfText.setPosition(x, y);

	const sf::FloatRect& bounds = sfText.getLocalBounds();
	sfText.setOrigin(bounds.width * ratioX, bounds.height * ratioY);

	Debug::Get()->mTexts.push_back(sfText);
}

void Debug::DrawBackground(const sf::Color& color) {
	sf::RectangleShape rectangle(sf::Vector2f(sf::VideoMode::getDesktopMode().width/100*61, sf::VideoMode::getDesktopMode().height));
	rectangle.setPosition(1280/100*5,0);
	rectangle.setFillColor(color);
	Debug::Get()->mRectangle.push_back(rectangle);
}