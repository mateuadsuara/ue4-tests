

#include "TestingFlappy.h"
#include "FindUtils.h"

FindUtils::FindUtils(AActor* Actor) : Actor(Actor)
{
}

FindUtils::~FindUtils()
{
}

AActor* FindUtils::GetAActorByName(FString Name) {
	//UE_LOG(LogTemp, Warning, TEXT("finding actor with name %s"), *Name);
	for (TActorIterator<AActor> ActorItr(Actor->GetWorld()); ActorItr; ++ActorItr) {
		//UE_LOG(LogTemp, Warning, TEXT("%s: %s"), *ActorItr->GetName(), *ActorItr->GetActorLocation().ToString());
		if (ActorItr->GetName().Equals(Name, ESearchCase::CaseSensitive)){
			//UE_LOG(LogTemp, Warning, TEXT("Found %s"), *Name);
			return *ActorItr;
		}
	}

	UE_LOG(LogTemp, Warning, TEXT("NOT FOUND!! %s"), *Name);
	return NULL;
}