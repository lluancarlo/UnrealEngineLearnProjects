// Fill out your copyright notice in the Description page of Project Settings.


#include "PresurePlate.h"
#include <Components/SphereComponent.h>
#include <BlueprintVsCPlusPlusCharacter.h>

// Sets default values
APresurePlate::APresurePlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	PresurePlateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PresurePlateMesh"));
	PresurePlateMesh->SetupAttachment(RootComponent);

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SphereCollider->SetupAttachment(RootComponent);

	//PresurePlateMesh->SetRelativeLocation(FVector(30.0f, 0.0f, 50.0f));
	//PresurePlateMesh->SetRelativeScale3D(FVector(0.6f, 0.1f, 1.0f));

	// Set a default cube mesh from the Engine's BasicShapes
	/*static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (CubeMesh.Succeeded())
	{
		DoorMesh->SetStaticMesh(CubeMesh.Object);
	}*/
}

// Called when the game starts or when spawned
void APresurePlate::BeginPlay()
{
	Super::BeginPlay();

	if (DoorRef)
	{
		SphereCollider->OnComponentBeginOverlap.AddDynamic(this, &APresurePlate::OnPressed);
		SphereCollider->OnComponentEndOverlap.AddDynamic(this, &APresurePlate::OnReleased);
	}
}

// Called every frame
void APresurePlate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APresurePlate::OnPressed(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnPressed"));
	if (OtherActor->IsA(ABlueprintVsCPlusPlusCharacter::StaticClass()) && DoorRef)
	{
		DoorRef->Open();
	}
}

void APresurePlate::OnReleased(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("OnReleased"));
	if (OtherActor->IsA(ABlueprintVsCPlusPlusCharacter::StaticClass()) && DoorRef)
	{
		DoorRef->Close();
	}
}
