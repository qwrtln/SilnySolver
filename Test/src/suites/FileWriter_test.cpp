/*
 * FileWriter_test.cpp
 *
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

FileWriter FileWriterTest:: fileWriter;


#ifdef MEMORY_CHECK
TEST_F(FileWriterTest, findingMemoryLeaks)
{
    int myArraySize = 3;
    int* myArray = new  int[myArraySize];
    myArray[0] = 2;
    myArray[1] = 5;
    myArray[2] = 8;

    fileWriter.inputArrayToWrite(myArray,myArraySize);
    fileWriter.isOpen();
    fileWriter.saveArrayToFile();

    delete[] myArray;
}

#else

TEST_F(FileWriterTest, basicWrite)
{

FileWriter fileWriter;

if(fileWriter.isOpen())
{
int myArraySize = 3;

int* myArray = new  int[myArraySize];

myArray[0] = 2;
myArray[1] = 5;
myArray[2] = 8;

fileWriter.inputArrayToWrite(myArray, myArraySize);

fileWriter.saveArrayToFile();


const char* filename = "data.txt";
std::ifstream inFile(filename);

int n = 0;
int i =0;
while(!inFile.eof()) {
    inFile >> n;
    ASSERT_EQ(n, myArray[i]);
    i++;
}

}


}



TEST_F(FileWriterTest, variableDigits)
{

FileWriter fileWriter;

if(fileWriter.isOpen())
{
int myArraySize = 3;

int* myArray = new  int[myArraySize];

myArray[0] = 46;
myArray[1] = 500;
myArray[2] = 8;

fileWriter.inputArrayToWrite(myArray, myArraySize);

fileWriter.saveArrayToFile();


const char* filename = "data.txt";
std::ifstream inFile(filename);

int n = 0;
int i =0;
while(!inFile.eof()) {
    inFile >> n;
    ASSERT_EQ(n, myArray[i]);
    i++;
}

}


}

#endif
