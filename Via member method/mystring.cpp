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

myString myString::operator+(const myString &second_obj)
{
     size_t bufer_size = strlen(this->char_string) + strlen(second_obj.char_string);
     char *buf = new char[bufer_size + 1];
     strcpy(buf, this->char_string);
     strcat(buf, second_obj.char_string);
     myString temp{buf};
     delete[] buf;
     return temp;
}
myString &myString::operator+=(const myString &second_obj)
{
     size_t bufer_size = strlen(this->char_string) + strlen(second_obj.char_string);
     char *buf = new char[bufer_size + 1];
     strcpy(buf, this->char_string);
     strcat(buf, second_obj.char_string);
     strcpy(this->char_string, buf);
     delete[] buf;
     return *this;
}
myString myString::operator*(const int &nr_times)
{
     size_t buf_size = strlen(this->char_string) * nr_times;
     char *buf = new char[buf_size + 1];
     strcpy(buf, this->char_string);
     for (size_t i = 0; i < (nr_times - 1); i++)
     {
          strcat(buf, this->char_string);
     }
     myString temp{buf};

     delete[] buf;
     return temp;
}
myString &myString::operator*=(const int &nr_times)
{
     size_t buf_size = strlen(this->char_string) * nr_times;
     char *buf = new char[buf_size + 1];
     strcpy(buf, this->char_string);
     for (size_t i = 0; i < nr_times - 1; i++)
     {
          strcat(buf, this->char_string);
     }
     strcpy(this->char_string, buf);
     delete[] buf;
     return *this;
}

myString &myString::operator++()
{
     char *buf = new char[strlen(this->char_string) + 1];
     strcpy(buf, this->char_string);
     buf[0] = toupper(buf[0]);
     strcpy(this->char_string, buf);
     delete[] buf;
     return *this;
}
myString &myString::operator++(int)
{
     size_t buf_size = strlen(this->char_string);
     char *buf = new char[buf_size + 1];
     strcpy(buf, this->char_string);
     buf[buf_size - 1] = toupper(buf[buf_size - 1]);
     strcpy(this->char_string, buf);
     delete[] buf;
     return *this;
}
myString &myString::operator--()
{
     char *buf = new char[strlen(this->char_string) + 1];
     strcpy(buf, this->char_string);
     buf[0] = tolower(this->char_string[0]);
     strcpy(this->char_string, buf);
     delete[] buf;
     return *this;
}
myString &myString::operator--(int)
{
     size_t buf_size = strlen(this->char_string);
     char *buf = new char[buf_size + 1];
     strcpy(buf, this->char_string);
     buf[buf_size - 1] = tolower(buf[buf_size - 1]);
     strcpy(this->char_string, buf);
     delete[] buf;
     return *this;
}