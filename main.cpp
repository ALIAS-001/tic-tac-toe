#include <iostream>
#include <time.h>
#include "./bored.h"
#include "./enum.h"
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
char single_char_input(){
    char res;
    res = cin.get();
    cin.ignore(1024,'\n');
    return res;
}
int main()
{
    long long int seed = time(NULL);
    bored game;
    cout << "Generating node tree" << endl;
    game.generate1();
    cout << "Done" << endl;
    banner();
    cout << "Are you playing with another player[y/n]: ";
    char res;
    bool start = true;
    bot_state player;
    srand(seed);
    int cell;
    //game.navagate();
	while(res != 'y' && res != 'n'){
		res = single_char_input();
        //input handler
		if(res != 'y' && res != 'n'){
		cout << "[y/n] (case sensitive) ";
		}
	}
	if(res == 'n'){
        game.set_bot(2,best);
		cout << "1 player game selected" << endl;
		cout << "do you want bots to battle each other[y/n]: ";
		res = 'u';
		while(res != 'y' && res != 'n'){
            res = single_char_input();
            //input handler
            if(res != 'y' && res != 'n'){
                cout << "[y/n] (case sensitive) ";
            }
		}

		if(res == 'y'){
            game.set_bot(1,best);
            cout << "the bots will battle each other" << endl;
            // set dificulty for both bots
		}else if(res == 'n'){
			cout << "would you like to play c-h or h-c?"<<endl;
			cout << "                       (1)    (2)"<<endl;
			int numres=3;
			while(numres != 0){
				cin >> numres;
				if(numres == 1){
					game.set_bot(1, best);
					game.set_bot(2, Player);
				}else if(numres == 2){

				}else{
					numres = 0;
					cout << "please input 1 or 2" << endl;
				}
                
			}
		}
        // set difficulty for opponent
	}else if(res == 'y'){
		cout << "2 player game selected" << endl;
	}else{
	    //this block should not run AT ALL!!!
		cout << "Something has gone wrong and the code is compromised" << endl;
        start = false;
	}
	//start the game
    cout << "Start!" << endl;
    game.output();
    cout << endl;
    while(start){
        //automaticaly sorts bots
		player = game.getbot();
        if(player == Player){
            // player actions
            game.indicator();
	        cin >> cell;
            //input handler
            if(!cin.fail()){
                game.play(cell);
                game.output();
                start = game.check();
            }else{
                cout << "Invalid input" << endl;
            }
            cin.clear();
            cin.ignore(1024,'\n');
        }else{
            // bot actions
            // invoke bot AI
			if(player == best){
				game.AI();	
			}else{
				cout << "Either player state or unknown state" << endl;
				start = true;
			}
            game.output();
            start = game.check();
        }
        cout << endl;
	}
    // the game is done and a winner/tie has been announced
	cout << "The game is done"<< endl;

	cout << "This game's seed is: " << seed << endl;
	return 0;
}
