// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEspia.h"
ANaveEspia::ANaveEspia() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void ANaveEspia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}
void ANaveEspia::Mover(float DeltaTime) {


	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(0.0f, 00, 250));
	}
}
void ANaveEspia::Ocultar() {

}
void ANaveEspia::Ataque() {

}
