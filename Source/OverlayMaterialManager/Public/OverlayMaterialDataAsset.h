// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "OverlayMaterialDataAsset.generated.h"

class UMaterialInstanceDynamic;
class UMaterialInterface;
class USkeletalMesh;
class USkeletalMeshComponent;

UCLASS(BlueprintType)
class OVERLAYMATERIALMANAGER_API UOverlayMaterialDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Overlay Manager")
	TObjectPtr<USkeletalMesh> SkeletalMeshAsset;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Overlay Manager")
	TArray<TObjectPtr<UMaterialInterface>> OverlayMaterials;

	UFUNCTION(BlueprintCallable, Category = "Overlay Manager")
	void SetOverlayMaterials(USkeletalMeshComponent* InComponent, bool bSetMesh = true, bool bDynamicMaterial = true);
	
protected:
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
};
