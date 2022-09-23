// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "Profile/Data/Configuration/ConfigurationItemDataAsset.h"
#include "CharacterDataAsset.generated.h"

class URarityDataAsset;
class UCharacterClassDataAsset;

UCLASS()
class EQUIPMENTSYSTEM_API UCharacterDataAsset : public UConfigurationItemDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character")
	URarityDataAsset* Rarity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character")
	UCharacterClassDataAsset* CharacterClass;
};
