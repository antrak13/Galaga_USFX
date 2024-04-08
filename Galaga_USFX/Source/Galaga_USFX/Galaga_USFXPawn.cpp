// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFXPawn.h"
#include "Galaga_USFXProjectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/EngineTypes.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "GameFramework/PlayerInput.h"

const FName AGalaga_USFXPawn::MoveForwardBinding("MoveForward");
const FName AGalaga_USFXPawn::MoveRightBinding("MoveRight");
const FName AGalaga_USFXPawn::FireForwardBinding("FireForward");
const FName AGalaga_USFXPawn::FireRightBinding("FireRight");

AGalaga_USFXPawn::AGalaga_USFXPawn()
{	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));

	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);
	
	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;
	//salto
    bIsJumping = false;
	JumpForce = 300;
	 ubicacionInicial = GetActorLocation();
	 ubicacionInicialX = GetActorLocation().X;
	 ubicacionInicialY = GetActorLocation().Y;
	//movimientoY = true;
	mover = false;

}
void AGalaga_USFXPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);
	//Salto
	 // Definir y registrar un mapeo de acción
	FInputActionKeyMapping saltar("Saltar", EKeys::T, 0, 0, 0, 0);
	UPlayerInput::AddEngineDefinedActionMapping(saltar);

	// Asociar el mapeo de tecla de acción con una función de la clase AWarrior
	PlayerInputComponent->BindAction("Saltar", IE_Pressed, this, &AGalaga_USFXPawn::Saltar);

	//volver a la ubicacion inicial
	FInputActionKeyMapping volver("Volver", EKeys::X, 0, 0, 0, 0);
	UPlayerInput::AddEngineDefinedActionMapping(volver);

	// Asociar el mapeo de tecla de acción con una función de la clase AWarrior
	PlayerInputComponent->BindAction("Volver", IE_Pressed, this, &AGalaga_USFXPawn::Volver);

	FInputAxisKeyMapping movq("MovQ", EKeys::Q, 01.0f);
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(movq);

	// Asociar el mapeo de tecla de acción con una función de la clase AWarrior
	PlayerInputComponent->BindAxis("MovQ", this , &AGalaga_USFXPawn::MovQ);

	FInputAxisKeyMapping movc("MovQ", EKeys::C, -01.0f);
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(movc);

	// Asociar el mapeo de tecla de acción con una función de la clase AWarrior
	PlayerInputComponent->BindAxis("MovQ", this, &AGalaga_USFXPawn::MovQ);
		
	FInputAxisKeyMapping move("MovE", EKeys::E, 01.0f);
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(move);

	// Asociar el mapeo de tecla de acción con una función de la clase AWarrior
	PlayerInputComponent->BindAxis("MovE", this, &AGalaga_USFXPawn::MovE);

	FInputAxisKeyMapping movz("MovE", EKeys::Z, -01.0f);
	GetWorld()->GetFirstPlayerController()->PlayerInput->AddAxisMapping(movz);

	// Asociar el mapeo de tecla de acción con una función de la clase AWarrior
	PlayerInputComponent->BindAxis("MovE", this, &AGalaga_USFXPawn::MovE);
}
void AGalaga_USFXPawn::Volver()
{
	mover = true;
	velocidad = 2000.0f;
	velocidadX = 2000.0f;
	velocidadY = 2000.0f;
}
void AGalaga_USFXPawn::Saltar()
{
	if (!bIsJumping)
	{
		// Calcular la nueva posición después del salto
		FVector NewLocation = GetActorLocation() + FVector(0.0f, 0.0f, JumpForce) ;

		// Establecer la nueva posición del personaje
		SetActorLocation(NewLocation, true); // El segundo parámetro indica que queremos que el salto sea simulado (afecte a la física)

		// Actualizar la variable que indica si el personaje está en el suelo
		bIsJumping = true;
		//FTimerHandle TimerHandle_Fall;
		//GetWorld()->GetTimerManager().SetTimer(TimerHandle_Fall, this, &AGalaga_USFXPawn::Caer, 1);
		FTimerHandle TimerHandle;
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AGalaga_USFXPawn::Caer, 0.5f, false);
	}
	//SetActorLocation(GetActorLocation()-(0.0f,0.0f,JumpForce), true);
}

void AGalaga_USFXPawn::Caer()
{
	// Calcular la nueva posición para que el personaje vuelva al suelo
	FVector NewLocation = GetActorLocation() - FVector(0.0f, 0.0f, JumpForce) ;

	// Establecer la nueva posición del personaje
	SetActorLocation(NewLocation, true); // El segundo parámetro indica que queremos que el movimiento sea simulado (afecte a la física)

	// Actualizar la variable que indica si el personaje está en el suelo
	bIsJumping = false;
}
/*void AGalaga_USFXPawn::Caer()
{
	// Aplicar gravedad para que el personaje vuelva a caer
	UPrimitiveComponent* MyPrimitive = Cast<UPrimitiveComponent>(RootComponent);
	if (MyPrimitive)
	{
		MyPrimitive->SetSimulatePhysics(true); // Asegúrate de que la simulación de física esté habilitada en tu componente raíz
	}
}*/
void AGalaga_USFXPawn::MovQ(float AxisValue)
{
	FVector MovimientoC = FVector(-1.0f, 1.0f, 0.0f);
	FVector MovimientoQ = FVector(1.0f, -1.0f, 0.0f).GetClampedToMaxSize(1.0f);
	if (AxisValue ) {
		if (AxisValue<0)
		{
			FRotator NuevaRotacion = MovimientoC.Rotation();
			SetActorRotation(NuevaRotacion);
		}
		else{
			FRotator NuevaRotacion = MovimientoQ.Rotation();// Dirección del movimiento en diagonal
			SetActorRotation(NuevaRotacion);
		}
	}
	float VelocidadQ = 10.0f; // Velocidad del movimiento
	// Aplica el movimiento basado en la dirección y la velocidad
	FVector NuevoMovimiento = GetActorLocation() + MovimientoQ * VelocidadQ * AxisValue;
	SetActorLocation(NuevoMovimiento);
	
}
void AGalaga_USFXPawn::MovE(float AxisValue)
{
	FVector MovimientoZ = FVector(-1.0f, -1.0f, 0.0f);
	FVector MovimientoE = FVector(1.0f, 1.0f, 0.0f).GetClampedToMaxSize(1.0f);
	if (AxisValue) {
		if (AxisValue < 0)
		{
			FRotator NuevaRotacion = MovimientoZ.Rotation();
			SetActorRotation(NuevaRotacion);
		}
		else {
			FRotator NuevaRotacion = MovimientoE.Rotation();// Dirección del movimiento en diagonal
			SetActorRotation(NuevaRotacion);
		
		}
	}
	float VelocidadQ = 10.0f; // Velocidad del movimiento
	// Aplica el movimiento basado en la dirección y la velocidad
	FVector NuevoMovimiento = GetActorLocation() + MovimientoE * VelocidadQ * AxisValue;
	SetActorLocation(NuevoMovimiento);
}

void AGalaga_USFXPawn::Tick(float DeltaSeconds)
{
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);
	
	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
		
		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		
		}

	}
	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);

	//Volver
	if (mover)
	 {
		//do {
		float PosicionActualY = GetActorLocation().Y;

		// Determinar la posición objetivo en Y
		float PosicionObjetivoY = PosicionActualY > 0 ? velocidad : -velocidad;
		// Mover el pawn hasta la posición objetivo en Y
			//FVector NuevaPosicion = FVector(GetActorLocation().X, GetActorLocation().Y + PosicionObjetivoY, GetActorLocation().Z);
		FVector NuevaPosicion1 = GetActorLocation() + FVector(0.0f, PosicionObjetivoY, 0.0f) * DeltaSeconds;
		SetActorLocation(NuevaPosicion1, true);
		if (abs(GetActorLocation().Y) >= 1800)
		{
			velocidad = 0;

			float PosicionActualX = GetActorLocation().X;

			// Determinar la posición objetivo en X
			float PosicionObjetivoX = PosicionActualX > 0 ? -velocidadX : velocidadX;
			// Mover el pawn hasta la posición objetivo en Y
				//FVector NuevaPosicion = FVector(GetActorLocation().X, GetActorLocation().Y + PosicionObjetivoY, GetActorLocation().Z);
			FVector NuevaPosicion2 = GetActorLocation() + FVector(PosicionObjetivoX, 0.0f, 0.0f) * DeltaSeconds;
			SetActorLocation(NuevaPosicion2, true);
			//	} while ((GetActorLocation().X > ubicacionInicialX + 5) || (GetActorLocation().X < ubicacionInicialX - 5));
		}
			if ((GetActorLocation().X < ubicacionInicialX + 20) && (GetActorLocation().X > ubicacionInicialX - 20))
			{
				velocidadX = 0;

				float PosicionActual3 = GetActorLocation().Y;

				// Volver a la posicion inicial
				float PosicionObjetivo3 = PosicionActual3 > 0 ? -velocidadY : velocidadY;
				// Mover el pawn hasta la posición objetivo en Y
					//FVector NuevaPosicion3 = FVector(GetActorLocation().X, GetActorLocation().Y + PosicionObjetivoY, GetActorLocation().Z);
				FVector NuevaPosicion3 = GetActorLocation() + FVector(0.0f, PosicionObjetivo3, 0.0f) * DeltaSeconds;
				SetActorLocation(NuevaPosicion3, true);
		
				//} while ((GetActorLocation().Y > ubicacionInicialY + 5) || (GetActorLocation().Y < ubicacionInicialY - 5));
				if ((GetActorLocation().Y < ubicacionInicialY + 20) && (GetActorLocation().Y > ubicacionInicialY - 20))
				{
					velocidadY = 0;
					//SetActorLocation(ubicacionInicial);
					//if ((GetActorLocation().X < ubicacionInicialX + 3) && (GetActorLocation().X > ubicacionInicialX - 3))
					//{
						//if ((GetActorLocation().Y < ubicacionInicialY + 3) && (GetActorLocation().Y > ubicacionInicialY - 3))
						//{
							mover = false;
						//	velocidadY = 0;
					    //}
					//}
				}
			}
		//}
				//do {
				
	}
}

void AGalaga_USFXPawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AGalaga_USFXProjectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGalaga_USFXPawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}


void AGalaga_USFXPawn::ShotTimerExpired()
{
	bCanFire = true;
}

