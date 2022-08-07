// Copyright by Danny Kudinov


#include "PlayerControllerBase.h"

void APlayerControllerBase::SetPlayerEnabledState(bool bIsPlayerEnabled)
{
	if (bIsPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}
	bShowMouseCursor = bIsPlayerEnabled;
}
