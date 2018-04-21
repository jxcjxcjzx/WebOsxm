// here we did all the drawing work through the draw_things interface provided
// by the Os main class page

class sys_title implements draw_in_main
{
   String os_title = "";
   void draw_things()
   {
     os_title = "I am Web OS _xm 1.0, Welcome";   
     text(os_title,width/2-80,height/2-3);
   }
   void clean_title()
   {
     os_title = "";
   }
}
