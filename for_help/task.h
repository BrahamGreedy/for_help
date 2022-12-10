#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>
#include <graphics.h>
#include <math.h>
#include <fstream>
#include "control.h"

using namespace std;

class Figure3d{
private:
   int I[3] = {1, 0, 0};
   int J[3] = {0, 1, 0};
   int K[3] = {0, 0, 1};
   int p[20];
   int surface_num, vertex_num;
   int d[3] = {0, 0, 0};
   vector<vector<double>> vertexs;
   vector<vector<int>> surfaces;
public:
   Figure3d();
   void rotate(int);
   void move(int, int);
   void draw(int);
};

#endif