#include "node.h"

using namespace std;

node::node(){
    parent = NULL;
    win = _;
    for (int i=0;i<9;i++){
        childs[i] = NULL;
        board[i] = _;
        win_board[i] = _;
    }
    turn = true;
}
