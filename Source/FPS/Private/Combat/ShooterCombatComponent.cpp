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
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Cyan, TEXT("Initiate_CycleWeapon"), false);
}

void UShooterCombatComponent::Initiate_FireWeapon_Pressed()
{
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Cyan, TEXT("Initiate_FireWeapon_Pressed"), false);
}

void UShooterCombatComponent::Initiate_FireWeapon_Released()
{
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Cyan, TEXT("Initiate_FireWeapon_Released"), false);
}

void UShooterCombatComponent::Initiate_ReloadWeapon()
{
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Cyan, TEXT("Initiate_ReloadWeapon"), false);
}

void UShooterCombatComponent::Initiate_AimWeapon_Pressed()
{
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Cyan, TEXT("Initiate_AimWeapon_Pressed"), false);
}

void UShooterCombatComponent::Initiate_AimWeapon_Released()
{
	GEngine->AddOnScreenDebugMessage(
		-1, 5.f, FColor::Cyan, TEXT("Initiate_AimWeapon_Released"), false);
}
