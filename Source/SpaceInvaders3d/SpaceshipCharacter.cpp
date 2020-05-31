// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceshipCharacter.h"
#include "Engine/World.h"
#include "Engine.h"
#include "AsteroidActor.h"

// Sets default values
ASpaceshipCharacter::ASpaceshipCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpaceshipCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceshipCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceshipCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASpaceshipCharacter::FireWeapon()
{
	FHitResult hit = InstantShot();
	AAsteroidActor* hitActor = Cast<AAsteroidActor>(hit.Actor);
	if (hitActor && hitActor->isAttackable)
	{
		hitActor->TakeAttack();
	}
}

int ASpaceshipCharacter::GetScore()
{
	return currentScore;
}

void ASpaceshipCharacter::SetScore(int score)
{
	currentScore = score;
}

// InstantShot
FHitResult ASpaceshipCharacter::InstantShot()
{
	FVector rayLocation;
	FRotator rayRotation;
	FVector endTrace = FVector::ZeroVector;

	APlayerController* const playerController = GetWorld()->GetFirstPlayerController();
	if (playerController)
	{
		playerController->GetPlayerViewPoint(rayLocation, rayRotation);
		endTrace = rayLocation + (rayRotation.Vector() * weaponRange);
	}

	FCollisionQueryParams traceParams(SCENE_QUERY_STAT(instantShot), true);
	FHitResult hit(ForceInit);
	GetWorld()->LineTraceSingleByChannel(hit, rayLocation, endTrace, ECC_Visibility, traceParams);
	DrawDebugLine(GetWorld(), rayLocation, endTrace, FColor(255, 0, 0));

	return hit;
}

