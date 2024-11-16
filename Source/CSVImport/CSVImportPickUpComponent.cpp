// Copyright Epic Games, Inc. All Rights Reserved.

#include "CSVImportPickUpComponent.h"

UCSVImportPickUpComponent::UCSVImportPickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UCSVImportPickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UCSVImportPickUpComponent::OnSphereBeginOverlap);
}

void UCSVImportPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	ACSVImportCharacter* Character = Cast<ACSVImportCharacter>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
