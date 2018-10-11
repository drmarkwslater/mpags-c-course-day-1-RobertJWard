#include<iostream>
#include<string>
#include<vector>

#include <cctype>

int main(int argc, char* argv[])
{
  const std::vector<std::string> cmdLineArgs{argv, argv+argc};

  char inChar{'x'};       //For some reason it prints out an @ between letters now!
  std::string inputFile{""};
  std::string outputFile{""};
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {cmdLineArgs.size()};

  for (unsigned int i{1}; i < cmdLineArgs.size(); i++)
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
	  if (i == nCmdLineArgs-1) {
	    std::cerr << "[error] -i requires a filename argument" << std::endl;
	    // exit main with non-zero return to indicate failure
	    return 1;
	  }
	  else 
	    {
	      std::cout << "Input file is: " << cmdLineArgs[i+1] << std::endl;
	      inputFile = cmdLineArgs[i+1];
	      i++; //Skip next argument as it's the file name
	    }
	}
      else if(cmdLineArgs[i]=="-o")
	{
	  if (i == nCmdLineArgs-1) {
	    std::cerr << "[error] -o requires a filename argument" << std::endl;
	    // exit main with non-zero return to indicate failure
	    return 1;
	  }
	  else 
	    {
	      std::cout << "Output file is: " << cmdLineArgs[i+1] << std::endl;
	      outputFile = cmdLineArgs[i+1];
	      i++;
	    }
	}
      else
	std::cout << "Unknown option:  " << cmdLineArgs[i] << std::endl;
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
      message += inChar;
    }

  //print out the new string
  std::cout << message << std::endl; 

  return 0;
}
