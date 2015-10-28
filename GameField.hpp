#ifndef GAME_FIELD
#define GAME_FIELD

class GameField{
private:
	static constexpr int gamefieldWidth = 48 + 4;
	static constexpr int gamefieldHeight = 48;

	int gamefield[gamefieldHeight][gamefieldWidth];

public:
	GameField(){
		
	}
};
#endif 