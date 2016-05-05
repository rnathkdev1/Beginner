#include <iostream>
#include <vector>
using namespace std;

bool compartor(double val, std::vector<double>::iterator thisIter)
{
  return true;
}
int main(){
  std::vector<double> testVec;
  testVec.push_back(0.1f);
  testVec.push_back(0.2f);
  testVec.push_back(0.3f);
  testVec.push_back(4.f);
  testVec.push_back(5.f);
  testVec.push_back(6.f);

  std::vector<double>::iterator low;
  low = std::upper_bound (testVec.begin(), testVec.end(), 0.21f);

  cout<<low - testVec.begin()<<endl;

}
