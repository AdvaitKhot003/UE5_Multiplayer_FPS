// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/ShooterCharacterInterface.h"
#include "ShooterCharacter.generated.h"

class UShooterInput_DataAsset;
class UShooterCombatComponent;
class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class FPS_API AShooterCharacter : public ACharacter, public IShooterCharacterInterface
{
	GENERATED_BODY()

public:
	AShooterCharacter();
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void PossessedBy(AController* NewController) override;
	
	UShooterCombatComponent* GetCombatComponent() const { return CombatComponent; }
	
	// Shooter Character Interface Start
	virtual FName GetWeaponAttachGripPoint_Implementation(const FGameplayTag& WeaponType) const override;
	virtual USkeletalMeshComponent* GetMesh1P_Implementation() const override;
	virtual USkeletalMeshComponent* GetMesh3P_Implementation() const override;
	// Shooter Character Interface End

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "FPS|Combat")
	TObjectPtr<UShooterCombatComponent> CombatComponent;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input")
	TObjectPtr<UShooterInput_DataAsset> ShooterInputDataAsset;
	
	void Input_CycleWeapon();
	
	void Input_FireWeapon_Pressed();
	void Input_FireWeapon_Released();
	
	void Input_ReloadWeapon();
	
	void Input_AimWeapon_Pressed();
	void Input_AimWeapon_Released();
	
	// 1st person view (camera).
	UPROPERTY(VisibleAnywhere, Category = "FPS|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, Category = "FPS|Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
	
	// 1st person view (arms).
	UPROPERTY(VisibleAnywhere, Category = "FPS|Mesh")
	TObjectPtr<USkeletalMeshComponent> Mesh1P;
};
