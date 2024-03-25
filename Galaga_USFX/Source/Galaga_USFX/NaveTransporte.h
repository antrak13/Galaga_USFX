// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave_Enemiga.h"
#include "NaveTransporte.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveTransporte : public ANave_Enemiga
{
	GENERATED_BODY()
private:
	int nNaves;
public:
	ANaveTransporte();
	FORCEINLINE int GetnumNaves() const { return nNaves; }
	FORCEINLINE void SetnumNaves(int _numNaves) { nNaves = _numNaves; }
	virtual void Tick(float DeltaTime);
protected:
	virtual void Mover(float DeltaTime);
	virtual void Soltar();
	virtual void Desaparecer();
};
