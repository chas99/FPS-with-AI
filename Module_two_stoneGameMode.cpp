// Copyright Epic Games, Inc. All Rights Reserved.

#include "Module_two_stoneGameMode.h"
#include "Module_two_stoneHUD.h"
#include "Module_two_stoneCharacter.h"
#include "UObject/ConstructorHelpers.h"

AModule_two_stoneGameMode::AModule_two_stoneGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AModule_two_stoneHUD::StaticClass();
}
