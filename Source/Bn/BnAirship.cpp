// Fill out your copyright notice in the Description page of Project Settings.


#include "BnAirship.h"
#include "TimerManager.h"
#include "Net/UnrealNetwork.h"

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

	Movement = CreateDefaultSubobject<UBnFloatMovement>(TEXT("FloatMovement"));
	Movement->SetUpdatedComponent(GetRootComponent());
	Movement->SetMass(Mass);
	
	bReplicates = true;
}

// Called when the game starts or when spawned
void ABnAirship::BeginPlay()
{
	Super::BeginPlay();

	if (GetLocalRole() == ROLE_Authority)
	{
		GetWorldTimerManager().SetTimer(TimerTickHandle, this, &ABnAirship::TimerTick, 1.0f, true, -1);
	}
}

// Called every frame
void ABnAirship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Movement->AddForce(FVector(0, 0, MainBalloon->GetForces()));
}

void ABnAirship::TimerTick_Implementation()
{
	MainBalloon->TimerTick();
}

// Called to bind functionality to input
void ABnAirship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABnAirship::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ABnAirship, MainBalloon);
}

