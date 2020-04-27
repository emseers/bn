// Fill out your copyright notice in the Description page of Project Settings.


#include "BnDoor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABnDoor::ABnDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bReplicates = true;

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door Mesh"));
	RootComponent = DoorMesh;

	DoorSwitch = CreateDefaultSubobject<UBnSwitchComponent>(TEXT("Door Switch"));
	DoorSwitch->SetupAttachment(GetRootComponent());
	DoorSwitch->SetIsReplicated(true);
	DoorSwitch->OnToggleSwitch.AddDynamic(this, &ABnDoor::OnToggleDoor);
}


// Called when the game starts or when spawned
void ABnDoor::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABnDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABnDoor::OnToggleDoor_Implementation(bool bIsOpen)
{
	ToggleDoor(bIsOpen);
}

void ABnDoor::ToggleDoor_Implementation(bool bIsOpen)
{
}
