// Fill out your copyright notice in the Description page of Project Settings.

//#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green,text)
//#define printFString(text, fstring) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(text), fstring))

#include "DrawDebugHelpers.h"
#include "GM_TriggerBox.h"

AGM_TriggerBox::AGM_TriggerBox()
{
	 OnActorBeginOverlap.AddDynamic(this, &AGM_TriggerBox::OnOverlapBegin);
	 OnActorEndOverlap.AddDynamic(this, &AGM_TriggerBox::OnOverlapEnd);
	 UE_LOG(LogTemp, Warning, TEXT("Stage 1"));
}

void AGM_TriggerBox::BeginPlay() 
{
	Super::BeginPlay();
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);
}

void AGM_TriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor) {
	if (OtherActor && (OtherActor != this)) {
		//print("Overlap Begun");
		//printf("Overlapped Actor = %s", *OverlappedActor->GetName());
		UE_LOG(LogTemp, Warning, TEXT("Overlapped Actor (Begin) = %s"), *OverlappedActor->GetName());
	}
}

void AGM_TriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor) {
	if (OtherActor && (OtherActor != this)) {
		//print("Overlap Begun");
		//printf("Overlapped Actor = %s", *OverlappedActor->GetName());
		UE_LOG(LogTemp, Warning, TEXT("Overlapped Actor (End) = %s"), *OtherActor->GetName());
		OtherActor->Destroy();
	}
}
