/*
 * CrazyCubeSolver_test.cpp
 *
 *  Created on: Sep 11, 2015
 *      Author: SecT
 */


#include <FileWriter.h>
#include "TestExecuter.h"


class FileWriterTest: public BaseTest
{
public:
	FileWriterTest(string testCase, string testName)
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
public:
	
	static FileWriter fileWriter;
};

//FileWriter FileWriterTest:: fileWriter;


TEST_F(FileWriterTest, initTest)
{
//	unsigned short int minDepth = 123;
//	solver.setMinDepth(minDepth);
//	ASSERT_EQ(solver.getMinDepth(), minDepth);

//check if text file exists after constructor

//bool isOpen = true;

//if(!fileWriter)
//{
//isOpen = false;
//}

FileWriterTest::fileWriter.isOpen();


}


