// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "PC_PlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROGRAM_EXERCICIO4_API APC_PlayerCharacter : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	UInputMappingContext* InputContext;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	UInputAction* Forward;

	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	UInputAction* Sideways;

	void MoveForward(const FInputActionValue& A);
	void MoveSideways(const FInputActionValue& A);
};
