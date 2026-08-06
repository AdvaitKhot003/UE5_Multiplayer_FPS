// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

class UShooterCombatComponent;
class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class FPS_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AShooterCharacter();
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UShooterCombatComponent* GetCombatComponent() const { return CombatComponent; }

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category = "FPS|Combat")
	TObjectPtr<UShooterCombatComponent> CombatComponent;
	
	// 1st person view (camera).
	UPROPERTY(VisibleAnywhere, Category = "FPS|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, Category = "FPS|Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
	
	// 1st person view (arms).
	UPROPERTY(VisibleAnywhere, Category = "FPS|Mesh")
	TObjectPtr<USkeletalMeshComponent> Mesh1P;
};
