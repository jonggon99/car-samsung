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
#include "Car.h"
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

Car* car = nullptr;
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
        //selectCarType(inputNumber);
        car = CarFactory().CreateCar(inputNumber);
        delay(800);
        return Engine_Q;
    }
    else if (questionStep == Engine_Q)
    {
        //selectEngine(inputNumber);
        car->CreateEngine(inputNumber);
        delay(800);
        return brakeSystem_Q;
    }
    else if (questionStep == brakeSystem_Q)
    {
        //selectbrakeSystem(inputNumber);
        car->CreateBreakSystem(inputNumber);
        delay(800);
        return SteeringSystem_Q;
    }
    else if (questionStep == SteeringSystem_Q)
    {
        //selectSteeringSystem(inputNumber);
        car->CreateSteeringSystem(inputNumber);
        delay(800);
        return Run_Test;
    }
    else if (questionStep == Run_Test && inputNumber == 1)
    {
        //runProducedCar();
        car->RunProduce();
        delay(2000);
    }
    else if (questionStep == Run_Test && inputNumber == 2)
    {
        printf("Test...\n");
        delay(1500);
        //testProducedCar();
        car->Test();
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