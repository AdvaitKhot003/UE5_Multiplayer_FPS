// No Copyright.

#include "Combat/ShooterCombatComponent.h"

UShooterCombatComponent::UShooterCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UShooterCombatComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UShooterCombatComponent::TickComponent(
	float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
}
