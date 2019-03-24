#include <iostream>

using namespace std;

int main() {
  unsigned int s = 0xffffffff;
  int q;
  unsigned int x;
  cin >> q;
  while (q--) {
    cin >> x;
    cout << s - x << endl;
  }
  return 0;
}