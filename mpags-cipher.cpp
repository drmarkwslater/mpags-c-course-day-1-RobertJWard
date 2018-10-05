// mpags-cipher.cpp source file

#include<iostream>
#include<string>


int main()
{
  // This is a comment
  /* Multiline comment
     still commented */

  std::cout << "Hello World!" << std::endl;
  
  int a{1}; //Uniform initialisation c++11

  a = 12 + 91;

  double b{91.67};

  b*=1.37;

  int c{b};

  std::cout << "a = " << a << ", b = " << b << ", c = " << c << std::endl;
  
  // endl tells the program to flush the code there and then, /n lets the program print whenever it fancies.
  // ' means char, " means string 

  std::string message{"This is a string"};
  std::cout << message << std::endl;

  const double d{12.234};
  std::cout << "d = " << d << std::endl;

  const int e{12};
  //e=123; //<-- this causes an error!
  std::cout << "e = " << e << std::endl;
  
  //Declare everything as const unless you know it needs to be changed at some point

  
  return 0;
}
