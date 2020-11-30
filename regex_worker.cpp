#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>

using namespace std;

int main()
{
    /* NOTES */

    // /^      // beginning of line
    // (?:     // do not capture
    // [^;]*   // unlimited characters we DON'T want
    // [;]     // a single character we DO want
    // ){4}    // n-1 matches
    // [^;]*   // unlimited characters we DON'T want
    // ([;])/   // the nth match, and capture it

    // /^(?:[^\t]*[\t]){2}[^\t]*(peak_.*)/

    //cout << "Hello world!" << endl;

    //int i;
    //cout << "Please enter an integer value: ";
    //cin  >> i;
    //cout << "The value you entered is " << i;
    //cout << " and its double is " << i*2 << ".\n";

    //string mystr;
    //string mystr2;
    //cout << "What's your name? ";
    //getline(cin, mystr);
    //cout << "Hello " << mystr << ".\n";
    //cout << "What is your favorite team? ";
    //getline (cin, mystr);
    //cout << "I like " << mystr << " too!\n";

    bool runProgram=true;
    while(runProgram==true)
    {

        //https://www.geeksforgeeks.org/buffer-flush-means-c/
        //In C++, we can explicitly flushed to forced the buffer to be written.
        //Generally std::endl function works the same by inserting new-line
        //character and flushes the stream. stdout/cout is line-buffered
        //that is the output doesn’t get sent to the OS until you write
        //a newline or explicitly flush the buffer.
        //cout << "Search a string with regex" << flush;

        cout << "Welcome to Regex Worker, where you can search a string with regex" << endl;

        //string to be searched
        //string mystr3 = "She sells_sea shells by the sea shore";
        //enter a string to be searched

        cout << "enter a string to be searched" << endl;
        string stringInput;
        getline(cin, stringInput);

        //enter a regex string
        cout << "enter a regex pattern as a string" << endl;
        string regexInput;
        getline(cin, regexInput);

        // regex expression for pattern to be searched
        //regex regexp("s[a-z_]+");
        regex regexp(regexInput);

        // flag type for determining the matching behavior (in this case on string objects)
        // instantiate matches object for string class;
        smatch m;

        // regex_search that searches pattern regexp in the string mystr
        regex_search(stringInput, m, regexp);

        // "auto" performs automatic type detection for us

        //https://stackoverflow.com/questions/35490236/colon-and-auto-in-for-loop-c-need-some-help-understanding-the-syntax

        //This is a range based for loop, it has the same basic behavior of:
        //for(auto it = deviceList.begin(); it != deviceList.end(); ++it)
        //{
        //  const auto& ioDev = *it;
        //}
        //The range based for loop has quickly become one of my favorite constructs,
        //it's terse and when you need to iterate an entire range, works as well
        //and as efficiently) as possible.

        //If you need the other constructs of a typical for loop
        //(say to exit early in some case),
        //then range-based for isn't for that use case.
        ofstream myFile;
        myFile.open("regex_matches.txt");
        cout << "String that matches the pattern:" << endl;
        for(auto x : m){
            //Output match results to console:
            cout << x << endl;
            //Output match results to file:
            //Create and open a text file
            myFile << x << "\n";
        }
        // Close the file
        myFile.close();

        string programStatus;
        cout << "would you like to run again? type yes or no" << endl;
        getline(cin,programStatus);

        if(programStatus=="yes"){
            runProgram=true;
        }else if(programStatus=="no"){
            runProgram=false;
        }else{
            cout << "did not enter yes or no, program terminating" << endl;
            cin.get();
            break;
        }

    }
    return(0);

}
