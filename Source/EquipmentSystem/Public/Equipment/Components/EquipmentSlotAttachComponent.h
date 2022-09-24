// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "Equipment/Components/EquipmentAttachComponent.h"
#include "EquipmentSlotAttachComponent.generated.h"

class UConfigurationSlotDataAsset;

UCLASS(ClassGroup = (Equipment), HideCategories = ("Equipment|Attach"), meta = (BlueprintSpawnableComponent))
class EQUIPMENTSYSTEM_API UEquipmentSlotAttachComponent : public UEquipmentAttachComponent
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment|SlotAttach")
	TMap<UConfigurationSlotDataAsset*, FEquipmentAttachData> SlotsAttachData;

public:

	virtual void InitEquipment() override;
};
