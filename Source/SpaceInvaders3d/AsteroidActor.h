// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AsteroidActor.generated.h"

UCLASS()
class SPACEINVADERS3D_API AAsteroidActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAsteroidActor();

	UFUNCTION(BlueprintImplementableEvent, Category = "Attack")
		void OnTakeAttack();

	UPROPERTY(EditAnywhere, Category = "Attack")
		bool isAttackable{ true };

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void TakeAttack();

};
