// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector & hitLocation);

	ATank* GetControlledTank () const;

private:
	UPROPERTY(EditAnywhere) float crosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere) float crosshairYLocation = 0.3333f;
	UPROPERTY(EditAnywhere) float range = 1000000.0f;
};
