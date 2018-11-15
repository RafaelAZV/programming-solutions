#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void get_balanced_bracket(std::stack<char> &brackets_stack, char bracket){

    switch(bracket){
        case '(':
            brackets_stack.push(')');
            break;
        case ')':
            brackets_stack.push('(');
            break;
        case '{':
            brackets_stack.push('}');
            break;
        case '}':
            brackets_stack.push('{');
            break;
        case '[':
            brackets_stack.push(']');
            break;
        case ']':
            brackets_stack.push('[');
            break;
    }
}

void is_balanced(std::string expression){

    int expression_size = expression.length();
    std::stack<char> brackets_stack;

    if(expression_size % 2 != 0) std::cout << "NO" << std::endl;
    else{
        int half = expression_size / 2;
        for(int i = 0; i < expression_size; i++){
            if(i < half) get_balanced_bracket(brackets_stack, expression.at(i));
            else{
                char current_bracket = brackets_stack.top();
                brackets_stack.pop();

                if(current_bracket != expression.at(i)){
                    std::cout << "NO" << std::endl;
                    return;
                }
            }
        }
        std::cout << "YES" << std::endl;
    }
}

int main(){

    std::string expression = "{{[[(())]]}}";
    is_balanced(expression);
}
