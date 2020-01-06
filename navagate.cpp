#include "bored.h"

using namespace std;
void bored::nav_output(node *current){
    player_call(current);
    for(int i=2;i>=0;i--){
        for(int n=0;n<3;n++){
            switch((*current).board[(i*3)+n]){
                case X:
                    cout << "X ";
                    continue;
                case O:
                    cout << "O ";
                    continue;
                case _:
                    cout << "_ ";
                    continue;
                default:
                    cout << "? ";
            }
        }
        cout << '\t';
        for(int n=0;n<3;n++){
            switch((*current).win_board[(i*3)+n]){
                case X:
                    cout << " 1 ";
                    continue;
                case T:
                    cout << " 0 ";
                    continue;
                case O:
                    cout << "-1 ";
                    continue;
                case _:
                    cout << " 2 ";
                    continue;
                default:
                    cout << " ? ";
            }
        }
        cout << endl;
    }
}
void bored::navagate(){
    bool done = false;
    cout << "Controls" << endl;
    cout << "1-9: explore those moves" << endl;
    cout << "0: return to parent" << endl;
    cout << endl;
    cout << "win value means is the board done or not" << endl;
    cout << endl;
    int play = 0;
    while(!done){
        nav_output(current_play);
        cout << "win value: "<<(*current_play).win << endl;
        cin >> play;
        while(play < 0 || play > 9){
            cout << "invalid number" << endl;
            cin >> play;
        }
        if(play == 0){
            if((*current_play).parent != NULL){
                current_play = current_play -> parent;
            }else{
                cout << "your on top of the world" << endl;
            }
        }else{
            if((*current_play).childs[play-1] != NULL){
                current_play = (*current_play).childs[play-1];
            }else{
                cout << "end of the line" << endl;
            }
            
        }
    }
}