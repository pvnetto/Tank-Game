// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
/*New includes go below here*/
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UTankAimingComponent::AimAt(FVector aimLocation, float launchSpeed) {
	if (!barrel) {
		return;
	}
	FString tankName = GetOwner()->GetName();

	FVector launchVelocity;
	FVector startLocation = barrel->GetSocketLocation(FName("FirePoint"));

	if (UGameplayStatics::SuggestProjectileVelocity(this, launchVelocity, startLocation, aimLocation,
		launchSpeed, false, 0.0f, 0.0f, ESuggestProjVelocityTraceOption::DoNotTrace)) {

		FVector aimDirection = launchVelocity.GetSafeNormal();
		MoveBarrelTowards(aimDirection);
		UE_LOG(LogTemp, Warning, TEXT("Tank %s is aiming at: %s"), *tankName, *aimDirection.ToString());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No solution found ):"));
	}
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* newBarrel) {
	this->barrel = newBarrel;
}

void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection) {
	FRotator currentBarrelRotator = barrel->GetForwardVector().Rotation();
	FRotator aimRotator = aimDirection.Rotation();
	FRotator newRotation = aimRotator - currentBarrelRotator;


}

void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

