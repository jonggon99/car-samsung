#pragma once
enum class SteeringSystemType {
	NONE,
	BOSCH,
	MOBIS
};

class SteeringSystem {
public:
	SteeringSystem() :steeringType(SteeringSystemType::NONE) {}
	virtual ~SteeringSystem() {}

	virtual void SelectSteeringSystem(void) = 0;
	virtual void RunSteeringSystem(void) = 0;
	SteeringSystemType GetSteeringType() { return steeringType; }
protected:
	SteeringSystemType steeringType;
};

class BOSCH : public SteeringSystem {
public:
	void SelectSteeringSystem(void) override;
	void RunSteeringSystem(void) override;
};

class MOBIS : public SteeringSystem {
public:
	void SelectSteeringSystem(void) override;
	void RunSteeringSystem(void) override;
};