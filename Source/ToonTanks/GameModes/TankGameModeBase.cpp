// Copyright by Danny Kudinov


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void ATankGameModeBase::HandleGameStart()
{
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon)
{
}

void ATankGameModeBase::ActorDied(AActor* DeadActor)
{
	UE_LOG(LogTemp, Warning, TEXT("A Pawn died!"))
}
