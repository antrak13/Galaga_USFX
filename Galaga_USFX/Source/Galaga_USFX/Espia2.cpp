// Fill out your copyright notice in the Description page of Project Settings.


#include "Espia2.h"
AEspia2::AEspia2() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void AEspia2::Mover() {
	
}
void AEspia2::Ataque() {

}
void AEspia2::Ocultar() {

}
void AEspia2::Cadenciaplus() {

}
