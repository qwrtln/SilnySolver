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



void readArrayFromFile(char delimiter = ' ');


void readArrayFromFileX(char delimiter = ' ');

int* getArray();

int getArraySize();


~FileReader();


};
