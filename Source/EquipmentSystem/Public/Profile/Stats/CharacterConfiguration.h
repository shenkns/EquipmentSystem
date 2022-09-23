// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "UObject/Object.h"
#include "Interfaces/SerializationInterface.h"
#include "Libs/ProfileSystemSerializationLibrary.h"
#include "Profile/Inventory/CharacterConfigurationItem.h"
#include "CharacterConfiguration.generated.h"

class UConfigurationSlotDataAsset;
class UCharacterConfigurationItem;

UCLASS(BlueprintType, EditInlineNew, DefaultToInstanced)
class EQUIPMENTSYSTEM_API UCharacterConfiguration : public UObject, public ISerializationInterface
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, SkipSerialization, Instanced, Category = "Configuration")
	TMap<UConfigurationSlotDataAsset*, UCharacterConfigurationItem*> CharacterConfigurationItems;

	UPROPERTY()
	TMap<UConfigurationSlotDataAsset*, FObjectSaveData> CharacterConfigurationItemsSaveData;

public:

	// Manage Configuration
	UFUNCTION(BlueprintPure, Category = "Configuration", meta = (CompactNodeTitle = "Items"))
	TMap<UConfigurationSlotDataAsset*, UCharacterConfigurationItem*> GetConfigurationItems() const {return CharacterConfigurationItems; };

	UFUNCTION(BlueprintPure, Category = "Configuration", meta = (CompactNodeTitle = "Item"))
	UCharacterConfigurationItem* GetItemInSlot(UConfigurationSlotDataAsset* Slot) const;

	UFUNCTION(BlueprintCallable, Category = "Configuration", meta = (CompactNodeTitle = "Set"))
	bool SetItemInSlot(UConfigurationSlotDataAsset* Slot, UCharacterConfigurationItem* NewItem);
	
	// Serialization
	virtual bool PreConvertToSaveData_Implementation() override;
	virtual bool PostConvertFromSaveData_Implementation() override;
};
