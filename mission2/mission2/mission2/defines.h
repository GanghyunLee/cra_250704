#pragma once

#define OUT
#define CLEAR_SCREEN "\033[H\033[2J"

#define STR_UNKNOWN_STR "Unknown"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    BrakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS,
};

enum RunMode
{
	Run = 1,
    Test = 2,
};