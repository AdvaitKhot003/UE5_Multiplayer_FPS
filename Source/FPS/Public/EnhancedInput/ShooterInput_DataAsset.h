// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ShooterInput_DataAsset.generated.h"

class UInputAction;
class UInputMappingContext;

/**
 * 
 */
UCLASS()
class FPS_API UShooterInput_DataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	// Input Mapping Context.
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IMC")
	TObjectPtr<UInputMappingContext> ShooterMappingContext;
	
	// Input Actions (Movement).
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IA|Movement")
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IA|Movement")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IA|Movement")
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IA|Movement")
	TObjectPtr<UInputAction> CrouchAction;
	
	// Input Actions (Combat).
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IA|Combat")
	TObjectPtr<UInputAction> CycleWeaponAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IA|Combat")
	TObjectPtr<UInputAction> FireWeaponAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IA|Combat")
	TObjectPtr<UInputAction> ReloadWeaponAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IA|Combat")
	TObjectPtr<UInputAction> AimWeaponAction;
};
