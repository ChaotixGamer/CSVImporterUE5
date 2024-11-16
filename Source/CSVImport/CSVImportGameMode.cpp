// Copyright Epic Games, Inc. All Rights Reserved.

#include "CSVImportGameMode.h"
#include "CSVImportCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACSVImportGameMode::ACSVImportGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
