#ifndef BACKTRAKING_H
#define BACKTRAKING_H
#include <iostream>
#include <vector>
#include <climits>
#include "listback.h"
#include <QString>


const int N = 22;
const int m = 15;


class backTraking
{
public:
    backTraking(int arr[m][N]);
    void backtrack(int x, int y, int distance, int end_x, int end_y,listBack path);


    int shortestPathLength;


    listBack shortestPath;
    listBack id_list;



    nodeBack *a;
    listBack auxFindShortestPath(int start_x, int start_y, int end_x, int end_y);
    listBack findShortestPath(int beggining, int final);






private:

    int grid[m][N];




};

#endif // BACKTRAKING_H
