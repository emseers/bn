// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BnSwitchComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BnDoor.generated.h"

UCLASS()
class BN_API ABnDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABnDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Visual")
    UStaticMeshComponent* DoorMesh;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay")
	UBnSwitchComponent* DoorSwitch;

	UFUNCTION(NetMulticast, Reliable)
	void OnToggleDoor(bool bIsOpen);

	UFUNCTION(BlueprintNativeEvent)
	void ToggleDoor(bool bIsOpen);
};
