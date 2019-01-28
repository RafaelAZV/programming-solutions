#include <iostream>
#include <vector>
#include <string>
using namespace std;

void realocate(std::string &input, int high, int low){

	while(high != low){
		input[high + 2] = input[high];
		high--;
	}

	input[low] = '%';
	input[low+1] = '2';
	input[low+2] = '0';
}

void urlify(std::string &input){

	int current_size = input.size();
	int high = 0;
	int low = 0;

	for(int i = 0; i < current_size; i++){

		if(input[i] == ' '){
			high = current_size - 1;
			low = i;
			input.resize(current_size + 2, ' ');
			realocate(input, high, low);
			current_size = input.size();
		}

	}
}


int main(){

    std::string test = "Mr John Smith";
    urlify(test);
    return 0;
}
