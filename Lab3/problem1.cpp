#include <bits/stdc++.h>
using namespace std;

set<string> keywords = {"def", "then", "if", "else", "then", "while", "do"};
set<string> operators = {"+", "-", "*", "/", "<", "<=", ">", ">=","=","==","!"};

bool check_operator(string str);
bool check_keyword(string str);
int check_number(string str, bool flag = false);
bool check_identifier(string str, bool first = true);
void handle_word(string &str) ;
void get_tok(string filename) {
  ifstream in(filename);
  ofstream f("output.txt");
  while (!in.eof()) {
    string text;
    getline(in, text);
    cout << endl << endl;
    cout << text << endl;
    if (text[0] == '#') {
      // its comment
      cout << "whole line is comment" << endl;
      continue;
    } else {
      string word = "";
      for (char i : text) {
        switch (i) {
        case ' ':
          handle_word(word);
          
          break;

        case '(':
          handle_word(word);
          cout << "lparenthesis: (" << endl;

          break;
        case ')':
          handle_word(word);
          cout << "rparen: )" << endl;
        
          break;
        default:
        
          word += i;
        }
      }
      handle_word(word);
  }
}
}
int main() {
  get_tok("language.txt");
  return 0;
}

bool check_keyword(string str) {
  if (keywords.find(str) != keywords.end())
    return true;
  return false;
}
bool check_operator(string str) {
  if (operators.find(str) != operators.end())
    return true;
  return false;
}
int check_number(string str, bool flag) {
  // return 0 for not number but something else
  //  return 1 for number
  // return 2 for invalid number
  //  cout << "checking: " << str << endl;
  if (str.size() == 0) {
    return 1;
  }
  if (str[0] == '.') {
    if (flag) {
      return 2;
    }
    return check_number(str.substr(1), true);
  }
  if (str[0] <= '9' && str[0] >= '0') {
    return check_number(str.substr(1), flag);
  } else {
    return 0;
  }
}
bool check_identifier(string str, bool first) {
    // cout << str << endl;
  if (first && str == "") {
    return false;
  }
  if (!first && str=="") {
    return true;
  }
  // check if str is a proper identifier
  if (first && str[0] >= '0' && str[0] <= '9') {
    // first one is number
    return false;
  } else {
    if ((str[0] <= 'z' && str[0] >= 'a') || (str[0] <= 'Z' && str[0] >= 'A') ||
        (str[0] == '_')) {
      return check_identifier(str.substr(1), false);
    }
    if (!first && str[0] >= '0' && str[0] <= '9') {
      return check_identifier(str.substr(1), false);
    }
    return false;
  }
}
void handle_word(string &str) {
    if (str.size()==0) {
        return;
    }
    // cout << "checking: " << str << endl;
    //this will print the lexeme and its token type
    //also it will make str = ""
    if (check_operator(str)) {
        cout << "Operator: " << str << endl;
        str = "";
        return ;
    }
    if (check_keyword(str)) {
        cout << "Keyword: " << str << endl;
        str = "";
        return;
    }
    if (check_identifier(str)) {
        cout << "Identifier: " << str << endl;
        str = "";
        return;
    }
    int num = check_number(str);
    if (num==2) {
        cout << "Invalid number: " << str << endl;
        exit(404);
        str = "";
        return;
    }
    if (num==1) {
        cout << "Number: " << str << endl;
        str = "";
        return ;
    }
    if (check_operator(str)) {
        cout << "Operator: " << str << endl;
        str = "";
        return ;
    }
    cout << "I give up: " << str << endl;
    exit(500);
    str = "";
    return ;

}