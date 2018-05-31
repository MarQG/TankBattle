// 2018 Copyright Rule One Computer Services

#include "Engine/World.h"
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
		GetControlledTank()->AimAt(HitLocation);
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	
	// Find the crosshair position
	int32 ViewPortSizeX, ViewPortSizeY;

	GetViewportSize(ViewPortSizeX, ViewPortSizeY);

	FVector2D ScreenLocation = FVector2D(ViewPortSizeX * CrossHairXLocation, ViewPortSizeY * CrossHairYLocation);
	
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection)) 
	{
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
	}

	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // For discarding

	// Line-trace along that look direction, and see what we hit (up to max range)
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& OutHitLocation) const
{
	FHitResult Hit;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + LookDirection * LineTraceRange;

	if (GetWorld()->LineTraceSingleByChannel(
		Hit,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
	)) 
	{
		OutHitLocation = Hit.Location;
		return true;
	}
	else {
		OutHitLocation = FVector(0);
		return false;
	}
}


