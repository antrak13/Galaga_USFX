// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveCaza.h"
ANaveCaza::ANaveCaza() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void ANaveCaza::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}
	void ANaveCaza::Mover(float DeltaTime) {
		//SetActorLocation(FVector(GetActorLocation().X - 1.75, GetActorLocation().Y, GetActorLocation().Z));

		if (GetActorLocation().X < -1800) {
			SetActorLocation(FVector(0.0f, 00, 250));
		}
	}

	void ANaveCaza::Ataque() {

	}
	void ANaveCaza::Vida() {

	 }
	void ANaveCaza::Bombardear() {

	}