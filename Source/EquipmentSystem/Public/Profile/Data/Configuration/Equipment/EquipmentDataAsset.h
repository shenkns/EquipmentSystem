// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "Profile/Data/Configuration/ConfigurationItemDataAsset.h"
#include "EquipmentDataAsset.generated.h"

class AEquipment;
class UEquipmentTypeDataAsset;

UCLASS()
class EQUIPMENTSYSTEM_API UEquipmentDataAsset : public UConfigurationItemDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	TSoftClassPtr<AEquipment> Class;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment")
	UEquipmentTypeDataAsset* Type;
};
