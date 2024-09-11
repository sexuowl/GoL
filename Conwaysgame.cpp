#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <cctype>
#include <cstring>
#include <time.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
const int square = 35;

void grid(int dots[square][square]){
    for (int i = 0; i < square; ++i){
        for(int j = 0; j < square; ++j){
            if(dots[i][j] == 1){
                cout << "0";
            } else{
                cout << "*";
            }
        }
        cout << endl;
    }
}
int alivecells(int grid[square][square], int i, int j){
    int numAlive = 0;

    for(int x = -1; x <= 1; x++){
        for(int y = -1; y <= 1; y++){
            if (x == 0 && y == 0) continue;

            int neighborX = i + x;
            int neighborY = j + y;

            if(neighborX >= 0 && neighborX < square && neighborY >= 0 && neighborY < square){
                if(grid[neighborX][neighborY] == 1){
                    numAlive++;
                }
            }
        }
    }
    return numAlive;
}

int main() {
srand(time(NULL));
int dots [square][square];
int dots2 [square][square];
char userInput;
int x, y;

for (int i = 0; i < square; ++i){
    for(int j = 0; j < square; ++j){
         //dots[i][j] = rand()%2; // to enable random starting cells
         dots[i][j] = 0; // to enable blank game
         dots2[i][j] = 0;
    }
}
userInput = (cin >>(cout << "press q to start simulation, or type anything else to check/edit grid" << endl, userInput),userInput);
while(userInput != 'q'){
system("cls");
grid(dots);
cout << "declare x and y vaule for dots matrix"<< endl;
cin >> x >> y;
if(dots[x-1][y-1]== 1){ // if its alive change it to dead
    dots[x-1][y-1] = 0;
} else {
    dots[x-1][y-1] = 1; // else dead change to alive cell
}

system("cls");
grid(dots);
userInput = (cin >>(cout << "press q to start simulation" << endl, userInput),userInput);
}
int nums = 2;
while(nums > 0 ){
system("cls");
for (int i = 0; i < square; i++){
    for(int j = 0; j < square; j++){

         if(dots[i][j] == 1){

            cout << "@"; //live cell
            if (alivecells(dots, i, j ) < 2 || alivecells(dots, i, j )> 3){ // checks if cell should die
                dots2[i][j] = 0; //dead cell
            } else{
                dots2[i][j] = 1; //alive cell
            }
         } else {
            cout << "*"; // dead cell
            if(alivecells(dots, i, j)== 3){ // if a dead cell has 3 alive neighbors
                dots2[i][j] = 1;
            }
         }
    }
    cout << endl;
}
for(int i = 0; i < square; i++){
    for(int j = 0; j < square; j++){
        dots[i][j] = dots2 [i][j]; // copy temp array to live array
    }
}
nums -= 1;
if(nums < 1){
nums = (cin >> (cout << "type how many steps to advance in the simulation"<< endl, nums), nums);
}
}


   return 0;
}
