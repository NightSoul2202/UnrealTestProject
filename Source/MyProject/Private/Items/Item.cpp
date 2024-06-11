// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "MyProject/DebugMacros.h"

// Sets default values
AItem::AItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	/*UE_LOG(LogTemp, Warning, TEXT("Begin play called!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"));

	UWorld* world = GetWorld();

	DRAW_SPHERE(GetActorLocation());

	if (world)
	{
		FVector location = GetActorLocation();
		DrawDebugSphere(world, location, 10.f, 13, FColor::Cyan, false, 30.f);
	}*/

}

float AItem::TransformedSin()
{
	return amplitude * FMath::Sin(runningTime * timeConstant);
}

float AItem::TransformedCos()
{
	return amplitude* FMath::Cos(runningTime * timeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	runningTime += DeltaTime;
	/*UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %f"), DeltaTime);
	if (GEngine)
	{
		FString Name = GetName();
		FString Message = FString::Printf(TEXT("Item name: %s"), *Name);
		FString Message = FString::Printf(TEXT("Item name: %s"), *Name);
		GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, Message);

		UE_LOG(LogTemp, Warning, TEXT("DeltaTime: %s"), *Name);
	}*/


	/*float movementRate = 50.f;
	float rotationRate = 45.f;

	AddActorWorldOffset(FVector(movementRate * DeltaTime, 0.f, 0.f));
	AddActorWorldRotation(FRotator(rotationRate * DeltaTime, 0.f, 0.f));*/

	

	float deltaZ = TransformedSin();
	AddActorWorldOffset(FVector(0.f, 0.f, deltaZ));


	/*DRAW_SPHERE_SingleFrame(GetActorLocation());
	DRAW_VECTOR_SingleFrame(GetActorLocation(), GetActorLocation() + GetActorForwardVector() * 100.f);*/
}

