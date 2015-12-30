#include "FileReader.h"

#include <string>

<<<<<<< HEAD
#include <cstring>
#include <cstdlib>

=======
>>>>>>> 90a858387e6f1a4711e226dfc8cf39ed1e201873
//#include <fstream>

//using std::ifstream;


FileReader::FileReader(char* fileName)
{

file.open(fileName, std::ifstream::in);

<<<<<<< HEAD
array = NULL;

=======
>>>>>>> 90a858387e6f1a4711e226dfc8cf39ed1e201873
}

void FileReader::readArray(char delimiter) //delimiter = ' '
{

//tmp
arraySize = 1;
<<<<<<< HEAD
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
=======

array = new int[arraySize];
//tmp
>>>>>>> 90a858387e6f1a4711e226dfc8cf39ed1e201873

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

<<<<<<< HEAD

=======
}
>>>>>>> 90a858387e6f1a4711e226dfc8cf39ed1e201873
