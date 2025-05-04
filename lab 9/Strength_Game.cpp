//Program for a game that finds and displays the difference in strength of each player with respwct to the player with maximum strength
#include <iostream> 
using namespace std; 

int* solve(int[] ,int ); 
int maxexcept(int[] ,int ,int); 

int main(){ 
int tc;
cout << "Enter the number of testcases: ";
cin >> tc;
for (int j = 0; j < tc; j++){
cout<<"Enter no of players: "; 
int el; 
cin>>el; 

int* players = new int[el]; 
for (int i = 0 ; i<el;i++){ 
cin>>players[i]; 
} 

int* outputArr = solve(players,el); 
for (int i = 0 ; i<el;i++){ 
cout<<outputArr[i]<<" "; 
} 
return 0; 
}
} 

//Calculates the difference in strength of the players
int* solve(int arr[],int el){ 
int* op = new int[el]; 
for (int i = 0 ; i<el;i++){ 
op[i] = arr[i] - maxexcept(arr,el, i); 
} 
return op; 
} 

//Finds the player with maximum strength
int maxexcept(int arr[],int size,int index){ 
int max = 0; 
for (int i = 0 ; i < size; i++){ 
if (i!=index){ 
if (arr[i] > max){ 
max = arr[i]; 
} 
} 
} 
return max; 
} 