#include "Utility.h"

void Utility::clamp(int* valueAddr, int min, int max) {
    if ((*valueAddr) > max) (*valueAddr) = max;
    else if ((*valueAddr) < min) (*valueAddr) = min;
}

std::string Utility::printT(std::string str, std::map<std::string, int*> myMap)
{
    int firstChar = -1;
    int lastChar = -1;

    size_t i, j, k, l;

    const std::string START_DELIMITER = "{{";
    const std::string END_DELIMITER = "}}";

    std::string ret = "";
    std::vector<std::string> strarray = {};

    if (str.size() <= 2)
    {
        return str;
    }

    for (i = 0; i < str.size(); i++)
    {
        bool isFind = false;

        // FIND FIRST CHAR
        if (i != (str.size() - (START_DELIMITER.size() + END_DELIMITER.size() - 1)))
        {
            for (j = 0; j < START_DELIMITER.size(); j++)
            {
                if (str.at(i + j) == START_DELIMITER.at(j))
                {
                    isFind = true;

                }
                else
                {
                    isFind = false;
                    break;
                }
            }

            if (isFind && firstChar == -1 && lastChar == -1 && i > START_DELIMITER.size())
            {
                strarray.push_back(str.substr(0, i));
            }

            isFind ? firstChar = (i + START_DELIMITER.size()) : firstChar = -1;
            if (lastChar != -1 && firstChar != -1)
            {
                strarray.push_back(str.substr(lastChar + END_DELIMITER.size() + 1, firstChar - (lastChar + END_DELIMITER.size() + START_DELIMITER.size() + 1)));
                lastChar = -1;
            }
        }
        else
        {
            // THERE IS NO MORE VARIABLES
            if (lastChar != -1)
            {
                strarray.push_back(str.substr(lastChar + END_DELIMITER.size() + 1, str.size()));
            }
            else
            {
                strarray.push_back(str);
            }
        }

        // FIND LAST CHAR

        if (firstChar != -1 && i < (str.size() - (END_DELIMITER.size() + 1)))
        {
            for (k = firstChar; k < str.size() - END_DELIMITER.size(); i++)
            {
                for (l = 0; l < END_DELIMITER.size(); l++)
                {
                    if (str.at(i) == END_DELIMITER.at(0))
                    {
                        isFind = true;
                    }
                    else
                    {
                        isFind = false;
                    }
                }
                isFind ? lastChar = (i - 1) : lastChar = -1;
                if (lastChar != -1) break;
            }

        }

        // PUSH VARIABLE

        if (firstChar != -1 && lastChar != -1)
        {
            std::string final = str.substr(firstChar, lastChar - firstChar);
            std::string::iterator end_pos = std::remove(final.begin(), final.end(), ' ');
            final.erase(end_pos, final.end());
            strarray.push_back(final);
        }


    }

    // APPEND RETURNED STRING
    for (i = 0; i < strarray.size(); i++)
    {
        if (strarray.at(i).at(0) == '$')
        {
            int value = *myMap.at(strarray.at(i).substr(1, (strarray.at(i).size())));
            ret += std::to_string(value);
        }
        else
        {
            ret += strarray.at(i);
        }
    }
    return ret;
}

std::string Utility::printT(std::string str, std::map<std::string, std::string*> myMap)
{
    int firstChar = -1;
    int lastChar = -1;

    size_t i, j, k, l;

    const std::string START_DELIMITER = "{{";
    const std::string END_DELIMITER = "}}";

    std::string ret = "";
    std::vector<std::string> strarray = {};

    if (str.size() <= 2)
    {
        return str;
    }

    for (i = 0; i < str.size(); i++)
    {
        bool isFind = false;

        // FIND FIRST CHAR
        if (i != (str.size() - (START_DELIMITER.size() + END_DELIMITER.size() - 1)))
        {
            for (j = 0; j < START_DELIMITER.size(); j++)
            {
                if (str.at(i + j) == START_DELIMITER.at(j))
                {
                    isFind = true;

                }
                else
                {
                    isFind = false;
                    break;
                }
            }

            if (isFind && firstChar == -1 && lastChar == -1 && i > START_DELIMITER.size())
            {
                strarray.push_back(str.substr(0, i));
            }

            isFind ? firstChar = (i + START_DELIMITER.size()) : firstChar = -1;
            if (lastChar != -1 && firstChar != -1)
            {
                strarray.push_back(str.substr(lastChar + END_DELIMITER.size() + 1, firstChar - (lastChar + END_DELIMITER.size() + START_DELIMITER.size() + 1)));
                lastChar = -1;
            }
        }
        else
        {
            // THERE IS NO MORE VARIABLES
            if (lastChar != -1)
            {
                strarray.push_back(str.substr(lastChar + END_DELIMITER.size() + 1, str.size()));
            }
            else
            {
                strarray.push_back(str);
            }
        }

        // FIND LAST CHAR

        if (firstChar != -1 && i < (str.size() - (END_DELIMITER.size() + 1)))
        {
            for (k = firstChar; k < str.size() - END_DELIMITER.size(); i++)
            {
                for (l = 0; l < END_DELIMITER.size(); l++)
                {
                    if (str.at(i) == END_DELIMITER.at(0))
                    {
                        isFind = true;
                    }
                    else
                    {
                        isFind = false;
                    }
                }
                isFind ? lastChar = (i - 1) : lastChar = -1;
                if (lastChar != -1) break;
            }

        }

        // PUSH VARIABLE

        if (firstChar != -1 && lastChar != -1)
        {
            std::string final = str.substr(firstChar, lastChar - firstChar);
            std::string::iterator end_pos = std::remove(final.begin(), final.end(), ' ');
            final.erase(end_pos, final.end());
            strarray.push_back(final);
        }


    }

    // APPEND RETURNED STRING
    for (i = 0; i < strarray.size(); i++)
    {
        if (strarray.at(i).at(0) == '&')
        {
            ret += *myMap.at(strarray.at(i).substr(1, (strarray.at(i).size())));
        }
        else
        {
            ret += strarray.at(i);
        }
    }
    return ret;
}

std::vector<std::pair<int, int>> Utility::getPath(std::pair<int, int> origin, std::pair<int, int> destination)
{
    std::vector<std::pair<int, int>> path;
    std::pair<int, int> pointer = origin;
    std::pair<int, int> tileToCheck;
    float min_distance = 100.0f;
    float temp = 100.0f;
    while (pointer != destination) {
        tileToCheck = pointer;
        // X + 1 CHECK
        tileToCheck.first += 1;
        if (tileToCheck.first >= 0) {
            temp = distance(tileToCheck, destination);
            if (min_distance > temp) {
                min_distance = temp;
                pointer = tileToCheck;
            }
        }
        // X - 1 CHECK
        tileToCheck.first -= 1;
        if (tileToCheck.first >= 0) {
            temp = distance(tileToCheck, destination);
            if (min_distance > temp) {
                min_distance = temp;
                pointer = tileToCheck;
            }
        }
        // Y + 1 CHECK
        tileToCheck.second += 1;
        if (tileToCheck.second >= 0) {
            temp = distance(tileToCheck, destination);
            if (min_distance > temp) {
                min_distance = temp;
                pointer = tileToCheck;
            }
        }
        // Y - 1 CHECK
        tileToCheck.second -= 1;
        if (tileToCheck.second >= 0) {
            temp = distance(tileToCheck, destination);
            if (min_distance > temp) {
                min_distance = temp;
                pointer = tileToCheck;
            }
        }
        path.push_back(pointer);
    }
    return path;
}

float Utility::distance(std::pair<int, int> origin, std::pair<int, int> destination) {
    return sqrt(pow(destination.first - origin.first, 2) + pow(destination.second - origin.second, 2));
}

bool Utility::writeToFile(char const* filename, unsigned lineNo, std::string toWrite)
{
    std::fstream file(filename);
    if (!file)
        return false;

    unsigned currentLine = 0;
    while (currentLine < lineNo)
    {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        ++currentLine;
    }

    file.seekp(file.tellg());

    file << toWrite;

    return true;
}