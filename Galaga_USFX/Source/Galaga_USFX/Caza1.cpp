// Fill out your copyright notice in the Description page of Project Settings.


#include "Caza1.h"
ACaza1::ACaza1() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void ACaza1::Mover() {
	
}
void ACaza1::Ataque() {

}
void ACaza1::Vida() {

}
void ACaza1::Bombardear() {

}
void ACaza1::Cargar_Sbomba() {

}
