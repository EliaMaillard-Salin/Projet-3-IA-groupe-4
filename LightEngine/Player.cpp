#include "Player.h"
#include "RugbyScene.h"
#include "Ball.h"

#include <math.h>

Player::Player(float radius, sf::Color color) : Entity(radius, color), m_hasBall(false), m_speed(1.f), m_pStateMachine(new StateMachine<Player>(this, m_stateCount)), m_team(-1), m_enumState(Idle)
{
	CreateStates();
	//m_pStateMachine->SetState(Idle);
}

void Player::CreateStates()
{
}

bool Player::TransitionTo(EnumPlayerState newState)
{
	if (m_transitions[m_enumState][newState] == 0)
		return false;
	m_enumState = newState;
	return true;
	//m_pStateMachine->SetState(m_enumState);
}

void Player::PassBall()
{
	if (TransitionTo(Idle) == false)
		return;
	Player* pClosestAlly = dynamic_cast<RugbyScene*>(GetScene())->GetClosestAlly(this);
	dynamic_cast<RugbyScene*>(GetScene())->GetBall()->SetPlayerWithBall(pClosestAlly);
}

void Player::SetTeam(int team)
{
	m_team = team;
}

void Player::OnUpdate()
{
	//m_pStateMachine->Update();
}

float Player::GetDistanceWith(Player* pPlayer)
{
	sf::Vector2f pos = GetPosition(); sf::Vector2f otherPos = pPlayer->GetPosition();
	return pow((pow(otherPos.x - pos.x, 2)) + pow(otherPos.y - pos.y, 2), 0.5);
}
