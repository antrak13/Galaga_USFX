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
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"

const FName AGalaga_USFXPawn::MoveForwardBinding("MoveForward");
const FName AGalaga_USFXPawn::MoveRightBinding("MoveRight");
const FName AGalaga_USFXPawn::FireForwardBinding("FireForward");
const FName AGalaga_USFXPawn::FireRightBinding("FireRight");
//Movimiento Q
const FName AGalaga_USFXPawn::MoveForwardLeftBinding("MoveForwardLeft");
const FName AGalaga_USFXPawn::MoveRightLeftBinding("MoveRightLeft");
//Movimiento C
const FName AGalaga_USFXPawn::MoveForwardLeftCBinding("MoveForwardLeftC");
const FName AGalaga_USFXPawn::MoveRightLeftCBinding("MoveRightLeftC");

//Movimiento E
const FName AGalaga_USFXPawn::MoveForwardRightBinding("MoveForwardRight");
const FName AGalaga_USFXPawn::MoveRight2Binding("MoveRight2");
//Movimiento Z
const FName AGalaga_USFXPawn::MoveForwardRightZBinding("MoveForwardRightZ");
const FName AGalaga_USFXPawn::MoveRight2ZBinding("MoveRight2Z");


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
}

void AGalaga_USFXPawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// set up gameplay key bindings
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);
	//Movimiento Q
	PlayerInputComponent->BindAxis(MoveForwardLeftBinding);
	PlayerInputComponent->BindAxis(MoveRightLeftBinding);
	//Movimiento C
	PlayerInputComponent->BindAxis(MoveForwardLeftCBinding);
	PlayerInputComponent->BindAxis(MoveRightLeftCBinding);
	//Movimiento E
	PlayerInputComponent->BindAxis(MoveForwardRightBinding);
	PlayerInputComponent->BindAxis(MoveRight2Binding);
	//Movimiento Z
	PlayerInputComponent->BindAxis(MoveForwardRightZBinding);
	PlayerInputComponent->BindAxis(MoveRight2ZBinding);
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

	//Movimiento Q

	float ForwardVal = GetInputAxisValue(MoveForwardLeftBinding);
	float RightVal = GetInputAxisValue(MoveRightLeftBinding);

	// Adjust movement direction for diagonal movement (up and left)
    if (GetInputAxisValue(MoveForwardLeftBinding)>0.0f)
	{

		//	ForwardVal = FMath::Max(-1.0f, ForwardVal - 1.0f); // Reduce forward movement
			RightVal = FMath::Max(-1.0f, RightVal - 1.0f); // Reduce right movement
			
	}
	if (GetInputAxisValue(MoveRightLeftBinding) > 0.0f)
	{

		ForwardVal = FMath::Max(-1.0f, ForwardVal - 1.0f); // Reduce forward movement
		//RightVal = FMath::Max(-1.0f, RightVal - 1.0f); // Reduce right movement

	}
	

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirections = FVector(-ForwardVal,- RightVal, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate movement
	const FVector Movements = MoveDirections * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movements.SizeSquared() > 0.0f)
	{
		const FRotator NewRotations = Movements.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movements, NewRotations, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2Ds = Hit.Normal.GetSafeNormal2D();
			const FVector Deflections = FVector::VectorPlaneProject(Movements, Normal2Ds) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflections, NewRotations, true);
		}
	}

	//Movimiento C
	float ForwardValC = GetInputAxisValue(MoveForwardLeftCBinding);
	float RightValC = GetInputAxisValue(MoveRightLeftCBinding);

	// Adjust movement direction for diagonal movement (up and left)
	if (GetInputAxisValue(MoveForwardLeftCBinding) > 0.0f)
	{

		//	ForwardVal = FMath::Max(-1.0f, ForwardVal - 1.0f); // Reduce forward movement
		RightValC = FMath::Max(-1.0f, RightValC - 1.0f); // Reduce right movement

	}
	if (GetInputAxisValue(MoveRightLeftCBinding) > 0.0f)
	{

		ForwardValC = FMath::Max(-1.0f, ForwardValC - 1.0f); // Reduce forward movement
		//RightVal = FMath::Max(-1.0f, RightVal - 1.0f); // Reduce right movement

	}


	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirectionsC = FVector(-ForwardValC,- RightValC, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate movement
	const FVector MovementsC = MoveDirectionsC * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (MovementsC.SizeSquared() > 0.0f)
	{
		const FRotator NewRotationsC = MovementsC.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(MovementsC, NewRotationsC, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2DsC = Hit.Normal.GetSafeNormal2D();
			const FVector DeflectionsC = FVector::VectorPlaneProject(MovementsC, Normal2DsC) * (1.f - Hit.Time);
			RootComponent->MoveComponent(DeflectionsC, NewRotationsC, true);
		}
	}



	/*float ForwardVal = GetInputAxisValue(MoveForwardLeftBinding);
	float RightVal = GetInputAxisValue(MoveRightLeftBinding);

	// Adjust movement direction for diagonal movement (up and left)
	if (GetInputAxisValue(MoveForwardLeftBinding) > 0.0f)
	{
		ForwardVal = FMath::Max(-1.0f, ForwardVal - 1.0f); // Reduce forward movement
		RightVal = FMath::Max(-1.0f, RightVal - 1.0f); // Reduce right movement
	}

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDireccions = FVector(ForwardVal, RightVal, 0.f).GetClampedToMaxSize(1.0f);
	const FVector Movements = MoveDireccions * MoveSpeed * DeltaSeconds;*/

	//Movimiento E
	float ForwardVal2 = GetInputAxisValue(MoveForwardRightBinding);
	float RightVal2 = GetInputAxisValue(MoveRight2Binding);

	// Adjust movement direction for diagonal movement (up and left)
	if (GetInputAxisValue(MoveForwardRightBinding) > 0.0f)
	{

		//	ForwardVal = FMath::Max(-1.0f, ForwardVal - 1.0f); // Reduce forward movement
		RightVal2 = FMath::Max(-1.0f, RightVal2 - 1.0f); // Reduce right movement

	}
	if (GetInputAxisValue(MoveRight2Binding) > 0.0f)
	{

		ForwardVal2 = FMath::Max(-1.0f, ForwardVal2 - 1.0f); // Reduce forward movement
		//RightVal = FMath::Max(-1.0f, RightVal - 1.0f); // Reduce right movement

	}


	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirections2 = FVector(-ForwardVal2, RightVal2, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate movement
	const FVector Movements2 = MoveDirections2 * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movements2.SizeSquared() > 0.0f)
	{
		const FRotator NewRotations2 = Movements2.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movements2, NewRotations2, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2Ds2 = Hit.Normal.GetSafeNormal2D();
			const FVector Deflections2 = FVector::VectorPlaneProject(Movements2, Normal2Ds2) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflections2, NewRotations2, true);
		}
	}

	//Movimiento Z
	float ForwardVal2Z = GetInputAxisValue(MoveForwardRightZBinding);
	float RightVal2Z = GetInputAxisValue(MoveRight2ZBinding);

	// Adjust movement direction for diagonal movement (up and left)
	if (GetInputAxisValue(MoveForwardRightZBinding) > 0.0f)
	{

		//	ForwardVal = FMath::Max(-1.0f, ForwardVal - 1.0f); // Reduce forward movement
		RightVal2Z = FMath::Max(-1.0f, RightVal2Z - 1.0f); // Reduce right movement

	}
	if (GetInputAxisValue(MoveRight2ZBinding) > 0.0f)
	{

		ForwardVal2Z = FMath::Max(-1.0f, ForwardVal2Z - 1.0f); // Reduce forward movement
		//RightVal = FMath::Max(-1.0f, RightVal - 1.0f); // Reduce right movement

	}


	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirections2Z = FVector(ForwardVal2Z, -RightVal2Z, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate movement
	const FVector Movements2Z = MoveDirections2Z * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movements2Z.SizeSquared() > 0.0f)
	{
		const FRotator NewRotations2Z = Movements2Z.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movements2Z, NewRotations2Z, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2Ds2Z = Hit.Normal.GetSafeNormal2D();
			const FVector Deflections2Z = FVector::VectorPlaneProject(Movements2Z, Normal2Ds2Z) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflections2Z, NewRotations2Z, true);
		}
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

