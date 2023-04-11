/**
 *   @file: lab11.cc
 * @author: Allison McKee
 *   @date: 04-04-2023
 *  @brief: predefined character functions and arrays
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

void convertFile(ifstream& inStream, ofstream& outStream);

// main function
int main(int argc, char const* argv[]) 
{
    if (argc != 3) 
    {
        cout << "Error: Incorrect number of command lines." << endl;
        exit(0);
    }
    
    ifstream inStream;
    ofstream outStream;
    string inputFile = argv[1];
    string outputFile = argv[2];

    // open files and test if they fail
    inStream.open(inputFile);
    if (inStream.fail())
    {
        cout << "Error: Input file did not open." << endl;
        exit(0);
    }
    outStream.open(outputFile);
    if (outStream.fail())
    {
        cout << "Error: Output file did not open." << endl;
        exit(0);
    }

    // call the function
    convertFile(inStream, outStream);
    
    // close the files
    inStream.close();
    outStream.close();
    return 0;
}

// converting digits to astericks and lowercase to uppercase function
void convertFile(ifstream& inStream, ofstream& outStream)
{
    char c;
    while (inStream.get(c))
    {
        if (isdigit(c))
        {
            outStream.put('*'); // if its a digit, replace it with *
        }
        else
        {
            outStream.put(toupper(c)); // make all letters uppercase
        }
    }
}