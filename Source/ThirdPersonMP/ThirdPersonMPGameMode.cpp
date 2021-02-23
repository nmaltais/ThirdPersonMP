// Copyright Epic Games, Inc. All Rights Reserved.

#include "ThirdPersonMPGameMode.h"
#include "ThirdPersonMPCharacter.h"
#include "UObject/ConstructorHelpers.h"

AThirdPersonMPGameMode::AThirdPersonMPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
void AThirdPersonMPGameMode::RespawnPlayerWithDelay(AController* PC, float Delay) {
    FTimerHandle UniqueHandle;
    if(PC) {
        FTimerDelegate RespawnDelegate = FTimerDelegate::CreateUObject(this, &AThirdPersonMPGameMode::RestartPlayer, PC);
        GetWorldTimerManager().SetTimer( UniqueHandle, RespawnDelegate, Delay, false );
    }
}
