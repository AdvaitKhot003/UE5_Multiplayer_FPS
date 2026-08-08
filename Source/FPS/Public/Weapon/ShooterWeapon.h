// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Actor.h"
#include "GameplayTags/ShooterGameplayTags.h"
#include "ShooterWeapon.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API AShooterWeapon : public AActor
{
	GENERATED_BODY()

public:
	AShooterWeapon();
	
	FORCEINLINE USkeletalMeshComponent* GetWeaponMesh1P() const { return WeaponMesh1P; }
	
	FORCEINLINE USkeletalMeshComponent* GetWeaponMesh3P() const { return WeaponMesh3P; }
	
	void AttachWeaponToOwningPawn();
	
	virtual void OnRep_Instigator() override;

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Weapon", meta = (Categories = "Weapon.WeaponType"))
	FGameplayTag WeaponType = ShooterWeaponTags::Weapon_WeaponType_None;
	
private:
	// Weapon mesh: 1st person view.
	UPROPERTY(VisibleAnywhere, Category = "FPS|Mesh")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh1P;
	
	// Weapon mesh: 3rd person view.
	UPROPERTY(VisibleAnywhere, Category = "FPS|Mesh")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh3P;
	
	void SetWeaponMeshVisibility(const APawn* OwningPawn);
};
