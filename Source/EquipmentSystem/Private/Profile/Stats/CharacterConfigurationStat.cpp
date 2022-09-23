// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#include "Profile/Stats/CharacterConfigurationStat.h"

#include "Profile/Stats/CharacterConfiguration.h"

bool UCharacterConfigurationStat::PreConvertToSaveData_Implementation()
{
	return UProfileSystemSerializationLibrary::ConvertObjectsToSaveData<UCharacterConfiguration>(Configurations, ConfigurationsSaveData);
}

bool UCharacterConfigurationStat::PostConvertFromSaveData_Implementation()
{
	Configurations = UProfileSystemSerializationLibrary::ConvertSaveDataToObjects<UCharacterConfiguration>(ConfigurationsSaveData, this);

	return true;
}

UCharacterConfiguration* UCharacterConfigurationStat::GetCurrentConfiguration() const
{
	return Configurations.IsValidIndex(CurrentConfigurationIndex) ? Configurations[CurrentConfigurationIndex] : nullptr;
}
