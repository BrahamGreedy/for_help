#include "graphics.h"
#include "control.h"

Control controls[N_CONTROLS];

void create_control(int i, int left, int top,
                    const char *file_name)
{
   IMAGE *image;
   
   image = loadBMP(file_name);
   putimage(left, top, image, COPY_PUT);
   
   controls[i].left   = left;
   controls[i].top    = top;
   controls[i].right  = left + 112;
   controls[i].bottom = top  + 50;
   freeimage(image);
}

int select_control()
{
   int x, y;
   
   x = mousex();
   y = mousey();
   
   for (int i = 0; i < N_CONTROLS; i++)
   {
      if (x > controls[i].left && x < controls[i].right &&
          y > controls[i].top  && y < controls[i].bottom)
      {
         return i;
      }
   }
   
   return NONE;
}

void set_bg(const char* name){
   IMAGE *image;
   image = loadBMP(name);
   putimage(0, 0, image, COPY_PUT);
   freeimage(image);
}

void save(){
   IMAGE *output;
   output = createimage(WIDTH+1, HEIGHT+1);
   getimage(0, 0, WIDTH, HEIGHT, output);
   saveBMP("output.jpg", output);
   freeimage(output);
}