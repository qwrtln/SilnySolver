#include <fstream>
//#include <string>


//using std::string;
using std::ofstream;

class FileWriter{


ofstream file;

int* array;

int arraySize;


public:

FileWriter();

FileWriter(char const* fileName);


void readArray(int* inputArray, int inputSize);

//int* getArray();

void writeArrayToFile(char delimiter = ' ');

//int getArraySize();


bool isOpen();

~FileWriter();


};