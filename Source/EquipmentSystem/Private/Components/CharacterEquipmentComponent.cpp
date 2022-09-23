// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#include "Components/CharacterEquipmentComponent.h"
#include "Equipment/Equipment.h"
#include "Libs/ProfileSystemLibrary.h"
#include "Profile/Data/Configuration/ConfigurationSlotDataAsset.h"
#include "Profile/Data/Configuration/Equipment/EquipmentDataAsset.h"
#include "Profile/Inventory/EquipmentItem.h"
#include "Profile/Stats/CharacterConfiguration.h"
#include "Profile/Stats/CharacterConfigurationStat.h"

UCharacterEquipmentComponent::UCharacterEquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UCharacterEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnEquipment();
}

void UCharacterEquipmentComponent::SpawnEquipment()
{
	const UCharacterConfigurationStat* Stat = UProfileSystemLibrary::GetStat<UCharacterConfigurationStat>();
	if(!Stat) return;

	const UCharacterConfiguration* Configuration = Stat->GetCurrentConfiguration();
	if(!Configuration) return;

	// Iterate Current Configuration Slots
	for(const TTuple<UConfigurationSlotDataAsset*, UCharacterConfigurationItem*>& Pair : Configuration->GetConfigurationItems())
	{
		if(!EquipmentSlots.Contains(Pair.Key->PrimarySlot)) continue;
		
		if(UEquipmentItem* Item = Cast<UEquipmentItem>(Pair.Value))
		{
			// Spawn Equipment
			AEquipment* NewEquipment = GetWorld()->SpawnActorDeferred<AEquipment>(Item->GetInventoryData<UEquipmentDataAsset>()->Class.LoadSynchronous(), GetOwner()->GetTransform(), GetOwner(), GetOwner<APawn>());
			NewEquipment->SetEquipmentEssentials(Pair.Key, Item);
			NewEquipment->FinishSpawning(GetOwner()->GetTransform());
			NewEquipment->InitEquipment();

			Equipment.Add(Pair.Key, NewEquipment);
		}
	}
}
