#include<iostream>
#include<string>
#include<vector>

int main(int argc, char* argv[])
{
  char inChar{'x'};       //For some reason it prints out an @ between letters now!

  const std::vector<std::string> cmdLineArgs{argv, argv+argc};
  
  for (unsigned int i{0}; i < cmdLineArgs.size(); i++)
    {
      std::cout << cmdLineArgs[i] << std::endl;
      if(cmdLineArgs[i]=="--help" || cmdLineArgs[i]=="-h")
	{
	  std::cout << "This is a help screen!" << std::endl;
	  return 0;
	}
      else if(cmdLineArgs[i]=="--version")
	{
	  std::cout << "This is version alpha 0.x" << std::endl;
	  return 0;
	}
      else if(cmdLineArgs[i]=="-i")
	{
	  std::cout << "Input file is: " << cmdLineArgs[i+1] << std::endl;
	  i++; //Skip next argument as it's the file name
	}
      else if(cmdLineArgs[i]=="-o")
	{
	  std::cout << "Output file is: " << cmdLineArgs[i+1] << std::endl;
	  i++;
	}
      else if(cmdLineArgs[i]=="./mpags-cipher")
	{//do nothing, it's the program name
	}
      else
	std::cout << "Unknown option!" << std::endl;
    }
  
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
      message.append(&inChar);
    }

  //print out the new string
  std::cout << message << std::endl; 

  return 0;
}
