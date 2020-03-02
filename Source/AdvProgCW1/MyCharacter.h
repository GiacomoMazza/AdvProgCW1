// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UStaticMeshComponent;
UCLASS()
class ADVPROGCW1_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	//Modified by Giacomo Mazza (added bool)
	bool bl_IsGameOver = false;

	//speed which the character moves at
	UPROPERTY(VisibleAnywhere, Category = "Player")
	float runSpeed = 60;

	//stopping the user move in the same direction again
	UPROPERTY(VisibleAnywhere, Category = "Player")
	float prevVal = 0;
	
	//score
	UPROPERTY(VisibleAnywhere, Category = "Player")
	float score = 0;
	//points added to score
	UPROPERTY(VisibleAnywhere, Category = "Player")
	float points = 5;

	//how much you move in the right axis
	float move= 0;
	//create the camera boon, the camera and the mesh for the character
	//with properties the properties of being visible anywhere and categorising them
	UPROPERTY(VisibleAnywhere, Category = "Camera")
		USpringArmComponent* springArmComp;
	UPROPERTY(VisibleAnywhere, Category = "Camera")
		UCameraComponent* cameraComp;
	UPROPERTY(VisibleAnywhere, Category = "Player")
		UStaticMeshComponent* meshComp;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
	void MoveRight(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Modified by Giacomo Mazza.
	void AddScore(float fl_ScoreAdded);
	//Modified by Giacomo Mazza.
};
