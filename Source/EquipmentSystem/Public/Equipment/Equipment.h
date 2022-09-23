// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "GameFramework/Actor.h"
#include "Profile/Inventory/EquipmentItem.h"
#include "Equipment.generated.h"

class UConfigurationSlotDataAsset;
class UEquipmentItem;
class UEquipmentComponent;

UCLASS()
class EQUIPMENTSYSTEM_API AEquipment : public AActor
{
	GENERATED_BODY()

public:

	AEquipment();

protected:

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Equipment")
	UConfigurationSlotDataAsset* Slot;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Equipment")
	UEquipmentItem* Item;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Components")
	TArray<UEquipmentComponent*> Components;

public:

	// Equipment Getters
	UFUNCTION(BlueprintPure, Category = "Equipment", meta = (CompactNodeTitle = "Slot"))
	UConfigurationSlotDataAsset* GetSlot() const { return Slot; };

	UFUNCTION(BlueprintPure, Category = "Equipment", meta = (CompactNodeTitle = "Item"))
	UEquipmentItem* GetItem() const { return Item; };
	
	// Initialization
	void SetEquipmentEssentials(UConfigurationSlotDataAsset* Slot, UEquipmentItem* Item);

	virtual void InitEquipment();

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Equipment")
	void Init();

private:

	void InitComponents();
};
