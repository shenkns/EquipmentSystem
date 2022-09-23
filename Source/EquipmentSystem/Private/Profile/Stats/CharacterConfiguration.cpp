// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#include "Profile/Stats/CharacterConfiguration.h"

#include "Libs/ProfileSystemLibrary.h"
#include "Managers/Stats/InventoryStat.h"
#include "Profile/Inventory/CharacterConfigurationItem.h"

bool UCharacterConfiguration::PreConvertToSaveData_Implementation()
{
	// Serialize Configuration Items
	CharacterConfigurationItemsSaveData.Empty();

	for(TTuple<UConfigurationSlotDataAsset*, UCharacterConfigurationItem*>& Pair : CharacterConfigurationItems)
	{
		UProfileSystemSerializationLibrary::ConvertObjectToSaveData<UCharacterConfigurationItem>(Pair.Value, CharacterConfigurationItemsSaveData.FindOrAdd(Pair.Key));
	}

	return true;
}

bool UCharacterConfiguration::PostConvertFromSaveData_Implementation()
{
	// Deserialize Configuration Items
	CharacterConfigurationItems.Empty();

	for(TTuple<UConfigurationSlotDataAsset*, FObjectSaveData>& Pair : CharacterConfigurationItemsSaveData)
	{
		if(UCharacterConfigurationItem* Item = UProfileSystemSerializationLibrary::ConvertSaveDataToObject<UCharacterConfigurationItem>(Pair.Value, this))
		{
			CharacterConfigurationItems.Add(Pair.Key, Item);
			continue;
		}

		CharacterConfigurationItems.Add(Pair.Key, nullptr);
	}

	return true;
}

UCharacterConfigurationItem* UCharacterConfiguration::GetItemInSlot(UConfigurationSlotDataAsset* Slot) const
{
	return *CharacterConfigurationItems.Find(Slot);
}

bool UCharacterConfiguration::SetItemInSlot(UConfigurationSlotDataAsset* Slot, UCharacterConfigurationItem* NewItem)
{
	if(!NewItem) return false;
	
	// Swap Items From Inventory And Configuration
	if(UInventoryStat* Inventory = UProfileSystemLibrary::GetInventoryStat())
	{
		// Find Item In Selected Slot
		if(UCharacterConfigurationItem** OldItem = CharacterConfigurationItems.Find(Slot))
		{
			Inventory->AddItem(*OldItem);
			*OldItem = NewItem;
		}
		else
		{
			CharacterConfigurationItems.Add(Slot, NewItem);
		}

		// Move Item To Configuration
		Inventory->RemoveItem(NewItem);
		NewItem->Rename(nullptr, this);

		UProfileSystemLibrary::SaveProfile();

		return true;
	}

	return false;
}
