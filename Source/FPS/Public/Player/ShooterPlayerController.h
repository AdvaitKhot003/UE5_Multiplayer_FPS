// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ShooterPlayerController.generated.h"

class UShooterInput_DataAsset;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class FPS_API AShooterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AShooterPlayerController();
	
protected:
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "FPS|Input")
	TObjectPtr<UShooterInput_DataAsset> ShooterInputDataAsset;
	
	void Input_Look(const FInputActionValue& InputActionValue);
	
	void Input_Move(const FInputActionValue& InputActionValue);
	
	void Input_JumpPressed();
	void Input_JumpReleased();
	
	void Input_CrouchPressed();
	void Input_CrouchReleased();
};
