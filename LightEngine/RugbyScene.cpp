#include "Player.h"
#include "Debug.h"
#include "RugbyScene.h"
#include "Ball.h"

void RugbyScene::OnInitialize()
{
	int width = GetWindowWidth();
	int height = GetWindowHeight();
	
	SetStartingPos(width, height);

	float playerRadius = 20.f;

	sf::Color colors[2] = { sf::Color::Green, sf::Color::Red };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Player* pPlayer;
			pPlayer = CreateEntity<Player>(playerRadius, colors[i]);
			pPlayer->SetTeam(i);
			pPlayer->SetPosition(m_teamStartingPos[i].xPos[j], m_teamStartingPos[i].yPos[j], 0.5f, 0.5f);
			if (i == 0)
				m_greenTeamList.push_back(pPlayer);
			else
				m_redTeamList.push_back(pPlayer);
		}
	}
	m_pBall = CreateEntity<Ball>(10.f, sf::Color::Magenta);
	m_pBall->SetPlayerWithBall(m_greenTeamList[1]);
}

void RugbyScene::SetStartingPos(int winWidth, int winHeight)
{
	m_teamStartingPos[0].xPos[0] = 45;
	m_teamStartingPos[0].yPos[0] = 50;
	m_teamStartingPos[0].xPos[1] = 150;
	m_teamStartingPos[0].yPos[1] = 90;
	m_teamStartingPos[0].xPos[2] = 220;
	m_teamStartingPos[0].yPos[2] = winHeight / 2;
	m_teamStartingPos[0].xPos[3] = 45;
	m_teamStartingPos[0].yPos[3] = winHeight - 50;
	m_teamStartingPos[0].xPos[4] = 150;
	m_teamStartingPos[0].yPos[4] = winHeight - 90;

	m_teamStartingPos[1].xPos[0] = winWidth- 45;
	m_teamStartingPos[1].yPos[0] = 50;
	m_teamStartingPos[1].xPos[1] = winWidth - 150;
	m_teamStartingPos[1].yPos[1] = 90;
	m_teamStartingPos[1].xPos[2] = winWidth - 220;
	m_teamStartingPos[1].yPos[2] = winHeight / 2;
	m_teamStartingPos[1].xPos[3] = winWidth - 45;
	m_teamStartingPos[1].yPos[3] = winHeight - 50;
	m_teamStartingPos[1].xPos[4] = winWidth - 150;
	m_teamStartingPos[1].yPos[4] = winHeight - 90;
}

void RugbyScene::OnUpdate()
{

}

int RugbyScene::GetClickedArea(int x, int y) const
{


	return -1;
}


void RugbyScene::OnEvent(const sf::Event& event)
{
	if (event.type == sf::Event::EventType::MouseButtonPressed)
	{
		m_pBall->GetPlayerWithBall()->PassBall();
	}
	int index = GetClickedArea(event.mouseButton.x, event.mouseButton.y);

	if (index == -1)
		return;

}


Player* RugbyScene::GetClosestAlly(Player* pPlayer)
{
	int minDistance = -1;
	Player* closestPlayer = nullptr;
	if (pPlayer->GetTeam() == 0)
	{
		for (int i = 0; i < m_greenTeamList.size(); i++)
			if (minDistance < 0 || minDistance > pPlayer->GetDistanceWith(m_greenTeamList[i]))
			{
				minDistance = pPlayer->GetDistanceWith(m_greenTeamList[i]);
				closestPlayer = m_greenTeamList[i];
			}
	}
	else
	{
		for (int i = 0; i < m_redTeamList.size(); i++)
			if (minDistance < 0 || minDistance > pPlayer->GetDistanceWith(m_redTeamList[i]))
			{
				minDistance = pPlayer->GetDistanceWith(m_redTeamList[i]);
				closestPlayer = m_redTeamList[i];
			}
	}

	return closestPlayer;
}

