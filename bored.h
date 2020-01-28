#include <iostream>
#include <stdlib.h>
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

    void set_bot(int,bot_state);
    bot_state getbot();
    bool check();
    void win_output();
    void indicator();

    void AI();

    void ouptut();
    void play(int);

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