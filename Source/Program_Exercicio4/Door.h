// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Interact.h"
#include "Door.generated.h"

UCLASS()
class PROGRAM_EXERCICIO4_API ADoor : public AActor, public ICPP_Interact
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "DoorInteract")
	void Interact();
};
