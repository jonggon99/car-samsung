#include "gmock/gmock.h"
#include "SteeringSystem.h"
#include "Car.h"
#include "Engine.h"

TEST(CARTEST, Test)
{
	Car* car = new Sedan();
	car->CreateEngine(1);
	car->CreateSteeringSystem(1);
	car->CreateBreakSystem(1);
	car->Test();

	car = new CarSUV();
	car->CreateEngine(1);
	car->CreateSteeringSystem(1);
	car->CreateBreakSystem(1);
	car->Test();

	car = new Truck();
	car->CreateEngine(1);
	car->CreateSteeringSystem(1);
	car->CreateBreakSystem(1);
	car->Test();
}

TEST(CARTEST, RunProduce)
{
	Car* car = new Sedan();
	car->CreateEngine(1);
	car->CreateSteeringSystem(1);
	car->CreateBreakSystem(1);
	car->RunProduce();
	delete car;

	car = new CarSUV();
	car->CreateEngine(1);
	car->CreateSteeringSystem(1);
	car->CreateBreakSystem(1);
	car->RunProduce();
	delete car;

	car = new Truck();
	car->CreateEngine(1);
	car->CreateSteeringSystem(1);
	car->CreateBreakSystem(1);
	car->RunProduce();
	delete car;
}
TEST(CARTEST, ValidCar)
{
	Car* car = new Sedan();
	car->CreateBreakSystem(2);
	EXPECT_EQ(false, car->IsValidCar());
	delete car;

	car = new CarSUV();
	car->CreateEngine(2);
	EXPECT_EQ(false, car->IsValidCar());
	delete car;

	car = new Truck();
	car->CreateEngine(3);
	EXPECT_EQ(false, car->IsValidCar());
	car->CreateEngine(2);
	EXPECT_EQ(true, car->IsValidCar());
	car->CreateBreakSystem(1);
	EXPECT_EQ(false, car->IsValidCar());
	delete car;

	car = new Truck();
	car->CreateSteeringSystem(1);
	car->CreateBreakSystem(3);
	EXPECT_EQ(true, car->breakCombinationCheck());
	car->CreateSteeringSystem(2);
	EXPECT_EQ(false, car->breakCombinationCheck());
	delete car;
}

TEST(CARTEST, CreaeteSteeringSystem)
{
	Car* car = new Sedan();
	car->CreateSteeringSystem(1);
	EXPECT_EQ(SteeringSystemType::BOSCH, car->GetSteeringType());

	car->CreateSteeringSystem(2);
	EXPECT_EQ(SteeringSystemType::MOBIS, car->GetSteeringType());

	car->CreateEngine(1);
	EXPECT_EQ(EngineType::GM, car->GetEngineType());
	car->CreateEngine(2);
	EXPECT_EQ(EngineType::TOYOTA, car->GetEngineType());
	car->CreateEngine(3);
	EXPECT_EQ(EngineType::WIA, car->GetEngineType());
	car->CreateEngine(4);
	EXPECT_EQ(EngineType::WRONG, car->GetEngineType());

	car->CreateBreakSystem(1);
	EXPECT_EQ(BreakSystemType::MANDO, car->GetBreakSystem());
	car->CreateBreakSystem(2);
	EXPECT_EQ(BreakSystemType::CONTINENTAL, car->GetBreakSystem());
	car->CreateBreakSystem(3);
	EXPECT_EQ(BreakSystemType::BOSCH, car->GetBreakSystem());
}

TEST(EngineTest, BreakSystemTest)
{
	BreakSystem* breakSys = new BreakMANDO();
	breakSys->SelectEngine();
	breakSys->RunProduce();
	EXPECT_EQ(breakSys->GetBreakSystemType(), BreakSystemType::MANDO);
}

TEST(EngineTest, GMFunction)
{
	Engine* engine = new GM();

	engine->SelectEngine();
	engine->RunEngine();
	EXPECT_EQ(true, engine->IsValidEngine());
	EXPECT_EQ(EngineType::GM, engine->GetEngineType());

	engine = new TOYOTA();

	engine->SelectEngine();
	engine->RunEngine();
	EXPECT_EQ(true, engine->IsValidEngine());
	EXPECT_EQ(EngineType::TOYOTA, engine->GetEngineType());

	engine = new WIA();

	engine->SelectEngine();
	engine->RunEngine();
	EXPECT_EQ(true, engine->IsValidEngine());
	EXPECT_EQ(EngineType::WIA, engine->GetEngineType());

	engine = new WRONG();

	engine->SelectEngine();
	engine->RunEngine();
	EXPECT_EQ(false, engine->IsValidEngine());
	EXPECT_EQ(EngineType::WRONG, engine->GetEngineType());
}

TEST(SteeringSystemTest, BoschFunction)
{
	SteeringSystem* steeringSystem = new BOSCH();

	steeringSystem->SelectSteeringSystem();
	steeringSystem->RunSteeringSystem();

	EXPECT_EQ(steeringSystem->GetSteeringType(), SteeringSystemType::BOSCH);
}

TEST(SteeringSystemTest, MobisFunction)
{
	SteeringSystem* steeringSystem = new MOBIS();

	steeringSystem->SelectSteeringSystem();
	steeringSystem->RunSteeringSystem();

	EXPECT_EQ(steeringSystem->GetSteeringType(), SteeringSystemType::MOBIS);
}