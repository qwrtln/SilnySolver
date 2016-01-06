#include "FileReader.h"

#include <string>


#include <cstring>
#include <cstdlib>

//#include <fstream>

//using std::ifstream;


FileReader::FileReader(const char* fileName)
{

file.open(fileName, std::ifstream::in);


array = NULL;
}

void FileReader::readArray(char delimiter) //delimiter = ' '
{

//tmp
arraySize = 1;

//tmp

//TODO   dynamic buffer size
#define TOKEN_BUFFER_SIZE 3
char token[TOKEN_BUFFER_SIZE];    
//

//short tokenLength = 0;

int currentArraySize = 0;

//first parse the file to get the required array size

while(!file.eof() )
{
	char currentChar;

	file.get(currentChar);


	if(currentChar == delimiter)
	{
	currentArraySize++;			
	}
}


//allocate the array
array = new int[arraySize];


//parse the file again, this time writing the numbers to the array

int currentTokenId = 0;

int currentTokenLength = 0;

while(!file.eof())
{
	char currentChar;

	file.get(currentChar);

	if(currentChar == delimiter)
	{
	
	//convert the token to an integer and write it to the array


	
	//mock

	strcpy(token, "27");
	//	

	array[currentTokenId] = atoi(token);


	//reset token
	for(int i = 0; i<TOKEN_BUFFER_SIZE; i++)
	{
	token[i] = '\0';
	}	


	currentTokenId++;

	}
	else
	{

	token[currentTokenLength] = currentChar;

	currentTokenLength++;

	}

}


}

int* FileReader::getArray()
{
return array; 
}

int FileReader::getArraySize()
{
return arraySize;
}


FileReader::~FileReader()
{

file.close();

}
