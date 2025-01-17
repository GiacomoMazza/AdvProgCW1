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

//When overlapping, add packages and set its new location and rotation.
void AGM_TriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor) 
{
	if (OtherActor && (OtherActor != this)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlapped Actor (Begin) = %s"), *OverlappedActor->GetName());

		///Previous methods - Not working
		//if (OverlappedActor->ActorHasTag("ScoreBlock")) 
		//{
		//AMyCharacter MyClass;
		//MyClass->AddScore(50.0);
		/*if (MyClass != nullptr)
		{
			MyClass->score += 50;
			OverlappedActor->Destroy();
		}*/
		//}

		//Increment number of packages collected (times trigger has been hit)
		in_Packages++;

		//Compute new position
		NewRotation = this->GetActorQuat();

		//Compute new rotation with offset - Change offset to positive or negative
		if (bl_PosOffset)
		{
			NewLocation = this->GetActorLocation() + FVector(fl_Distance, fl_Offset, 0);
			bl_PosOffset = !bl_PosOffset;
		}

		else if (!bl_PosOffset)
		{
			NewLocation = this->GetActorLocation() + FVector(fl_Distance, -fl_Offset, 0);
			bl_PosOffset = !bl_PosOffset;
		}

		//Set new location and new rotation
		SetActorLocationAndRotation(NewLocation, NewRotation, false, 0, ETeleportType::None);

		//Update draring of the edges
		DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green, true, -1, 0, 5);		
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
