#include <iostream>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

enum class PieceType{
    black,white,none
};

struct Step{
    int x = -1;
    int y =-1;
    Step(int x,int y):x(x),y(y){}
};


bool goNext(vector<vector<PieceType>>& vector, Step &step, PieceType ,int &nblack, int &nwhite);

void print(vector<vector<PieceType>> board){
    int c=0;
    cout<<"  ";
    for(int i=0;i<board.size();i++){
        cout<<char('A'+i)<<" ";
    }
    cout<<endl;
    for(auto& r:board){
        cout<<to_string(c+++1)<<" ";
        for(auto& c:r){
            switch (c){
                case PieceType ::none: cout<<"0"<<" ";
                    break;
                case PieceType ::black: cout<<"+"<<" ";
                    break;
                case PieceType ::white: cout<<"-"<<" ";
                    break;
            }
        }
        cout<<endl;
    }
}

vector<Step> getSteps(string s){
    vector<Step> steps;
    for(int i=0;i<s.size();i+=3){
        steps.emplace_back(s[i]-'A',s[i+1]-'1');
    }
    return steps;
}
int main() {
    vector<vector<PieceType>> board(8,vector<PieceType>(8,PieceType::none));
    board[3][3]=PieceType ::black;
    board[4][4]=PieceType ::black;
    board[3][4]=PieceType ::white;
    board[4][3]=PieceType ::white;

    string orders;
    std::getline(cin,orders);
    orders="F4,F5,F6,G5,E6";
    auto steps = getSteps(orders);

    int nblack=2;
    int nwhite = 2;
    int count = 0;
    for(auto& step:steps){
        print(board);
        if(!goNext(board,step,count++%2==0?PieceType ::black:PieceType ::white,nblack,nwhite)){
            cout<<"Error"<<endl;
            return -1;
        }
    }
    print(board);
    cout<<"Yes:"<<nblack<<":"<<nwhite<<endl;

    return 0;
}

bool changeDir(vector<vector<PieceType>>& board,tuple<int,int> dir,PieceType type,Step& step,int& nblack,int& nwhite){
    auto [xd,yd] = dir;
    int x=step.x+xd;
    int y=step.y+yd;
    bool met =false;
    while(x>=0&&x<board.size()&&y>=0&&y<board.size()){
        if(board[y][x]==PieceType::none) return false;
        if(board[y][x]!=type){
            met=true;
        }
        if(board[y][x]==type) break;
        x+=xd;
        y+=yd;
    }
    if(!met) return false;
    x-=xd;
    y-=yd;
    while(x!=step.x||y!=step.y){
        board[y][x]=type;
        if(type==PieceType::white) {
            nblack--;
            nwhite++;
        }
        else if(type==PieceType::black){
            nblack++;
            nwhite--;
        }
        x-=xd;
        y-=yd;
    }

    return true;
}

bool goNext(vector<vector<PieceType>>& board, Step &step,PieceType type,int &nblack, int &nwhite) {
    if(board[step.y][step.x]!=PieceType::none) return false;
    if(changeDir(board,{0,-1},type,step,nblack,nwhite)|
            changeDir(board,{1,-1},type,step,nblack,nwhite)|
            changeDir(board,{1,0},type,step,nblack,nwhite)|
            changeDir(board,{0,1},type,step,nblack,nwhite)|
            changeDir(board,{-1,1},type,step,nblack,nwhite)|
            changeDir(board,{-1,0},type,step,nblack,nwhite)|
            changeDir(board,{-1,-1},type,step,nblack,nwhite)|
            changeDir(board,{1,1},type,step,nblack,nwhite)){
        board[step.y][step.x]=type;
        if(type==PieceType::white) {
            nwhite++;
        }
        else if(type==PieceType::black){
            nblack++;
        }
        return true;
    }
    else return false;

}
