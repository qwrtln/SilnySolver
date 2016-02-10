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


//void readArray(char delimiter = ' ');

//int* getArray();

void writeArray(char delimiter = ' ');

//int getArraySize();


bool isOpen();

~FileWriter();


};
