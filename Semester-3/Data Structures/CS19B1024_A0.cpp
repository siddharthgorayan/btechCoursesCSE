#include<iostream>

using namespace std;

bool stringComparison(std::string string1, std::string string2)
{
    if(string1<string2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(){
  string numberPlate[2];
  bool act=0;
  while (cin >> numberPlate[act])
  {
    act=1-act;
    if(act==0)
    {
      // Call your string compare function here on numberPlate[0] and numberPlate[1].
        cout << stringComparison(numberPlate[0], numberPlate[1]) << "\n";
    }
  }
  return(0);
}
