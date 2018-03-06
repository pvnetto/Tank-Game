// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankPlayerController.h"

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	if (GetControlledTank()) {
		UE_LOG(LogTemp, Warning, TEXT("AITank is possesed by %s"), *GetControlledTank()->GetName());
	}
	if (GetPlayerTank()) {
		UE_LOG(LogTemp, Warning, TEXT("Targeting player: %s"), *GetPlayerTank()->GetName());
	}
}

ATank* ATankAIController::GetPlayerTank() {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

ATank* ATankAIController::GetControlledTank()
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	GetControlledTank()->AimAt(GetPlayerTank()->GetTransform().GetLocation());
}
