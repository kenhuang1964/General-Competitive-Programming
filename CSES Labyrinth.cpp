#include <bits/stdc++.h>

using namespace std;

int n, m;
const int mxN = 1005;

vector<vector<char>>maze;
vector<vector<int>>dist;
vector<vector<char>>path;
bool visited[mxN][mxN];
queue<tuple<int,int,int,char>>q;
pair<int,int>endLoc;
string ans;
string directionPath;

void floodfill(int x, int y, int n, int m, int d, char direction) {
    bool found = false;

    q.push({x, y, d, direction});
    while(!q.empty() && !found) {
        tie(x, y, d, direction) = q.front();
        q.pop();

        if (x >= 0 && y >= 0 && x < n && y < m && maze[x][y] != '#' && !visited[x][y]) {
            visited[x][y] = true;
            dist[x][y] = d;
            path[x][y] = direction;

            if (maze[x][y] == 'B') {
                endLoc = {x, y};
                ans = "YES";
                found = true;
                break;
            }

            q.push({x+1, y, d+1, 'D'});
            q.push({x-1, y, d+1, 'U'});
            q.push({x, y+1, d+1, 'R'});
            q.push({x, y-1, d+1, 'L'});
        }
    }
}

void pathRetrieval(int x, int y) {
    if (path[x][y] == 'A') {
        return;
    }
    directionPath += path[x][y];
    char dir = path[x][y];
    if (dir == 'D') {
        pathRetrieval(x-1, y);
    } else if (dir == 'U') {
        pathRetrieval(x+1, y);
    } else if (dir == 'R') {
        pathRetrieval(x, y-1);
    } else {
        pathRetrieval(x, y+1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    
    ans = "NO";
    directionPath = "";
    
    maze.resize(n, vector<char>(m, '.'));
    dist.resize(n, vector<int>(m));
    path.resize(n, vector<char>(m));
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> maze[i][j];
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'A') {
                floodfill(i, j, n, m, 0, 'A');
                break;
            }
        }
    }
    
    cout << ans << endl;
    if (ans=="YES") {
        pathRetrieval(endLoc.first, endLoc.second);
        reverse(directionPath.begin(), directionPath.end());
        cout << dist[endLoc.first][endLoc.second] << endl;
        cout << directionPath << endl;
    }
    return 0;
}