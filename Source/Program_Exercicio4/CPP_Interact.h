// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CPP_Interact.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCPP_Interact : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROGRAM_EXERCICIO4_API ICPP_Interact
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Interface")

	void Interact();
};
