// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ShooterCombatComponent.generated.h"

class UShooterWeapon_DataAsset;

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FPS_API UShooterCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UShooterCombatComponent();
	
	virtual void TickComponent(
		float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Weapon")
	TObjectPtr<UShooterWeapon_DataAsset> ShooterWeaponDataAsset;
	
	// Cycle to the next weapon in the inventory.
	void Initiate_CycleWeapon();
	
	void Initiate_FireWeapon_Pressed();
	void Initiate_FireWeapon_Released();
	
	void Initiate_ReloadWeapon();
	
	void Initiate_AimWeapon_Pressed();
	void Initiate_AimWeapon_Released();

protected:
	virtual void BeginPlay() override;
	
private:
	
};
