

#pragma once

/**
 * 
 */
class TESTINGFLAPPY_API FindUtils
{
public:
	FindUtils(AActor* Actor);
	~FindUtils();
	AActor* GetAActorByName(FString Name);

private:
	AActor* Actor;
};
