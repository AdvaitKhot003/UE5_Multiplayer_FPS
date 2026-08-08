// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "ShooterCharacterInterface.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UShooterCharacterInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FPS_API IShooterCharacterInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	FName GetWeaponAttachGripPoint(const FGameplayTag& WeaponType) const;
};
