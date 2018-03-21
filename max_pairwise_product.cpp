#include<cstdlib>
#include <iostream>
#include <vector>


using namespace std;


long long MaxPairwiseProductFast(const vector<int>& numbers) {
  long long result = 0;
  int n = numbers.size();
  long long lrg = 0;
  int pos = 0;
  for (int i = 0; i < n; ++i) {
      if(numbers[i] > lrg){
          lrg = numbers[i];
          pos = i;
      }
  }
  long long sl = 0;
  for(int i = 0; i < n; ++i){
    if(numbers[i] != lrg && numbers[i] > sl){
          sl = numbers[i];
    }
  }
  cout << lrg << " " << sl << '\n';
  return lrg * sl;
}

long long MaxPairwiseProductNaive(const vector<int>& numbers) {
  int product = 0;
  int n = numbers.size();
  for (int i = 0; i < n; ++i) {
   for (int j = i + 1; j < n; ++j) {
    product = max(product, numbers[i] * numbers[j]);
   }
}
  return product;
}

void StressTest(long long N, long long M){
  for(;;) {
     long long n = rand() % N + 2;
     vector<int> numbers(n);
     for (int i = 0; i < n; ++i){
       numbers[i] = rand() % M;
       cout << numbers[i] << " ";
     }
     cout << '\n';
     long long result1 = MaxPairwiseProductNaive(numbers);
     long long result2 = MaxPairwiseProductFast(numbers);
     if(result1 == result2){
       cout << "OK" << '\n';
     } else {
       cout << "Wrong answer: " << result1 << " " << result2 << '\n';
       break;
     }
  } 
}

int main() {
    StressTest(5, 9);
    return 0;
}
