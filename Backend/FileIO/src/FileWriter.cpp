#include <FileWriter.h>

#include <fstream>
#include "Tracer.h"

using std::ofstream;


FileWriter::FileWriter()
{
TRACE( TRACE_ALL, 0, "Constructor FileWriter");
	
file.open("data.txt", std::fstream::in);

}

FileWriter::FileWriter(char const* fileName)
{

}


void FileWriter::saveArrayToFile(char delimiter)
{

if (isOpen())
{

for(int i=0; i<arraySize; i++)
{


file<<array[i]<<delimiter;

}

}

}


void FileWriter::inputArrayToWrite(int* inputArray, int inputSize)
{

array = inputArray;
arraySize = inputSize;

}

bool FileWriter::isOpen()
{

if(!file) return false;

return true;

}

FileWriter::~FileWriter()
{
TRACE( TRACE_ALL, 0, "Destructor FileWriter");
}


