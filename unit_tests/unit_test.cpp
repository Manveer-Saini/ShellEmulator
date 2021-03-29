/******************************************************************************************/
/* File: unit_tests.cpp. this file is a test harness for the rshell system using the      */
/* Google test framework.                                                                 */
/* Author: John Palacios                                                                  */
/******************************************************************************************/

#include "../header/ProtoIn.h"
#include "../header/Command.h"
#include "../header/Connector.h"
#include "../header/Executable.h"
#include "../header/Pipes.h"
#include "../header/Semicolon.h"
#include "../header/Executable.h"
#include "../header/Exit.h"
#include "../header/Ampersands.h"
#include "../header/Test.h"
#include "gtest/gtest.h"
using namespace std;

TEST(ExecutableTest, ValidExecutableValidArg) {
	const char* file = "ls";
	char* argmnts[] = { "ls", "-a", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	int status = testCmnd->evaluate(1);

	EXPECT_EQ(0, status);
}

TEST(ExecutableTest, InValidExecutableValidArg) {
	const char* file = "invalid";
	char* argmnts[] = { "Invalid", "-a", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	int status = testCmnd->evaluate(0);

	EXPECT_EQ(-1, status);
}

TEST(ExecutableTest, InValidExecutableInValidArg) {
	const char* file = "invalid";
	char* argmnts[] = { "invalid", "Nope", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	int status = testCmnd->evaluate(0);

	EXPECT_EQ(-1, status);
}

TEST(ConnectorTest, ValidExecutableValidArg) {
	const char* file = "ls";
	char* argmnts[] = { "ls", "-a", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Connector(testCmnd);
	int status = testCmnd->evaluate(1);

	EXPECT_EQ(0, status);
}

TEST(ConnectorTest, InValidExecutableValidArg) {
	const char* file = "invalid";
	char* argmnts[] = { "invalid", "-a", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Connector(testCmnd);
	int status = testCmnd->evaluate(0);

	EXPECT_EQ(-1, status);
}

TEST(ConnectorTest, InValidExecutableInValidArg) {
	const char* file = "invalid";
	char* argmnts[] = { "invalid", "Nope", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Connector(testCmnd);
	int status = testCmnd->evaluate(0);

	EXPECT_EQ(-1, status);
}

TEST(CommandTest, ValidExecutableValidArg) {
	const char* file = "ls";
	char* argmnts[] = { "ls", "-a", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Connector(testCmnd);
    Command* command = new Command;
    command->Add(testCmnd);
	int status = command->evaluate(1);

	EXPECT_EQ(0, status);
}

TEST(CommandTest, InValidExecutableValidArg) {
	const char* file = "invalid";
	char* argmnts[] = { "invalid", "-a", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Connector(testCmnd);
    Command* command = new Command;
    command->Add(testCmnd);
	int status = command->evaluate(0);

	EXPECT_EQ(-1, status);
}

TEST(CommandTest,InValidExecutableInValidArg) {
	const char* file = "invalid";
	char* argmnts[] = { "invalid", "Nope", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Connector(testCmnd);
    Command* command = new Command;
    command->Add(testCmnd);
	int status = command->evaluate(0);

	EXPECT_EQ(-1, status);
}

TEST(AmpersandsTest, ValidExecutableValidArg) {
	const char* file = "ls";
	char* argmnts[] = { "ls", "-a", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Ampersands(testCmnd);
	int status = testCmnd->evaluate(1);

	EXPECT_EQ(0, status);
}

TEST(AmpersandsTest, InValidExecutableValidArg) {
	const char* file = "invalid";
	char* argmnts[] = { "invalid", "-a", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Ampersands(testCmnd);
	int status = testCmnd->evaluate(0);

	EXPECT_EQ(-1, status);
}

TEST(AmpersandsTest, InValidExecutableInValidArg) {
	const char* file = "invalid";
	char* argmnts[] = { "invalid", "Nope", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Ampersands(testCmnd);
	int status = testCmnd->evaluate(0);

	EXPECT_EQ(-1, status);
}

TEST(SemicolonTest, ValidExecutableValidArg) {
	const char* file = "ls";
	char* argmnts[] = { "ls", "-a", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Semicolon(testCmnd);
	int status = testCmnd->evaluate(1);

	EXPECT_EQ(0, status);
}

TEST(SemicolonTest, InValidExecutableValidArg) {
	const char* file = "invalid";
	char* argmnts[] = { "invalid", "-a", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Semicolon(testCmnd);
	int status = testCmnd->evaluate(0);

	EXPECT_EQ(-1, status);
}

TEST(SemicolonTest, InValidExecutableInValidArg) {
	const char* file = "invalid";
	char* argmnts[] = { "invalid", "Nope", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Semicolon(testCmnd);
	int status = testCmnd->evaluate(0);

	EXPECT_EQ(-1, status);
}

TEST(PipesTest, ValidExecutableValidArg) {
	const char* file = "ls";
	char* argmnts[] = { "ls", "-a", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Pipes(testCmnd);
	int status = testCmnd->evaluate(1);

	EXPECT_EQ(0, status);
}

TEST(PipesTest, InValidExecutableValidArg) {
	const char* file = "invalid";
	char* argmnts[] = { "invalid", "-a", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Pipes(testCmnd);
	int status = testCmnd->evaluate(0);

	EXPECT_EQ(0, status);
}

TEST(PipesTest, InValidExecutableInValidArg) {
	const char* file = "invalid";
	char* argmnts[] = { "invalid", "Nope", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Executable(file, args);
	testCmnd = new Pipes(testCmnd);
	int status = testCmnd->evaluate(0);

	EXPECT_EQ(0, status);
}
/*
TEST(ExitTest, ExitProperly) {
	const char* file = "invalid";
	char* argmnts[] = { "invalid", "Nope", NULL };
	char** const args = argmnts;
	ProtoIn* testCmnd = new Exit(file, args);;
	int status = testCmnd->evaluate(0);

	EXPECT_EQ(0, status);
}
*/
TEST(TestTest, ValidArg){
    const char* file = "-e";
    char* argmnts[] = {"-e", "prototype/someDir", "NULL"};
    char** const args = argmnts;
    ProtoIn* testCmd = new TestCommand(file, args);
    int status = testCmd->evaluate(0);

    EXPECT_EQ(0, status);
}

TEST(TestTest, InValidArg){
    const char* file = "-e";
    char* argmnts[] = {"-e", "prototype/someDir/meow", "NULL"};
    char** const args = argmnts;
    ProtoIn* testCmd = new TestCommand(file, args);
    int status = testCmd->evaluate(0);

    EXPECT_EQ(0, status);
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
