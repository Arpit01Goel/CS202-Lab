#include <bits/stdc++.h>
#include <string>
using namespace std;

#define RED "\033[31m"
#define BLUEBOLD "\033[1;34m"
#define RESET "\033[0m"
#define PINK "\033[35m"
#define GREEN "\033[32m"
#define ORANGE "\033[38;5;214m"
#define BLUE "\033[94m"
#define CYAN "\033[36m"

set<string> keywords = {"def", "then", "if", "else", "then", "while", "do"};
set<string> operators = {"+", "-",  "*", "/",  "<", "<=",  ">",  ">=",
                         "=", "==", "!", "||", "^", ">>>", "<<<"};
set<string> functions = {"print"};
set<string> esc_seq = {"\n", "\t", "\r", "\b", "\f", "\"", "\'", "\\"};
bool check_operator(string str);
bool check_keyword(string str);
int check_number(string str, bool flag = false);
bool check_identifier(string str, bool first = true);
bool check_escape_seq(string str);
void handle_word(string &str);

void get_tok(string filename) {
  ifstream in(filename);
  ofstream f("output.txt");
  while (!in.eof()) {
    string text;
    string expr;
    getline(in, text);
    cout << endl << endl;
    cout << BLUEBOLD << text << RESET << endl;
    if (text[0] == '#') {
      // its comment
      cout << "whole line is comment" << endl;
      continue;
    } else {
      string word = "";
      for (int i = 0; i < text.size(); i++) {
        switch (text[i]) {
        case ' ':
          expr += word;
          expr += " ";
          handle_word(word);

          break;

        case '(':
          handle_word(word);
          cout << "lparenthesis: (" << endl;
          expr = "";
          break;
        case ')':
          expr += word;
          handle_word(word);
          cout << "rparen: )" << endl;
          cout << CYAN << "Expression: " << expr << RESET<< endl;
          
          break;
        case '"':
          // string start
          expr += word;
          handle_word(word);
          cout << "string inititalizer: \"" << endl;
          expr += "\"";
          // init string
          i++;
          while (i < text.size() - 1 && text[i] != '"') {
            if (text[i] == '\\' && i<text.size() &&  text[i+1]==' ') {
              cout << RED << "invalid escape sequence" << endl;
              cout << text << RESET << endl;
              exit(402);
            }
            if (text[i] == '\\' &&
                (i == text.size() - 1 ||
                 check_escape_seq("\\" + string(1, text[i + 1])))) {
              cout << RED << "invalid escape sequence" << endl;
              cout << text << RESET << endl;
              exit(402);
            }
            word += text[i++];
          }
          if (i == text.size() || text[i-1]=='\\' ) {
            cout << RED << "invalid string , unclosed quotes : " << endl;
            cout << text << RESET << endl;
            exit(401);
          }
          if (text[i] == '"') {
            // valid string
            expr+= word + "\"";
            cout <<GREEN<< "string: " << word << RESET<< endl;
            cout << "string closing: \"" << endl;
            word = "";
          } else {
            cout << RED << "I give up : " << RESET << word << endl;
            exit(500);
          }
          // cout << "here" << endl;
          break;
        default:
          // cout << text[i] << endl;
          if (check_operator(string(1, text[i]))) {
            expr += word ;
            handle_word(word);
            word += text[i];
            while (i + 1 < text.size() &&
                   (check_operator(word + text[i + 1]))) {
              word += text[++i];
            }
            expr += word;
            handle_word(word);
          } else {
            word += text[i];
          }
        }
      }
      handle_word(word);
    }
  }
}
int main() {
  get_tok("language.txt");
  // if (check_escape_seq("))
  return 0;
}

bool check_keyword(string str) {
  if (keywords.find(str) != keywords.end())
    return true;
  return false;
}
bool check_operator(string str) {
  // cout << "checking: " << str << endl;
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
    return 0;
  }
  if (str[0]=='.') return 2; 
  int decimals = 0;
  for (int i = 0; i < str.size(); i++) {
    decimals += (str[i] == '.' ? 1 : 0);
    if ((str[i] <= '9' && str[i] >= '0') || (str[i] == '.')) {
      continue;
    } else {
      return 0;
    }
  }
  if (decimals > 1)
    return 2;
  return 1;
}
bool check_identifier(string str, bool first) {
  // cout << str << endl;
  if (first && str == "") {
    return false;
  }
  if (!first && str == "") {
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
bool check_function(string str) {
  if (functions.find(str) != functions.end()) {
    return true;
  } else {
    return false;
  }
}
bool check_escape_seq(string str) {
  
  if (esc_seq.find(str) != esc_seq.end())
    return true;
  return false;
}
void handle_word(string &str) {
  if (str.size() == 0) {
    return;
  }
  // cout << "checking: " << str << endl;
  // this will print the lexeme and its token type
  // also it will make str = ""
  if (check_operator(str)) {
    cout << BLUE << "Operator: " << str << RESET << endl;
    str = "";
    return;
  }
  if (check_function(str)) {
    cout << ORANGE << "Function: " << str << RESET << endl;
    str = "";
    return;
  }
  if (check_keyword(str)) {
    cout << ORANGE <<"Keyword: " << str <<RESET << endl;
    str = "";
    return;
  }
  if (check_identifier(str)) {
    cout << PINK << "Identifier: " << str << RESET << endl;
    str = "";
    return;
  }
  int num = check_number(str);
  if (num == 2) {
    cout << RED << "Invalid number: " << str << RESET << endl;
    exit(404);
    str = "";
    return;
  }
  if (num == 1) {
    cout << BLUE << "Number: " << str <<RESET << endl;
    str = "";
    return;
  }
  
  cout << RED << "I give up: " << RESET << str << endl;
  exit(500);
  str = "";
  return;
}