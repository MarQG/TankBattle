// 2018 Copyright Rule One Computer Services

#pragma once

#include "CoreMinimal.h"
#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	ATank* GetControlledTank() const;

	// Start the tank moving the barrel so that a show would hit where
	// the crosshair intersects with the world
	void AimTowardsCrosshair();

	
	
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime ) override;

private:

	// Return an OUT Parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector &OutHitLocation) const;
};
