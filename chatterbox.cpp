#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string command, word;
stack <string> deleted_words;
vector <string> result;

void delete_function(){
    if(command=="DELETE"){
        if(!result.empty()){
            deleted_words.push(result.back());
            result.pop_back();
        }
    }
}

void restore_function(){
    if(command=="RESTORE"){
        if(!deleted_words.empty()){
            result.push_back(deleted_words.top());
            deleted_words.pop();
        } 

    }
}

void type_function(int command_number){
    for(int i=0; i<command_number; i++){
        cin>>command;
        if(command=="POST") cin>>word, result.push_back(word);
        else{
            restore_function();
            delete_function();
        }
    }
}

void print_function(){
    for(string s: result) cout<<s;
}

int main(){
    int command_number;
    cin>>command_number;
    type_function(command_number);
    print_function();

}