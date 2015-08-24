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
		
	}
protected:
	virtual void SetUp()
	{		
		x = 12;
	}
	virtual void TearDown()
	{
		
	}
protected:
	int x;
};

TEST_F(SilneTesty, HelloWorld_Test)
{
	ASSERT_EQ(12, x);
	ASSERT_EQ_HEX(12, x);
}
TEST_F(SilneTesty, ByeByeWorld_Test)
{
	ASSERT_NE(11, x);
	ASSERT_NE_HEX(11, x);
}
