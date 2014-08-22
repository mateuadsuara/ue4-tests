

#pragma once

/**
 * 
 */
class TESTINGFLAPPY_API FindUtils
{
public:
	FindUtils(UWorld* World) : World(World){};
	~FindUtils(){};

	template <typename T> T* ByName(FString Name) {
		UE_LOG(LogTemp, Warning, TEXT("finding actor with name %s"), *Name);
		for (TActorIterator<T> ActorItr(World); ActorItr; ++ActorItr) {
			UE_LOG(LogTemp, Warning, TEXT("%s: %s"), *ActorItr->GetName(), *ActorItr->GetActorLocation().ToString());
			if (ActorItr->GetName().Equals(Name, ESearchCase::CaseSensitive)){
				UE_LOG(LogTemp, Warning, TEXT("Found %s"), *Name);
				return *ActorItr;
			}
		}

		UE_LOG(LogTemp, Warning, TEXT("NOT FOUND!! %s"), *Name);
		return NULL;
	};

private:
	UWorld* World;
};
