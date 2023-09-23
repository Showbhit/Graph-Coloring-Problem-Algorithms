#include <iostream>
using namespace std;
#define V 4
void Solution_print(int color[]);
// checks if the condition is valid
bool isSafe(int ver, bool graph[V][V], int color[], int c) // c= color filled in the vertex, color[] is the array i.e. passed as refrence array for keeping the color
{
    for (int i = 0; i < V; i++)
        if (graph[ver][i] && c == color[i]) /*edge is present between the
        two vertices or not, vertex is used by its adjecent vertex or not */
        return false;

    return true;
}
// this function is the main function of the program
bool GraphColoring(bool graph[V][V], int m, int color[], int ver)
{
    /* if provided vertices are equivalent to the total number of vertices,
    all the vertices are assigned a color and returns true*/
    if (ver == V)
        return true;
    /*trying different colours on the vertex ver */
    for (int c = 1; c <= m; c++)
    {
        /* checking if the condition is safe */
        if (isSafe(ver, graph, color, c))
        {
            color[ver] = c; // assigning a color to the vertex ver.
            /*check the rest of the verteces,
            if true, color will be assigned the vertex ver */
            if (GraphColoring(graph, m, color, ver + 1) == true)
                return true;
            /*otherwise it will remove the solution and backtrack */
            color[ver] = 0;
        }
    }
    /*returns false is no color is assigned */
    return false;
}
/*returns false if the m
 colors cannot be assigned, otherwise
 return true and prints assignments of
 colors to all vertice*/
bool coloring(bool graph[V][V], int m)
{
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;
    // Calling GraphColoring() for vertex 0
    if (GraphColoring(graph, m, color, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }
    // Print the solution
    Solution_print(color);
    return true;
}
/* Function used to print the solution */
void Solution_print(int color[])
{
    cout << "Solution Exists: \n"
         << "Following are the assignedcolours : "<< "\n ";
    for (int i = 0; i < V; i++)
        cout << " " << color[i] << " ";
    cout << "\n";
}
int main()
{
    bool graph[V][V] = {
        {0, 1, 0, 1},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {1, 1, 1, 0},
    };
    // Number of colors
    int m = 3;
    coloring(graph, m);
    return 0;
}
