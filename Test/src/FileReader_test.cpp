/*
 * FileReader_test.cpp
 *
 *  Created on: Sep 11, 2015
 *      Author: SecT
 */
#include "FileReader.h"
#include "TestExecuter.h"
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


	}

	void TearDown()
	{	


	}

protected:
	static FileReader fileReader;


};

FileReader FileReaderTest::fileReader;

TEST_F(FileReaderTest, basicRead)
{

	ofstream testFile;

	testFile.open("./testFileReader.txt");		

	testFile<<"1 2 6";

	testFile.close();




	fileReader.open("./testFileReader.txt");



	FileReader fileReader("./testFileReader.txt");		


	fileReader.readArrayFromFile();
	
	int* myArray = fileReader.getArray();
	int myArraySize = fileReader.getArraySize();

	ASSERT_EQ(myArraySize, 3);

	ASSERT_EQ(myArray[0], 1);
	
	ASSERT_EQ(myArray[1], 2);

	ASSERT_EQ(myArray[2], 6);


	remove("./testFileReader.txt");

}



TEST_F(FileReaderTest, doubleDigits)
{

	ofstream testFile;

	testFile.open("./testFileReader.txt");		

	testFile<<"50 20 40";

	testFile.close();




	fileReader.open("./testFileReader.txt");



	FileReader fileReader("./testFileReader.txt");		


	fileReader.readArrayFromFile();
	
	int* myArray = fileReader.getArray();
	int myArraySize = fileReader.getArraySize();

	ASSERT_EQ(myArraySize, 3);

	ASSERT_EQ(myArray[0], 50);
	
	ASSERT_EQ(myArray[1], 20);

	ASSERT_EQ(myArray[2], 40);


	remove("./testFileReader.txt");

}


TEST_F(FileReaderTest, tripleDigits)
{

	ofstream testFile;

	testFile.open("./testFileReader.txt");		

	testFile<<"500 245 471";

	testFile.close();




	fileReader.open("./testFileReader.txt");



	FileReader fileReader("./testFileReader.txt");		


	fileReader.readArrayFromFile();
	
	int* myArray = fileReader.getArray();
	int myArraySize = fileReader.getArraySize();

	ASSERT_EQ(myArraySize, 3);

	ASSERT_EQ(myArray[0], 500);
	
	ASSERT_EQ(myArray[1], 245);

	ASSERT_EQ(myArray[2], 471);


	remove("./testFileReader.txt");

}

TEST_F(FileReaderTest, variableDigits)
{

	ofstream testFile;

	testFile.open("./testFileReader.txt");		

	testFile<<"10 2 345";

	testFile.close();




	fileReader.open("./testFileReader.txt");



	FileReader fileReader("./testFileReader.txt");		


	fileReader.readArrayFromFile();
	
	int* myArray = fileReader.getArray();
	int myArraySize = fileReader.getArraySize();

	ASSERT_EQ(myArraySize, 3);

	ASSERT_EQ(myArray[0], 10);
	
	ASSERT_EQ(myArray[1], 2);

	ASSERT_EQ(myArray[2], 345);


	remove("./testFileReader.txt");

}


TEST_F(FileReaderTest, emptyFile)
{

	ofstream testFile;

	testFile.open("./testFileReader.txt");		


	testFile.close();




	fileReader.open("./testFileReader.txt");



	FileReader fileReader("./testFileReader.txt");		


	fileReader.readArrayFromFile();
	
	fileReader.getArray();
	int myArraySize = fileReader.getArraySize();

	ASSERT_EQ(myArraySize, 0);


	remove("./testFileReader.txt");

}



TEST_F(FileReaderTest, spaceAtEndOfFile)
{

	ofstream testFile;

	testFile.open("./testFileReader.txt");		

	testFile<<"10 20 1 ";

	testFile.close();




	fileReader.open("./testFileReader.txt");



	FileReader fileReader("./testFileReader.txt");		


	fileReader.readArrayFromFile();
	
	int* myArray = fileReader.getArray();
	int myArraySize = fileReader.getArraySize();

	ASSERT_EQ(myArraySize, 3);

	ASSERT_EQ(myArray[0], 10);
	
	ASSERT_EQ(myArray[1], 20);

	ASSERT_EQ(myArray[2], 1);


	remove("./testFileReader.txt");

}



TEST_F(FileReaderTest, spaceAtStartOfFile)
{

	ofstream testFile;

	testFile.open("./testFileReader.txt");		

	testFile<<" 10 20 1";

	testFile.close();




	fileReader.open("./testFileReader.txt");



	FileReader fileReader("./testFileReader.txt");		


	fileReader.readArrayFromFile();
	
	int* myArray = fileReader.getArray();
	int myArraySize = fileReader.getArraySize();

	ASSERT_EQ(myArraySize, 3);

	ASSERT_EQ(myArray[0], 10);
	
	ASSERT_EQ(myArray[1], 20);

	ASSERT_EQ(myArray[2], 1);


	remove("./testFileReader.txt");

}


TEST_F(FileReaderTest, readArrayAfterRemovingFile)
{

	ofstream testFile;

	testFile.open("./testFileReader.txt");		

	testFile<<"50 20 40";

	testFile.close();




	fileReader.open("./testFileReader.txt");



	FileReader fileReader("./testFileReader.txt");		


	fileReader.readArrayFromFile();
	

	remove("./testFileReader.txt");

	int* myArray = fileReader.getArray();
	int myArraySize = fileReader.getArraySize();

	ASSERT_EQ(myArraySize, 3);

	ASSERT_EQ(myArray[0], 50);
	
	ASSERT_EQ(myArray[1], 20);

	ASSERT_EQ(myArray[2], 40);




}



TEST_F(FileReaderTest, readArrayAfterDeletingReader)
{

	ofstream testFile;

	testFile.open("./testFileReader.txt");		

	testFile<<"50 20 40";

	testFile.close();




	fileReader.open("./testFileReader.txt");



	FileReader* fileReader = new FileReader("./testFileReader.txt");		


	fileReader->readArrayFromFile();
	
	delete fileReader;


	int* myArray = fileReader->getArray();
	int myArraySize = fileReader->getArraySize();

	ASSERT_EQ(myArraySize, 3);

	ASSERT_EQ(myArray[0], 50);
	
	ASSERT_EQ(myArray[1], 20);

	ASSERT_EQ(myArray[2], 40);



	remove("./testFileReader.txt");

}

