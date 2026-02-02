// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetupAttachment(RootComponent);
	DoorMesh->SetRelativeLocation(FVector(30.0f, 0.0f, 50.0f));
	DoorMesh->SetRelativeScale3D(FVector(0.6f, 0.1f, 1.0f));

	// Set a default cube mesh from the Engine's BasicShapes
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMesh.Succeeded())
	{
		DoorMesh->SetStaticMesh(CubeMesh.Object);
	}
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	FRotator currentRotation = this->GetActorRotation();
	YawOpenLimit = FMath::RoundToInt32(currentRotation.Yaw) - 90;
	YawCloseLimit = FMath::RoundToInt32(currentRotation.Yaw);
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MoveIncrement == 0.0f)
		return;

	RootComponent->AddRelativeRotation(FRotator(0.0f, MoveIncrement * DeltaTime, 0.0f));

	FRotator currentRotation = this->GetActorRotation();
	int32 yaw = FMath::RoundToInt32((currentRotation.Yaw < 0.0f) ? currentRotation.Yaw + 360.0f : currentRotation.Yaw);

	if (MoveIncrement < 0 && yaw <= YawOpenLimit)
	{
		MoveIncrement = 0.0f;
	}
	else if (MoveIncrement > 0 && yaw >= YawCloseLimit)
	{
		MoveIncrement = 0.0f;
	}
}

void ADoor::OpenDoor()
{
	MoveIncrement = -MoveSpeed;
}

void ADoor::CloseDoor()
{
	MoveIncrement = MoveSpeed;
}

