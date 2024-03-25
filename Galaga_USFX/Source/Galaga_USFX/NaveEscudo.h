// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave_Enemiga.h"
#include "NaveEscudo.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveEscudo : public ANave_Enemiga
{
	GENERATED_BODY()
	int tEscudo;
public:
	ANaveEscudo();
	FORCEINLINE int GettimEscudo() const { return tEscudo; }
	FORCEINLINE void SettimEscudo(int _timEscudo) { tEscudo = _timEscudo; }
	virtual void Tick(float DeltaTime);
	
protected:
	virtual void Mover(float DeltaTime);
	virtual void Proteger();
	virtual void Desaparecer();
};
