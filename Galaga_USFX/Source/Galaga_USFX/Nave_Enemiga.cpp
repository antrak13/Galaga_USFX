// Fill out your copyright notice in the Description page of Project Settings.


#include "Nave_Enemiga.h"
//#include"ComponenteMovimiento.h"

// Sets default values
ANave_Enemiga::ANave_Enemiga()

{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ComponenteMovimiento = CreateDefaultSubobject<UComponenteMovimiento>(TEXT("ComponenteMovimiento"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cone.Shape_Cone'"));
	// Create the mesh component
	mallaNaveEnemiga = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	//mallaNaveEnemiga->SetStaticMesh(ShipMesh.Object);
	mallaNaveEnemiga->SetupAttachment(RootComponent);
	RootComponent = mallaNaveEnemiga;

	
}

// Called when the game starts or when spawned
void ANave_Enemiga::BeginPlay()
{
	Super::BeginPlay() ;
	
	
}

// Called every frame
void ANave_Enemiga::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

