// Copyright Gavin Irby 2021. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "JoustCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class JOUST_API UJoustCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()

public:
	UJoustCharacterMovementComponent(const class FObjectInitializer& ObjectInitializer);
	
protected:
	// Joust implementation
	virtual void PhysCustom(float deltaTime, int32 Iterations) override;

	/** Returns maximum deceleration for the current state when braking (ie when there is no acceleration). */
	virtual float GetMaxBrakingDeceleration() const override;

public:

	// UMovementComponentInterface
	virtual bool IsMovingOnGround() const override;

	/** Returns whether this pawn is currently allowed to walk off ledges */
	virtual bool CanWalkOffLedges() const override;

	/**
	* Deceleration when in custom mode and not applying acceleration. This is a constant opposing force that directly lowers velocity by a constant value.
	* @see GroundFriction, MaxAcceleration
	*/
	UPROPERTY(Category = "Character Movement : Custom Movement", EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", UIMin = "0"))
	float BrakingDecelerationCustom;

	/**
	* Equivalent to GroundFriction for use during custom movement mode. Affects ability to turn sharply.
	*/
	UPROPERTY(Category = "Character Movement : Custom Movement", EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0", UIMin = "0"))
	float CustomFriction;
};
