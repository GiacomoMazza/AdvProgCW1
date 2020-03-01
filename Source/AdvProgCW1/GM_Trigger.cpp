// Fill out your copyright notice in the Description page of Project Settings.

//#include "DrawDebugHelpers.h"
#include "GM_Trigger.h"
//#include "MyCharacter.h"

// Sets default values
AGM_Trigger::AGM_Trigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGM_Trigger::BeginPlay()
{
	Super::BeginPlay();
	
}

////When overlapping, destroy the score actor, make an instance of the class and add to the score.
//void AGM_Trigger::OnOverlapBegin2(class AActor* OverlappedActor, class AActor* OtherActor)
//{
//	if (OtherActor && (OtherActor != this))
//	{
//		UE_LOG(LogTemp, Warning, TEXT("Overlapped Actor (Begin) = %s"), *OverlappedActor->GetName());
//
//		//This tag should be player
//		if (OverlappedActor->ActorHasTag("Obstacle"))
//		{
//			OverlappedActor->Destroy();
//
//			AMyCharacter MyClass;
//			MyClass.bl_IsGameOver = true;
//		}
//	}
//}

// Called every frame
void AGM_Trigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

