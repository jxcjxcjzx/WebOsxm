class sys_reminder_drawer implements sys_reminders
{
    String print_info;
    sys_reminder_drawer(){
      this.print_info = "";
    }
    void reset(){
    }
    void draw_bar(){
      fill(240,227,227);
      rect(0,height-20,width/2,20);
      fill(0,0,0);
      text(this.print_info,10,height-5);
    }
    void clear_bar(){
    }
    void set_reminder(String info){
      this.print_info = info;
    }
}

class sys_func implements system_functions
{
   TProgressBar  bar;
   
   // here we provide the function to show progress bar
   void initial()
   {
     bar = new TProgressBar(400,20,100,400);
   }
   
   boolean checklink()
   {
     boolean forreturn = true;
     try { 
      String strUrl = "http://www.baidu.com";     
      URL url = new URL(strUrl);  
      new InputStreamReader(url.openStream(),"utf-8");
     }
     catch (IOException e) {           
          forreturn = false;  
     }    
     return forreturn;
   }

    boolean check_length(ArrayList<String> for_check,int require)
    {
       boolean forreturn = true;
       if(require-1>for_check.size()){
         forreturn = false;
       }
       return forreturn;
    }
    
    void roundrect(int x1,int y1,int x2,int y2)
    {
    int radiushere = 20;
    rect(x1,y1+radiushere,x2-x1,y2-y1-2*radiushere);
    rect(x1+radiushere,y1,x2-x1-2*radiushere,y2-y1);
    ellipse(x1+radiushere,y1+radiushere,radiushere*2,radiushere*2);
    ellipse(x1+radiushere,y2-radiushere,radiushere*2,radiushere*2);
    ellipse(x2-radiushere,y1+radiushere,radiushere*2,radiushere*2);
    ellipse(x2-radiushere,y2-radiushere,radiushere*2,radiushere*2);
    }


}


class sys_signal_manager implements sys_signals
{
  String program_table[] = {"%jxc%","%Jxc%","%jXc%","%jxC%","%JXc%","%jXC%","%JxC%","%JXC%"};
  ArrayList<String> boolean_table = new ArrayList<String>();
  ArrayList<String> int_table = new ArrayList<String>();
  ArrayList<String> String_table = new ArrayList<String>();  
  // this is for the multi task
  ArrayList<String> process_watcher = new ArrayList<String>();
  
  boolean []boolean_signal = new boolean[7];
  int []int_signal = new int[16];
  String []String_signal = new String[2];
  
  void set_process(int index,String a)
  {
    if(a.equals("true")&&index<this.process_watcher.size()){
       this.process_watcher.set(index,"true");
    }
    else{
      if(index<this.process_watcher.size()){
        this.process_watcher.set(index,"false");
      }
    }
  }
  
   sys_signal_manager(){
     // here we add all the variables possiblely used by user
     boolean_table.add("delayed");  // this variable is for the opening of the OS
     boolean_table.add("w_keyPressed");
     boolean_table.add("ChineseNow");
     boolean_table.add("draw_progress");
     boolean_table.add("offline");
     boolean_table.add("stepexecute");     
     boolean_table.add("BoardUse");
     int_table.add("back_r");     
     int_table.add("back_g");     
     int_table.add("back_b"); 
     int_table.add("left_list_x");     
     int_table.add("left_list_y");
     int_table.add("right_list_x");
     int_table.add("right_list_y");   
     int_table.add("command_list_x");
     int_table.add("command_list_y");     
     int_table.add("left_scroll"); 
     int_table.add("right_scroll");      
     int_table.add("right_up_brim");
     int_table.add("right_down_brim");     
     int_table.add("cmd_up_brim"); 
     int_table.add("cmd_down_brim");     
     int_table.add("step_index");
     String_table.add("remind_info");    // delete it in the release edition
     String_table.add("handle_info"); 
  }
  void reset(){
  }
  
  void initial()
  {
    for(int i=0;i<boolean_signal.length;i++){
      boolean_signal[i] = false;
    }
    for(int j=0;j<int_signal.length;j++){
      int_signal[j] = 0;
    }
    for(int k=0;k<String_signal.length;k++){
      String_signal[k] = "";
    }
    this.process_watcher.add("false");
  }
  
  void set_boolean_signal(String info,boolean whethertrue){
     if(boolean_table.contains(info)){
       this.boolean_signal[boolean_table.indexOf(info)] = whethertrue;
     }
  }
  void set_int_signal(String info,int value){
     if(int_table.contains(info)){
       this.int_signal[int_table.indexOf(info)] = value;
     }
  }
  void set_String_signal(String info,String value){
       if(String_table.contains(info)){
       this.String_signal[String_table.indexOf(info)] = value;
     }
  }
  String sendout_String_signal(String command){
    String forreturn = "";
     if(String_table.contains(command)){
       forreturn = this.String_signal[String_table.indexOf(command)];
     }
    return forreturn;
  }
  boolean sendout_boolean_signal(String command){
    boolean forreturn = false;
     if(boolean_table.contains(command)){
       forreturn = this.boolean_signal[boolean_table.indexOf(command)];
     }
    return forreturn;
  }
  int sendout_int_signal(String command){
    int forreturn = 0;
     if(int_table.contains(command)){
       forreturn = this.int_signal[int_table.indexOf(command)];
     }
    return forreturn;
  }
}
