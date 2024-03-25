// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveTransporte.h"

ANaveTransporte::ANaveTransporte() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void ANaveTransporte::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}
void ANaveTransporte::Mover(float DeltaTime) {


	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(0.0f, 00, 250));
	}
}
void ANaveTransporte::Soltar() {

}
void ANaveTransporte::Desaparecer() {

}