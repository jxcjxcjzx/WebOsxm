interface extend_frame
{
   void start_show();
   void change_of_show();
   void end_show();
}

class DashBoard implements extend_frame
{
    boolean whether_show = false;
    void start_show()
    {
      this.whether_show = true;
    }
     
     void change_of_show()
     {
        if(this.whether_show)
        {
          // handling in the show
          fill(255,255,255);
          main.sysfunc.roundrect(30,30,width-30,height-30);
          
        }
        else{        
        }
     }
     
     void end_show()
     {
       this.whether_show = false;
     }
}




