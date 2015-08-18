#include "CrazyCube.h"
#include "TestExecuter.h"
#include "ConstDefs.h"

extern TestExecuter testExecuter;
class SilneTesty: public BaseTest
{
public:
	SilneTesty(string testCase, string testName)
		:BaseTest(testCase, testName)
	{
		SetUp();
	}
protected:
	void SetUp()
	{

	}
	void TearDown()
	{

	}
protected:
};

TEST(SilneTesty, HelloWorld_Test)
{
	ASSERT_EQ(1, 1);
}
TEST(SilneTesty, ByeByeWorld_Test)
{
	ASSERT_NE(21, 1);
}
