// No Copyright.

#include "Player/ShooterPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInput/ShooterInputComponent.h"
#include "EnhancedInput/ShooterInput_DataAsset.h"
#include "GameFramework/Character.h"

AShooterPlayerController::AShooterPlayerController()
{
	SetReplicates(true);
}

void AShooterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (!IsLocalController()) return;
	
	const ULocalPlayer* LocalPlayer = GetLocalPlayer();
	check(LocalPlayer);
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	
	check(Subsystem);
	check(ShooterInputDataAsset);
	check(ShooterInputDataAsset->ShooterMappingContext);
	
	Subsystem->AddMappingContext(ShooterInputDataAsset->ShooterMappingContext, 0);
}

void AShooterPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UShooterInputComponent* ShooterInputComponent = CastChecked<UShooterInputComponent>(InputComponent);
	check(ShooterInputDataAsset);
	
	check(ShooterInputDataAsset->LookAction);
	ShooterInputComponent->BindAction(
		ShooterInputDataAsset->LookAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);
	
	check(ShooterInputDataAsset->MoveAction);
	ShooterInputComponent->BindAction(
		ShooterInputDataAsset->MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	
	check(ShooterInputDataAsset->JumpAction);
	ShooterInputComponent->BindAction(
		ShooterInputDataAsset->JumpAction, ETriggerEvent::Started, this, &ThisClass::Input_JumpPressed);
	
	ShooterInputComponent->BindAction(
		ShooterInputDataAsset->JumpAction, ETriggerEvent::Completed, this, &ThisClass::Input_JumpReleased);
	
	check(ShooterInputDataAsset->CrouchAction);
	ShooterInputComponent->BindAction(
		ShooterInputDataAsset->CrouchAction, ETriggerEvent::Started, this, &ThisClass::Input_CrouchPressed);
	
	ShooterInputComponent->BindAction(
		ShooterInputDataAsset->CrouchAction, ETriggerEvent::Completed, this, &ThisClass::Input_CrouchReleased);
}

void AShooterPlayerController::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	
	if (!FMath::IsNearlyZero(InputAxisVector.X))
	{
		AddYawInput(InputAxisVector.X);
	}
	
	if (!FMath::IsNearlyZero(InputAxisVector.Y))
	{
		AddPitchInput(InputAxisVector.Y);
	}
}

void AShooterPlayerController::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	
	APawn* ControllerPawn = GetPawn<APawn>();
	if (!IsValid(ControllerPawn)) return;
	
	if (!FMath::IsNearlyZero(InputAxisVector.Y))
	{
		const FVector ForwardDirection = YawRotation.RotateVector(FVector::ForwardVector);
		ControllerPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
	}
	
	if (!FMath::IsNearlyZero(InputAxisVector.X))
	{
		const FVector RightDirection = YawRotation.RotateVector(FVector::RightVector);
		ControllerPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AShooterPlayerController::Input_JumpPressed()
{
	ACharacter* ShooterCharacter = GetCharacter();
	if (!IsValid(ShooterCharacter)) return;
	
	ShooterCharacter->Jump();
}

void AShooterPlayerController::Input_JumpReleased()
{
	ACharacter* ShooterCharacter = GetCharacter();
	if (!IsValid(ShooterCharacter)) return;
	
	ShooterCharacter->StopJumping();
}

void AShooterPlayerController::Input_CrouchPressed()
{
	ACharacter* ShooterCharacter = GetCharacter();
	if (!IsValid(ShooterCharacter)) return;

	ShooterCharacter->Crouch();
}

void AShooterPlayerController::Input_CrouchReleased()
{
	ACharacter* ShooterCharacter = GetCharacter();
	if (!IsValid(ShooterCharacter)) return;

	ShooterCharacter->UnCrouch();
}
