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

bool IsGreater_part1(int target, int num1, int num2)
{
    return num1 + num2 > target;
}

bool DoesSum_part1(int targetAmount, int num1, int num2)
{
    return num1 + num2 == targetAmount;
}

bool IsGreater_part2(int target, int num1, int num2, int num3)
{
    return num1 + num2 + num3 > target;
}

bool DoesSum_part2(int targetAmount, int num1, int num2, int num3)
{
    return num1 + num2 + num3 == targetAmount;
}

int main()
{
    int requiredAmount = 0;
    cout << "Enter a target number" << endl;
    cin >> requiredAmount;

    string input = GetDataFileContents();
    //vector<string> v = split(input, "\n");
    istringstream iss(input);
    vector<int> v{ istream_iterator<int>{iss},
                      istream_iterator<int>{} };

    std::sort(v.begin(), v.end());

    for (int i = 0; i < v.size() - 1; ++i)
    {
        for (int j = i + 1; j < v.size() - 1; ++j)
        {
            for (int k = 0; k < v.size() - 1; ++k)
            {
                if (IsGreater_part2(requiredAmount, v[i], v[j], v[k]))
                {
                    break;
                }

                if (DoesSum_part2(requiredAmount, v[i], v[j], v[k]))
                {
                    cout << "numbers adding total is:" << endl;
                    int value = v[i] * v[j] * v[k];
                    cout << value << endl;
                    cout << "numbers were: " << endl;
                    cout << v[i] << "\t";
                    cout << v[j] << "\t";
                    cout << v[k] << "\t";
                    goto endOfLoop;
                }
            }
        }
    }
    //HATE THIS but nested loops
endOfLoop:
    return 0;
}