// Fill out your copyright notice in the Description page of Project Settings.


#include "Escudo2.h"
AEscudo2::AEscudo2() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe_180.Shape_Pipe_180'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void AEscudo2::Mover() {
	
}
void AEscudo2::Proteger() {

}
void AEscudo2::Desaparecer() {

}

