#include <iostream>
#include "mystring.h"
#include "mystring.cpp"

int main()
{
     myString vlad{"Vlad"};
     myString vlad2{"slad"};
     if (vlad != vlad2)
     {
          std::cout << "it's not equal" << std::endl;
     }
     else
          std::cout << "it's equal" << std::endl;

     return 0;
}
