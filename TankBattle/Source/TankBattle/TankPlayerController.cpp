// 2018 Copyright Rule One Computer Services

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

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
