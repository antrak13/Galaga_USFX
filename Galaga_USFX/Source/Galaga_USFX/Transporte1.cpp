// Fill out your copyright notice in the Description page of Project Settings.


#include "Transporte1.h"
ATransporte1::ATransporte1() {
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
    mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void ATransporte1::Mover() {
 
}
void ATransporte1::Descargar() {

}
void ATransporte1::Desaparecer() {

}
