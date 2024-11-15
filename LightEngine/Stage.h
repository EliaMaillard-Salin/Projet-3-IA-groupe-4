#pragma once

#include "GameManager.h"


namespace sf
{
	class Event;
}

struct AABB
{
	int xMin;
	int yMin;
	int xMax;
	int yMax;
};

class Stage : public Scene
{
public :
	AABB mAreas[3];
	AABB mAreasOfGoals[2];

	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

private :
	int GetClicked(int x, int y) const;
};

