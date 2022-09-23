// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#include "Equipment/Equipment.h"

#include "Equipment/Components/EquipmentComponent.h"

AEquipment::AEquipment()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AEquipment::SetEquipmentEssentials(UConfigurationSlotDataAsset* EquipmentSlot, UEquipmentItem* EquipmentItem)
{
	Slot = EquipmentSlot;
	Item = EquipmentItem;
}

void AEquipment::InitEquipment()
{
	InitComponents();
	
	Init();
}

void AEquipment::InitComponents()
{
	
	GetComponents<UEquipmentComponent>(Components);
	
	for(UEquipmentComponent* Component : Components)
	{
		Component->InitEquipment();
	}
}
