// No Copyright.

#include "Weapon/ShooterWeapon.h"

AShooterWeapon::AShooterWeapon()
{
	PrimaryActorTick.bCanEverTick = false;
	SetReplicates(true);
	bNetUseOwnerRelevancy = true;
	
	WeaponMesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh1P"));
	SetRootComponent(WeaponMesh1P);
	WeaponMesh1P->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	WeaponMesh1P->SetCastShadow(false);
	WeaponMesh1P->SetReceivesDecals(false);
	WeaponMesh1P->SetHiddenInGame(true);
	
	WeaponMesh3P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh3P"));
	WeaponMesh3P->SetupAttachment(GetRootComponent());
	WeaponMesh3P->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	WeaponMesh3P->SetCastShadow(true);
	WeaponMesh3P->SetReceivesDecals(false);
	WeaponMesh3P->SetHiddenInGame(true);
}

void AShooterWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}
