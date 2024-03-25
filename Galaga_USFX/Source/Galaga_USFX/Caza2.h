// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveCaza.h"
#include "Caza2.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ACaza2 : public ANaveCaza
{
	GENERATED_BODY()
private:
	int misiles;
	float tMisiles;
public:
	ACaza2();
	FORCEINLINE int GetMisiles() const { return misiles; }
	FORCEINLINE void SetMisiles(int _misiles) { misiles = _misiles; }
	FORCEINLINE float SetTMisiles() const { return tMisiles; }
	FORCEINLINE void GetTMisiles(float _tMisiles) { tMisiles = _tMisiles; }
protected:
	virtual void Mover();
	virtual void Ataque();
	virtual void Lanzar();
};
