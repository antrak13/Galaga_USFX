// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave_Enemiga.h"
#include "NaveChoque.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveChoque : public ANave_Enemiga
{
	GENERATED_BODY()
private:
	float fImpacto;
	float vAtaque;
public:
	ANaveChoque();
	FORCEINLINE float GetFImpacto() const { return fImpacto; }
	FORCEINLINE float GetvAtaque() const { return vAtaque;}

	FORCEINLINE void SetFImpacto(float _fImpacto) { fImpacto = _fImpacto; }
	FORCEINLINE void SetVAtaque(float _vAtaque) { vAtaque = _vAtaque;}
	virtual void Tick(float DeltaTime);
	
protected:
	virtual void Mover(float DeltaTimme);
	virtual void Acelerar();
	virtual void Destruir();
};
