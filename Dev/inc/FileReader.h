#include <fstream>
//#include <string>


//using std::string;
using std::ifstream;

class FileReader{


ifstream file;

int* array;

int arraySize;


public:

FileReader();

FileReader(char const* fileName);


void readArray(char delimiter = ' ');

int* getArray();

int getArraySize();


~FileReader();


};
