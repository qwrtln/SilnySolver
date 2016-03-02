#include <FileWriter.h>

#include <fstream>

using std::ofstream;


FileWriter::FileWriter()
{

file.open("data.txt", std::fstream::in);

}

FileWriter::FileWriter(char const* fileName)
{

}


void FileWriter::writeArray(char delimiter)
{

if (isOpen())
{

for(int i=0; i<arraySize; i++)
{


file<<array[i]<<delimiter;

}

}

}


void FileWriter::readArray(int* inputArray, int inputSize)
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

}


