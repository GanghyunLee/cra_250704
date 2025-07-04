#include <assert.h>

#include "defines.h"
#include "utils.h"

#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

int userInputList[10];

void selectCarType(int answer);
void selectEngine(int answer);
void selectbrakeSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
void testProducedCar();
void printCarLogo();
void printError(const char* msg);

void getUserInput(OUT char buf[100]);
bool isExitString(const char* buf);
void showMenu(QuestionType currentStep);
bool tryParseNumber(const char* buf, OUT int& result);

QuestionType processUserInput(QuestionType currentStep, int userInput);
QuestionType processCarSelection(int userInput);

int main()
{
    char buf[100];
    QuestionType currentStep = CarType_Q;

    while (true)
    {
        showMenu(currentStep);
        getUserInput(OUT buf);

        if (isExitString(buf))
        {
            printf("바이바이\n");
            break;
        }

        int answer = 0;
        if (false == tryParseNumber(buf, OUT answer))
        {
	        printError("숫자만 입력 가능\n");
            continue;
        }

        currentStep = processUserInput(currentStep, answer);
    }
}

void selectCarType(CarType answer)
{
    userInputList[CarType_Q] = answer;
    
    if (answer == 1)
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
    if (answer == 2)
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
    if (answer == 3)
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
}

void selectEngine(int answer)
{
    userInputList[Engine_Q] = answer;
    if (answer == 1)
        printf("GM 엔진을 선택하셨습니다.\n");
    if (answer == 2)
        printf("TOYOTA 엔진을 선택하셨습니다.\n");
    if (answer == 3)
        printf("WIA 엔진을 선택하셨습니다.\n");
}

void selectbrakeSystem(int answer)
{
    userInputList[brakeSystem_Q] = answer;
    if (answer == 1)
        printf("MANDO 제동장치를 선택하셨습니다.\n");
    if (answer == 2)
        printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
    if (answer == 3)
        printf("BOSCH 제동장치를 선택하셨습니다.\n");
}

void selectSteeringSystem(int answer)
{
    userInputList[SteeringSystem_Q] = answer;
    if (answer == 1)
        printf("BOSCH 조향장치를 선택하셨습니다.\n");
    if (answer == 2)
        printf("MOBIS 조향장치를 선택하셨습니다.\n");
}

int ValidateUserInputList()
{
    if (userInputList[CarType_Q] == SEDAN && userInputList[brakeSystem_Q] == CONTINENTAL)
    {
        return false;
    }
    else if (userInputList[CarType_Q] == SUV && userInputList[Engine_Q] == TOYOTA)
    {
        return false;
    }
    else if (userInputList[CarType_Q] == TRUCK && userInputList[Engine_Q] == WIA)
    {
        return false;
    }
    else if (userInputList[CarType_Q] == TRUCK && userInputList[brakeSystem_Q] == MANDO)
    {
        return false;
    }
    else if (userInputList[brakeSystem_Q] == BOSCH_B && userInputList[SteeringSystem_Q] != BOSCH_S)
    {
        return false;
    }
    else
    {
        return true;
    }
    return true;
}

void runProducedCar()
{
    if (ValidateUserInputList() == false)
    {
        printf("자동차가 동작되지 않습니다\n");
    }
    else
    {
        if (userInputList[Engine_Q] == 4)
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            if (userInputList[CarType_Q] == 1)
                printf("Car Type : Sedan\n");
            if (userInputList[CarType_Q] == 2)
                printf("Car Type : SUV\n");
            if (userInputList[CarType_Q] == 3)
                printf("Car Type : Truck\n");
            if (userInputList[Engine_Q] == 1)
                printf("Engine : GM\n");
                printf("Engine : GM\n");
            if (userInputList[Engine_Q] == 2)
                printf("Engine : TOYOTA\n");
            if (userInputList[Engine_Q] == 3)
                printf("Engine : WIA\n");
            if (userInputList[brakeSystem_Q] == 1)
                printf("Brake System : Mando");
            if (userInputList[brakeSystem_Q] == 2)
                printf("Brake System : Continental\n");
            if (userInputList[brakeSystem_Q] == 3)
                printf("Brake System : Bosch\n");
            if (userInputList[SteeringSystem_Q] == 1)
                printf("SteeringSystem : Bosch\n");
            if (userInputList[SteeringSystem_Q] == 2)
                printf("SteeringSystem : Mobis\n");

            printf("자동차가 동작됩니다.\n");
        }
    }
}

void testProducedCar()
{
    if (userInputList[CarType_Q] == SEDAN && userInputList[brakeSystem_Q] == CONTINENTAL)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
    }
    else if (userInputList[CarType_Q] == SUV && userInputList[Engine_Q] == TOYOTA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
    }
    else if (userInputList[CarType_Q] == TRUCK && userInputList[Engine_Q] == WIA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
    }
    else if (userInputList[CarType_Q] == TRUCK && userInputList[brakeSystem_Q] == MANDO)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
    }
    else if (userInputList[brakeSystem_Q] == BOSCH_B && userInputList[SteeringSystem_Q] != BOSCH_S)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
    }
    else
    {
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
    }
}

void printCarLogo()
{
    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
}

void printError(const char* msg)
{
    printf("ERROR :: ");
    printf(msg);
    delay(800);
}

bool isExitString(const char* buf)
{
    return !strcmp(buf, "exit");
}

void showMenu(QuestionType currentStep)
{
    clearConsole();

    if (currentStep == CarType_Q)
    {
        printCarLogo();
        printLine();
        printf("어떤 차량 타입을 선택할까요?\n");
        printf("1. Sedan\n");
        printf("2. SUV\n");
        printf("3. Truck\n");
    }
    else if (currentStep == Engine_Q)
    {
        printf("어떤 엔진을 탑재할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. GM\n");
        printf("2. TOYOTA\n");
        printf("3. WIA\n");
        printf("4. 고장난 엔진\n");
    }
    else if (currentStep == brakeSystem_Q)
    {
        printf("어떤 제동장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. MANDO\n");
        printf("2. CONTINENTAL\n");
        printf("3. BOSCH\n");
    }
    else if (currentStep == SteeringSystem_Q)
    {
        printf("어떤 조향장치를 선택할까요?\n");
        printf("0. 뒤로가기\n");
        printf("1. BOSCH\n");
        printf("2. MOBIS\n");
    }
    else if (currentStep == Run_Test)
    {
        printf("멋진 차량이 완성되었습니다.\n");
        printf("어떤 동작을 할까요?\n");
        printf("0. 처음 화면으로 돌아가기\n");
        printf("1. RUN\n");
        printf("2. Test\n");
    }
    printLine();
}

bool tryParseNumber(const char* buf, OUT int& result)
{
    char* ptrForCheckNumber;
    result = strtol(buf, &ptrForCheckNumber, 10);

    return *ptrForCheckNumber == '\0'; // 숫자여야 한다.
}

QuestionType processUserInput(QuestionType currentStep, int userInput)
{
    if (userInput == 0)
    {
        // 처음으로 돌아가기
        if (currentStep == Run_Test)
			return CarType_Q;
        else
        {
            // 이전으로 돌아가기
            return static_cast<QuestionType>(static_cast<int>(currentStep) - 1);
        }
    }

    if (currentStep == CarType_Q)
    {
        if (!(userInput >= 1 && userInput <= 3))
        {
            printError("차량 타입은 1 ~ 3 범위만 선택 가능\n");
            return currentStep;
        }

        selectCarType(userInput);
        delay(800);
        return Engine_Q;
    }
    else if (currentStep == Engine_Q)
    {
        if (!(userInput >= 1 && userInput <= 4))
        {
	        printError("엔진은 1 ~ 4 범위만 선택 가능\n");
            return currentStep;
        }

        selectEngine(userInput);
        delay(800);
        return brakeSystem_Q;
    }
    else if (currentStep == brakeSystem_Q)
    {
        if (!(userInput >= 1 && userInput <= 3))
        {
	        printError("제동장치는 1 ~ 3 범위만 선택 가능\n");
            return currentStep;
        }

        selectbrakeSystem(userInput);
        delay(800);
        return SteeringSystem_Q;
    }
    else if (currentStep == SteeringSystem_Q)
    {
        if (!(userInput >= 1 && userInput <= 2))
        {
	        printError("조향장치는 1 ~ 2 범위만 선택 가능\n");
            return currentStep;
        }

        selectSteeringSystem(userInput);
        delay(800);
        return Run_Test;
    }
    else if (currentStep == Run_Test)
    {
        if (userInput == 1)
        {
            runProducedCar();
            delay(2000);
        }
        else if (userInput == 2)
        {
            printf("Test...\n");
            delay(1500);
            testProducedCar();
            delay(2000);
        }
        else
        {
            printError("Run 또는 Test 중 하나를 선택 필요\n");
        }

        return currentStep;
    }

    return currentStep;
}

void getUserInput(OUT char buf[100])
{
    printf("INPUT > ");
    fgets(buf, sizeof(buf), stdin);

    // 엔터 개행문자 제거
    char* context = nullptr;
    strtok_s(buf, "\r", &context);
    strtok_s(buf, "\n", &context);
}

#endif
