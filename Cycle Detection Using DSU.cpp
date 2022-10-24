#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> sz(N);      // Size

void make_set(int v){
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v){
    if(v == parent[v]){
        return v;
    }
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a != b){
        // They both belong to different sets
        if(sz[a] < sz[b]){
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main(){
    for(int i=0; i<N; i++){
        make_set(i);
    }

    int n;
    cout<<"Enter the number of vertices: "<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of Edges: "<<endl;
    cin>>m;

    vector<vector<int>> adjl(n);
    for(int i=0; i<m; i++){
        int x, y;
        cout<<"Enter the starting and ending vertices of edges: "<<endl;
        cin>>x>>y;

        adjl[x].push_back(y);
        adjl[y].push_back(x);
    }

    bool cycle = false;

    for(auto it : adjl){
        int u = it[0];      // First vectice
        int v = it[1];      // Second vectice

        int x = find_set(u);
        int y = find_set(v);

        if(x == y){
            cycle = true;
        }else{
            union_sets(u, v);
        }
    }

    if(cycle){
        cout<<"Cycle is found"<<endl;
    }
    else{
        cout<<"Cycle is not found"<<endl;
    }

    return 0;
}