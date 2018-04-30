#include<bits/stdc++.h>
using namespace std;



void print(int n,map<pair<int ,pair<vector<int >, int > >, int > &dp)
{

    map<pair<int ,pair<vector<int >, int > >, int > :: iterator it;

    cout << "\n" ;

    for(int j = 0; j < n; j++)
    {
        for (it = dp.begin(); it !=dp.end() ; it++)
        {
            if(it -> first.second.first.size() == j)
            {

            cout << "Cost( " << it -> first.first << " ,{";
            for(int i = 0; i < it -> first.second.first.size(); i++)
            {
                    cout << it -> first.second.first[i] << "," ;
            }
            cout << "}, 1) = " << it-> second << "\n";
            }

        }
        cout << "\n";
    }
}



int TSP(int a, vector<int >v, int c, int ** dist,map<pair<int ,pair<vector<int >, int > >, int > &dp,map <pair <int, vector<int> >, int > &path)
{
    if(dp[{a, {v, c}}])
        return dp[{a, {v, c}}];

    dp[{a, {v, c}}] = INT_MAX;
    int min_vertex;

    if(v.size() == 0)
        dp[{a, {v, c}}] = dist[a][c];

    else
    {
        for(int i = 0; i < v.size(); i++)
        {

            if(dist[a][v[i]])
            {

                vector<int > v2 = v;
                v2.erase(v2.begin() + i);
                int res = TSP(v[i], v2, c,dist,dp,path);
                if(res < INT_MAX - dist[a][v[i]] && dp[{a, {v, c}}] > dist[a][v[i]] + res)
                {
                    dp[{a, {v, c}}] =dist[a][v[i]] + res;
                    path[make_pair(a, v)] = i;
                }
                //dp[{a, {v, c}}] =  min(dp[{a, {v, c}}], dist[a][v[i]] + TSP(v[i], v2, c, dist, dp));
            }
        }
    }
    return dp[{a, {v, c}}];
}

int main()
{
    int n, i, j, ans;
	map<pair<int ,pair<vector<int >, int > >, int > dp;   

    vector<int > v;
    cin>>n;
    int **dist = (int **) malloc(sizeof(int*) * (n + 1));
    for(i=1;i<=n;i++)
        dist[i] = (int *) malloc(sizeof(int) * (n+1));

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            cin >> dist[i][j];

    for(i=2;i<=n;i++)
        v.push_back(i);

    map<pair<int,vector<int> >, int > path;

    ans= TSP(1, v, 1, dist,dp,path);
    print(n,dp);

    printf("Shortest length path : ");
    printf("1 -> ");
    int a = path[make_pair(1, v)];
    while(v.size()){
        int p = v[a];
        printf("%d ->", p);
        v.erase(v.begin() + a);
        a = path[make_pair(p, v)];
    }
    printf("%d\n", 1);
    free(dist);

}

/*
4
0 10 15 20
5 0 4 10
6 13 0 12
8 0 9 0

5
0 24 11 10 9
8 0 2 5 11
26 12 0 8 7
11 23 24 0 6
5 4 8 10 0

3
0 1 10
1 0 3
2 3 0

4
0 4 1 3
4 0 2 1
1 2 0 5
3 1 5 0
*/

