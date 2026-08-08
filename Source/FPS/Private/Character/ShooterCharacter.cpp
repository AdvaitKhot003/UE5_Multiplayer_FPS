// No Copyright.

#include "Character/ShooterCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Combat/ShooterCombatComponent.h"
#include "EnhancedInput/ShooterInputComponent.h"
#include "EnhancedInput/ShooterInput_DataAsset.h"
#include "Weapon/ShooterWeapon_DataAsset.h"

AShooterCharacter::AShooterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	GetCapsuleComponent()->SetCapsuleHalfHeight(90.f);
	GetCapsuleComponent()->SetCapsuleRadius(34.f);
	
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 0.f;
	CameraBoom->bEnableCameraLag = true;
	CameraBoom->CameraLagSpeed = 25.f;
	CameraBoom->CameraLagMaxDistance = 5.f;
	CameraBoom->bUsePawnControlRotation = true;
	CameraBoom->bDoCollisionTest = false;
	
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
	
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh1P"));
	Mesh1P->SetupAttachment(FollowCamera);
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetOwnerNoSee(false);
	Mesh1P->SetCastShadow(false);
	Mesh1P->SetReceivesDecals(false);
	Mesh1P->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	Mesh1P->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	
	GetMesh()->SetOnlyOwnerSee(false);
	GetMesh()->SetOwnerNoSee(true);
	GetMesh()->SetReceivesDecals(false);
	
	GetCharacterMovement()->MovementState.bCanCrouch = true;
	
	CombatComponent = CreateDefaultSubobject<UShooterCombatComponent>(TEXT("CombatComponent"));
	CombatComponent->SetIsReplicated(true);
}

FName AShooterCharacter::GetWeaponAttachGripPoint_Implementation(const FGameplayTag& WeaponType) const
{
	const UShooterWeapon_DataAsset* ShooterWeaponDataAsset = GetCombatComponent()->ShooterWeaponDataAsset;
	check(ShooterWeaponDataAsset);
	return ShooterWeaponDataAsset->WeaponGripPoints.FindChecked(WeaponType);
}

void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UShooterInputComponent* ShooterInputComponent = CastChecked<UShooterInputComponent>(PlayerInputComponent);
	check(ShooterInputDataAsset);
	
	check(ShooterInputDataAsset->CycleWeaponAction);
	ShooterInputComponent->BindAction(
		ShooterInputDataAsset->CycleWeaponAction, ETriggerEvent::Started, this,
		&AShooterCharacter::Input_CycleWeapon);
	
	check(ShooterInputDataAsset->FireWeaponAction);
	ShooterInputComponent->BindAction(
		ShooterInputDataAsset->FireWeaponAction, ETriggerEvent::Started, this,
		&AShooterCharacter::Input_FireWeapon_Pressed);
	
	ShooterInputComponent->BindAction(
		ShooterInputDataAsset->FireWeaponAction, ETriggerEvent::Completed, this,
		&AShooterCharacter::Input_FireWeapon_Released);
	
	check(ShooterInputDataAsset->ReloadWeaponAction);
	ShooterInputComponent->BindAction(
		ShooterInputDataAsset->ReloadWeaponAction, ETriggerEvent::Started, this,
		&AShooterCharacter::Input_ReloadWeapon);
	
	check(ShooterInputDataAsset->AimWeaponAction);
	ShooterInputComponent->BindAction(
		ShooterInputDataAsset->AimWeaponAction, ETriggerEvent::Started, this,
		&AShooterCharacter::Input_AimWeapon_Pressed);
	
	ShooterInputComponent->BindAction(
		ShooterInputDataAsset->AimWeaponAction, ETriggerEvent::Completed, this,
		&AShooterCharacter::Input_AimWeapon_Released);
}

void AShooterCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	GetCombatComponent()->SpawnInventory();
}

void AShooterCharacter::Input_CycleWeapon()
{
	GetCombatComponent()->Initiate_CycleWeapon();
}

void AShooterCharacter::Input_FireWeapon_Pressed()
{
	GetCombatComponent()->Initiate_FireWeapon_Pressed();
}

void AShooterCharacter::Input_FireWeapon_Released()
{
	GetCombatComponent()->Initiate_FireWeapon_Released();
}

void AShooterCharacter::Input_ReloadWeapon()
{
	GetCombatComponent()->Initiate_ReloadWeapon();
}

void AShooterCharacter::Input_AimWeapon_Pressed()
{
	GetCombatComponent()->Initiate_AimWeapon_Pressed();
}

void AShooterCharacter::Input_AimWeapon_Released()
{
	GetCombatComponent()->Initiate_AimWeapon_Released();
}
