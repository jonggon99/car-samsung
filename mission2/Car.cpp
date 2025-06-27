//#include "Engine.cpp"
//#include "BreakSystem.cpp"

#include "Car.h"
#include <stdio.h>

void Car::CreateBreakSystem(int inputNumber)
{
	delete breakSystem;
	if (inputNumber == 1)
		breakSystem = new BreakMANDO();
	if (inputNumber == 2)
		breakSystem = new BreakCONTINENTAL();
	if (inputNumber == 3)
		breakSystem = new BreakBOSCH();
}

void Car::CreateEngine(int inputNumber)
{
	delete engine;
	if (inputNumber == 1)
		engine = new GM();
	if (inputNumber == 2)
		engine = new TOYOTA();
	if (inputNumber == 3)
		engine = new WIA();
	if (inputNumber == 4)
		engine = new WRONG();
}

void Car::CreateSteeringSystem(int inputNumber)
{
	delete steeringSystem;
	if (inputNumber == 1)
		steeringSystem = new BOSCH();
	if (inputNumber == 2)
		steeringSystem = new MOBIS();

	steeringSystem->SelectSteeringSystem();
}

bool Car:: breakCombinationCheck() {
	if (breakSystem->GetBreakSystemType() == BreakSystemType::BOSCH) {
		if (steeringSystem->GetSteeringType() != SteeringSystemType::BOSCH) return false;
	}
	return true;
}

void Car::RunProduce()
{
	if (!IsValidCar() || !breakCombinationCheck()) {
		printf("자동차가 동작되지 않습니다\n");
		return;
	}

	if (!engine->IsValidEngine()) return;

	RunProduceCar();
	engine->RunEngine();
	breakSystem->RunProduce();
	steeringSystem->RunSteeringSystem();

	printf("자동차가 동작됩니다.\n");
}
bool Sedan::IsValidCar(void)
{
	if (breakSystem->GetBreakSystemType() == BreakSystemType::CONTINENTAL) return false;

	return true;
}
void Sedan::RunProduceCar(void)
{
	printf("Car Type : Sedan\n");
	return;
}
void Sedan::Test()
{
	if (!breakCombinationCheck()) {
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
		return;
	}
	if (breakSystem->GetBreakSystemType() == BreakSystemType::CONTINENTAL) {
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Sedan에는 Continental제동장치 사용 불가\n");

	}
	printf("자동차 부품 조합 테스트 결과 : PASS\n");
}

bool CarSUV::IsValidCar(void)
{
	if (engine->GetEngineType() == EngineType::TOYOTA) return false;
	return true;
}
void CarSUV::RunProduceCar(void)
{
	printf("Car Type : SUV\n");
	return;
}
void CarSUV::Test()
{
	if (!breakCombinationCheck()) {
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
		return;
	}
	if (engine->GetEngineType() == EngineType::TOYOTA) {
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("SUV에는 TOYOTA엔진 사용 불가\n");
		return;
	}
	printf("자동차 부품 조합 테스트 결과 : PASS\n");
}

bool Truck::IsValidCar(void)
{
	if (engine!=nullptr && engine->GetEngineType() == EngineType::WIA) return false;
	if (breakSystem!=nullptr && breakSystem->GetBreakSystemType() == BreakSystemType::MANDO) return false;
	return true;
}
void Truck::RunProduceCar(void)
{
	printf("Car Type : Truck\n");
	return;
}
void Truck::Test()
{
	if (!breakCombinationCheck()) {
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
		return;
	}
	if (engine->GetEngineType() == EngineType::WIA) {
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("SUV에는 WIA엔진 사용 불가\n");
		return;
	}
	if (breakSystem->GetBreakSystemType() == BreakSystemType::MANDO) {
		printf("자동차 부품 조합 테스트 결과 : FAIL\n");
		printf("Truck에는 Mando제동장치 사용 불가\n");
		return;
	}
	printf("자동차 부품 조합 테스트 결과 : PASS\n");
}