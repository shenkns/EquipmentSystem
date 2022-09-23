// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#include "Equipment/Components/EquipmentComponent.h"

#include "Equipment/Equipment.h"

UEquipmentComponent::UEquipmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UEquipmentComponent::InitEquipment()
{
	Init();
}

void UEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	Equipment = GetOwner<AEquipment>();
}
