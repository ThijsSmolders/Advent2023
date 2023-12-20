// Day1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <ctype.h>
#include <fstream>
#include <sstream>
#include <regex>

std::vector<std::string> txt = { "1abc2", "pqr3stu8vwx", "a1b2c3d4e5f", "treb7uchet"};
std::vector<std::string> txt2{ "two1nine", "eightwothree", "abcone2threexyz", "xtwone3four", "4nineeightseven2", "zoneight234", "7pqrstsixteen" };

std::string replaceString(std::string originalString, std::string stringToBeReplaced, std::string stringReplacement)
{
    std::string replacedString{ std::regex_replace(originalString, std::regex(stringToBeReplaced), stringReplacement) };
    return replacedString;
}

std::string parseString(std::string originalString)
{
    std::cout << "String before replacement " << std::endl << originalString << std::endl;
    std::string parsedString{ originalString };
    parsedString = replaceString(parsedString, "one", "o1e");
    parsedString = replaceString(parsedString, "two", "t2o");
    parsedString = replaceString(parsedString, "three", "t3e");
    parsedString = replaceString(parsedString, "four", "f4r");
    parsedString = replaceString(parsedString, "five", "f5e");
    parsedString = replaceString(parsedString, "six", "s6x");
    parsedString = replaceString(parsedString, "seven", "s7n");
    parsedString = replaceString(parsedString, "eight", "e8t");
    parsedString = replaceString(parsedString, "nine", "n9e");
    std::cout << "String after replacement " << std::endl << parsedString << std::endl;
    return parsedString;
}

int countString(std::string str)
{
    int firstInt{ 0 };
    bool firstIntHit{ false };
    int lastInt{ 0 };


    for (char i : str)
        if (std::isdigit(i))
        {
            if (not firstIntHit){
                // std::cout << "firstInt hit with value " << i << std::endl;
                firstIntHit = true;
                firstInt = i - '0';
                lastInt = i - '0';
            }
            else
            {
                // std::cout << "new int hit with value " << i << std::endl;
                lastInt = i - '0';
            }
        };

    int contributionSum{ firstInt*10 + lastInt };
    std::cout << "contribution is " << contributionSum << std::endl;

    return contributionSum;
}

int parseStringWithTextIntegers(std::string str)
{

    int firstInt{ 0 };
    bool firstIntHit{ false };
    int lastInt{ 0 };

    std::cout << "parsing string " << str << std::endl;

    for (char i : str)
        if (std::isdigit(i))
        {
            if (not firstIntHit) {
                // std::cout << "firstInt hit with value " << i << std::endl;
                firstIntHit = true;
                firstInt = i - '0';
                lastInt = i - '0';
            }
            else
            {
                // std::cout << "new int hit with value " << i << std::endl;
                lastInt = i - '0';
            }
        };

    int contributionSum{ firstInt * 10 + lastInt };
    std::cout << "contribution is " << contributionSum << std::endl;

    return contributionSum;
}

int main()
{
    int calibrationSum{ 0 };

    std::ifstream infile("C:\\Users\\thijs.smolders\\source\\repos\\Day1\\Day1.txt");

    std::string line;
    while (std::getline(infile, line))
    {
        std::string parsedLine{ parseString(line) };
        calibrationSum += countString(parsedLine);
    }

    //for (std::string i : txt2)
    //{
    //    // std::cout << i << std::endl;
    //    std::string parsedString{ parseString(i) };
    //    calibrationSum += countString(parsedString);
    //}

    std::cout << "calibrationSum = " << calibrationSum << std::endl;
    return calibrationSum;
}