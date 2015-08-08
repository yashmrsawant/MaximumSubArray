#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
  * @return index of position found in the vector
  *
  */
int binary_search(vector<int> v, int from, int to, int val) {
    if(v[(to - from) / 2] == val)
        return (to - from) / 2;
    else if(v[(to - from) / 2] > val) {
        binary_search(v, from, (to - from) / 2, val);
    }
    else
        binary_search(v, (to - from) / 2, to, val);
}
int main() {
   rand_seed();
   vector<int> v(20);
   v[0] = 1;
   for (int i = 1 ; i < v.size() ; i++) {
        v[i] = v[i - 1] + rand_int(1, 10);
   }
   print(v);
   cout << "Enter number to search for: ";
   int n;
   cin >> n;
   int j = binary_search(v, 0, v.size() - 1, n);
   cout << "Found in position " << j << endl;
   return 0;
}
