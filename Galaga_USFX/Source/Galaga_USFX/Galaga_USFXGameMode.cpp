// Copyright Epic Games, Inc. All Rights Reserved.
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include "Galaga_USFXGameMode.h"
#include "Galaga_USFXPawn.h"
#include "Nave_Enemiga.h"
#include "Caza1.h"
#include "Caza2.h"
#include "Choque1.h"
#include "Choque2.h"
#include "Escudo1.h"
#include "Escudo2.h"
#include "Espia1.h"
#include "Espia2.h"
#include "Transporte1.h"
#include "Transporte2.h"

AGalaga_USFXGameMode::AGalaga_USFXGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFXPawn::StaticClass();
	NaveEnemiga01 = nullptr;
}

void AGalaga_USFXGameMode::BeginPlay()
{
	Super::BeginPlay();
	//Set the game state to playing

	FVector ubicacionInicial = FVector(0.0f, 50.0f, 250.0f);
	//FVector ubicacionNave02 = FVector(-500.0f, -500.0f, 250.0f);
	//lo de arriba es para nave enemiga heredada
	FRotator rotacionNave = FRotator(2.0f, 2.0f, 0.0f);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		// spawn the projectile
		
		NaveEnemiga01 = World->SpawnActor<ANave_Enemiga>(ubicacionInicial, rotacionNave);
	}
	TArray<TSubclassOf<ANave_Enemiga>>NavesArray;
	int x;
	
	srand(time(NULL));
	for (int i = 0; i < 30; i++) {
		x=1+rand() % (10);
		switch (x)
		{
		case 1:
			NavesArray.Add(ACaza1::StaticClass());
			
			break;
		case 2:
			NavesArray.Add(ACaza2::StaticClass());

			break;
		case 3:
			NavesArray.Add(AChoque1::StaticClass());
			break;
		case 4:
			NavesArray.Add(AChoque2::StaticClass());
			break;
		case 5:
			NavesArray.Add(AEscudo1::StaticClass());
			break;
		case 6:
			NavesArray.Add(AEscudo2::StaticClass());
			break;
		case 7:
			NavesArray.Add(AEspia1::StaticClass());
			break;
		case 8:
			NavesArray.Add(AEspia2::StaticClass());
			break;
		case 9:
			NavesArray.Add(ATransporte1::StaticClass());
			break;
		case 10:
			NavesArray.Add(ATransporte2::StaticClass());
			break;
		}
	}
	int a = -500.0f;
	int b = -300.0f;
	int c = 0;
	for (const TSubclassOf<ANave_Enemiga>& ClaseNave : NavesArray)
	{
		/*if (ClaseNave)
		{
			// Spawnear la nave enemiga
			FVector SpawnLocation = ubicacionInicial + FVector(FMath::RandRange(-500.0f, 500.0f), FMath::RandRange(-500.0f, 500.0f), 0.0f);
			FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
			World->SpawnActor<ANave_Enemiga>(ClaseNave, SpawnLocation, SpawnRotation);
		}*/
		if (ClaseNave)
		{
			// Spawnear la nave enemiga
				
			FVector SpawnLocation = ubicacionInicial + FVector(b, a, 0.0f);
					FRotator SpawnRotation = FRotator(0.0f, 0.0f, 0.0f);
					World->SpawnActor<ANave_Enemiga>(ClaseNave, SpawnLocation, SpawnRotation);
					a = a + 200;
					c = c + 1;
					if (c == 6)
					{
						b = b + 200;
						c = 0;
						a = -500.0f;
					}
		}
	}
}


