// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEscudo.h"
ANaveEscudo::ANaveEscudo() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe_180.Shape_Pipe_180'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void ANaveEscudo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}
void ANaveEscudo::Mover(float DeltaTime) {


	if (GetActorLocation().X < -1800) {
		SetActorLocation(FVector(0.0f, 00, 250));
	}
}
void ANaveEscudo::Proteger() {

}
void ANaveEscudo::Desaparecer() {

}