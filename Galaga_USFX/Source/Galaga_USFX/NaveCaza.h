// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave_Enemiga.h"
#include "NaveCaza.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveCaza : public ANave_Enemiga
{
	GENERATED_BODY()
private:
	int nBombas;
public:
	ANaveCaza();
	FORCEINLINE int GetnumBombas() const { return nBombas; }
	FORCEINLINE void SetnumBombas(int _numBombas) { nBombas = _numBombas; }
	virtual void Tick(float DeltaTime) ;
protected:
	virtual void Mover(float DeltaTime);
	virtual void Ataque();
	virtual void Vida();
	virtual void Bombardear();
};
