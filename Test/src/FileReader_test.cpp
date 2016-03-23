/*
 * FileReader_test.cpp
 *
 *  Created on: Sep 11, 2015
 *      Author: SecT
 */
#include "FileReader.h"
#include "TestExecuter.h"
//#include "CrazyCubeAbstract.h"
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

	testFile<<"10 20";

	testFile.close();


	//fileReader = new FileReader("./testFileReader.txt");


	fileReader.open("./testFileReader.txt");

	}

	void TearDown()
	{

	
	remove("./testFileReader.txt");
	//delete	fileReader;

	}

protected:
	static FileReader fileReader;


};

FileReader FileReaderTest::fileReader;

TEST_F(FileReaderTest, readNumbersFromFile)
{
	FileReader fileReader("./testFileReader.txt");		





	fileReader.readArrayFromFile();
	
	fileReader.getArray();
	int myArraySize = fileReader.getArraySize();

	ASSERT_EQ(myArraySize, 2);
}



