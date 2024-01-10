 #include<bits/stdc++.h>
 using namespace std;
 
 int main()
 { vector<vector<int>> a = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},  
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
};
int n=1;
int k=0;
bool IsValid=true;

for(int i=0;i<9;i++){
    while(n<=9){
    for(int j=k+1;j<9;j++){
        if(a[k][i]==a[j][i]){ IsValid=false; cout<<"Col: "<<i<<" "<<j<<endl; break;}//check column
       if(a[i][k]==a[i][j]){ IsValid=false; cout<<"Row: "<<i<<" "<<j<<endl; break;}//check row
    }
    if(!IsValid)break;
    k++;  n++;}
    n=1; k=0;
    if(!IsValid)break;
}

if(IsValid){
for(int i = 0; i < 3; i++){
    for(int n = 0; n < 3; n++){
        
        bool seen[10] = {false};  

        
        for(int j = 0; j < 3; j++){
            for(int l = 0; l < 3; l++){
                
                int num = a[i*3 + j][n*3 + l];

                
                if(seen[num]){
                    
                    IsValid = false;
                    break;
                } else {
                    
                    seen[num] = true;
                }
            }
            if(!IsValid) break;
        }
        if(!IsValid) break;
    }
    if(!IsValid) break;
}}

if(IsValid)cout<<"Valid"<<endl;
else cout<<"Invalid"<<endl;




    
    return 0;
 }