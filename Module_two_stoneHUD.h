// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Module_two_stoneHUD.generated.h"

UCLASS()
class AModule_two_stoneHUD : public AHUD
{
	GENERATED_BODY()

public:
	AModule_two_stoneHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

