#pragma once

#include "Entity.h"

class Player;

class Ball : public Entity
{
public:
	Ball(float radius, sf::Color color);
	~Ball() {};

	void SetPlayerWithBall(Player* pPlayer);
	void OnUpdate() override;
	Player* GetPlayerWithBall() { return m_pPlayer; };

private:
	Player* m_pPlayer;

};

