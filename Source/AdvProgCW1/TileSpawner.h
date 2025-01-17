// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h" 
#include "Engine/TriggerVolume.h"
#include "GameFramework/Actor.h"
#include "TileSpawner.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ADVPROGCW1_API UTileSpawner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTileSpawner();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	

	///-JT- 
	///----------------------------------------------------------------------------------------------------------------------------
	// Add Root (for Transform)
	
	// Exposed Variable Actor (choose the Actor that will be spawned)
	UPROPERTY(EditAnywhere) 
	TSubclassOf<UObject> ActorToSpawn;
	
	UPROPERTY(EditAnywhere) 
	UObject* TileClass = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Script/AdvProgCW1.TrackTile")));



	// Tile Length Parameter
	UPROPERTY(EditAnywhere) 
	float TileLength = 2500;

	///----------------------------------------------------------------------------------------------------------------------------



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:

	///-JT- 
	///----------------------------------------------------------------------------------------------------------------------------
	/// Function that will handle the Object Spawning
	UFUNCTION()
	void SpawnObject();
	bool NextTileSpawned = false;

	///----------------------------------------------------------------------------------------------------------------------------
		
};
