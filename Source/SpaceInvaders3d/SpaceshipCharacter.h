// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpaceshipCharacter.generated.h"

UCLASS()
class SPACEINVADERS3D_API ASpaceshipCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASpaceshipCharacter();

	UPROPERTY(EditAnywhere, Category = "Weapon")
		float weaponRange{ 1000 };

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void FireWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	FHitResult InstantShot();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
