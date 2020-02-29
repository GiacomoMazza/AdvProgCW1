// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Components/PointLightComponent.h" 
#include "GameFramework/Actor.h"
#include "TrackTile.generated.h"

UCLASS()
class ADVPROGCW1_API ATrackTile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATrackTile();

///-JT- 
///----------------------------------------------------------------------------------------------------------------------------
	// Add Root (for Transform)
	UPROPERTY()
	USceneComponent* Root;

	// Add StaticMesh Component
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	// Colliders
	UBoxComponent* EntryCollider = nullptr;
	UBoxComponent* ExitCollider = nullptr;

	// Light
	UPointLightComponent* TunnelLight = nullptr;

///----------------------------------------------------------------------------------------------------------------------------
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
