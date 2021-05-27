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
     bool operator==(const myString &second_obj);      // check for equality
     bool operator!=(const myString &second_obj);      // check for inequality
     bool operator<(const myString &second_obj);       //check for greater
     bool operator>(const myString &second_obj);       // check for smaller
     myString operator+(const myString &second_obj);   // concatenation
     myString &operator+=(const myString &second_obj); // concatenation and store to the same object
     myString operator*(const int &nr_times);          // multimply n time object value
     myString &operator*=(const int &nr_times);        // multimply n time object value and store to the same object
     myString &operator++();                           // prefix // to upper first letter
     myString &operator++(int);                        // postfix // to upper last letter
     myString &operator--();                           // prefix // to lowest first letter
     myString &operator--(int);                        // postfix // to lowest last letter

public:
};

#endif // !_MY_STRING_H_
