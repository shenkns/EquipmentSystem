// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "Managers/Data/ProfileSystemDataAsset.h"
#include "CharacterClassDataAsset.generated.h"

class UEquipmentTypeDataAsset;

UCLASS()
class EQUIPMENTSYSTEM_API UCharacterClassDataAsset : public UProfileSystemDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterClass")
	TMap<UEquipmentTypeDataAsset*, float> StrengthenedEquipmentTypes;
};
