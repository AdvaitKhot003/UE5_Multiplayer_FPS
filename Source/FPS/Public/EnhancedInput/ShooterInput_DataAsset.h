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
	
	// Input Actions.
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IA")
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IA")
	TObjectPtr<UInputAction> MoveAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IA")
	TObjectPtr<UInputAction> JumpAction;
	
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input|IA")
	TObjectPtr<UInputAction> CrouchAction;
};
