#include <stdio.h>
#include <conio.h>
#define GRIDSIZE 20

char grid[GRIDSIZE][GRIDSIZE];
int snakesize = 1;


struct poss{
    int y;
    int x;
};

struct apple{
     int x;
     int y;
     char size;
    char vanish;
};

struct poss snakepos = {0,4};

void drawsnake(int size,struct poss poz){
     for(int i=0; i<size; i++){
            grid[poz.y][poz.x-i-2] = '0';
    }
    grid[poz.y][poz.x] = '>';
    grid[poz.y][poz.x-1] = '-';
   
}
void start(void){
    for(int i =0, j =0; i<GRIDSIZE && j < GRIDSIZE; j++){
            grid[i][j] = ' ';
            if(i == GRIDSIZE-1 && j == GRIDSIZE -1 )
                grid[i][j] = ' ';
            if(j == GRIDSIZE -1){
                grid[i][j-1] = '|';
                grid[i][j] = '\n';
                i++;
                j=0;
            }
    
    }
  

    return;
}
void drawgrid(){
    for(int i =0, j =0; i<GRIDSIZE  && j < GRIDSIZE; j++){
            start();
           drawsnake(snakesize,snakepos);
           printf("%c",grid[i][j]);
            if(j == GRIDSIZE-1)  {
                j = 0;
                i++;
            }
    }
}

int main(){
    int c;

    //reset the grid
    

    while((c = _getch())!= 27){
        
        if(c == 224 || c == 0){
            switch(c =_getch()){
            case 72:
                printf("^\n");

                break;
            case 80:
                printf("V\n");
                break;
            case 77:
                snakepos.x += 1; 
                break;
            case 75:
                snakepos.x -= 1;
                break;
            default:
            break;
            }
        }
        else if(c == 118){
            start();
        }
        else{
            _putch(c);
        }
        drawgrid();    
    }
}