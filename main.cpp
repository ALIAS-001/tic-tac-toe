#include <iostream>
#include "./bored.h"
using namespace std;

void banner(){
    cout 	<< "------------------------" << endl
		 	<< "-      Tic Tac Toe     -" << endl
			<< "------------------------" << endl
			<< endl
			<< "       how to use       " << endl
			<< "     - - -   7 8 9      " << endl
			<< "     - - -   4 5 6      " << endl
			<< "     - - -   1 2 3      " << endl
			<< "recommend using num pad " << endl;
    cout << endl;
}
int main()
{
    bored game;
    game.generate1();
    banner();



    game.navagate();
}
