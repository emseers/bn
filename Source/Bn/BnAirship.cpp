// Fill out your copyright notice in the Description page of Project Settings.


#include "BnAirship.h"

// Sets default values
ABnAirship::ABnAirship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HullMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HullMesh"));
	HullMesh->SetupAttachment(GetRootComponent());

	MainBalloonMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MainBalloonMesh"));
	MainBalloonMesh->SetupAttachment(HullMesh);
	
	MainBalloon = CreateDefaultSubobject<UBnBuoyancy>(TEXT("MainBalloon"));
	MainBalloon->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ABnAirship::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABnAirship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABnAirship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

