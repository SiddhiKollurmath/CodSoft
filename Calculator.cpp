#include <iostream>
  using namespace std;

class calculator
{
    char operation;
    double num1, num2, result;
    int exit1=1;

 public:

    void accept();
    void calculation();
};

void calculator :: accept()
{
    cout << "ENTER NUMBERS:" << endl;
    cout << "ENTER 1st NUMBER:";
    cin >> num1 ;
    cout << "ENTER 2nd NUMBER:"; 
    cin >> num2 ; 
}

void calculator :: calculation()

{
    do
    {    
        cout << "ENTER A OPERATION OF THE FOLLOWING : (+, -, *, /): ";
        cin >> operation;
        
        switch (operation) 
        {
            case '+':
                accept();
                result = num1 + num2;
                cout << num1 << " + " << num2 << " = " << result << endl;
                break;

            case '-':  
                accept();
                result = num1 - num2;
                cout << num1 << " - " << num2 << " = " << result << endl;
                break;

            case '*':
                accept();
                result = num1 * num2;
                cout << num1 << " * " << num2 << " = " << result << endl;
                break;

            case '/':
                accept();
                if (num2 != 0) 
                {
                    result = num1 / num2;
                    cout << num1 << " / " << num2 << " = " << result << endl;
                } 
                else 
                {
                    cout << "Error: Division by zero is undefined." << endl;
                }
                break;
            
           default:

                cout << "Exiting..." << endl;
                exit1=0;
                break;
        }
    }
    while(exit1);
}

int main() 
{
    calculator C;
    C.calculation();    

    return 0;
}