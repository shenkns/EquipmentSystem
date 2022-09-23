// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#include "Equipment/Components/EquipmentSlotAttachComponent.h"

#include "Equipment/Equipment.h"

void UEquipmentSlotAttachComponent::InitEquipment()
{
	if(FEquipmentAttachData const* SlotAttachData = SlotsAttachData.Find(Equipment->GetSlot()))
	{
		AttachData = *SlotAttachData;
	}
	
	Super::InitEquipment();
}
