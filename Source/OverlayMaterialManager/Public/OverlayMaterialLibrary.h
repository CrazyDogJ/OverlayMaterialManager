// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "OverlayMaterialLibrary.generated.h"

UCLASS()
class OVERLAYMATERIALMANAGER_API UOverlayMaterialLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Overlay Material Library")
	static void SetScalarParameterValueOnOverlayMaterials(USkeletalMeshComponent* MeshComponent, const FName ParameterName, const float ParameterValue);

	UFUNCTION(BlueprintCallable, Category = "Overlay Material Library")
	static FVector FindClosestPointOnCapsule(const FVector& Point, const UCapsuleComponent* Capsule, bool& bIsInCapsule);

	UFUNCTION(BlueprintCallable, Category = "Overlay Material Library")
	static float GetDistanceToCapsule(const FVector& Location, const UCapsuleComponent* Capsule);
};
