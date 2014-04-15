module main;

import std.stdio;
import std.traits;

int main(string[] args)
{
    auto matrix = readMatrixFromFile!(float)("matrix.txt");
    writeln("Distance between verteces:\n", matrix);

    int next[][];

    auto pathMatrix = FloydAlgorithm!(float)(matrix, next);
    writeln("\nShortes pathes betwen vertes:\n", pathMatrix);
    //writeln(next);

    int i = 0 , j = 2;
    auto path = getShortestPath(next, i, j);
    writeln("\nShortest path between: " , i , " and " , j , " verteces:\n" , path);

    return 0;
}

T [][] readMatrixFromFile(T)(string filename)
in
{
    assert(isNumeric!(T), "T [][] readMatrixFromFile(T)(string filename) : T is not numeric!\n");
}
body
{
    auto file = File(filename, "r");

    /* Getting number of verteces in graph ( it's the same as size of square adjacency matrix ) */
    size_t size;
    file.readf(" %d", &size);

    T matrix[][] = new T[][size];
    foreach(i; 0..size)
    matrix[i] = new T[size];

    /* Set value to INFINITY for floating types and max value fo intagral types */
    foreach(i; 0..size)
    foreach(j; 0..size)
    {
        static if(isIntegral!(T))
            matrix[i][j] = T.max/2; // for avoiding int type overflow in line 123:  if(D[i][k] + D[k][j] < D[i][j])
        else static if(isFloatingPoint!(T))
            matrix[i][j] = T.infinity;
        else
        {
            file.close();
            assert(false, "Type T hasn't property max or infinity!");
        }
    }

    size_t i,j;
    T w;

    file.readf(" %d", &i);
    file.readf(" %d", &j);

    static if(isIntegral!(T))
        file.readf(" %d", &w);
    else static if(isFloatingPoint!(T))
        file.readf(" %f", &w);

    while( !file.eof())
    {
        matrix[i][j] = cast(T)w;
        file.readf(" %d", &i);
        file.readf(" %d", &j);

        static if(isIntegral!(T))
            file.readf(" %d", &w);
        else static if(isFloatingPoint!(T))
            file.readf(" %f", &w);
    }

    file.close();

    return matrix;
}

T[][] FloydAlgorithm(T)(T matrix[][], ref int next[][])
in
{
    assert(isNumeric!(T), "T[][] FloydAlgorithm(T)(T matrix[][], ref T next[][]) : T is not numeric!\n");
}
body
{
    next = new int[][matrix.length];
    foreach(i; 0..next.length)
    next[i] = new int[matrix.length];

    foreach(i; 0..next.length)
    foreach(j; 0..next[i].length)
    next[i][j] = -1;

    T D[][] = matrix[][];

    /*  I'm so sorry for this Govnokod */
    static if(isIntegral!(T))
    {
        foreach(i; 0..next.length)
        foreach(j; 0..next.length)
        if( matrix[i][j] < T.max)
            next[i][j] = cast(int)j;
    }
    else static if(isFloatingPoint!(T))
    {
        foreach(i; 0..next.length)
        foreach(j; 0..next.length)
        if( matrix[i][j] < T.infinity)
            next[i][j] = cast(int)j;
    }
    else
    {
        assert(false, "Type T hasn't property max or infinity!\n");
    }

    foreach(k; 0..matrix.length)
    foreach(i; 0..matrix.length)
    foreach(j; 0..matrix.length)
    if(D[i][k] + D[k][j] < D[i][j])
    {
        D[i][j] = D[i][k] + D[k][j];
        next[i][j] = cast(int)k;
    }
    return D;
}

size_t[] getShortestPath(int next[][], size_t i, size_t j)
in
{
    assert(i >=0 && i < next.length && j >=0 && j < next.length,
    "T[] getShortechPath(int next[][],size_t i, size_t j): invalid value of size_t i, size_t  j: array out of bounds!\n");
}
body
{
    size_t path[];
    if (next[i][j] == -1)
        return path;

    size_t current = j;

    path ~= j;
    while(current != next[i][current])
    {
        current = next[i][current];
        path ~= current;
    }
    path ~= i;

    path.reverse;

    return path;
}
