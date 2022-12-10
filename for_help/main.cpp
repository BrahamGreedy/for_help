#include "task.h"
#include "control.h"

void draw_bg(){
   set_bg("bg.jpg");
   create_control(X_ROTATE, 0, 750, "xr.jpg");
   create_control(Y_ROTATE, 113, 750, "yr.jpg");
   create_control(Z_ROTATE, 226, 750, "zr.jpg");
   create_control(X_MOVE, 339, 750, "xm.jpg");
   create_control(Y_MOVE, 452, 750, "ym.jpg");
   create_control(Z_MOVE, 565, 750, "zm.jpg");
   create_control(SAVE, 678, 750, "save.jpg");
   create_control(EXIT, 791, 750, "exit.jpg");
}

int main(){
   initwindow(WIDTH, HEIGHT);
   draw_bg();
   Figure3d figure = Figure3d();
   figure.draw(0);
   while(1){
      while(mousebuttons() != 1);
      switch(select_control()){
         case X_ROTATE:
            figure.rotate(0);
            draw_bg();
            figure.draw(0);
            break;
         case Y_ROTATE:
            figure.rotate(1);
            draw_bg();
            figure.draw(0);
            break;
         case Z_ROTATE:
            figure.rotate(2);
            draw_bg();
            figure.draw(0);
            break;
         case X_MOVE:
            figure.move(0, 1);
            draw_bg();
            figure.draw(0);
            break;
         case Y_MOVE:
            figure.move(1, 1);
            draw_bg();
            figure.draw(0);
            break;
         case Z_MOVE:
            figure.move(2, 1);
            draw_bg();
            figure.draw(0);
            break;
         case SAVE:
            save();
            break;
         case EXIT:
            return 0;
      }
   }
}