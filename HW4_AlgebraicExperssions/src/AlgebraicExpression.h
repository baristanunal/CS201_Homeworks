//
// Barış Tan Ünal
// 220003617
// 29.12.2021
//

#include "Stack.h"
#include <string>
#include <cstdio>
using namespace std;

#ifndef HOMEWORK4_ALGEBRAICEXPRESSION_H
#define HOMEWORK4_ALGEBRAICEXPRESSION_H


// It converts an infix expression exp to its equivalent prefix form.
string infix2prefix(const string exp);

// It converts an infix expression exp to its equivalent postfix form.
string infix2postfix(const string exp);

// It converts a prefix expression exp to its equivalent infix form.
string prefix2infix(const string exp);

// It converts a prefix expression exp to its equivalent postfix form.
string prefix2postfix(const string exp);

// It converts a postfix expression exp to its equivalent infix form.
string postfix2infix(const string exp);

// It converts a postfix expression exp to its equivalent prefix form.
string postfix2prefix(const string exp);

//It evaluates an infix expression.
double evaluateInfix(const string exp);

//It evaluates a prefix expression.
double evaluatePrefix(const string exp);

//It evaluates a postfix expression.
double evaluatePostfix(const string exp);

bool isOperator( string str ) ;

bool isOperand( string str ) ;

bool isRightParenthesis( string str ) ;

bool isLeftParenthesis( string str ) ;

double calculateExp( double x, double y, string op ) ;

int precedenceRank( string op ) ;


class AlgebraicExpression {

};

#endif //HOMEWORK4_ALGEBRAICEXPRESSION_H
