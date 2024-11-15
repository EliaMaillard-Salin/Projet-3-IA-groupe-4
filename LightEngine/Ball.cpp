#include "Ball.h"
#include "Player.h"

Ball::Ball(float radius, sf::Color color) : Entity(radius, color), m_pPlayer(nullptr)
{}

void Ball::SetPlayerWithBall(Player * pPlayer)
{
	if (pPlayer->TransitionTo(Player::HasBall))
		m_pPlayer = pPlayer;
}

void Ball::OnUpdate()
{
	SetPosition(m_pPlayer->GetPosition().x, m_pPlayer->GetPosition().y);
}
