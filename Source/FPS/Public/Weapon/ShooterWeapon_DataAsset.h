// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "ShooterWeapon_DataAsset.generated.h"

/**
 * 
 */
UCLASS()
class FPS_API UShooterWeapon_DataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly,
		Category = "FPS|WeaponData|Weapons", meta = (Categories = "Weapon.WeaponType"))
	TMap<FGameplayTag, FName> WeaponGripPoints;
};
