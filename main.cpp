#include <iostream>
#include <raylib.h>

struct Game {
	const int WIDTH = 800;
	const int HEIGHT = 800;
	const char* TITLE = "Testing game";
};

Game game;


int main(){
	InitWindow(game.WIDTH , game.HEIGHT , game.TITLE);

	while (!WindowShouldClose()){
	BeginDrawing();
	// From here, it beginnnnnnnnnnnnnnnnnns
	ClearBackground(BLACK);

	EndDrawing();

	}
	CloseWindow();
	return 0;
}
