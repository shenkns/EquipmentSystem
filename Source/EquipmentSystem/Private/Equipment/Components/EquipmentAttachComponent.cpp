// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#include "Equipment/Components/EquipmentAttachComponent.h"

#include "Equipment/Equipment.h"

void UEquipmentAttachComponent::InitEquipment()
{
	Equipment->AttachToActor(Equipment->GetInstigator(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, AttachData.SocketName);

	Equipment->SetActorRelativeLocation(AttachData.Location);
	Equipment->SetActorRelativeRotation(AttachData.Rotation);
	
	Super::InitEquipment();
}
