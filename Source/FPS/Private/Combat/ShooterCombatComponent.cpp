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

void UShooterCombatComponent::Initiate_CycleWeapon()
{
	
}

void UShooterCombatComponent::Initiate_FireWeapon_Pressed()
{
	
}

void UShooterCombatComponent::Initiate_FireWeapon_Released()
{
	
}

void UShooterCombatComponent::Initiate_ReloadWeapon()
{
	
}

void UShooterCombatComponent::Initiate_AimWeapon_Pressed()
{
	
}

void UShooterCombatComponent::Initiate_AimWeapon_Released()
{
	
}
