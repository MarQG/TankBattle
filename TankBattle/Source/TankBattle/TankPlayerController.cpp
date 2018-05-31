// 2018 Copyright Rule One Computer Services

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.bCanEverTick = true;

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
		return;
	}
	else 
	{
		FString CurrentOwner = ControlledTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *CurrentOwner);
	}
	
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() 
{
	if (!GetControlledTank()) 
	{
		return;
	}

	FVector HitLocation; // OUT parameter

	if (GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{ 
		// Tell controlled tank to aim at this location
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString());
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	OutHitLocation = FVector(1.0f);
	return true;
}

