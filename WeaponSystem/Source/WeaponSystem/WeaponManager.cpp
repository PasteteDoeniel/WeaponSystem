// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponManager.h"
#include "WeaponSystemCharacter.h"
#include "WeaponSystemProjectile.h"


// Sets default values for this component's properties
UWeaponManager::UWeaponManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWeaponManager::BeginPlay()
{
	Super::BeginPlay();

	//Sets Firerate TimeVariable
	FAssaultEnergyFireRateTime = 60.0f / FAssaultEnergyFireRate;

	// ...

}


// Called every frame
void UWeaponManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWeaponManager::FireWeapon(FVector SpawnPoint, FRotator SpawnRotation)
{
	switch (ProjectileEnum)
	{
	case EProjectileTypeEnum::PE_Energy:

		switch (WeaponEnum)
		{
		case EWeaponTypeEnum::WE_AssaultRifle:

			if (canFire)
			{
				if (ProjectileClass != NULL)
				{
					UWorld* const World = GetWorld();
					if (World != NULL)
					{
						//Set Spawn Collision Handling Override
						FActorSpawnParameters ActorSpawnParams;
						ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

						// spawn the projectile at the muzzle
						World->SpawnActor<AWeaponSystemProjectile>(ProjectileClass, SpawnPoint, SpawnRotation, ActorSpawnParams);

						//starts timer for firerate
						World->GetTimerManager().SetTimer(AssaultFireRateTimerHandle, this, &UWeaponManager::ResetFireRateTimer, FAssaultEnergyFireRateTime, false);
					}
				}
			}

			break;

		case EWeaponTypeEnum::WE_Shotgun:

			if (ProjectileClass != NULL)
			{
				UWorld* const World = GetWorld();
				if (World != NULL)
				{

					//Set Spawn Collision Handling Override
					FActorSpawnParameters ActorSpawnParams;
					ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

					for (int projectile = 0; projectile < IShotgunEnergyAmount; projectile++)
					{
						FTransform NewSPawnRotation(SpawnRotation);
						NewSPawnRotation.ConcatenateRotation(FRotator(FMath::FRandRange(-0.1f, 0.1f) * (FShotgunEnergySpread), (FMath::FRandRange(-0.1f, 0.1f) * (FShotgunEnergySpread)), 0).Quaternion());
						NewSPawnRotation.NormalizeRotation();

						AWeaponSystemProjectile* p = World->SpawnActor<AWeaponSystemProjectile>(ProjectileClass, SpawnPoint, NewSPawnRotation.Rotator(), ActorSpawnParams);//[projectile];
					}
				}
			}

			break;

		case EWeaponTypeEnum::WE_SniperRifle:

			break;
		}

		break;

	case EProjectileTypeEnum::PE_Projectile:

		switch (WeaponEnum)
		{
		case EWeaponTypeEnum::WE_AssaultRifle:

			break;

		case EWeaponTypeEnum::WE_Shotgun:

			break;

		case EWeaponTypeEnum::WE_SniperRifle:

			break;
		}

		break;
	}
}

void UWeaponManager::StopFireWeapon()
{
	GetWorld()->GetTimerManager().ClearTimer(AssaultFireRateTimerHandle);
}


void UWeaponManager::ResetFireRateTimer()
{
	AWeaponSystemCharacter* Owner = Cast<AWeaponSystemCharacter>(GetOwner());
	canFire = true;
	Owner->AutomaticFire();
}