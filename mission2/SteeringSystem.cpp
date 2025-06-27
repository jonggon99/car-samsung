#pragma once
#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SteeringSystem.h"

void BOSCH::SelectSteeringSystem(void) {
	printf("BOSCH 조향장치를 선택하셨습니다.\n");
	steeringType = SteeringSystemType::BOSCH;
}
void BOSCH::RunSteeringSystem(void) {
	printf("SteeringSystem : Bosch\n");
}

void MOBIS::SelectSteeringSystem(void) {
	printf("MOBIS 조향장치를 선택하셨습니다.\n");
	steeringType = SteeringSystemType::MOBIS;
}
void MOBIS::RunSteeringSystem(void) {
	printf("SteeringSystem : Mobis\n");
}

//class SteeringSystemFactory {
//public:
//	SteeringSystem CreateSteeringSystem(int input);
//};
//
//SteeringSystem SteeringSystemFactory::CreateSteeringSystem(int input)
//{
//	return new SteeringSystem();
//}
#endif