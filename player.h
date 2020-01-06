#include <iostream>
#include "./enum.h"
class player{
public:
	// init function
    player();
    // set player variables
    void set(bot_state, symbols);
    // set player to bot
	void set_bot(bot_state);
    // return bot status
    bot_state get_bot();
    // returns players' symbol
	symbols get_symbol();
private:
    bot_state bot;
    symbols selected;
};
