// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlayMaterialTestActor.h"

#include "OverlayMaterialDataAsset.h"

AOverlayMaterialTestActor::AOverlayMaterialTestActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsEditorOnlyActor = true;
}

void AOverlayMaterialTestActor::RefreshOverlayMaterials() const
{
	if (OverlayMaterialDataAsset)
	{
		OverlayMaterialDataAsset->SetOverlayMaterials(GetSkeletalMeshComponent(), true, false);
	}
}
