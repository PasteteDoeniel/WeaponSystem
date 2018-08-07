// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "WeaponManager.generated.h"


UENUM(BlueprintType)
enum class EWeaponTypeEnum : uint8
{
	WE_AssaultRifle UMETA(DisplayName = "AssaultRifle"),
	WE_Shotgun UMETA(DisplayName = "Shotgun"),
	WE_SniperRifle UMETA(DisplayName = "SniperRifle")
};

UENUM(BlueprintType)
enum class EProjectileTypeEnum : uint8
{
	PE_Energy UMETA(DisplayName = "Energy"),
	PE_Projectile UMETA(DisplayName = "Projectile"),
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_API UWeaponManager : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWeaponManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		EWeaponTypeEnum WeaponEnum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		EProjectileTypeEnum ProjectileEnum;

	//used to determine if weapon can fire
	UPROPERTY()
		bool canFire = true;

	//AssautRifle-Energy

	FTimerHandle AssaultFireRateTimerHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float FAssaultEnergyDamage UMETA(DisplayName = "Assault Energy Damage");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		int FAssaultEnergyFireRate UMETA(DisplayName = "Assault Energy Fire rate");

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Shotgun)
		float FAssaultEnergyFireRateTime UMETA(DisplayName = "Assault Energy Fire rate Time");


	//Shotgun-Projectile
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float FShotgunProjectileDamage UMETA(DisplayName = "Shotgun Projectile Damage");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float FShotgunProjectileSpread UMETA(DisplayName = "Shotgun Projectile Spread");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		int IShotgunProjectileAmount UMETA(DisplayName = "Shotgun Projectile Amount");

	//Shotgun-Energy
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float FShotgunEnergyDamage UMETA(DisplayName = "Shotgun Energy Damage");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		float FShotgunEnergySpread UMETA(DisplayName = "Shotgun Energy Spread");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Shotgun)
		int IShotgunEnergyAmount UMETA(DisplayName = "Shotgun Energy Amount");

	//SniperRifle



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AWeaponSystemProjectile> ProjectileClass;

	UFUNCTION()
		void FireWeapon(FVector SpawnPoint, FRotator SpawnRotation);

	UFUNCTION()
		void StopFireWeapon();

	UFUNCTION()
		void ResetFireRateTimer();

};
