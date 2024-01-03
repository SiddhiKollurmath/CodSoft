#include <iostream>
#include <time.h>

using namespace std;

class numguess
{
 public:  
  int randomnum = (rand() % 100) + 1;
  int userinput=0;
  void functionnum();
};

void numguess :: functionnum()
{
 do
{
  cout << "Guess a number between 1 and 100: ";
  cin >>userinput;

  if (userinput == randomnum) 
  {
    cout << "You guessed correctly!" << endl;
  } 
 else if (userinput < randomnum) 
 {
    cout << "Your guess was too low." << endl;
    cout<<"Guess Again!!"<<endl;
  }
 else 
 {
    cout << "Your guess was too high." << endl;
    cout<<"Guess Again!!"<<endl;
  }
}
while(userinput!=randomnum);
cout<<endl;

}

int main() 
{
  srand((unsigned int) time(NULL)); 
  numguess n;
  n.functionnum();
  return 0;
}
