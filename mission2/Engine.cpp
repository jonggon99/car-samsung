#include "Engine.h"
#include <stdio.h>
#include <string>
#include <iostream>

static std::string enineName[5] = {"NONE", "GM", "TOYOTA", "WIA", "WRONG"};
bool Engine::IsValidEngine()
{
	if (engineType == EngineType::WRONG) {
		printf("������ ���峪�ֽ��ϴ�.\n");
		printf("�ڵ����� �������� �ʽ��ϴ�.\n");
		return false;
	}
	return true;
}

void Engine::SelectEngine()
{
	std::cout << enineName[(int)engineType] << "������ �����ϼ̽��ϴ�" << std::endl;
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