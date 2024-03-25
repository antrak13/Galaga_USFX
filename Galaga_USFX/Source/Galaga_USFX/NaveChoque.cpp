// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveChoque.h"
ANaveChoque::ANaveChoque() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void ANaveChoque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}

void ANaveChoque::Mover(float DeltaTime) {
	

	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(0.0f, 00, 250));
	}
}
void ANaveChoque::Acelerar() {

}
void ANaveChoque::Destruir() {

}
