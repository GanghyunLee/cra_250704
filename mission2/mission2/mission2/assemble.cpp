#include <assert.h>
#include <iosfwd>
#include <sstream>

#include "BrakeSystemFactory.h"
#include "CarRunner.h"
#include "CarTypeFactory.h"
#include "defines.h"
#include "EngineFactory.h"
#include "SteeringSystemFactory.h"

#ifdef _DEBUG
#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}

#else

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    BrakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

enum RunMode
{
    Run = 1,
    Test = 2,
};

struct SelectedValueDto
{
    std::shared_ptr<AbstractCarType> selectedCarType = nullptr;
    std::shared_ptr<AbstractBrakeSystem> selectedBrakeSystem = nullptr;
    std::shared_ptr<AbstractEngine> selectedEngine = nullptr;
    std::shared_ptr<AbstractSteering> selectedSteering = nullptr;
};
SelectedValueDto selectedValueDto{};

void selectCarType(CarType answer);
void selectEngine(Engine engine);
void selectbrakeSystem(BrakeSystem brake);
void selectSteeringSystem(SteeringSystem steering);

void runProducedCar(std::shared_ptr<Car> car);
void testProducedCar(std::shared_ptr<Car> car);
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
const char* generatePassFailString(bool result);

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

    std::stringstream ss;
    if (currentStep == CarType_Q)
    {
        if (false == CarTypeFactory::ValidateUserInputIndex(userInput))
        {
            std::stringstream ss;
            ss << "차량 타입은 " << CarTypeFactory::GetMinInput() << " ~ " << CarTypeFactory::GetMaxInput()
                << " 범위만 선택 가능\n";
            printError(ss.str().c_str());
            return currentStep;
        }

        selectCarType(static_cast<CarType>(userInput));
    	delay(800);
        return Engine_Q;
    }
    else if (currentStep == Engine_Q)
    {
        if (false == EngineFactory::ValidateUserInputIndex(userInput))
        {
            ss << "엔진은 " << EngineFactory::GetMinInput() << " ~ " << EngineFactory::GetMaxInput();
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
        if (false == BrakeSystemFactory::ValidateUserInputIndex(userInput))
        {
            std::stringstream ss;
            ss << "제동장치는 " << BrakeSystemFactory::GetMinInput() << " ~ " << BrakeSystemFactory::GetMaxInput()
                << " 범위만 선택 가능\n";
            printError(ss.str().c_str());
            return currentStep;
        }

        selectbrakeSystem(static_cast<BrakeSystem>(userInput));
        delay(800);
        return SteeringSystem_Q;
    }
    else if (currentStep == SteeringSystem_Q)
    {
        if (false == SteeringSystemFactory::ValidateUserInputIndex(userInput))
        {
            ss << "조향장치는 " << SteeringSystemFactory::GetMinInput() << " ~ " << SteeringSystemFactory::GetMaxInput();
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
        std::shared_ptr<Car> car = std::make_shared<Car>(
            selectedValueDto.selectedCarType,
            selectedValueDto.selectedBrakeSystem,
            selectedValueDto.selectedEngine,
            selectedValueDto.selectedSteering
        );

        if (userInput == RunMode::Run)
        {
            runProducedCar(car);
            delay(2000);
        }
        else if (userInput == RunMode::Test)
        {
            printf("Test...\n");
            delay(1500);
            testProducedCar(car);
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


void selectCarType(CarType answer)
{
    selectedValueDto.selectedCarType = CarTypeFactory::CreateCarType(answer);

    std::stringstream ss;
    ss << selectedValueDto.selectedCarType->GetComponentName() << "으로 " <<
        selectedValueDto.selectedCarType->GetCarTypeName() << "을 선택하셨습니다.\n";
    printf(ss.str().c_str());
}

void selectEngine(Engine answer)
{
    selectedValueDto.selectedEngine = EngineFactory::CreateEngine(answer);

    std::stringstream ss;
    ss << selectedValueDto.selectedEngine->GetComponentName() << "을 선택하셨습니다.\n";
    printf(ss.str().c_str());
}

void selectbrakeSystem(BrakeSystem brake)
{
    selectedValueDto.selectedBrakeSystem = BrakeSystemFactory::CreateBrakeSystem(brake);

    std::stringstream ss;
    ss << selectedValueDto.selectedBrakeSystem->GetBrakeSystemName() << " "
        << selectedValueDto.selectedBrakeSystem->GetComponentName() << "를 선택하셨습니다.\n";
    printf(ss.str().c_str());
}

void selectSteeringSystem(SteeringSystem steering)
{
    selectedValueDto.selectedSteering = SteeringSystemFactory::CreateSteering(steering);

    std::stringstream ss;
    ss << selectedValueDto.selectedSteering->GetSteeringName() << " "
        << selectedValueDto.selectedSteering->GetComponentName() << "를 선택하셨습니다.\n";
    printf(ss.str().c_str());
}

void runProducedCar(std::shared_ptr<Car> car)
{
    CarRunner carRunner{car};

    try
    {
        carRunner.ValidateCar();
        printf(carRunner.RunCar().c_str());
    }
    catch (const std::exception& e)
    {
        printf("자동차가 동작되지 않습니다\n");
    }
}

void testProducedCar(std::shared_ptr<Car> car)
{
    CarRunner carRunner{ car };

    try
    {
        printf("자동차 부품 조합 테스트 결과 : ");
        carRunner.ValidateCar();

        printf(generatePassFailString(true));
    }
    catch (const std::exception& e)
    {
        printf(generatePassFailString(false));
        printf("\n");
        printf(e.what());
        
    }
    printf("\n");
}

void printCarLogo()
{
    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
}

void printError(std::string& msg)
{
    printf("ERROR :: ");
    printf(msg.c_str());
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

void printError(const char* msg)
{
    printf("ERROR :: ");
    printf(msg);
    delay(800);
}

#endif