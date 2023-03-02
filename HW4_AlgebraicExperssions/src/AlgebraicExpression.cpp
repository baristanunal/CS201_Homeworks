//
// Barış Tan Ünal
// 220003617
// 29.12.2021
//

#include "AlgebraicExpression.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;


string infix2prefix(const string exp) {

    string postfix, prefix;

    postfix = infix2postfix( exp );
    prefix = postfix2prefix( postfix );

    return prefix;
}


string infix2postfix(const string exp) {

    Stack stack;
    string delim = " ";
    int posOfSpace = -1;
    string token;
    string copyStr = exp;

    string outStr;

    while( posOfSpace != 0 ) {

        // 1.1: Read the next token.
        token = copyStr.substr(0, copyStr.find(delim));
        posOfSpace = copyStr.find(delim) + 1;
        copyStr = copyStr.substr(posOfSpace);

        if( isOperand( token ) ) {
            if( outStr == "" ) {
                outStr = outStr + token;
            }
            else {
                outStr = outStr + " " + token;
            }
        }
        else if( isLeftParenthesis( token ) ) {
            stack.push( token );
        }
        else if( isRightParenthesis( token ) ) {

            string topItem;
            stack.getTop( topItem );

            while( !isLeftParenthesis( topItem ) ) {

                if( outStr == "" ) {
                    outStr = outStr + topItem;
                }
                else {
                    outStr = outStr + " " + topItem;
                }
                stack.pop();
                stack.getTop( topItem );
            }
            stack.pop();
        }
        else if( isOperator( token ) ) {

            string topItem;
            stack.getTop( topItem );

            while( !stack.isEmpty() && ( precedenceRank( token ) <= precedenceRank( topItem ) ) ) {

                if( outStr == "" ) {
                    outStr = outStr + topItem;
                }
                else {
                    outStr = outStr + " " + topItem;
                }
                stack.pop();
                stack.getTop( topItem );
            }
            stack.push( token );
        }
        else {
            cout << "ERROR: Invalid character in the given expression!" << endl;
            return NULL;
        }
    }

    while( !stack.isEmpty() ) {

        string topItem;
        stack.pop( topItem );
        outStr = outStr + " " + topItem;
    }

    return outStr;
}


string prefix2infix(const string exp) {

    string postfix, infix;

    postfix = prefix2postfix( exp );
    infix = postfix2infix( postfix );

    return infix;
}


string prefix2postfix(const string exp) {

    // 1: Reverse the expression.
    string reversedExp = exp;
    reverse( reversedExp.begin(), reversedExp.end() );

    Stack stack;

    string delim = " ";
    int posOfSpace = -1;
    string token;
    string copyStr = reversedExp;

    // 1: While there are tokens to be read.
    while( posOfSpace != 0 ) {

        // 1.1: Read the next token.
        token = copyStr.substr(0, copyStr.find(delim));
        posOfSpace = copyStr.find(delim) + 1;
        copyStr = copyStr.substr(posOfSpace);

        reverse( token.begin(), token.end() );

        if( isOperand( token ) ) {
            stack.push( token );
        }
        else if( isOperator( token ) ) {

            string a, b, postfix;
            stack.pop( a );
            stack.pop( b );

            postfix = a + " " + b + " " + token;

            stack.push( postfix );
        }
        else {
            cout << "ERROR: Invalid character in the given expression!" << endl;
            return NULL;
        }
    }

    string finalResultStr;
    stack.pop( finalResultStr );

    return finalResultStr;
}


string postfix2infix(const string exp) {

    Stack stack;

    string delim = " ";
    int posOfSpace = -1;
    string token;
    string copyStr = exp;

    // 1: While there are tokens to be read.
    while( posOfSpace != 0 ) {

        // 1.1: Read the next token.
        token = copyStr.substr(0, copyStr.find(delim));
        posOfSpace = copyStr.find(delim) + 1;
        copyStr = copyStr.substr(posOfSpace);

        if( isOperand( token ) ) {
            stack.push( token );
        }
        else if( isOperator( token ) ) {

            string a, b;

            stack.pop( b );
            stack.pop( a );

            if( token == "+" || token == "-" ) {
                stack.push( "( " + a + " " + token + " " + b + " )" );
            }
            else{
                stack.push( a + " " + token + " " + b );
            }
        }
    }

    string result;
    stack.pop( result );

    return result;
}


string postfix2prefix(const string exp) {

    Stack stack;

    string delim = " ";
    int posOfSpace = -1;
    string token;
    string copyStr = exp;

    // 1: While there are tokens to be read.
    while( posOfSpace != 0 ) {

        // 1.1: Read the next token.
        token = copyStr.substr(0, copyStr.find(delim));
        posOfSpace = copyStr.find(delim) + 1;
        //cout << token << endl;
        copyStr = copyStr.substr(posOfSpace);

        if( isOperand( token ) ) {
            stack.push( token );
        }
        else if( isOperator( token ) ) {

            string a, b, postfix;
            stack.pop( a );
            stack.pop( b );

            postfix = token + " " + b + " " + a;

            stack.push( postfix );
        }
        else {
            cout << "ERROR: Invalid character in the given expression!" << endl;
            return NULL;
        }
    }

    string finalResultStr;
    stack.pop( finalResultStr );

    return finalResultStr;

}


double evaluateInfix(const string exp) {

    string postfix;
    postfix = infix2postfix( exp );

    double result;
    result = evaluatePostfix( postfix );

    return result;
}


double evaluatePrefix(const string exp) {

    string postfix;
    postfix = prefix2postfix( exp );

    double result;
    result = evaluatePostfix( postfix );

    return result;
}


double evaluatePostfix(const string exp) {

    Stack operandStack;

    string delim = " ";
    int posOfSpace = -1;
    string token;
    string copyStr = exp;

    while( posOfSpace != 0 ) {

        // 1: Read the next token.
        token = copyStr.substr(0, copyStr.find(delim));
        posOfSpace = copyStr.find(delim) + 1;
        copyStr = copyStr.substr(posOfSpace);

        // 2.1: If the token is an operand.
        if( isOperand( token ) ) {
            operandStack.push( token );
        }
        // 2.2: IF the token is an operator.
        else if( isOperator( token ) ) {

            string aStr, bStr, resultStr;
            ostringstream tmp;
            double a, b, result;

            // 2.2.1: Pop two operands.
            operandStack.pop( bStr );
            operandStack.pop( aStr );

            b = strtod( bStr.c_str(), NULL );
            a = strtod( aStr.c_str(), NULL );

            // 2.2.2: Calculate expression.
            result = calculateExp( a, b, token );
            tmp << result;
            resultStr = tmp.str();

            // 2.2.3: Push the result back to the stack.
            operandStack.push( resultStr );

        }
        else {
            cout << "ERROR: Invalid character in the given expression!" << endl;
            return NULL;
        }
    }

    string finalResultStr;
    double finalResult;

    operandStack.pop( finalResultStr );
    finalResult = strtod( finalResultStr.c_str(), NULL );

    return finalResult;
}


bool isOperator( string str )  {

    char op = str[0];

    if( op == '+' ) {
        return true;
    }
    else if ( op == '-' ) {
        return true;
    }
    else if ( op == '*' ) {
        return true;
    }
    else if ( op == '/' ) {
        return true;
    }
    else {
        return false;
    }
}


bool isOperand(string str)  {

    char op = str[0];

    if( op >= 48 && op <= 57 ) {
        return true;
    }
    else {
        return false;
    }
}


bool isRightParenthesis(string str)  {

    char op = str[0];

    if( op == 41 ) {
        return true;
    }
    else {
        return false;
    }
}


bool isLeftParenthesis(string str)  {

    char op = str[0];

    if( op == 40 ) {
        return true;
    }
    else {
        return false;
    }
}


double calculateExp(double x, double y, string str)  {

    char op = str[0];

    if( op == '+' ) {
        return x + y;
    }
    else if( op == '-' ) {
        return x - y;
    }
    else if( op == '*' ) {
        return x * y;
    }
    else if( op == '/' ) {
        return x / y;
    }
    else {
        return NULL;
    }
}

int precedenceRank(string str)  {

    char op = str[0];

    if( op == '+' ) {
        return 1;
    }
    else if( op == '-' ) {
        return 1;
    }
    else if( op == '*' ) {
        return 2;
    }
    else if( op == '/' ) {
        return 2;
    }
    else {
        return NULL;
    }

}




