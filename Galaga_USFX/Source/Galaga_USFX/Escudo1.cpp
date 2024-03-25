// Fill out your copyright notice in the Description page of Project Settings.


#include "Escudo1.h"
AEscudo1::AEscudo1() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Pipe_180.Shape_Pipe_180'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void AEscudo1::Mover() {
	
}
void AEscudo1::Proteger() {

}
void AEscudo1::Desaparecer() {

}
