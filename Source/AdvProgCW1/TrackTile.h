// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h" 	
#include "Components/SpotLightComponent.h"
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

	// Light
	UPROPERTY(EditAnywhere)
	USpotLightComponent* TunnelLight;
	UPROPERTY(EditAnywhere)
	UPointLightComponent* TunnelPointLight;

	// Box Collider
	UPROPERTY(EditAnywhere)
	UBoxComponent* EntryCollider;

///----------------------------------------------------------------------------------------------------------------------------
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
