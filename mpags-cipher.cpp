#include<iostream>
#include<string>

int main()
{
  char inChar{'x'};
  std::string message{""};
  while(std::cin >> inChar)
    {
      //Loop until the user presses Enter then Ctrl+D

      //Take each letter from user input and in each case:

      //  - Convert to upper case
      inChar = toupper(inChar);

      //  - Change numbers to words
      switch (inChar)
	{
	case '0':
	  message.append("ZERO");
	  break;
	case '1':
	  message.append("ONE");
	  break;
	case '2':
	  message.append("TWO");
	  break;
	case '3':
	  message.append("THREE");
	  break;
	case '4':
	  message.append("FOUR");
	  break;
	case '5':
	  message.append("FIVE");
	  break;
	case '6':
	  message.append("SIX");
	  break;
	case '7':
	  message.append("SEVEN");
	  break;
	case '8':
	  message.append("EIGHT");
	  break;
	case '9':
	  message.append("NINE");
	  break;
	default:
	  break; //don't really need the default
	}
      //  - Ignore any other (non-alpha) characters
      if (!isalpha(inChar))
	continue; //If the non-alpha character is a number it will already be converted
      //  - In each case, add result to a string variable
      char* outChar{&inChar};
      message.append(outChar);
    }

  //print out the new string
  std::cout << message << std::endl; 

  return 0;
}
