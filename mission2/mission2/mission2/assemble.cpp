#include <assert.h>
#include <iosfwd>
#include <sstream>

#include "CarTypeFactory.h"
#include "defines.h"

#ifdef _DEBUG
#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

int userInputList[10];

void selectCarType(CarType answer);
void selectEngine(Engine engine);
void selectbrakeSystem(BrakeSystem brake);
void selectSteeringSystem(SteeringSystem steering);

void runProducedCar();
void testProducedCar();
void printCarLogo();
void printError(const char* msg);

void getUserInput(OUT char buf[100]);
bool isExitString(const char* buf);
void showMenu(QuestionType currentStep);
bool tryParseNumber(const char* buf, OUT int& result);

void clearConsole();
void delay(int ms);
void printLine();

QuestionType processUserInput(QuestionType currentStep, int userInput);
QuestionType processCarSelection(int userInput);

const char* generateCarString(CarType carType);
const char* generateEngineString(Engine engine);
const char* generateBrakeString(BrakeSystem brake);
const char* generateSteeringString(SteeringSystem steering);

const char* generatePassFailString(bool result);

CarType getCurrentUserInputCarType() { return static_cast<CarType>(userInputList[CarType_Q]); }
BrakeSystem getCurrentUserInputBrakeSystem() { return static_cast<BrakeSystem>(userInputList[BrakeSystem_Q]); }
Engine getCurrentUserInputEngine() { return static_cast<Engine>(userInputList[Engine_Q]); }
SteeringSystem getCurrentUserInputSteeringSystem() { return static_cast<SteeringSystem>(userInputList[SteeringSystem_Q]); }

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
    userInputList[CarType_Q] = static_cast<int>(answer);

    printf("차량 타입으로 ");
    printf(generateCarString(answer));
    printf("을 선택하셨습니다.\n");
}

void selectEngine(Engine engine)
{
    userInputList[Engine_Q] = engine;
    printf(generateEngineString(engine));
    printf("을 선택하셨습니다.\n");
}

void selectbrakeSystem(BrakeSystem brake)
{
    userInputList[BrakeSystem_Q] = brake;
    printf(generateBrakeString(brake));
    printf(" 제동장치를 선택하셨습니다.\n");
}

void selectSteeringSystem(SteeringSystem steering)
{
    userInputList[SteeringSystem_Q] = steering;
    printf(generateSteeringString(steering));
    printf(" 조향장치를 선택하셨습니다.\n");
}

int ValidateUserInputList()
{
    CarType userInputCarType = getCurrentUserInputCarType();                            
    BrakeSystem userInputBrakeSystem = getCurrentUserInputBrakeSystem();                
    Engine userInputEngine = getCurrentUserInputEngine();                               
    SteeringSystem userInputSteeringSystem = getCurrentUserInputSteeringSystem();

	if (userInputCarType == CarType::SEDAN)
    {
        if (userInputBrakeSystem == CONTINENTAL)
            return false;
    }

	if (userInputCarType == CarType::SUV)
	{
        if (userInputEngine == TOYOTA)
            return false;
	}

    if (userInputCarType == CarType::TRUCK)
    {
        if (userInputEngine == WIA)
            return false;

        if (userInputBrakeSystem == MANDO)
            return false;
    }

    if (userInputBrakeSystem == BOSCH_B)
    {
        if (userInputSteeringSystem != BOSCH_S)
            return false;
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
        if (getCurrentUserInputEngine() == Engine::BROKEN)
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            printf("Car Type : ");
            printf(generateCarString(getCurrentUserInputCarType()));
            printf("\n");

            printf("Engine : ");
            printf(generateEngineString(getCurrentUserInputEngine()));
            printf("\n");

            printf("Brake System  : ");
            printf(generateBrakeString(getCurrentUserInputBrakeSystem()));
            printf("\n");

            printf("SteeringSystem  : ");
            printf(generateSteeringString(getCurrentUserInputSteeringSystem()));
            printf("\n");

            printf("자동차가 동작됩니다.\n");
        }
    }
}

void testProducedCar()
{
    const CarType carType = getCurrentUserInputCarType();
    const BrakeSystem brake = getCurrentUserInputBrakeSystem();
    const Engine engine = getCurrentUserInputEngine();
    const SteeringSystem steering = getCurrentUserInputSteeringSystem();

    printf("자동차 부품 조합 테스트 결과 : ");
    if (carType == CarType::SEDAN)
    {
        if (brake == BrakeSystem::CONTINENTAL)
        {
            generatePassFailString(false);
            printf("\n");
            printf(generateCarString(carType));
            printf("에는 ");
            printf(generateBrakeString(brake));
            printf("제동장치 사용 불가\n");
        }
    }
    else if (carType == CarType::SUV)
    {
	    if (engine == TOYOTA)
	    {
            generatePassFailString(false);
            printf("\n");
            printf(generateCarString(carType));
            printf("에는 ");
            printf(generateEngineString(engine));
            printf("엔진 사용 불가\n");
	    }
    }
    else if (carType == CarType::TRUCK)
    {
        if (engine == WIA)
        {
            generatePassFailString(false);
            printf("\n");
            printf(generateCarString(carType));
            printf("에는 ");
            printf(generateEngineString(engine));
            printf("엔진 사용 불가\n");
        }
        else if (brake == MANDO)
        {
            generatePassFailString(false);
            printf("\n");
            printf(generateCarString(carType));
            printf("에는 ");
            printf(generateEngineString(engine));
            printf("제동장치 사용 불가\n");
        }
    }

    else if (brake == BOSCH_B && steering != BOSCH_S)
    {
        generatePassFailString(false);
        printf("\n");
        printf(generateBrakeString(brake));
        printf("에는 ");
        printf(generateSteeringString(steering));
        printf("조향장치 이외 사용 불가\n");
    }
    else
    {
        generatePassFailString(true);
        printf("\n");
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
    else if (currentStep == BrakeSystem_Q)
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
    const int MIN_USER_INPUT = 1;
    const int MAX_CAR_TYPE_INPUT = 3;
    const int MAX_ENGINE_INPUT = 4;
    const int MAX_BRAKE_INPUT = 3;
    const int MAX_STEERING_INPUT = 2;

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

    std::stringstream ss;
    if (currentStep == CarType_Q)
    {
        if (!(userInput >= MIN_USER_INPUT && userInput <= MAX_CAR_TYPE_INPUT))
        {
            std::stringstream ss;
            ss << "차량 타입은 " << MIN_USER_INPUT << " ~ " << MAX_CAR_TYPE_INPUT;
            ss << " 범위만 선택 가능\n";
            printError(ss.str().c_str());
            return currentStep;
        }

        selectCarType(static_cast<CarType>(userInput));
        delay(800);
        return Engine_Q;
    }
    else if (currentStep == Engine_Q)
    {
        if (!(userInput >= MIN_USER_INPUT && userInput <= MAX_ENGINE_INPUT))
        {
            ss << "엔진은 " << MIN_USER_INPUT << " ~ " << MAX_ENGINE_INPUT;
            ss << " 범위만 선택 가능\n";
            printError(ss.str().c_str());
            return currentStep;
        }

        selectEngine(static_cast<Engine>(userInput));
        delay(800);
        return BrakeSystem_Q;
    }
    else if (currentStep == BrakeSystem_Q)
    {
        if (!(userInput >= MIN_USER_INPUT && userInput <= MAX_BRAKE_INPUT))
        {
            ss << "제동장치는 " << MIN_USER_INPUT << " ~ " << MAX_BRAKE_INPUT;
            ss << " 범위만 선택 가능\n";
            printError(ss.str().c_str());
            return currentStep;
        }

        selectbrakeSystem(static_cast<BrakeSystem>(userInput));
        delay(800);
        return SteeringSystem_Q;
    }
    else if (currentStep == SteeringSystem_Q)
    {
        if (!(userInput >= MIN_USER_INPUT && userInput <= MAX_STEERING_INPUT))
        {
            ss << "조향장치는 " << MIN_USER_INPUT << " ~ " << MAX_STEERING_INPUT;
            ss << " 범위만 선택 가능\n";
            printError(ss.str().c_str());
            return currentStep;
        }

        selectSteeringSystem(static_cast<SteeringSystem>(userInput));
        delay(800);
        return Run_Test;
    }
    else if (currentStep == Run_Test)
    {
        if (userInput == RunMode::Run)
        {
            runProducedCar();
            delay(2000);
        }
        else if (userInput == RunMode::Test)
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

const char* generateCarString(CarType carType)
{
    switch (carType)
    {
    case CarType::SEDAN:
        return "Sedan";
    case CarType::SUV:
	    return "Suv";
    case CarType::TRUCK:
	    return "Truck";
    }

    return STR_UNKNOWN_STR;
}

const char* generateEngineString(Engine engine)
{
    switch (engine)
    {
    case Engine::GM:
        return "GM";
    case Engine::TOYOTA:
        return "TOYOTA";
    case Engine::WIA:
        return "WIA";
    case Engine::BROKEN:
        return "고장난 엔진";
    }

    return STR_UNKNOWN_STR;
}

const char* generateBrakeString(BrakeSystem brake)
{
    switch (brake)
    {
    case BrakeSystem::MANDO:
        return "MANDO";
    case BrakeSystem::CONTINENTAL:
        return "CONTINENTAL";
    case BrakeSystem::BOSCH_B:
        return "BOSCH_B";
    }

    return STR_UNKNOWN_STR;
}

const char* generateSteeringString(SteeringSystem steering)
{
    switch (steering)
    {
    case SteeringSystem::BOSCH_S:
        return "BOSCH_S";
    case SteeringSystem::MOBIS:
        return "MOBIS";
    }

    return STR_UNKNOWN_STR;
}

const char* generatePassFailString(bool result)
{
	return result ? "PASS" : "FAIL";
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

void clearConsole()
{
    printf(CLEAR_SCREEN);
}

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

void printLine()
{
    printf("===============================\n");
}

#endif