// Copyright Gavin Irby 2021. All rights reserved.


#include "JoustCharacterMovementComponent.h"

// Defines for build configs
#if DO_CHECK && !UE_BUILD_SHIPPING // Disable even if checks in shipping are enabled.
#define devCode( Code )		checkCode( Code )
#else
#define devCode(...)
#endif

UJoustCharacterMovementComponent::UJoustCharacterMovementComponent(const class FObjectInitializer& ObjectInitializer) :
	Super(ObjectInitializer)
{
	DefaultLandMovementMode = MOVE_Walking; // This means that we will revert to Custom mode after a fall. May need further work here as code assumes that the only valid modes for GroundMovementMode are MOVE_Walking and MOVE_NavWalking.
	BrakingDecelerationCustom = MaxAcceleration;
	BrakingFrictionFactor = 1.0f;
	CustomFriction = 1.0f;
}

// MOVE_Custom also returns TRUE
bool UJoustCharacterMovementComponent::IsMovingOnGround() const
{
	return ((MovementMode == MOVE_Walking) || (MovementMode == MOVE_NavWalking) || (MovementMode == MOVE_Custom)) && UpdatedComponent;
}

// Need to account for being in custom movement mode
bool UJoustCharacterMovementComponent::CanWalkOffLedges() const
{
	if (MovementMode != MOVE_Custom && !bCanWalkOffLedgesWhenCrouching && IsCrouching())
	{
		return false;
	}

	return MovementMode == MOVE_Custom || bCanWalkOffLedges ? true: false;
}

// This function must be overriden so that we can set a BrakingDecelerationCustom value
float UJoustCharacterMovementComponent::GetMaxBrakingDeceleration() const
{
	switch (MovementMode)
	{
		case MOVE_Walking:
		case MOVE_NavWalking:
			return BrakingDecelerationWalking;
		case MOVE_Falling:
			return BrakingDecelerationFalling;
		case MOVE_Swimming:
			return BrakingDecelerationSwimming;
		case MOVE_Flying:
			return BrakingDecelerationFlying;
		case MOVE_Custom:
			return BrakingDecelerationCustom;
		case MOVE_None:
		default:
			return 0.f;
	}
}

void UJoustCharacterMovementComponent::PhysCustom(float deltaTime, int32 Iterations)
{
	// Calls Blueprint Event
	Super::PhysCustom(deltaTime, Iterations);
}
