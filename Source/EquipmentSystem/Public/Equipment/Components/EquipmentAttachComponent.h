// Copyright shenkns Equipment System Developed With Unreal Engine. All Rights Reserved 2022.

#pragma once

#include "Equipment/Components/EquipmentComponent.h"
#include "EquipmentAttachComponent.generated.h"

USTRUCT(BlueprintType)
struct FEquipmentAttachData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment|Attach")
	FName SocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment|Attach")
	FVector Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Equipment|Attach")
	FRotator Rotation;
};

UCLASS(ClassGroup = (Equipment), meta = (BlueprintSpawnableComponent))
class EQUIPMENTSYSTEM_API UEquipmentAttachComponent : public UEquipmentComponent
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Equipment|Attach")
	FEquipmentAttachData AttachData;

public:

	virtual void InitEquipment() override;
};
