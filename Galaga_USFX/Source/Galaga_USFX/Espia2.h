// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEspia.h"
#include "Espia2.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API AEspia2 : public ANaveEspia
{
	GENERATED_BODY()
private:
	int multiplicadorbonus;
public:
	AEspia2();
	FORCEINLINE int GetMultiplicadorBonus() const { return multiplicadorbonus; }

	FORCEINLINE void SetMultiplicadorBonus(int _multiplicadorbonus) { multiplicadorbonus = _multiplicadorbonus; }
protected:
	virtual void Mover();
	virtual void Ataque();
	virtual void Ocultar();
	virtual void Cadenciaplus();
};
