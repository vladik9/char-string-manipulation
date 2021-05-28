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

myString &operator-(myString &object)
{
     char *buf = new char[strlen(object.char_string) + 1];
     strcpy(buf, object.char_string);
     for (size_t i = 0; i < strlen(object.char_string); i++)
     {
          buf[i] = tolower(buf[i]);
     }
     strcpy(object.char_string, buf);
     delete[] buf;
}

bool operator==(const myString &first_obj, const myString &second_obj)
{
     return {strcmp(first_obj.char_string, second_obj.char_string) == 0};
}

bool operator!=(const myString &first_obj, const myString &second_obj)
{
     return {strcmp(first_obj.char_string, second_obj.char_string) != 0};
}
bool operator<(const myString &first_obj, const myString &second_obj)
{
     return {strlen(first_obj.char_string) < strlen(second_obj.char_string)};
}
bool operator>(const myString &first_obj, const myString &second_obj)
{
     return {strlen(first_obj.char_string) > strlen(second_obj.char_string)};
}

myString operator+(const myString &first_obj, const myString &second_obj)
{
     char *buf = new char[strlen(first_obj.char_string) + strlen(second_obj.char_string) + 1];

     strcpy(buf, first_obj.char_string);
     strcat(buf, second_obj.char_string);
     myString temp{buf};
     delete[] buf;
     return temp;
}

myString &operator+=(const myString &first_obj, const myString &second_obj)
{
     char *buf = new char[strlen(first_obj.char_string) + strlen(second_obj.char_string) + 1];

     strcpy(buf, first_obj.char_string);
     strcat(buf, second_obj.char_string);
     strcpy(first_obj.char_string, buf);
     delete[] buf;
}
myString operator*(const myString &obj, const int &nr_times)
{
     size_t buf_size = strlen(obj.char_string) * nr_times;

     char *buf = new char[buf_size + 1];

     strcpy(buf, obj.char_string);

     for (size_t i = 0; i < nr_times - 1; i++)
     {
          strcat(buf, obj.char_string);
     }
     myString temp{buf};
     delete[] buf;
     return temp;
}
myString &operator*=(const myString &obj, const int &nr_times)
{
     size_t buf_size = strlen(obj.char_string) * nr_times;

     char *buf = new char[buf_size + 1];

     strcpy(buf, obj.char_string);

     for (size_t i = 0; i < nr_times - 1; i++)
     {
          strcat(buf, obj.char_string);
     }
     strcpy(obj.char_string, buf);
     delete[] buf;
}
myString &operator++(const myString &obj)
{

     char *buf = new char[strlen(obj.char_string) + 1];
     strcpy(buf, obj.char_string);
     buf[0] = toupper(buf[0]);
     strcpy(obj.char_string, buf);
     delete[] buf;
}
myString &operator++(const myString &obj, int)
{

     char *buf = new char[strlen(obj.char_string) + 1];
     strcpy(buf, obj.char_string);
     buf[strlen(obj.char_string) - 1] = toupper(buf[strlen(obj.char_string) - 1]);
     strcpy(obj.char_string, buf);
     delete[] buf;
}

myString &operator--(const myString &obj)
{

     char *buf = new char[strlen(obj.char_string) + 1];
     strcpy(buf, obj.char_string);
     buf[0] = tolower(buf[0]);
     strcpy(obj.char_string, buf);
     delete[] buf;
}
myString &operator--(const myString &obj, int)
{

     char *buf = new char[strlen(obj.char_string) + 1];
     strcpy(buf, obj.char_string);
     buf[strlen(obj.char_string) - 1] = tolower(buf[strlen(obj.char_string) - 1]);
     strcpy(obj.char_string, buf);
     delete[] buf;
}
