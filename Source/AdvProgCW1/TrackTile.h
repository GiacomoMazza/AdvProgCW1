// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h" 	
#include "Components/SpotLightComponent.h"
#include "Components/PointLightComponent.h"
#include "Engine/TriggerVolume.h"
#include "GameFramework/Actor.h"
#include "TileSpawner.h"
#include "TrackTile.generated.h"

UCLASS()
class ADVPROGCW1_API ATrackTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrackTile();

	UFUNCTION()
	void OnOverlapBeginExit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); 

///-JT- 
///----------------------------------------------------------------------------------------------------------------------------
	// Add Root (for Transform)
	UPROPERTY()
	USceneComponent* Root;

	// Exposed Variable Actor (choose the Actor that will be spawned)
	UPROPERTY(EditAnywhere) 
	TSubclassOf<AActor> TileToSpawn;

	UPROPERTY(EditAnywhere) 
	UObject* TileClass = Cast<UObject>(StaticLoadObject(UObject::StaticClass(), NULL, TEXT("/Script/AdvProgCW1.TrackTile")));


	// Add StaticMesh Component
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	// Light
	UPROPERTY(EditAnywhere)
	USpotLightComponent* TunnelLight;
	UPROPERTY(EditAnywhere)
	UPointLightComponent* TunnelPointLight;

	// // Box Collider
	UPROPERTY(EditAnywhere)
	class UBoxComponent* EntryCollider;
	UPROPERTY(EditAnywhere)
	class UBoxComponent* ExitCollider;

	// Tile Spawner
	UPROPERTY(EditAnywhere)
	class UTileSpawner* TileSpawner;
	
	// Tile Length Parameter
	UPROPERTY(EditAnywhere) 
	float TileLength = 2500;

///----------------------------------------------------------------------------------------------------------------------------
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult); 

	UFUNCTION()
	void SpawnObject();



};
