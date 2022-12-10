#include "task.h"

Figure3d::Figure3d(){
   ifstream f("info_for_figure.txt");
   f>>vertex_num>>surface_num;
   vertexs.resize(vertex_num, vector<double> (3));
   for(int i=0; i<vertex_num; i++){
      for(int j=0; j<3; j++){
         f>>vertexs[i][j];
      }
   }
   surfaces.resize(surface_num, vector<int> (vertex_num));
   for(int i=0; i<surface_num; i++){
      for(int j=0; j<4; j++){
         f>>surfaces[i][j];
      }
   }
   f.close();
}

void Figure3d::rotate(int type){
   for(int i=0; i<vertex_num; i++){
      vertexs[i][0] -= d[0];
      vertexs[i][1] -= d[1];
      vertexs[i][2] -= d[2];
   }
   switch(type){
      case 0:
         for(int i=0; i<vertex_num; i++){
            vertexs[i][0] = vertexs[i][0]*cos(acos(-1)/24)+vertexs[i][1]*sin(acos(-1)/24);
            vertexs[i][1] = vertexs[i][1]*cos(acos(-1)/24)-vertexs[i][0]*sin(acos(-1)/24);
         }
         break;
      case 1:
         for(int i=0; i<vertex_num; i++){
            vertexs[i][0] = vertexs[i][0]*cos(acos(-1)/24)-vertexs[i][2]*sin(acos(-1)/24);
            vertexs[i][2] = vertexs[i][0]*sin(acos(-1)/24)+vertexs[i][2]*cos(acos(-1)/24);
         }
         break;
      case 2:
         for(int i=0; i<vertex_num; i++){
            vertexs[i][1] = vertexs[i][1]*cos(acos(-1)/24)+vertexs[i][2]*sin(acos(-1)/24);
            vertexs[i][2] = vertexs[i][2]*cos(acos(-1)/24)-vertexs[i][1]*sin(acos(-1)/24);
         }
         break;
   }
   for(int i=0; i<vertex_num; i++){
      vertexs[i][0] += d[0];
      vertexs[i][1] += d[1];
      vertexs[i][2] += d[2];
   }
}

void Figure3d::move(int type, int direction){
   d[0] += direction*I[type];
   d[1] += direction*J[type];
   d[2] += direction*K[type];
   for(int i=0; i<vertex_num; i++){
      vertexs[i][0] += direction*I[type];
      vertexs[i][1] += direction*J[type];
      vertexs[i][2] += direction*K[type];
   }
}

void Figure3d::draw(int type){
   int k;
   setcolor(LIGHTGRAY);
   setfillstyle(SOLID_FILL, WHITE);
   switch(type){
      case 0:
         for(int i=0; i<surface_num; i++){
            k = 0;
            for(int j=0; j<4; j++){
               p[2*k] = WIDTH/4 + vertexs[surfaces[i][j]][0];
               p[2*k+1] = HEIGHT/2 - vertexs[surfaces[i][j]][1];
               k++;
            }
            drawpoly(k, p);
         }
         break;
      case 1:
         for(int i=0; i<surface_num; i++){
            k = 0;
            for(int j=0; j<4; j++){
               p[2*k] = WIDTH/2 + vertexs[surfaces[i][j]][0];
               p[2*k+1] = 5*HEIGHT/8 - vertexs[surfaces[i][j]][2];
               k++;
            }
            drawpoly(k, p);
         }
         break;
      case 2:
         for(int i=0; i<surface_num; i++){
            k = 0;
            for(int j=0; j<4; j++){
               p[2*k] = 3*WIDTH/4 + vertexs[surfaces[i][j]][1];
               p[2*k+1] = 5*HEIGHT/8 - vertexs[surfaces[i][j]][2];
               k++;
            }
            drawpoly(k, p);
         }
         break;
   }
}