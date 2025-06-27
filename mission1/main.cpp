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
        printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
    if (inputNumber == 2)
        printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
    if (inputNumber == 3)
        printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
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
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Sedan���� Continental������ġ ��� �Ұ�\n");
            return false;
        }
    }
    else if (inputHistory[CarType_Q] == SUV)
    {
        if (inputHistory[Engine_Q] == TOYOTA) {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("SUV���� TOYOTA���� ��� �Ұ�\n");
            return false;
        }
    }
    else if (inputHistory[CarType_Q] == TRUCK)
    {
        if (inputHistory[Engine_Q] == WIA) {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� WIA���� ��� �Ұ�\n");
            return false;
        }
        if (inputHistory[brakeSystem_Q] == MANDO) {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� Mando������ġ ��� �Ұ�\n");
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
        printf("GM ������ �����ϼ̽��ϴ�.\n");
    if (inputNumber == 2)
        printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
    if (inputNumber == 3)
        printf("WIA ������ �����ϼ̽��ϴ�.\n");
}

bool CheckInvalidEngine()
{
    if (inputHistory[Engine_Q] == 4)
    {
        printf("������ ���峪�ֽ��ϴ�.\n");
        printf("�ڵ����� �������� �ʽ��ϴ�.\n");
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
        printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
    if (inputNumber == 2)
        printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
    if (inputNumber == 3)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
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
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
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
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
    if (inputNumber == 2)
        printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
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
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
        return;
    }

    if (CheckInvalidEngine()) return;

    PrintCarType();
    PrintEngine();
    PrintBreakSystem();
    PrintSteeringSystem();

    printf("�ڵ����� ���۵˴ϴ�.\n");
}

void testProducedCar()
{
    if (TestCar() && TestBreakSystem())
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
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
        printf("� ���� Ÿ���� �����ұ��?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }
    else if (questionStep == Engine_Q)
    {
        printf(CLEAR_SCREEN);
        printf("� ������ ž���ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. ���峭 ����\n");
    }
    else if (questionStep == brakeSystem_Q)
    {
        printf(CLEAR_SCREEN);
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }
    else if (questionStep == SteeringSystem_Q)
    {
        printf(CLEAR_SCREEN);
        printf("� ������ġ�� �����ұ��?\n");
        printf("0. �ڷΰ���\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }
    else if (questionStep == Run_Test)
    {
        printf(CLEAR_SCREEN);
        printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
        printf("� ������ �ұ��?\n");
        printf("0. ó�� ȭ������ ���ư���\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    printf("===============================\n");

    printf("INPUT > ");
}

int ConvertStringToNumber(char* input)
{
    char* checkNumber;
    return strtol(input, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ
}

bool IsNotNumber(char* input)
{
    char* checkNumber;
    int inputNumber = strtol(input, &checkNumber, 10); // ���ڿ��� 10������ ��ȯ

    if (*checkNumber != '\0')
    {
        printf("ERROR :: ���ڸ� �Է� ����\n");
        delay(800);
        return true;
    }
    return false;
}
bool InputNumberInValidRange(QuestionType questionStep, int inputNumber)
{
    if (questionStep == CarType_Q && !(inputNumber >= 1 && inputNumber <= 3))
    {
        printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
        delay(800);
        return false;
    }

    if (questionStep == Engine_Q && !(inputNumber >= 0 && inputNumber <= 4))
    {
        printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
        delay(800);
        return false;
    }

    if (questionStep == brakeSystem_Q && !(inputNumber >= 0 && inputNumber <= 3))
    {
        printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
        delay(800);
        return false;
    }

    if (questionStep == SteeringSystem_Q && !(inputNumber >= 0 && inputNumber <= 2))
    {
        printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
        delay(800);
        return false;
    }

    if (questionStep == Run_Test && !(inputNumber >= 0 && inputNumber <= 2))
    {
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
        delay(800);
        return false;
    }
    return true;
}

QuestionType DoJob(QuestionType questionStep, int inputNumber)
{
    // ó������ ���ư���
    if (inputNumber == 0 && questionStep == Run_Test)
    {
        return CarType_Q;
    }

    // �������� ���ư���
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

    // ���� ���๮�� ����
    char* context = nullptr;
    strtok_s(input, "\r", &context);
    strtok_s(input, "\n", &context);
}
bool CheckExitProgam(char  input[100])
{
    if (!strcmp(input, "exit"))
    {
        printf("���̹���\n");
        return true;
    }

    return false;
}
#endif