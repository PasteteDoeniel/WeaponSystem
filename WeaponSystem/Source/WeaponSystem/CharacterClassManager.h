// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "CharacterClassManager.generated.h"

UENUM(BlueprintType)
enum class EWeaponSlotEnum : uint8
{
	WS_Primary UMETA(DisplayName = "Primary Weapon"),
	WS_Secondary UMETA(DisplayName = "Secondary Weapon")
};


UENUM(BlueprintType)
enum class EWeaponClassEnum : uint8
{
	WC_AssaultRifle UMETA(DisplayName = "Assault Rifle"),
	WC_Shotgun UMETA(DisplayName = "Shotgun"),
	WC_SniperRifle UMETA(DisplayName = "SniperRifle")
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_API UCharacterClassManager : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCharacterClassManager();

	/*enums*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		EWeaponSlotEnum WeaponSlotEnum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		EWeaponClassEnum WeaponClassEnum;

	//primary Weapon

	UPROPERTY(EditDefaultsOnly, Category = Weapon)
		TSubclassOf<class ABaseWeapon> PrimaryWeapon;

	//secondary weapon

	UPROPERTY(EditDefaultsOnly, Category = Weapon)
		TSubclassOf<class ABaseWeapon> SecondaryWeapon;

	//attach weapon blueprint to character
	//select character mesh

	/*Switch between primary and secondary weapon*/
	UFUNCTION()
		void SwitchWeapon();

	/*Fires the weapon*/
	UFUNCTION()
		void Fire();


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



};
