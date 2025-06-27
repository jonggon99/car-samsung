#pragma once
enum class EngineType {
	NONE,
	GM,
	TOYOTA,
	WIA,
	WRONG
};

class Engine {
public:
	Engine() :engineType(EngineType::NONE) {}
	Engine(EngineType type) :engineType(type) {}
	virtual ~Engine() {}

	virtual void SelectEngine(void);
	virtual void RunEngine(void);
	bool IsValidEngine(void);

	EngineType GetEngineType() { return engineType; }
protected:
	EngineType engineType;
};

class GM : public Engine {
public:
	GM() : Engine(EngineType::GM){}
};

class TOYOTA : public Engine {
public:
	TOYOTA() : Engine(EngineType::TOYOTA) {}
};

class WIA : public Engine {
public:
	WIA() : Engine(EngineType::WIA) {}
};

class WRONG : public Engine {
public:
	WRONG() : Engine(EngineType::WRONG) {}
	void SelectEngine(void) override;
	void RunEngine(void) override;
};