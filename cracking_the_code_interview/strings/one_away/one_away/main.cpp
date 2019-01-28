#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stdlib.h>

using namespace std;

bool insertion(std::string min_input, std::string max_input){

	int index_min = 0;
	int index_max = 0;

	while(index_min < min_input.length() && index_max < min_input.length()){

		if(min_input[index_min] == max_input[index_max]){
			index_min++;
			index_max++;
		}
		else{
			index_max++;
		}
	}

	if(index_min + 1 >= min_input.length() && ((index_max - index_min) == 0 || (index_max - index_min) == 1)) return true;
	else return false;
}

bool replace(std::string input1, std::string input2){

	int index1 = 0;
	int index2 = 0;
	int hit = 0;

	while(index1 < input1.length() && index2 < input1.length()){

		if(input1[index1] == input2[index2]){
			hit++;
		}

        index1++;
        index2++;
	}

	if(input1.size() - hit <= 1) return true;
	else return false;

}


bool is_one_edit_away(std::string input1, std::string input2){

	if(input1.length() == input2.length()) return replace(input1, input2);
	else if(input1.length() + 1 == input2.length()) return insertion(input1, input2);
	else if(input2.length() + 1 == input1.length()) return insertion(input2, input1);
	else return false;
}


int main()
{

	std::cout << is_one_edit_away("abed", "abcd");
    return 0;
}
