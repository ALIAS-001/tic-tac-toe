#include <iostream>
#include "./node.h"
#include "./enum.h"
#include "./player.h"
class bored{
public:
    bored(); 
    void output();
    void generate1();
    symbols generate2(node*);
    symbols board_win(node*);

    void ouptut();

    void navagate();
    void player_call(node*);
    void nav_output(node*);
private:
    node *start;
    node *current_play;
    player A;
    player B;
    //true = player A | false = player B
};