#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

string GetDataFileContents()
{
    string path = "data.txt";
    ifstream ifs(path);
    string str((std::istreambuf_iterator<char>(ifs)),
        (std::istreambuf_iterator<char>()));

    return str;
}

vector<string> split(string phrase, string delimiter) {
    vector<string> list;
    size_t pos = 0;
    string token;
    while ((pos = phrase.find(delimiter)) != string::npos) {
        token = phrase.substr(0, pos);
        list.push_back(token);
        phrase.erase(0, pos + delimiter.length());
    }
    list.push_back(phrase);
    return list;
}

bool Success_part1(string data)
{
    int delimiter = data.find(":");
    char character = data.substr(delimiter - 1, 1)[0];

    int firstpoint = data.find("-");
    int minVal = std::stoi(data.substr(0, firstpoint));

    int secondPoint = data.find(" ");
    int lengthsecond = (data.size() - firstpoint) - (data.size() - secondPoint);
    int maxVal = std::stoi(data.substr(firstpoint + 1, lengthsecond));

    string password = data.substr(delimiter + 2, data.size() - 1);
    
    size_t n = std::count(password.begin(), password.end(), character);
    int _n = static_cast<int>(n);

    return (_n >= minVal) && (_n <= maxVal);
}

bool Success_part2(string data)
{
    int delimiter = data.find(":");
    char character = data.substr(delimiter - 1, 1)[0];

    int firstpoint = data.find("-");
    int firstIndex = std::stoi(data.substr(0, firstpoint))-1;

    int secondPoint = data.find(" ");
    int lengthsecond = (data.size() - firstpoint) - (data.size() - secondPoint);
    int secondIndex = std::stoi(data.substr(firstpoint + 1, lengthsecond))-1;

    string password = data.substr(delimiter + 2, data.size() - 1);

    if (secondIndex > password.size()) return false;

    return (password[firstIndex] == character) && (password[secondIndex] != character) || (password[secondIndex] == character && password[firstIndex] != character);
}

int main()
{
    int totalSuccess = 0;

    string input = GetDataFileContents();
    vector<string> v = split(input, "\n");

    for (int i = 0; i < v.size(); ++i)
    {
        if (Success_part2(v[i]))++totalSuccess;
    }

    cout << totalSuccess;

    return 0;
}