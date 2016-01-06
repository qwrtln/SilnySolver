/*
 * FileReader_test.cpp
 *
 *  Created on: Sep 11, 2015
 *      Author: SecT
 */
#include "FileReader.h"
#include "TestExecuter.h"
#include "CrazyCubeAbstract.h"
#include <cmath>

#include <fstream>
#include <cstdio>

using  std::ofstream;


class FileReaderTest: public BaseTest
{
public:
	FileReaderTest(string testCase, string testName)
		:BaseTest(testCase, testName)
	{
		SetUp();
	}
protected:
	void SetUp()
	{

	ofstream testFile;

	testFile.open("./testFileReader.txt");		

	testFile<<"1";

	testFile.close();


	//fileReader = new FileReader("./testFileReader.txt");

	}
	void TearDown()
	{

	
	remove("./testFileReader.txt");
	//delete	fileReader;

	}
protected:
	//static FileReader* fileReader;
};

//FileReader FileReaderTest::fileReader;

TEST_F(FileReaderTest, openFile)
{
	

	//ASSERT_EQ(solver.getSolvedMask(), solvedMask);
}



