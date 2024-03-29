//Programmers 게임 맵 최단거리
//https://school.programmers.co.kr/learn/courses/30/lessons/1844
 

#include <vector>
#include <queue>
#include <iostream>

using namespace std;


struct Node {
    int x,y;
    int lev;
};


int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
int used[101][101]={0};

queue<Node> q;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int height = maps.size();
    int width = maps[0].size();
    int N = height-1;
    int M = width-1;
    
    q.push({0,0,0});
    
    while(q.empty()) {
        Node now = q.front();
        q.pop();
        
        for(int dir=0; dir<4; dir++) {
            int nx=now.x+dx[dir];
            int ny=now.y+dy[dir];
            
            if(nx<0 || nx>height || ny<0 || ny>height)
                continue;
            
            if(maps[nx][ny]==0)
                continue;
            
            if(used[nx][ny]==0)
                continue;
            
            if(nx==N && ny==M)
                return (now.lev+1)+1;
           
            used[nx][ny]=1;
            q.push({nx,ny,now.lev+1});
            
        }//for
    }//while
    
    return -1;
}
