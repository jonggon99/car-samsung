#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CLEAR_SCREEN "\033[H\033[2J"

int inputHistory[10];

enum QuestionType
{
    CarType_Q = 0,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

enum CarType
{
    SEDAN = 1,
    SUV,
    TRUCK
};

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA
};

enum brakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS
};

void selectCarType(int answer);
void selectEngine(int answer);
void selectbrakeSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
bool CheckInvalidEngine();
void PrintSteeringSystem();
void PrintBreakSystem();
void PrintEngine();
void PrintCarType();
bool TestCar();
bool TestBreakSystem();
void delay(int ms);

void delay(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}
void PrintScreen(QuestionType questionStep);
bool InputNumberInValidRange(QuestionType questionStep, int inputNumber);
QuestionType DoJob(QuestionType questionStep, int inputNumber);
bool CheckExitProgam(char  input[100]);
bool IsNotNumber(char* input);
void GetInput(char* input);
int ConvertStringToNumber(char* input);

int main()
{
    char input[100];
    QuestionType questionStep = CarType_Q;

    while (1)
    {

        PrintScreen(questionStep);
        GetInput(input);

        if (CheckExitProgam(input)) break;

        if (IsNotNumber(input)) continue;
        int inputNumber = ConvertStringToNumber(input);

        if (!InputNumberInValidRange(questionStep, inputNumber)) continue;

        questionStep = DoJob(questionStep, inputNumber);
    }
}

/*
* Car
*/
void selectCarType(int inputNumber)
{
    inputHistory[CarType_Q] = inputNumber;
    if (inputNumber == 1)
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
    if (inputNumber == 2)
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
    if (inputNumber == 3)
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
}

bool isCarTypeValidCheck()
{
    if (inputHistory[CarType_Q] == SEDAN)
    {
        if (inputHistory[brakeSystem_Q] == CONTINENTAL) return false;
    }
    if (inputHistory[CarType_Q] == SUV)
    {
        if (inputHistory[Engine_Q] == TOYOTA) return false;
    }
    if (inputHistory[CarType_Q] == TRUCK) {
        if (inputHistory[Engine_Q] == WIA) return false;
        if (inputHistory[brakeSystem_Q] == MANDO) return false;
    }
    return true;
}

void PrintCarType()
{
    if (inputHistory[CarType_Q] == 1)
        printf("Car Type : Sedan\n");
    if (inputHistory[CarType_Q] == 2)
        printf("Car Type : SUV\n");
    if (inputHistory[CarType_Q] == 3)
        printf("Car Type : Truck\n");
}

bool TestCar()
{
    if (inputHistory[CarType_Q] == SEDAN)
    {
        if (inputHistory[brakeSystem_Q] == CONTINENTAL) {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Sedan에는 Continental제동장치 사용 불가\n");
            return false;
        }
    }
    else if (inputHistory[CarType_Q] == SUV)
    {
        if (inputHistory[Engine_Q] == TOYOTA) {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("SUV에는 TOYOTA엔진 사용 불가\n");
            return false;
        }
    }
    else if (inputHistory[CarType_Q] == TRUCK)
    {
        if (inputHistory[Engine_Q] == WIA) {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 WIA엔진 사용 불가\n");
            return false;
        }
        if (inputHistory[brakeSystem_Q] == MANDO) {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 Mando제동장치 사용 불가\n");
            return false;
        }
    }
    return true;
}

/*
* ENGINE
*/
void selectEngine(int inputNumber)
{
    inputHistory[Engine_Q] = inputNumber;
    if (inputNumber == 1)
        printf("GM 엔진을 선택하셨습니다.\n");
    if (inputNumber == 2)
        printf("TOYOTA 엔진을 선택하셨습니다.\n");
    if (inputNumber == 3)
        printf("WIA 엔진을 선택하셨습니다.\n");
}

bool CheckInvalidEngine()
{
    if (inputHistory[Engine_Q] == 4)
    {
        printf("엔진이 고장나있습니다.\n");
        printf("자동차가 움직이지 않습니다.\n");
        return true;
    }
    return false;
}

void PrintEngine()
{
    if (inputHistory[Engine_Q] == 1)
        printf("Engine : GM\n");
    if (inputHistory[Engine_Q] == 2)
        printf("Engine : TOYOTA\n");
    if (inputHistory[Engine_Q] == 3)
        printf("Engine : WIA\n");
}

/*
* Break System
*/
void selectbrakeSystem(int inputNumber)
{
    inputHistory[brakeSystem_Q] = inputNumber;
    if (inputNumber == 1)
        printf("MANDO 제동장치를 선택하셨습니다.\n");
    if (inputNumber == 2)
        printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
    if (inputNumber == 3)
        printf("BOSCH 제동장치를 선택하셨습니다.\n");
}

bool isBreakSystemValidCheck()
{
    if (inputHistory[brakeSystem_Q] == BOSCH_B)
    {
        if (inputHistory[SteeringSystem_Q] != BOSCH_S) return false;
    }
    return true;
}

void PrintBreakSystem()
{
    if (inputHistory[brakeSystem_Q] == 1)
        printf("Brake System : Mando");
    if (inputHistory[brakeSystem_Q] == 2)
        printf("Brake System : Continental\n");
    if (inputHistory[brakeSystem_Q] == 3)
        printf("Brake System : Bosch\n");
}

bool TestBreakSystem()
{
    if (inputHistory[brakeSystem_Q] == BOSCH_B)
    {
        if (inputHistory[SteeringSystem_Q] != BOSCH_S) {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
            return false;
        }
    }
    return true;
}

/*
* Steering System
*/
void selectSteeringSystem(int inputNumber)
{
    inputHistory[SteeringSystem_Q] = inputNumber;
    if (inputNumber == 1)
        printf("BOSCH 조향장치를 선택하셨습니다.\n");
    if (inputNumber == 2)
        printf("MOBIS 조향장치를 선택하셨습니다.\n");
}

void PrintSteeringSystem()
{
    if (inputHistory[SteeringSystem_Q] == 1)
        printf("SteeringSystem : Bosch\n");
    if (inputHistory[SteeringSystem_Q] == 2)
        printf("SteeringSystem : Mobis\n");
}

/*
* MAIN
*/

void runProducedCar()
{
    if (isCarTypeValidCheck() == false || isBreakSystemValidCheck() == false)
    {
        printf("자동차가 동작되지 않습니다\n");
        return;
    }

    if (CheckInvalidEngine()) return;

    PrintCarType();
    PrintEngine();
    PrintBreakSystem();
    PrintSteeringSystem();

    printf("자동차가 동작됩니다.\n");
}

void testProducedCar()
{
    if (TestCar() && TestBreakSystem())
    {
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
    }
}

void PrintScreen(QuestionType questionStep)
{
    if (questionStep == CarType_Q)
    {
        printf(CLEAR_SCREEN);

        printf("        ______________\n");
        printf("       /|            | \n");
        printf("  ____/_|_____________|____\n");
        printf(" |                      O  |\n");
        printf(" '-(@)----------------(@)--'\n");
        printf("===============================\n");
        printf("어떤 차량 타입을 선택할까요?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }
    else if (questionStep == Engine_Q)
    {
        printf(CLEAR_SCREEN);
        printf("어떤 엔진을 탑재할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. 고장난 엔진\n");
    }
    else if (questionStep == brakeSystem_Q)
    {
        printf(CLEAR_SCREEN);
        printf("어떤 제동장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }
    else if (questionStep == SteeringSystem_Q)
    {
        printf(CLEAR_SCREEN);
        printf("어떤 조향장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }
    else if (questionStep == Run_Test)
    {
        printf(CLEAR_SCREEN);
        printf("멋진 차량이 완성되었습니다.\n");
        printf("어떤 동작을 할까요?\n");
        printf("0. 처음 화면으로 돌아가기\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    printf("===============================\n");

    printf("INPUT > ");
}

int ConvertStringToNumber(char* input)
{
    char* checkNumber;
    return strtol(input, &checkNumber, 10); // 문자열을 10진수로 변환
}

bool IsNotNumber(char* input)
{
    char* checkNumber;
    int inputNumber = strtol(input, &checkNumber, 10); // 문자열을 10진수로 변환

    if (*checkNumber != '\0')
    {
        printf("ERROR :: 숫자만 입력 가능\n");
        delay(800);
        return true;
    }
    return false;
}
bool InputNumberInValidRange(QuestionType questionStep, int inputNumber)
{
    if (questionStep == CarType_Q && !(inputNumber >= 1 && inputNumber <= 3))
    {
        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    if (questionStep == Engine_Q && !(inputNumber >= 0 && inputNumber <= 4))
    {
        printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    if (questionStep == brakeSystem_Q && !(inputNumber >= 0 && inputNumber <= 3))
    {
        printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    if (questionStep == SteeringSystem_Q && !(inputNumber >= 0 && inputNumber <= 2))
    {
        printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
        delay(800);
        return false;
    }

    if (questionStep == Run_Test && !(inputNumber >= 0 && inputNumber <= 2))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        delay(800);
        return false;
    }
    return true;
}

QuestionType DoJob(QuestionType questionStep, int inputNumber)
{
    // 처음으로 돌아가기
    if (inputNumber == 0 && questionStep == Run_Test)
    {
        return CarType_Q;
    }

    // 이전으로 돌아가기
    if (inputNumber == 0 && questionStep >= 1)
    {
        return (QuestionType)(questionStep - 1);
    }

    if (questionStep == CarType_Q)
    {
        selectCarType(inputNumber);
        delay(800);
        return Engine_Q;
    }
    else if (questionStep == Engine_Q)
    {
        selectEngine(inputNumber);
        delay(800);
        return brakeSystem_Q;
    }
    else if (questionStep == brakeSystem_Q)
    {
        selectbrakeSystem(inputNumber);
        delay(800);
        return SteeringSystem_Q;
    }
    else if (questionStep == SteeringSystem_Q)
    {
        selectSteeringSystem(inputNumber);
        delay(800);
        return Run_Test;
    }
    else if (questionStep == Run_Test && inputNumber == 1)
    {
        runProducedCar();
        delay(2000);
    }
    else if (questionStep == Run_Test && inputNumber == 2)
    {
        printf("Test...\n");
        delay(1500);
        testProducedCar();
        delay(2000);
    }
    return questionStep;
}

void GetInput(char* input)
{
    fgets(input, sizeof(input), stdin);

    // 엔터 개행문자 제거
    char* context = nullptr;
    strtok_s(input, "\r", &context);
    strtok_s(input, "\n", &context);
}
bool CheckExitProgam(char  input[100])
{
    if (!strcmp(input, "exit"))
    {
        printf("바이바이\n");
        return true;
    }

    return false;
}
#endif