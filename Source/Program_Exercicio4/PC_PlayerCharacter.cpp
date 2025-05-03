// Fill out your copyright notice in the Description page of Project Settings.


#include "PC_PlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void APC_PlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (ULocalPlayer* PlayerCharacter=GetLocalPlayer())
	{
		if (UEnhancedInputLocalPlayerSubsystem* SubSystem=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerCharacter))
		{
			SubSystem->AddMappingContext(InputContext, 0);
		}
	}
}

void APC_PlayerCharacter::MoveForward(const FInputActionValue& A)
{
	const float V = A.Get<float>();
	APawn* PlayerCharacter = GetPawn();
	if (V!=0)
	{
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorForwardVector(), V);
	}
}

void APC_PlayerCharacter::MoveSideways(const FInputActionValue& A)
{
	const float V = A.Get<float>();
	APawn* PlayerCharacter = GetPawn();
	if (V != 0)
	{
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorRightVector(), V);
	}
}

void APC_PlayerCharacter::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent))
	{
		Input->BindAction(Forward, ETriggerEvent::Triggered, this, &APC_PlayerCharacter::MoveForward);
		Input->BindAction(Sideways, ETriggerEvent::Triggered, this, &APC_PlayerCharacter::MoveSideways);
	}
}
