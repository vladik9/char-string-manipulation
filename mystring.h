#ifndef _MY_STRING_H_
#define _MY_STRING_H_
#include <cstring>
#include <iostream>
class myString
{
private:
     char *char_string;

public:
     myString(char *ptr);
     ~myString();
     myString(const myString &copy);
     myString(myString &&move);
     friend std::ostream &operator<<(std::ostream &out, const myString &ref)
     {
          out << ref.char_string;
          return out;
     }
     char *printChar();

     myString operator-();
     bool operator==(const myString &second_obj);
     bool operator!=(const myString &second_obj);
     bool operator<(const myString &second_obj);
     bool operator>(const myString &second_obj);

public:
};

#endif // !_MY_STRING_H_
