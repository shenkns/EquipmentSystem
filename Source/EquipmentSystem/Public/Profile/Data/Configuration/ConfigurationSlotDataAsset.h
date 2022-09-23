// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "Managers/Data/ProfileSystemDataAsset.h"
#include "ConfigurationSlotDataAsset.generated.h"

class UConfigurationPrimarySlotDataAsset;

UCLASS()
class EQUIPMENTSYSTEM_API UConfigurationSlotDataAsset : public UProfileSystemDataAsset
{
	GENERATED_BODY()

public:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Configuration|Slot")
	UConfigurationPrimarySlotDataAsset* PrimarySlot;
};
