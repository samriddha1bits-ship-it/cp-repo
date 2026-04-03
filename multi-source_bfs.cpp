#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first 
#define INF 1e18
#define S second
#define endl "\n"

int n,m;
vector<string> grid;
queue<pair<int,int>> qMon;
queue<pair<int,int>> qA;
vector<vector<int>> visByMon;
vector<vector<int>> distFromMon;
vector<vector<int>> visByA;
vector<vector<int>> distFromA;
int dx[] = {-1, 0 , 1, 0};
int dy[] = {0, 1 , 0 , -1};


bool isValid(int x,int y){
    // can you visit this
    if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y]!='#'){
        return true;
    }
    return false;
}
bool checkBoundary(pair<int,int> node){
    int x = node.F;
    int y = node.S;
    if(x == 0 || x == n-1 || y == 0 || y ==m-1){
        if(isValid(x,y)){
            return true;
        }
    }
    return false;
}
vector<pair<int,int>> neighList(pair<int,int> node){
    int x = node.F;
    int y = node.S;
    vector<pair<int,int>> ans;
    for(int i = 0 ; i < 4 ; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(isValid(nx,ny)){
            ans.push_back({nx,ny});
        }
    }
    return ans;
}
void solve(){
    cin>>n>>m;
    grid.resize(n);
    visByMon = vector<vector<int>> (n,vector<int>(m,0));
    visByA = vector<vector<int>> (n,vector<int>(m,0));
    distFromMon = vector<vector<int>> (n,vector<int>(m,INF)); 
    distFromA = vector<vector<int>> (n,vector<int>(m,INF)); 
    for(int i = 0 ; i < n ; i++){
        cin>>grid[i];
        for(int j = 0 ; j < m ; j++){
            if(grid[i][j] == 'M'){
                //store this to apply BFS on monster
                qMon.push({i,j});
                distFromMon[i][j] = 0;
            }
            if(grid[i][j] == 'A'){
                //store this to apply BFS to exit point from here
                qA.push({i,j});
                distFromA[i][j] = 0;
                // Edge Case: If A is already on the boundary at the very beginning
                if (checkBoundary({i,j})) {
                    cout << "YES" << endl;
                    cout << 0 << endl;
                    return; // End the program immediately!
                }
            }
        }
    }
    // apply bfs from all monsters
    while(!qMon.empty()){
        pair<int,int> node = qMon.front();
        qMon.pop();


        if(visByMon[node.F][node.S]){continue;}
        visByMon[node.F][node.S] = 1;
        for(auto neigh : neighList(node)){
            if(!visByMon[neigh.F][neigh.S] && distFromMon[neigh.F][neigh.S] > distFromMon[node.F][node.S] + 1){
                distFromMon[neigh.F][neigh.S] = distFromMon[node.F][node.S] + 1;
                qMon.push(neigh);
            }
        }
    }
    // apply bfs from A
    bool possible = false;
    int pathLen = INF;
    while(!qA.empty()){
        pair<int,int> node = qA.front();
        qA.pop();


        if(visByA[node.F][node.S]){continue;}
        visByA[node.F][node.S] = 1;
        for(auto neigh: neighList(node)){
            if(!visByA[neigh.F][neigh.S] && distFromA[neigh.F][neigh.S] > distFromA[node.F][node.S] + 1){
                distFromA[neigh.F][neigh.S] = distFromA[node.F][node.S] + 1;
                qA.push(neigh);
                if(checkBoundary(neigh) && distFromA[neigh.F][neigh.S] < distFromMon[neigh.F][neigh.S]){
                    possible = true;
                    pathLen = min(pathLen,distFromA[neigh.F][neigh.S]);
                }
            }


        }
    }
    if(possible){
        cout<<"YES"<<endl;
        cout<<pathLen<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}
