#include <bits/stdc++.h>

using namespace std;

int main(){

int n;

cout << "Input number: ";
cin >> n;

int size = ceil(sqrt(n));

if(size%2==0){
    size++;
}

int Spiral[size][size];
int width = ceil(log10(size*size));
int moves_copy;
int moves = 1;
int i = size/2, j = size/2;
int number = 1;

for(int i =0; i<size; i++){
    for(int j = 0; j<size; j++){
        Spiral[i][j] = 0;
    }
}

Spiral[i][j] = number;
number++;
moves_copy = moves;

while(number+2*moves<=n){

    moves_copy = moves + 1;

    if(moves%2 ==1){
        while(moves>0){
            j += 1;
            Spiral[i][j]= number;
            number++;
            moves--;
        }

    moves = moves_copy-1;

    while(moves>0){
            i--;
            Spiral[i][j] = number;
            number++;
            moves--;
    }

    }else{
        while(moves>0){
            j--;
            Spiral[i][j] = number;
            number++;
            moves--;
    }

    moves = moves_copy-1;

    while(moves>0){
            i++;
            Spiral[i][j] = number;
            number++;
            moves--;
    }
    }

    moves = moves_copy;

}

moves = moves_copy;

if(number + moves>n){
    if(moves%2 == 0){
        while(number<=n){
            j--;
            Spiral[i][j] = number;
            number++;
        }
    }else{
        while(number<=n){
            j++;
            Spiral[i][j] = number;
            number++;
        }
    }

}else{
    if(moves%2 == 0){
        while(moves > 0){
            j--;
            Spiral[i][j] = number;
            number++;
            moves--;
        }
        while(number<=n){
            i++;
            Spiral[i][j] = number;
            number++;
        }
    }else{
        while(moves > 0){
            j++;
            Spiral[i][j] = number;
            number++;
            moves--;
        }
        while(number<=n){
            i--;
            Spiral[i][j] = number;
            number++;
        }
    }
}

for(int i =0; i<size; i++){
    for(int j = 0; j<size; j++){
        cout.width(width);
        cout << Spiral[i][j] << " ";
    }
    cout << endl;
}

}
