// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "Managers/Data/Inventory/InventoryItemDataAsset.h"
#include "ConfigurationItemDataAsset.generated.h"

class UConfigurationPrimarySlotDataAsset;

UCLASS()
class EQUIPMENTSYSTEM_API UConfigurationItemDataAsset : public UInventoryItemDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration")
	UConfigurationPrimarySlotDataAsset* PrimarySlot;
};
