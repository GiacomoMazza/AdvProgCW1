// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "GM_TriggerBox.h"
#include "MyCharacter.h"

///This is the class that belongs to the pick-up scores.
AGM_TriggerBox::AGM_TriggerBox()
{
	 OnActorBeginOverlap.AddDynamic(this, &AGM_TriggerBox::OnOverlapBegin);
	 OnActorEndOverlap.AddDynamic(this, &AGM_TriggerBox::OnOverlapEnd);
}

//Help visualising the box
void AGM_TriggerBox::BeginPlay() 
{
	Super::BeginPlay();

	//This works only in the editor, which is fine, but consider adding a mesh before distributing it.
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green, true, -1, 0, 5);
}

//When overlapping, destroy the score actor, make an instance of the class and add to the score.
void AGM_TriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor) 
{
	if (OtherActor && (OtherActor != this)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlapped Actor (Begin) = %s"), *OverlappedActor->GetName());

		//This tag should be player
		//if (OverlappedActor->ActorHasTag("ScoreBlock")) 
		//{
		AMyCharacter MyClass;
		MyClass.AddScore(50.0);
		//OverlappedActor->Destroy();
		//}
	}
}

//When overlapping is over, do something
void AGM_TriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor) 
{
	if (OtherActor && (OtherActor != this)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlapped Actor (End) = %s"), *OtherActor->GetName());

		
	}
}

//Made by Giacomo Mazza.
