#include "mystring.h"
#include <iostream>
myString::myString(char *ptr)
{
     char_string = new char[strlen(ptr) + 1];
     strcpy(char_string, ptr);
}

myString::~myString()
{
     delete[] char_string;
}
myString::myString(const myString &copy)
{
     std::cout << "copy" << std::endl;
     if (char_string != nullptr)
     {
          delete[] char_string;
     }
     char_string = new char[strlen(copy.char_string) + 1];
     strcpy(char_string, copy.char_string);
}

char *myString::printChar()
{
     return char_string;
}

myString::myString(myString &&move)
{
     std::cout << "move" << std::endl;
     if (char_string != nullptr)

     {
          delete[] char_string;
     }
     char_string = new char[strlen(char_string) + 1];
     strcpy(char_string, move.char_string);
     move.char_string = nullptr;
}

myString myString::operator-()
{
     char *buf = new char[100];
     strcpy(buf, char_string);
     for (size_t i = 0; i < strlen(buf); i++)
     {
          buf[i] = tolower(char_string[i]);
     }
     myString temp{buf};
     delete[] buf;
     return temp;
}
bool myString::operator==(const myString &second_obj)
{
     return {strcmp(this->char_string, second_obj.char_string) == 0};
}
bool myString::operator!=(const myString &second_obj)
{
     return {strcmp(this->char_string, second_obj.char_string) != 0};
}
bool myString::operator<(const myString &second_obj)
{
}