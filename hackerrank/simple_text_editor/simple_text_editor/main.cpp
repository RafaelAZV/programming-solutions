#include <iostream>
#include <stack>
#include <bits/stdc++.h>
using namespace std;
typedef std::pair<int, std::string> operation;

void append_text(std::stack<operation> &s, std::string to_append, std::string &text, bool should_stack){
    text = text + to_append;
    if(should_stack) s.push(make_pair(1, to_append));
}

void delete_text(std::stack<operation> &s, std::string &text, int k, bool should_stack){
    std::string deleted_text = text.substr(text.length() - k, k);
    text.erase(text.length() - k, k);
    if(should_stack) s.push(make_pair(2, deleted_text));
}

void print_character(std::string text, int k){
    std::cout << text.at(k) << std::endl;
}

void undo(std::stack<operation> &s, std::string &text){

    int last_operation = s.top().first;
    std::string last_operation_text = s.top().second;
    s.pop();

    if(last_operation == 1)
        delete_text(s, text, last_operation_text.length(), false);
    else
        append_text(s, last_operation_text, text, false);
}


int main(){


    std::stack<std::pair<int, std::string> > s;
    std::string text = "";
    append_text(s, "abc", text, true);
    append_text(s, "d", text, true);
    std::cout << text << std::endl;
    delete_text(s, text, 1, true);
    std::cout << text << std::endl;
    undo(s, text);
    std::cout << text << std::endl;
    undo(s, text);
    std::cout << text << std::endl;
    undo(s, text);
    std::cout << text << std::endl;

    return 0;
}
