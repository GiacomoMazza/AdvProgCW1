// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Math/Vector.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//sets up the spring arm component which is kind of like a boon for the camera to be attached to the player
	springArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComp"));
	springArmComp->SetupAttachment(RootComponent);
	springArmComp->TargetArmLength = 200;
	
	//sets up the camera components
	cameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	cameraComp->SetupAttachment(springArmComp);//attaches the camera to the 'boon'

	//set up the player mesh
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	meshComp->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	score += (points * DeltaTime);
	AddMovementInput(GetActorForwardVector(), runSpeed*DeltaTime);
	
}

void AMyCharacter::MoveRight(float Value)
{
	//makes sure the player cannot move passed the further most points
	if (prevVal != Value)
	{
		if ((Controller) && (Value != 0.0))
		{
			//schanges preval based on where they are
			//so if you're in the centre (0) you move left or right
			//or if you are either left or right you move back to the centre
			if (prevVal == 0)
			{
				prevVal = Value;
			}
			else
			{
				prevVal += Value;
			}

			//the distance you move right or left
			if (Value < 0)
			{
				move = -5;
			}
			else
			{
				move = 5;
			}
			AddMovementInput(GetActorRightVector(), move);
			//FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
			//AddMovementInput(Direction, Value);
		}
	}
	
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
}

