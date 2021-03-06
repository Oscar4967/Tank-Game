// Copyright Oscar Pettersson

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

// Forward declaration
class UTankAimingComponent;

/**
* Responsible for helping the player aim
*/
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef);

	virtual void SetPawn(APawn* InPawn) override;

private:

	//start the tank moving the barrel towards the crosshair location
	void AimTowardsCrosshair();

	
	
	// Return an OUT parameter, true if hit landscape
	bool GetSightRayHitLocation(FVector& OurHitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = 0.5;
	
	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 10000000;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& OurHitLocation) const;

	UFUNCTION()
	void OnPossessedTankDeath();


	

	
	// Call StartSpectatingOnly() when dead
};