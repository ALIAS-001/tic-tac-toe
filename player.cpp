#include "player.h"
//player functions

// basic init
player::player(){
    bot = Player;
    selected = _;
}
// actual init function for player var
void player::set(bot_state sbot, symbols sselect){
    bot = sbot;
    selected = sselect;
}
// overwrites the bot var of the player
void player::set_bot(bot_state pl){
	bot = pl;
}
bot_state player::get_bot(){
    return bot;
}
// returns the symbol the player is set
symbols player::get_symbol(){
	return selected;
}
//end of player functions
