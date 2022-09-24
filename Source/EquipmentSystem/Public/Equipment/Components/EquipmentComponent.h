// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "Components/ActorComponent.h"
#include "EquipmentComponent.generated.h"

class AEquipment;

UCLASS(ClassGroup = (Equipment), meta = (BlueprintSpawnableComponent))
class EQUIPMENTSYSTEM_API UEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	
	UEquipmentComponent();

protected:

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Equipment")
	AEquipment* Equipment;

public:

	virtual void InitEquipment();

protected:
	
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent, Category = "Equipment")
	void Init();
};
