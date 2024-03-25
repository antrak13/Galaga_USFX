// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveCaza.h"
#include "Caza1.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_API ACaza1 : public ANaveCaza
{
	GENERATED_BODY()
private:
	bool super_bomba;
public:
	ACaza1();
	FORCEINLINE bool SetSuper_bomba() const { return super_bomba; }
	FORCEINLINE void GetSuper_bomba(bool _super_bomba) { super_bomba = _super_bomba; }
protected:
	virtual void Mover();
	virtual void Ataque();
	virtual void Vida();
	virtual void Bombardear();
	virtual void Cargar_Sbomba();
};
