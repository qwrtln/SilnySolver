#include <fstream>
//#include <string>


//using std::string;
using std::ifstream;

class FileReader{


ifstream file;

int* array;

int arraySize;


public:

FileReader(const char* fileName);


void readArray(char delimiter = ' ');

int* getArray();

int getArraySize();


~FileReader();


};
