// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BnInteractive.generated.h"

UENUM(BlueprintType)
enum class EBnInteractionType : uint8
{
	Momentary,
	Toggle,
	Slide,
	Hold
};

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBnInteractive : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class BN_API IBnInteractive
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnInteractStart();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnInteractEnd();
	EBnInteractionType InteractionType;
};
