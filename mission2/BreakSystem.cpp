#include "BreakSystem.h"
#include <iostream>
#include <string>

static std::string breakName[5] = { "NONE", "MANDO", "CONTINENTAL", "BOSCH" };

void BreakSystem::SelectEngine(void)
{
	std::cout << breakName[(int)breakSystem] << "������ �����ϼ̽��ϴ�" << std::endl;

}

void BreakSystem::RunProduce(void)
{
	std::cout << "Brake System : " << breakName[(int)breakSystem] << std::endl;
}