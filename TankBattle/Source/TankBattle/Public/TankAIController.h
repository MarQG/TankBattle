// 2018 Copyright Rule One Computer Services

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Public/Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANKBATTLE_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;
};
