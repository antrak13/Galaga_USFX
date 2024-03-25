// Fill out your copyright notice in the Description page of Project Settings.


#include "Choque2.h"
AChoque2::AChoque2() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void AChoque2::Mover() {
	
}
void AChoque2::Acelerar() {

}
void AChoque2::Destruir() {

}
