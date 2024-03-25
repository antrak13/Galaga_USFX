// Fill out your copyright notice in the Description page of Project Settings.


#include "Espia1.h"
AEspia1::AEspia1() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void AEspia1::Mover() {

}
void AEspia1::Ataque() {

}
void AEspia1::Ocultar() {

}
void AEspia1::Velocidadplus() {

}
