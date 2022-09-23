// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "Managers/Stats/ProfileStat.h"
#include "Libs/ProfileSystemSerializationLibrary.h"
#include "Interfaces/SerializationInterface.h"
#include "CharacterConfigurationStat.generated.h"

class UCharacterConfiguration;

UCLASS()
class EQUIPMENTSYSTEM_API UCharacterConfigurationStat : public UProfileStat, public ISerializationInterface
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Instanced, Category = "Configuration")
	TArray<UCharacterConfiguration*> Configurations;

	UPROPERTY(EditDefaultsOnly, Category = "Configuration")
	int CurrentConfigurationIndex = 0;

	UPROPERTY()
	TArray<FObjectSaveData> ConfigurationsSaveData;

public:

	// Configurations Getters
	UFUNCTION(BlueprintPure, Category = "Configuration", meta = (CompactNodeTitle = "Configurations"))
	TArray<UCharacterConfiguration*> GetConfigurations() const { return Configurations; };
	
	UFUNCTION(BlueprintPure, Category = "Configuration", meta = (CompactNodeTitle = "Current"))
	UCharacterConfiguration* GetCurrentConfiguration() const;

	// Serialization
	virtual bool PreConvertToSaveData_Implementation() override;
	virtual bool PostConvertFromSaveData_Implementation() override;
};
