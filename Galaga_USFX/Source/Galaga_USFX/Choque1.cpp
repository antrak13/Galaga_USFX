// Fill out your copyright notice in the Description page of Project Settings.


#include "Choque1.h"
AChoque1::AChoque1() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void AChoque1::Mover() {
	
}
void AChoque1::Acelerar() {

}
void AChoque1::Destruir() {

}
