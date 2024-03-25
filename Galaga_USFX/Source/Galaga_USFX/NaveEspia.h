// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Nave_Enemiga.h"
#include "NaveEspia.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ANaveEspia : public ANave_Enemiga
{
	GENERATED_BODY()
private:
	int tcamuflaje;
public:
	ANaveEspia();
	FORCEINLINE int GettimCamuflaje() const { return  tcamuflaje; }
	FORCEINLINE void SettimCamuflaje(int _timCamuflaje) { tcamuflaje = _timCamuflaje; }
	virtual void Tick(float DeltaTime);
protected:
	virtual void Mover(float DeltaTime);
	virtual void Ocultar();
	virtual void Ataque();
};
