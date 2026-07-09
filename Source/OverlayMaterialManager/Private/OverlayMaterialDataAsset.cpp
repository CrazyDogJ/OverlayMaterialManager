// Fill out your copyright notice in the Description page of Project Settings.


#include "OverlayMaterialDataAsset.h"

#include "Engine/SkeletalMesh.h"
#include "Components/SkeletalMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

void UOverlayMaterialDataAsset::SetOverlayMaterials(USkeletalMeshComponent* InComponent, bool bSetMesh, bool bDynamicMaterial)
{
	if (InComponent)
	{
		// Set skeletal mesh asset when not equal.
		if (InComponent->GetSkeletalMeshAsset() != SkeletalMeshAsset)
		{
			if (bSetMesh)
			{
				InComponent->SetSkeletalMesh(SkeletalMeshAsset);
			}
		}

		// Set overlay materials when equal.
		if (InComponent->GetSkeletalMeshAsset() == SkeletalMeshAsset)
		{
			TArray<TObjectPtr<UMaterialInterface>> OutOverlayMaterials;
			for (const auto MI : OverlayMaterials)
			{
				if (MI)
				{
					if (bDynamicMaterial)
					{
						UMaterialInstanceDynamic* MID = UMaterialInstanceDynamic::Create(MI, InComponent);
						OutOverlayMaterials.Add(MID);
					}
					else
					{
						OutOverlayMaterials.Add(MI);
					}
				}
				else
				{
					OutOverlayMaterials.Add(nullptr);
				}
			}

			InComponent->MaterialSlotsOverlayMaterial = OutOverlayMaterials;
			InComponent->PrecachePSOs();
			InComponent->MarkRenderStateDirty();
		}
	}
}

void UOverlayMaterialDataAsset::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(ThisClass, SkeletalMeshAsset))
	{
		if (SkeletalMeshAsset)
		{
			OverlayMaterials.SetNum(SkeletalMeshAsset->GetNumMaterials());
		}
	}
}
