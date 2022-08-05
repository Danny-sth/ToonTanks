// Copyright by Danny Kudinov



#include "HealthComponent.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	Health = DefaultHealth;
	GameModePtr = Cast<ATankGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::TakeDamage);
}

void UHealthComponent::TakeDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType,
                                  AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage == 0 && Health <= 0)
	{
		return;
	}
	Health = FMath::Clamp(Health - Damage, 0.f, DefaultHealth);

	if (Health <= 0 && GameModePtr)
	{
		GameModePtr->ActorDied(GetOwner());
	}
	else if (!GameModePtr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Health component has no reference to the GameMode"));
	}
}
