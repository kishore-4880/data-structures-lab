//Program that eliminates the players according to the positions entered and displays the number of winners at the end of the program.
#include <iostream> 
using namespace std; 

int* fillarr(int*,int); 
int solve(int,int[],int); 

int main(){ 
int tc;
cout << "Enter the number of testcases: ";
cin >> tc;
for (int j = 0; j < tc; j++){
cout <<"Enter no of elimination indices: "; 
int el; 
cin>>el; 

int* IndArr = new int[el]; 
for (int i = 0 ; i < el ; i++){ 
    cin>>IndArr[i]; 
} 
cout<<"Enter no of queries: "; 
int q; 
cin>>q; 

for (int i = 1 ; i < q+1 ; i++){ 
    cout<<"Enter n"<<i<<": "; 
    int n; 
    cin>>n; 
    int output = solve(n,IndArr,el); 
    cout<<"Answer: "<<output<<endl; 
} 
}
} 

//Fills the array with given numhber of players.
int* fillarr(int* arr, int n){ 
    for (int i = 0 ; i < n ; i++){ 
        arr[i]=i+1; 
} 
return arr; 
} 

//Calculates and displays the number of winners after elimination.
int solve(int n , int IndArr[] , int IndArrSize){ 
    int* arr = new int[n]; 
    arr = fillarr(arr,n); 
    int size = n ; 

    while(1){   
        int reduce = 0 ; 
        for (int i = 0 ; i < IndArrSize ; i++){ 
            int ri = IndArr[i]; 
            if (arr[size-1] >= ri){ 
                reduce++; 
} 
} 
    if (reduce == 0 ){ 
        return size; 
} 
    else{ 
        size = size-reduce; 
} 
} 
} 