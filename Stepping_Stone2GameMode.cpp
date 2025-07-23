// Copyright Epic Games, Inc. All Rights Reserved.

#include "Stepping_Stone2GameMode.h"
#include "Stepping_Stone2Character.h"
#include "UObject/ConstructorHelpers.h"

AStepping_Stone2GameMode::AStepping_Stone2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
