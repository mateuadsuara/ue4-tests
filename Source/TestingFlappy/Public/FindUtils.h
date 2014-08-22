

#pragma once

/**
 * 
 */
class TESTINGFLAPPY_API FindUtils
{
public:
	FindUtils(UWorld* World) : World(World){};
	~FindUtils(){};

	template <typename T = AActor> T* ByName(FString Name) {
		//UE_LOG(LogTemp, Warning, TEXT("finding by name %s"), *Name);
		for (TActorIterator<T> ActorItr(World); ActorItr; ++ActorItr) {
			//UE_LOG(LogTemp, Warning, TEXT("%s: %s"), *ActorItr->GetName(), *ActorItr->GetActorLocation().ToString());
			if (ActorItr->GetName().Equals(Name, ESearchCase::CaseSensitive)){
				//UE_LOG(LogTemp, Warning, TEXT("Found %s"), *Name);
				return *ActorItr;
			}
		}

		UE_LOG(LogTemp, Warning, TEXT("NOT FOUND!! %s"), *Name);
		return NULL;
	};

	template <typename T = AActor> TArray<T*> All() {
		TArray<T*> Array = TArray<T*>();

		//UE_LOG(LogTemp, Warning, TEXT("finding all"));
		for (TActorIterator<T> ActorItr(World); ActorItr; ++ActorItr) {
			//UE_LOG(LogTemp, Warning, TEXT("%s: %s"), *ActorItr->GetName(), *ActorItr->GetActorLocation().ToString());
			Array.Add(*ActorItr);
		}

		return Array;
	}

private:
	UWorld* World;
};
