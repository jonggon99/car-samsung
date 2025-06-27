#include "BreakSystem.h"
#include <iostream>
#include <string>

static std::string breakName[5] = { "NONE", "MANDO", "CONTINENTAL", "BOSCH" };

void BreakSystem::SelectEngine(void)
{
	std::cout << breakName[(int)breakSystem] << "엔진을 선택하셨습니다" << std::endl;

}

void BreakSystem::RunProduce(void)
{
	std::cout << "Brake System : " << breakName[(int)breakSystem] << std::endl;
}