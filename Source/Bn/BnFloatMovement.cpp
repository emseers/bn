// Fill out your copyright notice in the Description page of Project Settings.


#include "BnFloatMovement.h"

void UBnFloatMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// TODO: Implement the other checks in original - (ProjectileMovementComponent)
	// TODO: Remove checks that are irrelevant to this type of component
	AActor* ActorOwner = UpdatedComponent->GetOwner();

	if (!ActorOwner)
	{
		return;
	}

	const FVector OldVelocity = Velocity;

	const FVector MoveDelta = ComputeMoveDelta(OldVelocity, DeltaTime);

	FQuat NewRotation = OldVelocity.IsNearlyZero(0.01f) ?  UpdatedComponent->GetComponentQuat() : OldVelocity.ToOrientationQuat();
	
	FRotator DesiredRotation = NewRotation.Rotator();
	DesiredRotation.Pitch = 0.0f;
	DesiredRotation.Yaw = FRotator::NormalizeAxis(DesiredRotation.Yaw);
	DesiredRotation.Roll = 0.0f;
	NewRotation = DesiredRotation.Quaternion();

	FHitResult Hit;
	SafeMoveUpdatedComponent(MoveDelta, NewRotation, true, Hit);

	if (Hit.IsValidBlockingHit())
	{
		SlideAlongSurface(MoveDelta, 1.f - Hit.Time, Hit.Normal, Hit);
	}

	PendingForce = FVector::ZeroVector;
}

bool UBnFloatMovement::IsFlying() const
{
	
	return true;
}

// From: ProjectileMovementComponent
FVector UBnFloatMovement::ComputeMoveDelta(const FVector& InVelocity, float DeltaTime) const
{
	// Velocity Verlet integration (http://en.wikipedia.org/wiki/Verlet_integration#Velocity_Verlet)
	// The addition of p0 is done outside this method, we are just computing the delta.
	// p = p0 + v0*t + 1/2*a*t^2

	// We use ComputeVelocity() here to infer the acceleration, to make it easier to apply custom velocities.
	// p = p0 + v0*t + 1/2*((v1-v0)/t)*t^2
	// p = p0 + v0*t + 1/2*((v1-v0))*t

	const FVector NewVelocity = ComputeVelocity(InVelocity, DeltaTime);
	const FVector Delta = InVelocity * DeltaTime + (NewVelocity - InVelocity) * (0.5f * DeltaTime);
	return Delta;
}

FVector UBnFloatMovement::ComputeVelocity(FVector InitialVelocity, float DeltaTime) const
{
	// v = v0 + a*t
	const FVector Acceleration = ComputeAcceleration(InitialVelocity, DeltaTime);
	const FVector NewVelocity = InitialVelocity + Acceleration * DeltaTime;

	return LimitVelocity(NewVelocity);
}

FVector UBnFloatMovement::ComputeAcceleration(const FVector& InVelocity, float DeltaTime) const
{
	FVector Acceleration(FVector::ZeroVector);

	Acceleration.Z += GetGravityZ();

	Acceleration += PendingForce;

	return Acceleration;
}

FVector UBnFloatMovement::LimitVelocity(FVector NewVelocity) const
{
	const float CurrentMaxSpeed = GetMaxSpeed();
	if (CurrentMaxSpeed > 0.f)
	{
		NewVelocity = NewVelocity.GetClampedToMaxSize(CurrentMaxSpeed);
	}

	return NewVelocity;
}

void UBnFloatMovement::AddForce(const FVector Force)
{
	PendingForce += Force;
}

void UBnFloatMovement::SetMass(const float NewMass)
{
	if(NewMass > 0.f)
	{
		Mass = NewMass;
	}
}

