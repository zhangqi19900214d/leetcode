/*
Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.



Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
Example 4:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both ¡°01¡± and ¡°001" represent the same number ¡°1¡±
Example 5:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"


Note:

Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
Version strings do not start or end with dots, and they will not be two consecutive dots.
*/

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution 
{
public:
    string getNumber(const std::string s, int start)
    {
        if (start >= s.size())
        {
            return "";
        }

        size_t end = s.find('.', start);
        if (end != string::npos)
        {
            return s.substr(start, end - start);
        }
        else
        {
            return s.substr(start, string::npos);
        }
    }

    int compareVersion(string version1, string version2)
    {
        int indexA = 0;
        int indexB = 0;

        while (indexA < version1.size() || indexB < version2.size())
        {
            string &&strA = this->getNumber(version1, indexA);
            string &&strB = this->getNumber(version2, indexB);

            indexA += strA.size() + 1;
            indexB += strB.size() + 1;

            int len = max(strA.size(), strB.size());
            while (strA.size() < len)
            {
                strA.insert(0, "0");
            }
            while (strB.size() < len)
            {
                strB.insert(0, "0");
            }

            if (strA != strB)
            {
                return strA > strB ? 1 : -1;
            }
        }
        return 0;
    }
};

int main()
{
    auto sol = new Solution();
    sol->compareVersion("3.11", "3.12");
   // return 0;

    cout << sol->compareVersion("0.1",      "1.1") << endl;
    cout << sol->compareVersion("1.0.1",    "1") << endl;
    cout << sol->compareVersion("7.5.2.4",  "7.5.3") << endl;
    cout << sol->compareVersion("1.01",     "1.001") << endl;
    cout << sol->compareVersion("1.0",      "1.0.0") << endl;
}