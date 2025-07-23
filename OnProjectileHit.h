// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OnProjectileHit.generated.h"

UCLASS()
class MODULE_TWO_STONE_API AOnProjectileHit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOnProjectileHit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

		UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

		// Additional properties and methods here if you want them
	};
