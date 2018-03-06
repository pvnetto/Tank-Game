// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"


void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	if (GetPawn()) {
		FString tankName = GetPawn()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("TankPlayerController started. %s"), *tankName);
	}
}

void ATankPlayerController::AimTowardsCrosshair() {
	FVector hitLocation;

	GetSightRayHitLocation(hitLocation);
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation) {
	int32 viewportXSize, viewportYSize;
	GetViewportSize(viewportXSize, viewportYSize);
	FVector2D sightScreenPos (viewportXSize * crosshairXLocation, viewportYSize * crosshairYLocation);

	FVector widgetWorldPos, sightDirection;
	DeprojectScreenPositionToWorld(sightScreenPos.X, sightScreenPos.Y, widgetWorldPos, sightDirection);

	FHitResult hitResult;
	FVector cameraLocation = PlayerCameraManager->GetCameraLocation();
	FVector lineEnd = cameraLocation + (sightDirection * range);

	if (GetWorld()->LineTraceSingleByChannel(hitResult, cameraLocation, lineEnd, ECollisionChannel::ECC_Visibility)) {
		hitLocation = hitResult.Location;
		GetControlledTank()->AimAt(hitLocation);
		return true;
	}
	hitLocation = FVector(0);
	UE_LOG(LogTemp, Warning, TEXT("Couldn't hit anything."));
	return false;
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank> (GetPawn());
}


void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

