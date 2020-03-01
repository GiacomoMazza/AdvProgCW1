// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GM_Trigger.generated.h"

UCLASS()
class ADVPROGCW1_API AGM_Trigger : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGM_Trigger();

	//UFUNCTION()
	//	void OnOverlapBegin2(class AActor* OverlappedActor, class AActor* OtherActor);

	//UFUNCTION()
	//	void OnOverlapEnd2(class AActor* OverlappedActor, class AActor* OtherActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
