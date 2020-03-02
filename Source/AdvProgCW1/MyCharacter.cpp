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

	//Set the timer.
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AMyCharacter::RepeatingFunction, 2.0f, true, fl_GameDuration);
}

//Once time is over, stop movement.
void AMyCharacter::RepeatingFunction()
{
	bl_IsGameOver = true;
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Modified by Giacomo Mazza (if statement): Stop movign forward if game is over.
	if (!bl_IsGameOver)
	{
		score += (points * DeltaTime);
		AddMovementInput(GetActorForwardVector(), runSpeed*DeltaTime);
	}
}

//Modified by Giacomo Mazza (Added function) - Not working (nullptr).
//void AMyCharacter::AddScore(float fl_ScoreAdded) {
	//score += fl_ScoreAdded;
//}

void AMyCharacter::MoveRight(float Value)
{
	//makes sure the player cannot move passed the further most points
	if (prevVal != Value)
	{
		//Modified by Giacomo Mazza (if statement): stop moving left/right is game is over.
		if ((Controller) && (Value != 0.0) && (!bl_IsGameOver))
		{
			//changes preval based on where they are
			//so if you're in the centre (0) you move left or right
			//or if you are either left or right you move back to the centre
			if (prevVal == 0)
			{
				prevVal = Value + 10;
			}
			else
			{
				prevVal += Value + 10;
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

