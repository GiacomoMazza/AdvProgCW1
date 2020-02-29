// Fill out your copyright notice in the Description page of Project Settings.

#include "DrawDebugHelpers.h"
#include "GM_TriggerBox.h"

//Constructor
AGM_TriggerBox::AGM_TriggerBox()
{
	 OnActorBeginOverlap.AddDynamic(this, &AGM_TriggerBox::OnOverlapBegin);
	 OnActorEndOverlap.AddDynamic(this, &AGM_TriggerBox::OnOverlapEnd);
}

//Help visualising the box
void AGM_TriggerBox::BeginPlay() 
{
	Super::BeginPlay();
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green, true, -1, 0, 5);
}

//When overlapping, do something
void AGM_TriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor) {
	if (OtherActor && (OtherActor != this)) {
		UE_LOG(LogTemp, Warning, TEXT("Overlapped Actor (Begin) = %s"), *OverlappedActor->GetName());
	}
}

//When overlapping is over, do something
void AGM_TriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor) {
	if (OtherActor && (OtherActor != this)) {
		UE_LOG(LogTemp, Warning, TEXT("Overlapped Actor (End) = %s"), *OtherActor->GetName());
		OtherActor->Destroy();
	}
}

//Made by Giacomo Mazza.
