// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	Camera->SetupAttachment(RootComponent);
	Camera->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAxis("MoveFoward", this, &APlayerCharacter::MoveFoward);
	PlayerInputComponent->BindAxis("MoveSideways", this, &APlayerCharacter::MoveSideways);
	
	PlayerInputComponent->BindAxis("TurnCameraX", this, &APlayerCharacter::TurnCameraX);
	PlayerInputComponent->BindAxis("TurnCameraY", this, &APlayerCharacter::TurnCameraY);

}

void APlayerCharacter::MoveFoward(float InputValue)
{
	FVector FowardDirection = GetActorForwardVector();
	AddMovementInput(FowardDirection, InputValue);
}

void APlayerCharacter::MoveSideways(float InputValue)
{
	FVector RightDirection = GetActorRightVector();
	AddMovementInput(RightDirection, InputValue);
}

void APlayerCharacter::TurnCameraX(float InputValue)
{
	AddControllerYawInput(InputValue);
}

void APlayerCharacter::TurnCameraY(float InputValue)
{
	AddControllerPitchInput(InputValue);
}

