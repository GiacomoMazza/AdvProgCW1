// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GM_TriggerBox.h"
#include "MyCharacter.h"
#include "GM_TriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class ADVPROGCW1_API AGM_TriggerBox : public ATriggerBox
{	
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	AGM_TriggerBox();

	//Offset of trigger's location
	UPROPERTY(EditAnywhere)
	float fl_Offset = 100.f;

	//Is the offset negative or positive?
	bool bl_PosOffset = true;

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	/*UPROPERTY()
		class AMyCharacter* MyClass;*/

	//Number of times the trigger has been hit
	UPROPERTY(VisibleAnywhere)
		int in_Packages = 0;

	//The new location the trigger will be spawned at
	UPROPERTY(EditAnywhere, Category = Location)
		FVector NewLocation;

	//The new rotation the trigger will be spawned at (implemented if endless runner has curves)
	UPROPERTY(EditAnywhere, Category = Location)
		FQuat NewRotation;

	//The distance the trigger is instantiated forward starting from the player's location
	UPROPERTY(EditAnywhere, Category = Location)
		float fl_Distance = 300.0;
};

//Made by Giacomo Mazza.
