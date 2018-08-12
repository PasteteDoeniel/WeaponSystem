// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseWeapon.h"
#include "BaseShotgun.generated.h"

/**
 * 
 */
UCLASS()
class WEAPONSYSTEM_API ABaseShotgun : public ABaseWeapon
{
	GENERATED_BODY()
	
public:
	ABaseShotgun();

	virtual void PostInitializeComponents() override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	
	
};
