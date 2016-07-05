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


void inputArrayToWrite(int* inputArray, int inputSize);


void saveArrayToFile(char delimiter = ' ');



bool isOpen();

~FileWriter();


};
