#include <bits/stdc++.h>

using namespace std;

const int mxN = 1005;

char direction[mxN][mxN];

string path;

void directionRetrieval(int x, int y) {
    if (direction[x][y] == 'A') {
        return;
    }
    char dir = direction[x][y];
    path += dir;
    if (dir == 'D') {
        directionRetrieval(x-1, y);
    } else if (dir == 'U') {
        directionRetrieval(x+1, y);
    } else if (dir == 'R') {
        directionRetrieval(x, y-1);
    } else {
        directionRetrieval(x, y+1);
    }
}

int main() {
    int n, m; cin >> n >> m;
    path = "";
    
    char maze[n][m];
    int dist[n][m] = {0};
    bool visited[n][m] ={};
    vector<pair<int,int>>monstersCoordinates;
    
    pair<int,int>startPos;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'M') {
                monstersCoordinates.push_back({i, j});
            } else if (maze[i][j] == 'A') {
                startPos = {i, j};
            }
        }
    }
    // Have the monsters go first so that any pos they visit is marked
    queue<tuple<int,int,int,char,bool>>q; // {x,y,dist,dir, monster?}
    for (pair<int,int>coord : monstersCoordinates) {
        q.push({coord.first, coord.second, 0, '.', true});
    }
    q.push({startPos.first, startPos.second, 0, 'A', false});
    
    bool founddirection = false;
    string ans = "NO";
    pair<int,int>endLoc;
    while (!q.empty() && !founddirection) {
        int x, y, d;
        char dir;
        bool monster;
        tie(x, y, d, dir, monster) = q.front();
        q.pop();
        
        if (x >= 0 && y >= 0 && x < n && y < m && maze[x][y] != '#' && !visited[x][y]) {
            visited[x][y] = true;
            dist[x][y] = d;
            
            // On the edge
            if (!monster) {
                direction[x][y] = dir;
                if (x == 0 || x == n-1 || y == 0 || y == m-1) {
                    founddirection = true;
                    ans = "YES";
                    endLoc = {x, y};
                    break;
                }
            }
            
            if (monster) {
                q.push({x+1, y, d+1, '.', true});
                q.push({x-1, y, d+1, '.', true});
                q.push({x, y+1, d+1, '.', true});
                q.push({x, y-1, d+1, '.', true});
            } else {
                q.push({x+1, y, d+1, 'D', false});
                q.push({x-1, y, d+1, 'U', false});
                q.push({x, y+1, d+1, 'R', false});
                q.push({x, y-1, d+1, 'L', false});
            }
        }
    }
    
    cout << ans << endl;
    if (ans == "YES") {
        directionRetrieval(endLoc.first, endLoc.second);
        reverse(path.begin(), path.end());
        cout << dist[endLoc.first][endLoc.second] << endl;
        cout << path << endl;
    }
    return 0;
}