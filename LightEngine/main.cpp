
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "Debug.h"
#include "Stage.h"


#include <cstdlib>
#include <crtdbg.h>

int main() 
{
    GameManager* pInstance = GameManager::Get();

	pInstance->CreateWindow(1280, 720, "TA GROSSE DARONNE LA RUGBYMAN",60,sf::Color(49,123,3));
	pInstance->LaunchScene<Stage>();

	return 0;
}