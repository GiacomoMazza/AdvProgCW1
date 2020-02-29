// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/StaticMeshComponent.h"
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

		// Add Light
		// if (TunnelLight != nullptr)
		// {
		// 	TunnelLight = CreateDefaultSubobject<ULightComponent>(TEXT("Point Light"));
		// 	TunnelLight->AttachTo(Root);
		// }
		
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
		if (EntryCollider == nullptr)
		{
			EntryCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("Entry Collider"));
			EntryCollider->AttachTo(Root);
		};
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

