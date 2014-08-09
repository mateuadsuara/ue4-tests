
#include "TestingFlappy.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FMySimpleTest, "MyTest.MySimpleTest", EAutomationTestFlags::ATF_Editor)
DEFINE_LATENT_AUTOMATION_COMMAND_ONE_PARAMETER(FExecStringLatentCommand, FString, ExecCommand);
bool FExecStringLatentCommand::Update(){
	UE_LOG(LogTemp, Error, TEXT("%s"),*ExecCommand);
	return true;
}

DEFINE_LATENT_AUTOMATION_COMMAND_ONE_PARAMETER(FEngineWaitLatentCommand, FFloat16, ExecCommand);
bool FEngineWaitLatentCommand::Update(){
	UE_LOG(LogTemp, Error, TEXT("hola hola"));
	return true;
}
bool FMySimpleTest::RunTest(const FString& Parameters)
{

	ADD_LATENT_AUTOMATION_COMMAND(FEngineWaitLatentCommand(2.0f));
	ADD_LATENT_AUTOMATION_COMMAND(FExecStringLatentCommand(TEXT("setres 555640x5555480")));

	return true;
}