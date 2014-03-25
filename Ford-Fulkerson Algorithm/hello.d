module main;

import std.stdio;
import std.file;

int main(string[] args)
{
    string filename = "matrix2.txt";

    auto graph = getGraphFromFile(filename);

    int r[5][6];

    auto maxFlow = AFF(graph);
    writeln("Max Flow: ",maxFlow);

    return 0;
}

int AFF(int graph[][])
{

    auto N = graph.length;
    auto r = new int[N];
    auto p = new int[N];
    auto col = new int[N];

    auto f = new int[][](N,N);        // empy, all numbers are 0
    int cut[][];

    initAFF(r,p,col);

    while( existWhiteMarkedVertex(p,col) )
    {

        //writeln("\n", r, "\t", p , "\t", col);
        int tempVertex = getWhiteMarkedVertex(p,col);

        auto surroundings = getSurroundings(graph, tempVertex);

        for(int i = 0; i < surroundings.length; ++i)
        {
            int j = surroundings[i];

            if(p[j] == -1)
            {
                if( graph[tempVertex][j] && f[tempVertex][j] < graph[tempVertex][j])
                {
                    r[j] = graph[tempVertex][j] - f[tempVertex][j];
                    p[j] = tempVertex;
                }
                if( graph[j][tempVertex] && f[j][tempVertex] > 0)
                {
                    r[j] = f[j][tempVertex];
                    p[j] = tempVertex;
                }
            }
        }

        col[tempVertex] = 1;

        //writeln(r, "\t", p , "\t", col);

        if (p[N-1] != -1)
        {
            auto j = N-1;
            auto i = p[j];
            int cf;

            while(  j!= 0)
            {
                cf = ( cf == 0 || cf > graph[i][j] ) ? graph[i][j] : cf;

                j = i;
                i = p[i];
            }

          //writeln("достигли стока ", cf, "\n");

            j = N-1;
            i = p[j];

            while(  j!= 0)
            {
                if( graph[i][j] )
                    f[i][j] = f[i][j] + cf;
                else
                    f[i][j] = f[i][j] - cf;

                j = i;
                i = p[i];
            }


            initAFF(r,p,col);
        }
        //writeln(f, "\n");
    }

    cut = getCut(col);

    writeln("Cut: ",cut);

    auto maxFlow = getMaxFlow(graph,cut,f);

    return maxFlow;
}

int getMaxFlow(int graph[][],int cut[][],int f[][])
{
    int maxFlow = 0;

    for(int i = 0; i < cut[0].length; ++i)
        for(int j = 0; j < cut[1].length; ++j)
        {
            if( graph[ cut[0][i] ][ cut[1][j] ] )
                maxFlow += f[ cut[0][i] ][ cut[1][j] ];
        }

    return maxFlow;
}


int[][] getCut(int col[])
{
    int cut[][] = new int[] [2];

    for(int i = 0; i < col.length; ++i)
        if(col[i] != -1)
            cut[0] ~= i;
        else cut[1] ~= i;

    return cut;
}

bool existWhiteMarkedVertex(int p[], int col[])
{
    for(int i = 0; i < p.length; ++i)
        if( col[i] == -1 && p[i] != -1)
            return true;

    return false;
}


int getWhiteMarkedVertex(int p[],int col[])
{
    for(int i = 0; i < p.length; ++i)
        if( col[i] == -1 && p[i] != -1)
            return i;

    return -1;

}

int[] getSurroundings(int graph[][], int v)
{
    int surroundings[];

    for(int i = 0; i < graph.length; ++i)
    {
        if(v != i && (graph[v][i] || graph[i][v]) )
            surroundings ~= i;
    }

    return surroundings;
}

void initAFF(ref int r[],ref int p[],ref int col[])
{
    r[0] = 1000000;         //      infinity
    p[0] = 0;
    col[0] = -1;
    for(int i = 1; i < r.length; ++i)
    {
        r[i] = 0;           //      ...
        p[i] = -1;          //      unmarked
        col[i] = -1;        //      white color
    }
}


int[][] getGraphFromFile(string filename)
{
    int N;                            //   number of vertices of graph

    auto file = File(filename, "r");
    file.readf("%d", &N);

    auto graph = new int[][](N,N);    //    matrix of adjacency

    foreach(ref row; graph)
    {
        foreach(ref elem; row)
        {
            file.readf(" %d", &elem);
        }
    }

    return graph;
}
