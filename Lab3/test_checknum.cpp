/**
 * @file test_checknum.cpp
 * @author Arpit01Goel
 * @date 2025/01/26 07:06:17
 */

#include <bits/stdc++.h>
using namespace std;

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

int main() {
    cout <<
    check_number("1.2.3", false) << endl;
    return 0;
}

// GitHub: https://github.com/Arpit01Goel