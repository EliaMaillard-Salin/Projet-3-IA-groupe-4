#pragma once

#include "Entity.h"
#include "StateMachine.h"

class Ball;

class Player : public Entity
{
public: 
	Player(float radius, sf::Color color);
	~Player() {};


	enum EnumPlayerState
	{
		Idle, Run, HasBall, Count
	};

	void PassBall();
	void SetTeam(int team);
	void OnUpdate() override;
	int GetTeam() { return m_team; }

	float GetDistanceWith(Player* pPlayer);
	bool TransitionTo(EnumPlayerState newState);

private:
	void CreateStates();
protected:
	static const int m_stateCount = (int)EnumPlayerState::Count;
	int m_transitions[m_stateCount][m_stateCount] =
	{
		{0,1,1},
		{1,0,1},
		{1,1,0}
	};

	EnumPlayerState m_enumState;
	int m_speed;
	bool m_hasBall;

	int m_team;

	StateMachine<Player>* m_pStateMachine;
};

