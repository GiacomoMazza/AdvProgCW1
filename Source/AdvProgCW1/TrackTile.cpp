// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "TrackTile.h"

// Sets default values
ATrackTile::ATrackTile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	///-JT- 
	/// Constructor
	///----------------------------------------------------------------------------------------------------------------------------
		// Default SubObject
		Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
		// Transform
		RootComponent = Root;

		// Static Mesh Creation + Attach to Root
		Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TrackTile_SM"));
		Mesh->AttachTo(Root);
		
		// TunnelLights
		TunnelLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight_L"));
		TunnelLight->SetIntensity(1000000.f); 
		TunnelLight->SetOuterConeAngle(65.f);
		TunnelLight->SetAttenuationRadius(2000.f);
		TunnelLight->SetRelativeRotation(FRotator(-90.f, 0.f, 0.f));
		TunnelLight->SetRelativeLocation(FVector(2000.f, 0.f, 800.f));
		TunnelLight->AttachTo(Root);
		TunnelPointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight_L"));
		TunnelPointLight->SetIntensity(100000.f); 
		TunnelPointLight->SetRelativeLocation(FVector(2000.f, 0.f, 750.f));
		TunnelPointLight->AttachTo(Root);
		
		///-------------------------------------------
		// OBJECT FINDER
		static ConstructorHelpers::FObjectFinder<UStaticMesh>TrackTileAssetA(TEXT
		("/Game/Models/TrackTile_01.TrackTile_01"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>TrackTileAssetB(TEXT
		("/Game/Models/TrackTile_02.TrackTile_02"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>TrackTileAssetC(TEXT
		("/Game/Models/TrackTile_03.TrackTile_03"));
		static ConstructorHelpers::FObjectFinder<UStaticMesh>TrackTileAssetD(TEXT
		("/Game/Models/TrackTile_04.TrackTile_04"));

		// Check if Model Exists and Assign based on Rnd Seed
		int32 Seed = FMath::RandRange(1, 4);

		if(TrackTileAssetA.Succeeded() && TrackTileAssetB.Succeeded() && TrackTileAssetC.Succeeded() && TrackTileAssetD.Succeeded())
		if (Seed == 1)
				Mesh->SetStaticMesh(TrackTileAssetA.Object);
		else if (Seed == 2)
				Mesh->SetStaticMesh(TrackTileAssetB.Object);
		else if (Seed == 3)
				Mesh->SetStaticMesh(TrackTileAssetC.Object);
		else if (Seed == 4)
				Mesh->SetStaticMesh(TrackTileAssetD.Object);
		else
			UE_LOG(LogTemp, Error, TEXT("TILE MESH NOT FOUND - Attached to TrackTile Class - Attempted Spawn by TileSpawner"));
		///-------------------------------------------
		

		// Create Colliders (Entry + Exit)
		// EntryCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Entry Collider"));
	///----------------------------------------------------------------------------------------------------------------------------
	

}

// Called when the game starts or when spawned
void ATrackTile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrackTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

