# include <iostream>
# include <cstdlib>
# include <conio.h>
# include <ctime>
using namespace std;
bool GameOver;
const int hight = 20;
const int width = 20;
int x, y, fruitX, fruitY,score;
int tailX[100], tailY[100];
int ntail;
enum eDirection {Stop = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;
void setup()
{
	GameOver = false;
	dir = Stop;
	x = width / 2;
	y = hight / 2;
	fruitX = rand() % width;
	fruitY = rand() % hight;
	score = 0;	
}
void Draw()
{
	system("cls"); //for clear screen;
	for(int i = 0; i<width+2; i++)
	    printf("#");
	printf("\n");
	
	for(int i = 0; i<hight; i++)
	{
		
		for(int j = 0; j<width; j++)
		{
			
			if(j == 0){
				printf("#");
			}
			if(i == y and j == x){
				printf("O");
			}
			else if(i == fruitY and j == fruitX){
				printf("F");
			}
			else{
				bool print = false;
				for(int k = 0; k < ntail; k++){
					if(tailX[k] == j && tailY[k] == i){
						printf("o");
						print = true;
					}
				}
				if(!print){
					printf(" ");
					}
			}
			
			if(j == width - 1){
				printf("#");
			}
		}
		printf("\n");
	}
	for(int i = 0; i<width+2; i++){
		cout << "#";
	}
	printf("\n");
	printf("Score = %d",score);
}
void Input()
{
	if(_kbhit()){
		
		switch(_getch()){
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				GameOver = true;
				break;
		}
	}
}
void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X,prev2Y;
	tailX[0] = x;
    tailY[0] = y;
	for(int i = 1; 1000 < ntail; i++){
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y; 
	}
	switch(dir){
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
	}
	if(x > width || x < 0 || y > hight || y < 0){
		GameOver = true;
	}
	if(x == fruitX && y == fruitY){
		score += 10;
		ntail += 1;
		fruitX = rand() % width;
	    fruitY = rand() % hight;
	}
}
int main(){
	setup();
	while(!GameOver)
	{
	Draw();
	Input();
	Logic();	
	}
	return 0;
}
