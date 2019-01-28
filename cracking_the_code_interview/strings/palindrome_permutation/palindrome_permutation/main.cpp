#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_palindrome_permutation(std::string input){

	std::vector<int> c_table((int)'z' - (int)'a' + 1, 0);

	int count_odd = 0;

	for(int i = 0; i < input.length(); i++){

		c_table[(int)input[i]]++;

		if(c_table[(int)input[i] - (int)'a'] % 2 != 0) count_odd++;
		else count_odd--;
	}

	if(count_odd > 1) return false;
	else return true;
}

int main(){

	std::cout << is_palindrome_permutation("tact coa");

    return 0;
}
