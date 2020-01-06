#include "bored.h"

using namespace std;

bored::bored(){
    node *temp = new node;
    start = temp;
    current_play = temp;
    A.set(Player,X);
    B.set(Player,O);
}
void bored::generate1(){
    node *current = start;
    symbols select;
    for(int i=0;i<9;i++){
        (*current).childs[i] = new node;
        //set the parent node of the child to the current node
        (*(*current).childs[i]).parent = current;
        (*(*current).childs[i]).turn = !(*current).turn;
        if((*current).turn){
            select = A.get_symbol();
        }else{
            select = B.get_symbol();
        }
        (*(*current).childs[i]).board[i] = select;
        //seg fault here
        (*current).win_board[i] = generate2((*current).childs[i]);
    }
}
symbols bored::generate2(node *current){
    //dont forget to copy the parent board to the child
    (*current).win = board_win(current);
    if((*current).win != _){
        return (*current).win;
    }
    for(int i=0;i<9;i++){
        if((*current).board[i] == _){
            symbols select;
            if((*current).turn){
                select = A.get_symbol();
            }else{
                select = B.get_symbol();
            }
            (*current).childs[i] = new node;
            for(int n=0;n<9;n++){
                (*(*current).childs[i]).board[n] = (*current).board[n];
            }
            (*(*current).childs[i]).board[i] = select;
            (*(*current).childs[i]).parent = current;
            (*(*current).childs[i]).turn = !(*current).turn;
            (*current).win_board[i] = generate2((*current).childs[i]);
        }
    }
    // all spaces have been checked
    symbols held;
    if((*current).turn){
        held = O;
    }else{
        held = X;
    }
    for(int i=0;i<9;i++){
        if((*current).turn){
            if((*current).win_board[i] > held && (*current).win_board[i] != _){
                held = (*current).win_board[i];
            }
        }else{
            if((*current).win_board[i] < held && (*current).win_board[i] != _){
                held = (*current).win_board[i];
            }
        }
    }
    return held;
}
//rewriten for nodes
symbols bored::board_win(node *current){
    bool check = true;
    for(int i=0;i<9;i++){
        if((*current).board[i] == _){
            check = false;
        }
    }
    for(int i=0;i<3;i++){
        if((*current).board[i] == (*current).board[i+3] && (*current).board[i+6] == (*current).board[i]){
            if((*current).board[i] == X){
                return X;
            }else if((*current).board[i] == O){
                return O;
            }
        }
        if((*current).board[i*3] == (*current).board[(i*3)+1] && (*current).board[(i*3)+2] == (*current).board[i*3]){
            if((*current).board[i*3] == X){
                return X;
            }else if((*current).board[i*3] == O){
                return O;
            }
        }
    }
    if((*current).board[0] == (*current).board[4] && (*current).board[8] == (*current).board[0]){
        if((*current).board[0] == X){
            return X;
        }else if((*current).board[0] == O){
            return O;
        }
    }
    if((*current).board[2] == (*current).board[4] && (*current).board[6] == (*current).board[2]){
        if((*current).board[2] == X){
            return X;
        }else if((*current).board[2] == O){
            return O;
        }
    }
    if(check){
        return T;
    }
    return _;
}
void bored::output(){
    for(int i=2;i>=0;i--){
        for(int n=0;n<3;n++){
            switch((*current_play).board[(i*3)+n]){
                case X:
                    cout << "X ";
                    return;
                case O:
                    cout << "O ";
                    return;
                case _:
                    cout << "_ ";
                    return;
                default:
                    cout << "? ";
                    return;
            }
        }
    }
}
void bored::player_call(node* current){
    if((*current).turn){
        cout << "X turn" << endl;
    }else{
        cout << "O turn" << endl;
    }
    return;
}