// 2018 Copyright Rule One Computer Services


#include "../Public/TankAIController.h"

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetControlledTank();
	if (!AIControlledTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank"));
		return;
	}
	else 
	{
		FString CurrentOwner = AIControlledTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *CurrentOwner);
	}
}
