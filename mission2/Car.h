#pragma once
#include "SteeringSystem.h"
#include "Engine.h"
#include "BreakSystem.h"
enum class CarType {
	NONE,
	Sedan,
	SUV,
	Truck
};


class Car {
public:
	Car() : carType(CarType::NONE),steeringSystem(nullptr), breakSystem(nullptr) {}
	Car(CarType type) : carType(type), steeringSystem(nullptr), breakSystem(nullptr) {}
	virtual ~Car() {}

	virtual bool IsValidCar(void) = 0;
	virtual void RunProduceCar(void) = 0;
	void RunProduce();
	virtual void Test() = 0;
	void CreateEngine(int inputNumer);
	void CreateBreakSystem(int inputNumber);
	void CreateSteeringSystem(int inputNumer);
	EngineType GetEngineType() { return engine->GetEngineType(); }
	BreakSystemType GetBreakSystem() { return breakSystem->GetBreakSystemType(); }
	SteeringSystemType GetSteeringType() { return steeringSystem->GetSteeringType(); }
	bool breakCombinationCheck();
protected:
	CarType carType;
	Engine* engine;
	BreakSystem* breakSystem;
	SteeringSystem* steeringSystem;
};

class Sedan :public Car {
public:
	Sedan() :Car(CarType::Sedan) {}
	~Sedan() {}
	bool IsValidCar(void) override;
	void RunProduceCar(void) override;
	void Test() override;
};

class CarSUV :public Car {
public:
	CarSUV() :Car(CarType::SUV) {}
	~CarSUV() {}
	bool IsValidCar(void) override;
	void RunProduceCar(void) override;
	void Test() override;
};

class Truck :public Car {
public:
	Truck() :Car(CarType::Truck) {}
	~Truck() {}

	bool IsValidCar(void) override;
	void RunProduceCar(void) override;
	void Test() override;
};

class CarFactory {
public:
	Car* CreateCar(int inputNumber) {
		if (inputNumber == 1) {
			return new Sedan();
		}
		if (inputNumber == 2) {
			return new CarSUV();
		}
		if (inputNumber == 3) {
			return new Truck();
		}
		return nullptr;
	}
};