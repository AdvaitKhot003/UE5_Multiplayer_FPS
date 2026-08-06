// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

protected:
	virtual void BeginPlay() override;
	
private:
	// Weapon mesh: 1st person view.
	UPROPERTY(VisibleAnywhere, Category = "FPS|Weapon")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh1P;
	
	// Weapon mesh: 3rd person view.
	UPROPERTY(VisibleAnywhere, Category = "FPS|Weapon")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh3P;
};
