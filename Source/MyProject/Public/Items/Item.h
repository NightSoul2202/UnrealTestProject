// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class MYPROJECT_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AItem();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure)
	float TransformedSin();
	
	UFUNCTION(BlueprintPure)
	float TransformedCos();

private:
	UPROPERTY(EditAnywhere)
	float amplitude = 0.25f;

	UPROPERTY(EditAnywhere)
	float timeConstant = 5.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float runningTime;
};
