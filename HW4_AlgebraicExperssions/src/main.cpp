#include <iostream>
#include <string>
#include "AlgebraicExpression.h"

using namespace std;


int main() {

    // INFIX
    cout << infix2prefix("21 - 5 / ( 6 - 7 ) + 3 * 2 * 1" ) << endl;
    cout << infix2postfix("21 - 5 / ( 6 - 7 ) + 3 * 2 * 1" ) << endl;
    cout << evaluateInfix( "21 - 5 / ( 6 - 7 ) + 3 * 2 * 1" ) << endl;
    cout << endl;

    // PREFIX
    cout << prefix2postfix( "- / + 13 7 * 2 5 12" ) << endl;
    cout << prefix2infix( "- / + 13 7 * 2 5 12" ) << endl;
    cout << evaluatePrefix( "- / + 13 7 * 2 5 12" ) << endl;
    cout << endl;

    // POSTFIX
    cout << postfix2prefix( "7 3 + 9 3 / 5 4 - - *" ) << endl;
    cout << postfix2infix( "7 3 + 9 3 / 5 4 - - *" ) << endl;
    cout << evaluatePostfix( "7 3 + 9 3 / 5 4 - - *" ) << endl;


    return 0;
}
