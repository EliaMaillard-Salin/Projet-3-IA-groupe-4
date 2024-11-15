#pragma once

#include "GameManager.h"

#include <list>
#include "Player.h"

namespace sf
{
	class Event;
}

struct TeamStartingPos
{
	int xPos[5], yPos[5];
};


class RugbyScene : public Scene
{
	enum Tag
	{
		Green, Red
	};

	int mLaneZombieCount[3] = { 0, 0, 0 };

	TeamStartingPos m_teamStartingPos[2];
	std::vector<Player*> m_greenTeamList;
	std::vector<Player*> m_redTeamList;
	Ball* m_pBall;
private:
	void SetStartingPos(int winWidth, int winHeight);
	int GetClickedArea(int x, int y) const;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

	Ball* GetBall() { return m_pBall; };

	Player* GetClosestAlly(Player* pPlayer);

};

