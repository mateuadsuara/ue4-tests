// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "TestingFlappy.h"
#include "TestingFlappyCharacter.h"

ATestingFlappyCharacter::ATestingFlappyCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PrimaryActorTick.bCanEverTick = true;
	// Set size for collision capsule
	CapsuleComponent->InitCapsuleSize(42.f, 96.0f);
	CapsuleComponent->OnComponentHit.AddDynamic(this, &ATestingFlappyCharacter::OnHit);
	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = PCIP.CreateDefaultSubobject<USpringArmComponent>(this, TEXT("CameraBoom"));
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->RelativeRotation = FRotator(0.f,180.f,0.f);

	// Create a camera and attach to boom
	SideViewCameraComponent = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("SideViewCamera"));
	SideViewCameraComponent->AttachTo(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUseControllerViewRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	CharacterMovement->bOrientRotationToMovement = true; // Face in the direction we are moving..
	CharacterMovement->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	CharacterMovement->GravityScale = 1.5f;
	CharacterMovement->AirControl = 0.0f;
	CharacterMovement->JumpZVelocity = 1000.f;
	CharacterMovement->GroundFriction = 3.f;
	CharacterMovement->MaxWalkSpeed = 600.f;
	CharacterMovement->MaxFlySpeed = 600.f;

	

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void ATestingFlappyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Actual = this->GetTransform().GetLocation();
	FVector* Next = new FVector(Actual.X, Actual.Y - DeltaTime * 100, Actual.Z);
	this->SetActorLocation(*Next);

	//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Cyan, TEXT("DeltaTime %f"));
	//UE_LOG(LogTemp, Log, TEXT("DeltaTime %f"), DeltaTime); // this does nothing
}


//////////////////////////////////////////////////////////////////////////
// Input

void ATestingFlappyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	InputComponent->BindAction("Jump", IE_Pressed, this, &ATestingFlappyCharacter::Jump);

	InputComponent->BindTouch(IE_Pressed, this, &ATestingFlappyCharacter::TouchStarted);
}

void ATestingFlappyCharacter::Jump()
{
	CharacterMovement->DoJump();
}

void ATestingFlappyCharacter::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	Jump();
}

void ATestingFlappyCharacter::OnHit(AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit){
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Cyan, TEXT("hit"));

}

