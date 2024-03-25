// Fill out your copyright notice in the Description page of Project Settings.


#include "Caza2.h"
ACaza2::ACaza2() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_QuadPyramid.Shape_QuadPyramid'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void ACaza2::Mover() {
	
}
void ACaza2::Ataque() {

}
void ACaza2::Lanzar() {

}
