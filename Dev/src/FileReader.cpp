#include "FileReader.h"

#include <string>

//#include <fstream>

//using std::ifstream;


FileReader::FileReader(char* fileName)
{

file.open(fileName, std::ifstream::in);

}

void FileReader::readArray(char delimiter) //delimiter = ' '
{

//tmp
arraySize = 1;

array = new int[arraySize];
//tmp

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
