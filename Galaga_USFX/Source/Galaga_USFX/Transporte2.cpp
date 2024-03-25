// Fill out your copyright notice in the Description page of Project Settings.


#include "Transporte2.h"
ATransporte2::ATransporte2() {
    static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
    mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
}
void ATransporte2::Mover() {
   
}
void ATransporte2::Descargar() {

}
void ATransporte2::Desaparecer() {

}

