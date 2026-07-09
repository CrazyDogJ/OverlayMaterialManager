// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/SkeletalMeshActor.h"
#include "OverlayMaterialTestActor.generated.h"

class UOverlayMaterialDataAsset;

UCLASS()
class OVERLAYMATERIALMANAGER_API AOverlayMaterialTestActor : public ASkeletalMeshActor
{
	GENERATED_BODY()

public:
	AOverlayMaterialTestActor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Overlay Manager")
	TObjectPtr<UOverlayMaterialDataAsset> OverlayMaterialDataAsset = nullptr;

	UFUNCTION(CallInEditor, Category = "Overlay Manager")
	void RefreshOverlayMaterials() const;
};
