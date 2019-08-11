#include<iostream>
#include<vector>
using namespace std;
vector<vector<char>> board;
string word;
bool found=false;
void recur(int,int,int);
void helper(int i,int j,int x,int y,int point){
    if(i+x<board.size() && j+y<board[i+x].size())
        if(board[i+x][j+y]==word[point]){
            recur(i+x,j+y,point+1);
    }
}
void recur(int i,int j, int point) {
    if(found==true) return;
    if(point==word.length()){
        found=true;
        return;
    }
    int x,y;
    char temp=board[i][j];
    board[i][j]='\0';
        
    helper(i,j,0,1,point);
    helper(i,j,1,0,point);
    helper(i,j,0,-1,point);
    helper(i,j,-1,0,point);
        
    board[i][j]=temp;
}
void exist() {
    if(word.size()==0 || board.size()==0) return;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            if(board[i][j]==word[0]){
                recur(i,j,1);
                }
            }
        }
    return;
}
int main(){
    int m,n;
    char x;
    cout<<"Enter board dimensions";
    cin>>m>>n;
    cout<<"Enter board values";
    for(int i=0;i<m;i++){
        vector<char> temp;
        for(int j=0;j<n;j++){
            cin>>x;
            temp.push_back(x);
        }
        board.push_back(temp);
    }
    cout<<"Enter word to be searched";
    cin>>word;
    exist();
    cout<<std::boolalpha<<found;
    return 1;
}