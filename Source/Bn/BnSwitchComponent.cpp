// Fill out your copyright notice in the Description page of Project Settings.


#include "BnSwitchComponent.h"


// Sets default values for this component's properties
UBnSwitchComponent::UBnSwitchComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	UPrimitiveComponent::SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	UPrimitiveComponent::SetCollisionResponseToAllChannels(ECR_Ignore);
	UPrimitiveComponent::SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Block);
}


// Called when the game starts
void UBnSwitchComponent::BeginPlay()
{
	Super::BeginPlay();
}

EBnInteractionType UBnSwitchComponent::GetInteractiveType_Implementation()
{
	return InteractionType;
}

void UBnSwitchComponent::OnInteractEnd_Implementation()
{
}

void UBnSwitchComponent::OnInteractStart_Implementation()
{
	OnToggleSwitch.Broadcast();
}