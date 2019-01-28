#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_anagram(std::string s1, std::string s2){

    if(s1.empty() && s2.empty()) return true;
    if(s1.empty() || s2.empty()) return false;
    if(s1.length() != s2.length()) return false;

	std::vector<int> table1(((int)'z' - (int)'a' + 1), 0);
    std::vector<int> table2(((int)'z' - (int)'a' + 1), 0);


	for(int i = 0; i < s1.length(); i++){
        table1[(int)s1[i] - (int)'a']++;
        table2[(int)s2[i] - (int)'a']++;
	}

	for(int i = 0; i < 26; i++){
        if(table1[i] != table2[i]) return false;
	}

	return true;
}


std::vector<std::vector<string> > groupAnagrams(std::vector<string> &strs){

	std::vector<bool> visited(strs.size(), false);
	std::vector<std::vector<string> > result;

	for(int i = 0; i < strs.size(); i++){

		if(visited[i]) continue;
		visited[i] = true;
		std::vector<string> group;
		group.push_back(strs[i]);

		for(int j = 0; j < strs.size(); j++){
			if(i == j) continue;
			if(visited[j]) continue;
			if(is_anagram(strs[i], strs[j])){
				group.push_back(strs[j]);
				visited[j] = true;
			}
		}

		result.push_back(group);
	}

	return result;
}


int main(){

	std::vector<string> strs = {"tea","and","ace","ad","eat","dans"};
	groupAnagrams(strs);
    return 0;
}
