#include "FileReader.h"

#include <string>

//#include <fstream>

//using std::ifstream;


FileReader::FileReader(char* fileName)
{

file.open(fileName, std::ifstream::in);

}



FileReader::~FileReader()
{

file.close();

}
