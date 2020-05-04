// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BnInteractionType.h"
#include "BnInteractive.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/BoxComponent.h"

#include "BnSwitchComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnToggleSwitch);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BN_API UBnSwitchComponent : public UBoxComponent, public IBnInteractive
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBnSwitchComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnInteractStart();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnInteractEnd();
	EBnInteractionType InteractionType = EBnInteractionType::Toggle;
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	EBnInteractionType GetInteractiveType();

	UPROPERTY(BlueprintAssignable, Category="Gameplay")
    FOnToggleSwitch OnToggleSwitch;
};
