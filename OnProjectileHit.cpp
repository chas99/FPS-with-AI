// Fill out your copyright notice in the Description page of Project Settings.


#include "OnProjectileHit.h"

// Sets default values
AOnProjectileHit::AOnProjectileHit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOnProjectileHit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Set up the projectile properties here, e.g.movement component, collider, etc.

void AOnProjectileHit::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics body
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		const float ImpulseStrength = 100.0f; // Could be a variable or property to adjust in the editor
		OtherComp->AddImpulseAtLocation(GetVelocity() * ImpulseStrength, GetActorLocation());
		Destroy();
	}
}
// Called every frame
void AOnProjectileHit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

