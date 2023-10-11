#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <climits>

std::string noSpace(const std::string &s)
{
    std::string result;
    for (size_t i = 0; i < s.length(); i++)
    {
        if(s[i] != ' ')
            result += s[i];
    }
    return result;
    
}

int    err(const std::string &s)
{
    std::cerr << "Error: " << s << std::endl;
    return (1);
}

int     format_check(const std::pair<std::string, std::string> &pair, long double bitCount)
{
    if (pair.first.empty() || pair.second.empty())
        return err("bad input => " + (pair.first.empty()? pair.second.empty()? NULL : pair.second : pair.first));
    else if (bitCount < 0)
        return err("not a positive number.");
    else if (bitCount > INT_MAX)
        return err("too large a number.");
    return (0);
}

template <typename T>
void getColumnData(const std::string &filename, int columnKey, int columnValue, T &result, char denom)
{
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string token;
        std::string key = "", value = "";
        int currentColumn = 1;

        while (std::getline(ss, token, denom)) {
            if (currentColumn == columnKey) {
                key = noSpace(token);
            }
            if (currentColumn == columnValue) {
                value = noSpace(token);
            }
            currentColumn++;
        }
        result.insert(std::make_pair(key, value));
    }
    inputFile.close();
}

int main() {
    std::multimap<std::string, std::string> csv_data;
    //getColumnData("bitcoin_csv.csv", 1, 6, csv_data, ',');
    getColumnData("data.csv", 1, 2, csv_data, ',');
    std::multimap<std::string, std::string> input_data;
    getColumnData("input.txt", 1, 2, input_data, '|');

    for (const std::pair<std::string, std::string> &pair : input_data)
    {
        long double bitCount = 0, bitValue = 1;
        if (!pair.first.empty() && !pair.second.empty())
        {
            bitValue = std::strtold(csv_data.lower_bound(pair.first)->second.c_str(), 0);
            bitCount = std::strtold(pair.second.c_str(), 0);
        }
        if (!format_check(pair, bitCount))
            std::cout << pair.first << " => " << bitCount << " = " << bitCount*bitValue << std::endl;
    }

    return 0;
}
