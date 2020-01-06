#include <iostream>
#include "./enum.h"
class node{
public:
    node();
    node *parent;
    node *childs[9];
    symbols board[9];
    symbols win_board[9];
    symbols win;
    bool turn;
};
