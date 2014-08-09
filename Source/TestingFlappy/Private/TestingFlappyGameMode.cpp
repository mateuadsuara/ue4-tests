// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "TestingFlappy.h"
#include "TestingFlappyGameMode.h"

ATestingFlappyGameMode::ATestingFlappyGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FObjectFinder<UClass> PlayerPawnBPClass(TEXT("Class'/Game/Blueprints/MyCharacter.MyCharacter_C'"));
	if (PlayerPawnBPClass.Object != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Object;
	}
}
