#include "Stage.h"

#include "Debug.h"

void Stage::OnInitialize() {
	int width = GetWindowWidth();
	int height = GetWindowHeight();

	float startX = width / 100 * 5;
	float startY = 0;

	for (int i = 0; i < 3; i++)
	{

		int xMin = startX ;
		int yMin = startY;
		int xMax = width - width / 100 * 5;
		int yMax = height;

		mAreas[i] = { xMin, yMin, xMax, yMax };

		startY += height/3;
	}
}

int Stage::GetClicked(int x, int y) const{
	return 0;
}

void Stage::OnEvent(const sf::Event& event) {

}

void Stage::OnUpdate() {
	Debug::DrawBackground(sf::Color(144, 32, 12));
	for (int i = 0; i < 3; i++)
	{
		const AABB& aabb = mAreas[i];

		Debug::DrawRectangle(aabb.xMin, aabb.yMin, aabb.xMax - aabb.xMin, aabb.yMax - aabb.yMin, sf::Color::Black);
	}

	int width = GetWindowWidth();
	int height = GetWindowHeight();
	for (int i = 0; i < 2; i++) {
		const AABB& bbaa = mAreasOfGoals[i];

		Debug::DrawRectangle(bbaa.xMin, bbaa.yMin, width / 100 * 5,height, sf::Color::Black);

		Debug::DrawRectangle(bbaa.xMax, bbaa.yMin, bbaa.xMin , height, sf::Color::Black);
	}
	
}