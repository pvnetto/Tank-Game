// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	if (GetPawn()) {
		FString tankName = GetPawn()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController started. %s"), *tankName);
	}
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank> (GetPawn());
}

