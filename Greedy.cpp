#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int v, e;
int i, j;
vector<vector<int>> gr;
vector<int> clr;
void gr_clr()
{
    clr[0] = 0;
    for (i = 1; i < v; i++)
        clr[i] = -1;
    bool unuse[v];
    for (i = 0; i < v; i++)
        unuse[i] = 0;
    for (i = 1; i < v; i++)
    {
        for (j = 0; j < gr[i].size(); j++)
            if (clr[gr[i][j]] != -1)
                unuse[clr[gr[i][j]]] = true;
        int cr;
        for (cr = 0; cr < v; cr++)
            if (unuse[cr] == false)
                break;
        clr[i] = cr;
        for (j = 0; j < gr[i].size(); j++)
            if (clr[gr[i][j]] != -1)
                unuse[clr[gr[i][j]]] = false;
    }
}
int main()
{
    int a, b;
    cout << "Enter number of vertices and edges respectively:";
    cin >> v >> e;
    cout << "\n";
    gr.resize(v);
    clr.resize(v);
    for (i = 0; i < e; i++)
    {
        cout << "\nEnter edge vertices of edge " << i + 1 << " :";
        cin >> a >> b;
        a--;
        b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    gr_clr();
    for (i = 0; i < v; i++)
    {
        cout << "Vertex " << i + 1 << " is coloured with " << clr[i] + 1
             << "\v";
    }
}
