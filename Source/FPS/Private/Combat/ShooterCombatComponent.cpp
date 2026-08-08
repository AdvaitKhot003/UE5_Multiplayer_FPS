// No Copyright.

#include "Combat/ShooterCombatComponent.h"
#include "Weapon/ShooterWeapon.h"
#include "Net/UnrealNetwork.h"

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

void UShooterCombatComponent::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(UShooterCombatComponent, Inventory);
}

AShooterWeapon* UShooterCombatComponent::SpawnWeapon(const TSubclassOf<AShooterWeapon> WeaponClassToSpawn) const
{
	AActor* OwnerActor = GetOwner();
	if (!IsValid(OwnerActor)) return nullptr;
	if (!OwnerActor->HasAuthority()) return nullptr;
	
	FActorSpawnParameters SpawnParams;
	SpawnParams.Instigator = Cast<APawn>(OwnerActor);
	SpawnParams.Owner = OwnerActor;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	
	return GetWorld()->SpawnActor<AShooterWeapon>(WeaponClassToSpawn, SpawnParams);
}

void UShooterCombatComponent::SpawnInventory()
{
	const AActor* OwnerActor = GetOwner();
	if (!IsValid(OwnerActor)) return;
	if (!OwnerActor->HasAuthority()) return;
	
	for (const TSubclassOf<AShooterWeapon>& WeaponClass : DefaultWeaponClasses)
	{
		AShooterWeapon* ShooterWeapon = SpawnWeapon(WeaponClass);
		if (!IsValid(ShooterWeapon)) continue;
		Inventory.AddUnique(ShooterWeapon);
	}
	
	if (Inventory.IsEmpty()) return;
	Inventory[0]->AttachWeaponToOwningPawn();
}

void UShooterCombatComponent::DestroyInventory()
{
	
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
