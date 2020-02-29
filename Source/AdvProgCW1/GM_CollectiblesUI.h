// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GM_CollectiblesUI.generated.h"

/**
 * 
 */
UCLASS()
class ADVPROGCW1_API UGM_CollectiblesUI : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	/*Responsible for adding the ItemToAdd to our UI*/
	UFUNCTION(BlueprintImplementableEvent, Category = UI)
		void AddItemToUI();

	/*The next item that is going to get added inside our UI*/
	UPROPERTY(BlueprintReadOnly)
		FText ItemToAdd;

public:

	/*Adds the name of the item we collected inside our UI by using our AddItemToUI protected function*/
	void AddItemToUI(FText ItemName);
};

// Made by Giacomo Mazza.
