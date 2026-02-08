// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class BLUEPRINTVSCPLUSPLUS_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Door Actions")
	void Open();

	UFUNCTION(BlueprintCallable, Category = "Door Actions")
	void Close();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Door Properties")
	float MoveSpeed = 50.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	float MoveIncrement = 50.0f;
	int32 YawOpenLimit;
	int32 YawCloseLimit;
};
