#include "Engine.h"
#include <stdio.h>
#include <string>
#include <iostream>

static std::string enineName[5] = {"NONE", "GM", "TOYOTA", "WIA", "WRONG"};
bool Engine::IsValidEngine()
{
	if (engineType == EngineType::WRONG) {
		printf("엔진이 고장나있습니다.\n");
		printf("자동차가 움직이지 않습니다.\n");
		return false;
	}
	return true;
}

void Engine::SelectEngine()
{
	std::cout << enineName[(int)engineType] << "엔진을 선택하셨습니다" << std::endl;
}

void Engine::RunEngine()
{
	std::cout << "Engine : " << enineName[(int)engineType] << std::endl;
}

void WRONG::SelectEngine()
{
	return;
}

void WRONG::RunEngine()
{
	return;
}