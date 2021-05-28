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

     friend myString &operator-(myString &object);                                  //turn string tolower characters
     friend bool operator==(const myString &first_obj, const myString &second_obj); // check for equality
     friend bool operator!=(const myString &first_obj, const myString &second_obj); // check for inequality
     friend bool operator<(const myString &first_obj, const myString &second_obj);  //check for greater
     friend bool operator>(const myString &first_obj, const myString &second_obj);  // check for smaller

     friend myString operator+(const myString &first_obj, const myString &second_obj); // concatenation

     friend myString &operator+=(const myString &first_obj, const myString &second_obj); // concatenation and store to the same object
     friend myString operator*(const myString &obj, const int &nr_times);                // multimply n time object value

     friend myString &operator*=(const myString &obj, const int &nr_times); // multimply n time object value and store to the same object
     friend myString &operator++(const myString &obj);                      // prefix // to upper first letter
     friend myString &operator++(const myString &obj, int);                 // postfix // to upper last letter
     friend myString &operator--(const myString &obj);                      // prefix // to lowest first letter
     friend myString &operator--(const myString &obj, int);                 // postfix // to lowest last letter

public:
};

#endif // !_MY_STRING_H_
