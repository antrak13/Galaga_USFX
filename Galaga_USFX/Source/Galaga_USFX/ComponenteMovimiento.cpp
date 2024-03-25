// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponenteMovimiento.h"

// Sets default values for this component's properties
UComponenteMovimiento::UComponenteMovimiento()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	//MovimientoSig = 5;
	MovimientoSig = 5;
	/*MovimientoSag = 100.0f;
	bMovimientoDerecha = true;*/
	bMovimientoArriba = true;
}


// Called when the game starts
void UComponenteMovimiento::BeginPlay()
{
	Super::BeginPlay() ;

	// ...
	
}


// Called every frame
void UComponenteMovimiento::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	AActor* Parent = GetOwner();
	if (Parent)
	{
		// Encuentra una nueva posición para que vaya el objeto
		auto NuevaPosicion = Parent->GetActorLocation() + FVector(bMovimientoArriba ? MovimientoSig : -MovimientoSig,
			bMovimientoArriba ? MovimientoSig : -MovimientoSig, 0.0f);
		//Actualiza la posición del objeto
		Parent->SetActorLocation(NuevaPosicion);
	/*	FVector Movimiento = FVector(bMovimientoArriba ? MovimientoSig : -MovimientoSig,
			bMovimientoArriba ? MovimientoSig : -MovimientoSig, 0.0f);*/
		if (bMovimientoArriba && GetOwner()->GetActorLocation().X >= 1000.0f)
		{
			bMovimientoArriba = false;
		}
		else if (!bMovimientoArriba && GetOwner()->GetActorLocation().X <= 0.0f)
		{
			bMovimientoArriba = true;
		}
		if (bMovimientoArriba && GetOwner()->GetActorLocation().Y >= 1000.0f)
		{
			bMovimientoArriba = false;
		}
		else if (!bMovimientoArriba && GetOwner()->GetActorLocation().Y <= 0.0f)
		{
			bMovimientoArriba = true;
		}
		//Parent->SetActorLocation(Movimiento);
	}
	
	/*float DesplazamientoHorizontal = MovimientoSig * DeltaTime;
	float DesplazamientoVertical = MovimientoSag * DeltaTime;
	// Si está moviéndose hacia la derecha, incrementa la posición horizontal
	// Si está moviéndose hacia la izquierda, decrementa la posición horizontal
	FVector Movimiento = FVector(bMovimientoDerecha ? DesplazamientoHorizontal : -DesplazamientoHorizontal, 
		bMovimientoArriba ? DesplazamientoVertical : -DesplazamientoVertical, 0.0f);

	// Aplica el desplazamiento a la posición actual del actor
	GetOwner()->AddActorLocalOffset(Movimiento, true);

	// Cambia la dirección del movimiento si alcanza un límite
	if (bMovimientoDerecha && GetOwner()->GetActorLocation().X >= 1000.0f)
	{
		bMovimientoDerecha = false; // Cambia a moverse hacia la izquierda
	}
	else if (!bMovimientoDerecha && GetOwner()->GetActorLocation().X <= 0.0f)
	{
		bMovimientoDerecha = true; // Cambia a moverse hacia la derecha
	}
	// Cambia la dirección del movimiento vertical si alcanza un límite
	if (bMovimientoArriba && GetOwner()->GetActorLocation().Y >= 1000.0f)
	{
		bMovimientoArriba = false;
	}
	else if (!bMovimientoArriba && GetOwner()->GetActorLocation().Y <= 0.0f)
	{
		bMovimientoArriba = true;
	}*/
}

