#pragma once

enum class BreakSystemType {
	NONE,
	MANDO,
	CONTINENTAL,
	BOSCH
};


class BreakSystem {
public:
	BreakSystem() : breakSystem(BreakSystemType::NONE) {}
	BreakSystem(BreakSystemType type) : breakSystem(type) {}
	virtual ~BreakSystem() {}

	void SelectEngine(void);
	void RunProduce(void);
	BreakSystemType GetBreakSystemType() { return breakSystem; }
protected:
	BreakSystemType breakSystem;
};

class BreakMANDO : public BreakSystem {
public:
	BreakMANDO() : BreakSystem(BreakSystemType::MANDO) {}
	~BreakMANDO() {}
};

class BreakCONTINENTAL : public BreakSystem {
public:
	BreakCONTINENTAL() : BreakSystem(BreakSystemType::CONTINENTAL) {}
	~BreakCONTINENTAL() {}
};

class BreakBOSCH : public BreakSystem {
public:
	BreakBOSCH() : BreakSystem(BreakSystemType::BOSCH) {}
	~BreakBOSCH() {}

};