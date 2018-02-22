// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	if (GetControlledTank()) {
		UE_LOG(LogTemp, Warning, TEXT("AITank is possesed by %s"), *GetControlledTank()->GetName())
	}
}

ATank* ATankAIController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}
