// 2018 Copyright Rule One Computer Services

#include "Engine/World.h"
#include "../Public/TankAIController.h"

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerControlledPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerControlledPawn)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerControlledPawn);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank) 
	{
		UE_LOG(LogTemp, Warning, TEXT("AIControllercan find player tank"));
	}
	else 
	{
		FString CurrentPlayerTank = PlayerTank->GetName();
		UE_LOG(LogTemp, Warning, TEXT("AIController found player tank: %s"), *CurrentPlayerTank);
	}

	
}
