// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "Components/ActorComponent.h"
#include "CharacterEquipmentComponent.generated.h"

class AEquipment;
class UConfigurationPrimarySlotDataAsset;
class UConfigurationSlotDataAsset;

UCLASS(ClassGroup=(Equipment), meta = (BlueprintSpawnableComponent))
class EQUIPMENTSYSTEM_API UCharacterEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	UCharacterEquipmentComponent();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	TArray<UConfigurationPrimarySlotDataAsset*> EquipmentSlots;

	UPROPERTY(VisibleInstanceOnly, Category = "Equipment")
	TMap<UConfigurationSlotDataAsset*, AEquipment*> Equipment;

protected:

	virtual void BeginPlay() override;

private:

	void SpawnEquipment();
};
