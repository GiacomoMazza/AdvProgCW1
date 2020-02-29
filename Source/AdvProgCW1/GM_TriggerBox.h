// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GM_TriggerBox.h"
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

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
};

//Made by Giacomo Mazza.
