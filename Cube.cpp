// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.


#include "Cube.h"
#include "Kismet/GameplayStatics.h"
#include "Module_two_stoneProjectile.h"

#define PrintString(String) GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::White,String)

// Sets default values
ACube::ACube()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	DamagedCubeMaterial = CreateDefaultSubobject<UMaterialInstance>(TEXT("DamageMaterial"));
	CubeMaterial = CreateDefaultSubobject<UMaterialInstance>(TEXT("CubeMaterial"));

	CubeMesh->SetSimulatePhysics(true);

}

// Called when the game starts or when spawned
void ACube::BeginPlay()
{
 
        Super::BeginPlay();
        CubeMesh->OnComponentHit.AddDynamic(this, &ACube::OnComponentHit);
}

 // Called every frame
 void ACube::Tick(float DeltaTime)
 {
      Super::Tick(DeltaTime);

 }

 void ACube::OnComponentHit(UPrimitiveComponent * HitComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, FVector NormalImpulse, const FHitResult & Hit)
 {

     if (AModule_two_stoneProjectile* HitActor = Cast<AModule_two_stoneProjectile>(OtherActor))
     {
         UGameplayStatics::ApplyDamage(this, 20.0f, nullptr, OtherActor, UDamageType::StaticClass());
         OnTakeDamage();
     }
 }

void ACube::OnTakeDamage()
{
     CubeMesh->SetMaterial(0, DamagedCubeMaterial);
     GetWorld()->GetTimerManager().SetTimer(DamageTimer, this, &ACube::ResetDamage, 1.5f, false);
}

void ACube::ResetDamage()
{
    CubeMesh->SetMaterial(0, CubeMaterial);
}

    