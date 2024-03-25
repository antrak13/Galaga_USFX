// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveChoque.h"
#include "Choque2.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API AChoque2 : public ANaveChoque
{
	GENERATED_BODY()
private:
	int aVelocidad;
public:
	AChoque2();
	FORCEINLINE int GetAVelocidad() const { return aVelocidad; }
	FORCEINLINE void SetAVelocidads(int _aVelocidad) { aVelocidad = _aVelocidad; }
protected:
	virtual void Mover();
	virtual void Acelerar();
	virtual void Destruir();
};
