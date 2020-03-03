// Fill out your copyright notice in the Description page of Project Settings.


#include "Engine/World.h"
#include "Components/SceneComponent.h"
#include "TrackTile.h"
#include "TileSpawner.h"


// Sets default values for this component's properties
UTileSpawner::UTileSpawner()
{	
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UTileSpawner::BeginPlay()
{
	Super::BeginPlay(); 
}


// Called every frame
void UTileSpawner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


///-JT- 
/// Spawner Function 
///----------------------------------------------------------------------------------------------------------------------------
void UTileSpawner::SpawnObject()
{	

	// Get CurrentTile Position
	FVector CurrentTilePosition = GetOwner()->GetActorLocation();
	// Calculate position of spawned Tile (currentTile X + TileLength)
	FVector SpawnPosition = FVector(CurrentTilePosition.X + TileLength, CurrentTilePosition.Y, CurrentTilePosition.Z);
	FRotator SpawnRotation = GetOwner()->GetActorRotation();

	// Spawn Parameters
	FActorSpawnParameters SpawnParameters;
	// Spawn Actor at specified Position
	AActor* SpawnedActorRef = GetWorld()->SpawnActor<AActor>(ActorToSpawn, SpawnPosition, SpawnRotation);


	// DEBUG LOG (Optional)
	UE_LOG(LogTemp, Warning, TEXT("TILE SPAWNED AT: %s"), *SpawnPosition.ToString());
}
///----------------------------------------------------------------------------------------------------------------------------
