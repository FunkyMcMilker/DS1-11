
#include <iostream>
#include <string>
#include <iomanip>
#include "DSLL.h"

using namespace std;


bool checkParenth( string expression )
{
    DSStack<int> myStack;
    char current;
    //iterate over the given expression
    for ( int itr = 0 ; itr != expression.length() - 1 ; itr++)
    {
        if ( expression[itr] == '(' )
        {
            myStack.push(1);
        }
        if ( expression[itr] == ')' )
        {
            try {
                myStack.pop();
            }
            catch( ... )
            {
                return false;
            }
            
        }
    }
    
    if( myStack.is_empty() ) 
    {
        return true;
    }
    else
    {
        return false;
    }
}

void bitCoin( string expression ="The value of Bitcoin was 8389.51, now it is 57625.40.")
{
    auto itr = expression.find( "Bitcoin was ");
    string value1Found = "";
    string value2Found = "";
    float value1 = 0;
    float value2 = 0;
    float investmentThen = 100;
    float investmentNow;
    itr = itr + itr - 1;
    while( expression[itr] >= 48 && expression[itr] <= 57 || expression[itr] == 46)
    {
        value1Found = value1Found + expression[itr];
        itr++;
    }
    value1 = stof(value1Found);
    // cout<< value1 << endl;
    
    itr = expression.find("now it is ");
    itr = itr + 10;
    while( expression[itr] >= 48 && expression[itr] <= 57 || expression[itr] == 46)
    {
        value2Found = value2Found + expression[itr];
        itr++;
    }
    value2 = stof(value2Found);
    // cout<< value2 << endl;
    
    investmentNow = ( value2 / value1 ) * investmentThen;
    cout << "If you invested $" <<investmentThen<< ", it would be worth $" << fixed << setprecision(2) << investmentNow << " now." <<endl;
}



int main()
{

    string wrongExpression = "(  2 * 3 ) ) ";
    string wrongExpression2 = "1 ) + ( 2*3";
    string expression = "1 + ( 2*3 )";
    if( checkParenth( expression ) )
    {
        cout <<"Parentheses in expression: "<< expression <<" are properly balanced" << endl;
    }
    else 
    {
        cout <<"Parentheses in expression: "<< expression <<" are NOT properly balanced" << endl;

    }
    
    if( checkParenth( wrongExpression ) )
    {
        cout <<"Parentheses in expression: "<< wrongExpression <<" are properly balanced" << endl;
    }
    else
    {
        cout <<"Parentheses in expression: "<< wrongExpression <<" are NOT properly balanced" << endl;

    }

    if( checkParenth( wrongExpression2 ) )
    {
        cout <<"Parentheses in expression: "<< wrongExpression2 <<" are properly balanced" << endl;
    }
    else
    {
        cout <<"Parentheses in expression: "<< wrongExpression2 <<" are NOT properly balanced" << endl;

    }
    bitCoin();
    return 0;
}




