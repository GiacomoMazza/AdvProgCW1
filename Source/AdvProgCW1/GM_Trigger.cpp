// Fill out your copyright notice in the Description page of Project Settings.


#include "GM_Trigger.h"

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

// Called every frame
void AGM_Trigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

