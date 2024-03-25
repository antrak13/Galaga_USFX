// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFXGameMode.generated.h"

class ANave_Enemiga;
UCLASS(MinimalAPI)
class AGalaga_USFXGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFXGameMode();
public:
	ANave_Enemiga* NaveEnemiga01;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};



