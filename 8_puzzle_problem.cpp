
//IDA*
/**
 * https://www.cnblogs.com/na-sr/p/8-puzzle.html
 * 
 * “八数码问题（8-Puzzle Problem）——多种搜索算法”
 */


#include <bits/stdc++.h>
 
using namespace std;
const int dx[] = { 1, -1, 0, 0 };
const int dy[] = { 0, 0, 1, -1 };
const int pos_x[] = { 2, 1, 1, 1, 2, 3, 3, 3, 2 };
const int pos_y[] = { 2, 1, 2, 3, 3, 3, 2, 1, 1 };
int lim;  // depth limit
int m[5][5];
 
int h() {
    int ans = 0;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            if (m[i][j] != 0)
                ans += abs(i - pos_x[m[i][j]]) + abs(j - pos_y[m[i][j]]);  // Manhattan distance
    return ans;
}
 
bool dfs(int x, int y, int t, int lx, int ly) {
    int dis = h();
    if (t + dis > lim)
        return false;  // prune with f(x)
    if (dis == 0)
        return true;  // exit
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx < 1 || tx > 3 || ty < 1 || ty > 3)
            continue;
        if (tx == lx && ty == ly)
            continue;  // very important
        swap(m[x][y], m[tx][ty]);
        if (dfs(tx, ty, t + 1, x, y))
            return true;  // expand
        swap(m[x][y], m[tx][ty]);  // backtrack
    }
    return false;
}
 
int main() {
    int num;
    cin >> num;
    int sx, sy;
    for (int i = 3; i >= 1; --i) {
        for (int j = 3; j >= 1; --j) {
            m[i][j] = num % 10;
            num /= 10;
            if (m[i][j] == 0)
                sx = i, sy = j;
        }
    }
    lim = 0;
    while (!dfs(sx, sy, 0, -1, -1))
        ++lim;  // IDA*
    cout << lim << endl;
    return 0;
}


//A*
/**
 * https://www.cnblogs.com/na-sr/p/8-puzzle.html
 * 
 * “八数码问题（8-Puzzle Problem）——多种搜索算法”
 */

/**
    //估价函数：
    //当前状态中每个数与它目标位置的曼哈顿距离之和
    #include <cstring>
    #include <iostream>
    #include <algorithm>
    #include <queue>
    #include <unordered_map>
    
    using namespace std;
    
    int f(string state)
    {
        int res = 0;
        for (int i = 0; i < state.size(); i ++ )
            if (state[i] != 'x')
            {
                int t = state[i] - '1';
                res += abs(i / 3 - t / 3) + abs(i % 3 - t % 3);
            }
        return res;
    }
    
    string bfs(string start)
    {
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        char op[4] = {'u', 'r', 'd', 'l'};
        
        string end = "12345678x";
        unordered_map<string, int> dist;
        unordered_map<string, pair<string, char>> prev;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> heap;
        
        heap.push({f(start), start});
        dist[start] = 0;
        
        while (heap.size())
        {
            auto t = heap.top();
            heap.pop();
            
            string state = t.second;
            
            if (state == end) break;
            
            int step = dist[state];
            int x, y;
            for (int i = 0; i < state.size(); i ++ )
                if (state[i] == 'x')
                {
                    x = i / 3, y = i % 3;
                    break;
                }
            string source = state;
            for (int i = 0; i < 4; i ++ )
            {
                int a = x + dx[i], b = y + dy[i];
                if (a >= 0 && a < 3 && b >= 0 && b < 3)
                {
                    swap(state[x * 3 + y], state[a * 3 + b]);
                    if (!dist.count(state) || dist[state] > step + 1)
                    {
                        dist[state] = step + 1;
                        prev[state] = {source, op[i]};
                        heap.push({dist[state] + f(state), state});
                    }
                    swap(state[x * 3 + y], state[a * 3 + b]);
                }
            }
        }
        
        string res;
        while (end != start)
        {
            res += prev[end].second;
            end = prev[end].first;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    int main()
{
    string g, c, seq;
    while (cin >> c)
    {
        g += c;
        if (c != "x") seq += c;
    }
    
    int t = 0;
    for (int i = 0; i < seq.size(); i ++ )
        for (int j = i + 1; j < seq.size(); j ++ )
            if (seq[i] > seq[j])
                t ++ ;
    
    if (t % 2) puts("unsolvable");
    else cout << bfs(g) << endl;
    
    return 0;
}
*/


//双向BFS
/**
 * https://www.cnblogs.com/na-sr/p/8-puzzle.html
 * 
 * “八数码问题（8-Puzzle Problem）——多种搜索算法”
 */

/**
    
    #include <bits/stdc++.h>
    
    using namespace std;
    const int target = 123804765;
    const int dx[] = { 1, -1, 0, 0 };
    const int dy[] = { 0, 0, 1, -1 };
    
    struct Status {
        int maze[5][5];  // matrix
        int x, y;        // coordinate of blank space
        bool d;          // bfs direction (true: forward, false: back)
        int t;           // step number
    
        explicit Status(int num) {
            memset(maze, 0, sizeof(maze));
            t = 0;
            if (num == target)
                d = false;
            else
                d = true;
            for (int i = 3; i >= 1; --i) {
                for (int j = 3; j >= 1; --j) {
                    maze[i][j] = num % 10;
                    num /= 10;
                    if (maze[i][j] == 0)
                        x = i, y = j;
                }
            }
        }
    
        int to_int() const {
            int ans = 0;
            for (int i = 1; i <= 3; ++i)
                for (int j = 1; j <= 3; ++j)
                    ans = ans * 10 + maze[i][j];  // hash
            return ans;
        }
    };
    
    int bfs(int num) {
        queue<Status> q;
        unordered_map<int, pair<int, bool>> vis;
        q.emplace(target);  // target state
        vis[target] = make_pair(0, false);
        q.emplace(num);  // starting state
        vis[num] = make_pair(0, true);
        while (!q.empty()) {
            Status now = q.front();
            q.pop();
            if (vis.count(now.to_int()) && vis[now.to_int()].second != now.d)
                return now.t + vis[now.to_int()].first;  // meet in the middle
            ++now.t;
            int x = now.x, y = now.y;
            for (int i = 0; i < 4; ++i) {
                int tx = x + dx[i], ty = y + dy[i];
                if (tx < 1 || tx > 3 || ty < 1 || ty > 3)
                    continue;
                swap(now.maze[x][y], now.maze[tx][ty]);
                now.x = tx;
                now.y = ty;
                if (!vis.count(now.to_int()) || vis[now.to_int()].second != now.d) {
                    q.push(now);  // expand
                    vis[now.to_int()] = make_pair(now.t, now.d);
                }
                now.x = x;
                now.y = y;
                swap(now.maze[now.x][now.y], now.maze[tx][ty]);  // backtrack
            }
        }
        return -1;  // unused value
    }
    
    int main() {
        int num;
        cin >> num;
        cout << bfs(num) << endl;
        return 0;
    }

*/

//限制下的技巧解
/**
 * [B14 BFS 八数码难题] https://www.bilibili.com/video/BV1oa41157eB
 * 
 *  P1379
 */

/**
    #include <iostream>
    #include <cstring>
    #include <queue>
    #include <unordered_map>
    using namespace std;

    int bfs(string str);

    //用hash-map存
    //value(int)是key(string)对应的移动次数
    unordered_map<string,int> d;
    queue<string> q;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};

    int main(){
        string initStr;
        cin>>initStr;

        cout<<bfs(initStr)<<endl;

        return 0;
    }

    int bfs(string str){
        q.push(str);
        string end="123804765";     //目标状态
        while(q.size()){
            //取
            auto s=q.front();
            q.pop();

            //退出条件：达到目标
            if(s==end){return d[s];}

            //先确定'0'的位置,坐标转换
            int k=s.find('0');
            int x=k/3,y=k%3;

            //开始寻找下一个状态
            for(int i=0;i<4;++i){
                int a=x+dx[i],b=y+dy[i];    //更新坐标(维度转换)
                if(a<0||a>2||b<0||b>2){     //保证不会越界
                    continue;
                }
                int dis=d[s];               //取出value对应的key值
                swap(s[k],s[a*3+b]);
                if(!d.count(s)){            //查重
                    d[s]=dis+1;
                    q.push(s);
                }
                swap(s[k],s[a*3+b]);
            }
        }
    }
*/


//最朴素版本，通用解
/**
 * URL https://www.geeksforgeeks.org/8-puzzle-problem-using-branch-and-bound/
 * 
 */

/**

    // Program to print path from root node to destination node
    // for N*N -1 puzzle algorithm using Branch and Bound
    // The solution assumes that instance of puzzle is solvable
    #include <bits/stdc++.h>
    using namespace std;
    #define N 3

    // state space tree nodes
    struct Node
    {
        // stores the parent node of the current node
        // helps in tracing path when the answer is found
        Node* parent;

        // stores matrix
        int mat[N][N];

        // stores blank tile coordinates
        int x, y;

        // stores the number of misplaced tiles
        int cost;

        // stores the number of moves so far
        int level;
    };

    // Function to print N x N matrix
    int printMatrix(int mat[N][N])
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                printf("%d ", mat[i][j]);
            printf("\n");
        }
    }

    // Function to allocate a new node
    Node* newNode(int mat[N][N], int x, int y, int newX,
                int newY, int level, Node* parent)
    {
        Node* node = new Node;

        // set pointer for path to root
        node->parent = parent;

        // copy data from parent node to current node
        memcpy(node->mat, mat, sizeof node->mat);

        // move tile by 1 position
        swap(node->mat[x][y], node->mat[newX][newY]);

        // set number of misplaced tiles
        node->cost = INT_MAX;

        // set number of moves so far
        node->level = level;

        // update new blank tile coordinates
        node->x = newX;
        node->y = newY;

        return node;
    }

    // bottom, left, top, right
    int row[] = { 1, 0, -1, 0 };
    int col[] = { 0, -1, 0, 1 };

    // Function to calculate the number of misplaced tiles
    // ie. number of non-blank tiles not in their goal position
    int calculateCost(int initial[N][N], int final[N][N])
    {
        int count = 0;
        for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (initial[i][j] && initial[i][j] != final[i][j])
            count++;
        return count;
    }

    // Function to check if (x, y) is a valid matrix coordinate
    int isSafe(int x, int y)
    {
        return (x >= 0 && x < N && y >= 0 && y < N);
    }

    // print path from root node to destination node
    void printPath(Node* root)
    {
        if (root == NULL)
            return;
        printPath(root->parent);
        printMatrix(root->mat);

        printf("\n");
    }

    // Comparison object to be used to order the heap
    struct comp
    {
        bool operator()(const Node* lhs, const Node* rhs) const
        {
            return (lhs->cost + lhs->level) > (rhs->cost + rhs->level);
        }
    };

    // Function to solve N*N - 1 puzzle algorithm using
    // Branch and Bound. x and y are blank tile coordinates
    // in initial state
    void solve(int initial[N][N], int x, int y,
            int final[N][N])
    {
        // Create a priority queue to store live nodes of
        // search tree;
        priority_queue<Node*, std::vector<Node*>, comp> pq;

        // create a root node and calculate its cost
        Node* root = newNode(initial, x, y, x, y, 0, NULL);
        root->cost = calculateCost(initial, final);

        // Add root to list of live nodes;
        pq.push(root);

        // Finds a live node with least cost,
        // add its childrens to list of live nodes and
        // finally deletes it from the list.
        while (!pq.empty())
        {
            // Find a live node with least estimated cost
            Node* min = pq.top();

            // The found node is deleted from the list of
            // live nodes
            pq.pop();

            // if min is an answer node
            if (min->cost == 0)
            {
                // print the path from root to destination;
                printPath(min);
                return;
            }

            // do for each child of min
            // max 4 children for a node
            for (int i = 0; i < 4; i++)
            {
                if (isSafe(min->x + row[i], min->y + col[i]))
                {
                    // create a child node and calculate
                    // its cost
                    Node* child = newNode(min->mat, min->x,
                                min->y, min->x + row[i],
                                min->y + col[i],
                                min->level + 1, min);
                    child->cost = calculateCost(child->mat, final);

                    // Add child to list of live nodes
                    pq.push(child);
                }
            }
        }
    }

    // Driver code
    int main()
    {
        // Initial configuration
        // Value 0 is used for empty space
        int initial[N][N] =
        {
            {1, 2, 3},
            {5, 6, 0},
            {7, 8, 4}
        };

        // Solvable Final configuration
        // Value 0 is used for empty space
        int final[N][N] =
        {
            {1, 2, 3},
            {5, 8, 6},
            {0, 7, 4}
        };

        // Blank tile coordinates in initial
        // configuration
        int x = 1, y = 2;

        solve(initial, x, y, final);

        return 0;
    }

*/