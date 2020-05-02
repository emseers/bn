// Fill out your copyright notice in the Description page of Project Settings.


#include "BnDoor.h"
#include "Components/StaticMeshComponent.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ABnDoor::ABnDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	bReplicates = true;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	RootComponent = DoorMesh;

	DoorSwitch = CreateDefaultSubobject<UBnSwitchComponent>(TEXT("Door Switch"));
	DoorSwitch->SetupAttachment(GetRootComponent());
	DoorSwitch->SetIsReplicated(true);
	DoorSwitch->OnToggleSwitch.AddDynamic(this, &ABnDoor::OnServerToggleDoor);
}


// Called when the game starts or when spawned
void ABnDoor::BeginPlay()
{
	Super::BeginPlay();
}

void ABnDoor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABnDoor, IsOpen);
	DOREPLIFETIME(ABnDoor, IsLocked);
}

void ABnDoor::OnServerToggleDoor()
{
	if (!IsLocked)
	{
		IsOpen = !IsOpen;
		OnToggleDoor();
	}
}

void ABnDoor::OnToggleDoor_Implementation()
{
	if(GetLocalRole() != ROLE_Authority)
	{
		ToggleDoor(IsOpen);	
	}
}

void ABnDoor::ToggleDoor_Implementation(bool bIsOpen)
{
}
