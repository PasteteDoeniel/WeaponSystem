// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CharacterClassManager.generated.h"

UENUM(BlueprintType)
enum class EWeaponSlotTypeEnum : uint8
{
	WE_Primary UMETA(DisplayName = "Primary Weapon"),
	WE_Secondary UMETA(DisplayName = "Secondary Weapon")
};

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WEAPONSYSTEM_API UCharacterClassManager : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UCharacterClassManager();

	//primary Weapon
	//secondary weapon

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
