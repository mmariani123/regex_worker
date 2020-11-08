#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>

using namespace std;

std::ifstream fileIn("22_S22_L002_R1_001.sorted.mapped.narrowPeak");
std::string   line;

// Create and open a text file
std::ofstream MyFile("22_S22_L002_R1_001.sorted.mapped.bed");

int main()
{

 if(fileIn.is_open())
 {
    while(std::getline(fileIn, line))
    {
        std::stringstream   linestream(line);
        std::string         data;
        //std::string         val1;
        //std::string         val2;

        // If you have truly tab delimited data use getline() with third parameter.
        // If your data is just white space separated data
        // then the operator >> will do (it reads a space separated word into a string).
        std::getline(linestream, data, '\n');  // read up-to the first tab (discard tab).

        // Read the integers using the operator >>
        //linestream >> val1 >> val2;

        //std::cout << data << std::endl;

        //std::cout << val1 << val2 << std::endl;

        std::string s = data;

        if(regex_match(s, regex("^(track)(.*)"))){continue;}

        std::string delimiter = "\t";

        //remove newline:
        s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());

            size_t pos = 0;
            std::string token;
            while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            std::cout << token << std::endl;
            std::cin.get();
            s.erase(0, pos + delimiter.length());
            //(if you want to preserve the original string, just use s = s.substr(pos + delimiter.length());):
            }
            //std::cout << s << std::endl;
            std::string arr[10];
            int i = 0;
            std::stringstream ssin(line);
            while (ssin.good() && i < 10){
                ssin >> arr[i];
                ++i;
            }
            for(i = 0; i < 10; i++){
                std::cout << arr[i] << std::endl;
               // Write to the file
               if(i<2){
                MyFile << arr[i] << "\t";
               }else if(i==2){
               MyFile << arr[i] << std::endl;
               }
            }
            std::cin.get();
    }

 }


// Close the file
MyFile.close();

return(0);

}
