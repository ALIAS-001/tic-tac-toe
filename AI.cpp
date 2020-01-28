#include "bored.h"
using namespace std;

void bored::AI(){
   	int possible_plays[9],play_count=0;
    symbols held;
	if((*current_play).turn){
		held = O;
	}else{
		held = X;
	}
    for(int i=0;i<9;i++){
        possible_plays[i] = 0;
        if((*current_play).turn){
            if((*current_play).win_board[i] > held && (*current_play).win_board[i] != _){
                held = (*current_play).win_board[i];
            }
        }else{
            if((*current_play).win_board[i] < held && (*current_play).win_board[i] != _){
                held = (*current_play).win_board[i];
            }
        }
    }
    for(int i=0;i<9;i++){
		if((*current_play).win_board[i] == held){
			possible_plays[play_count] = i;
			play_count++;
		}
	}
	int play_number = rand() % play_count;
	//cout << possible_plays[play]+1 << endl << play << endl;;
	play(possible_plays[play_number]+1);
	return;
}