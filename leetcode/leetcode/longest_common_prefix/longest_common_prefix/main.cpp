#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::string longestCommonPrefixUtil(std::string str, std::string prefix){

    std::string result = "";

    for(int i = 0; i < prefix.length(); i++){
        if(str[i] == prefix[i]) result += str[i];
        else break;
    }

    return result;
}


std::string longestCommonPrefix(std::vector<std::string> &strs){

    if(strs.size() == 0) return "";

    std::string prefix = strs[0];

    for(int i = 1; i < strs.size(); i++){
        prefix = longestCommonPrefixUtil(strs[i], prefix);
    }

    return prefix;
}


int main()
{
    std::vector<std::string> strs = {"geeksforgeeks", "geeks", "geek", "geezer"};
    longestCommonPrefix(strs);
    return 0;
}
