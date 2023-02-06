#include <iostream>
#include <vector>
#include <string>

//ARGUMENT CONTROLEREN OF HET INT ETC IS
//DOORSTUREN NAAR DE JUISTE FUNCTIE
//STATIC CAST? PER CATEGORIE
// https://cdn.intra.42.fr/pdf/pdf/68807/en.subject.pdf

int main(int argc, char const *argv[])
{
     
     if (argc != 2)
     {
          std::cout << "Wrong amount of Arguments" << std::endl;
          return EXIT_FAILURE;
     }


     std::string input = argv[1];

     if (input.length() == 1)
     {
          std::cout << "CHAR IS 1 " << std::endl;
          return (0);

     }



     //if (isalpha(argv[1][0]))
     if (input.find_first_not_of("-0123456789.f") != std::string::npos)
          std::cout << "FUNCTION FOR CHAR " << std::endl;
     else if (input.find_first_not_of(".f") == std::string::npos)
          std::cout << "FUNCTION FOR INT " << std::endl;
     else if (input.find_first_not_of("f") == (std::string::npos -1))
          std::cout << "FUNCTION FOR FLOAT " << std::endl;
     else
          std::cout << "DOUBLE" << std::endl;
     

     // How to f with char






     //else if (isdigit(argv[1][0]) || (argv[1][0] == '-' && isdigit(argv[1][1])))
     //{
     //     int i = 0;
     //     try
     //     {
     //          while (argv[1][i] != '\0')
     //          {
     //               int num = std::stoi(argv[1]);
     //               std::cout << "FUNCTION FOR INT " << num << std::endl;
     //               i++;
     //          }
     //     }
     //     catch (std::invalid_argument)
     //     {
     //          try
     //          {
     //               float floatNum = std::stof(argv[1]);
     //               std::cout << "FUNCTION FOR FLOAT " << floatNum << std::endl;
                    
     //          }
     //          catch(std::invalid_argument)
     //          {
     //               double doubleNum = std::stod(argv[1]);
     //               std::cout << "FUNCTION FOR Double " << doubleNum << std::endl;
                    
     //          }
     //     }
     //}
     //else
     //     std::cout << "Argument not valid" << std::endl;


     //float f = 3.4f;
     //int n = static_cast<int>(f);

     //std::cout << f << std::endl;
     //std::cout << n << std::endl;

     //int test = 123522;
     //float result = static_cast<float>(test);

     //std::cout << result << std::endl;
     return EXIT_SUCCESS;
}