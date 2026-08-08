// No Copyright.

#include "Weapon/ShooterWeapon.h"
#include "Interface/ShooterCharacterInterface.h"

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

void AShooterWeapon::SetWeaponMeshVisibility(const APawn* OwningPawn)
{
	if (OwningPawn->IsLocallyControlled())
	{
		GetWeaponMesh1P()->SetHiddenInGame(false);
		GetWeaponMesh3P()->SetHiddenInGame(true);
	}
	else
	{
		GetWeaponMesh1P()->SetHiddenInGame(true);
		GetWeaponMesh3P()->SetHiddenInGame(false);
	}
}

void AShooterWeapon::AttachWeaponToOwningPawn()
{
	const APawn* OwningPawn = GetInstigator();
	if (!IsValid(OwningPawn) || !OwningPawn->Implements<UShooterCharacterInterface>()) return;
	
	SetWeaponMeshVisibility(OwningPawn);
	
	const FName AttachGripPoint = IShooterCharacterInterface::Execute_GetWeaponAttachGripPoint(OwningPawn, WeaponType);
	
	USkeletalMeshComponent* PawnMesh1P = IShooterCharacterInterface::Execute_GetMesh1P(OwningPawn);
	USkeletalMeshComponent* PawnMesh3P = IShooterCharacterInterface::Execute_GetMesh3P(OwningPawn);
	
	if (!PawnMesh1P || !PawnMesh3P) return;
	
	GetWeaponMesh1P()->AttachToComponent(
		PawnMesh1P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, AttachGripPoint);
	
	GetWeaponMesh3P()->AttachToComponent(
		PawnMesh3P, FAttachmentTransformRules::SnapToTargetNotIncludingScale, AttachGripPoint);
}

void AShooterWeapon::OnRep_Instigator()
{
	Super::OnRep_Instigator();
	
	AttachWeaponToOwningPawn();
}
