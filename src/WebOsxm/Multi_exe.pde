interface Multi
{
  void handle(String command);
}

// structure to store information

class Multi_exe implements Multi
{
  // well, I admit this is really not easy to do
  int task_count = 0;
  int left_register_index = 1;
  int left_register_sum = 1;
  int right_register_index = 1;
  int right_register_sum = 1;
  int cmd_register_index = 1;
  int cmd_register_sum = 1;
  
  void draw_hint()
  {
     fill(120,120,120);
     for(int i=1;i<=left_register_sum;i++)
     {
       ellipse(20+10*i,600,7,7); 
     }
     fill(255,0,0);
     ellipse(20+10*this.left_register_index,600,9,9);  
     
     fill(120,120,120);
     for(int i=1;i<=right_register_sum;i++)
     {
       ellipse(680+10*i,390,7,7); 
     }
     fill(0,255,0);
     ellipse(680+10*this.right_register_index,390,9,9);  

     fill(120,120,120);
     for(int i=1;i<=cmd_register_sum;i++)
     {
       ellipse(680+10*i,620,7,7); 
     }
     fill(0,0,255);
     ellipse(680+10*this.cmd_register_index,620,9,9);       
  }
  
  void add_left_register()
  {
    this.left_register_index++;
  }
  
  void add_right_register()
  {
    this.right_register_index++;
  }  
  
  void add_cmd_register()
  {
    this.cmd_register_index++;
  }
  
  void reduce_left_register()
  {
    if(this.left_register_index>1){
      this.left_register_index--;
    }
  }  
 
  void reduce_right_register()
  {
    if(this.right_register_index>1){
      this.right_register_index--;
    }
  }  
  
  void reduce_cmd_register()
  {
    if(this.cmd_register_index>1){
      this.cmd_register_index--;
    }
  }  
  
  String get_left_index()
  {
    return String.valueOf(this.left_register_index);
  }
    
  String get_right_index()
  {
    return String.valueOf(this.right_register_index);
  }

  String get_cmd_index()
  {
    return String.valueOf(this.cmd_register_index);
  }
  
  void set_draw(boolean whethertrue)
  {
    main.sys_signal.set_boolean_signal("draw_progress",whethertrue);
  }
  
  int get_count()
  {
    return this.task_count; 
  }
  
  void handle(String command)
  {
      // only handle when there is something to be handled
      // here firstly we draw a progress bar
       if(command.equals("right_key")){
         if(main.parsexml.GetStringValue("current_focus").equals("cmd")){
           this.add_cmd_register();
           if(cmd_register_index>cmd_register_sum){
             cmd_register_sum++;
             main.dataiseverything.StoreData("cmd",this.cmd_register_index-1,main.sys_commander.getcommands());
             ArrayList<String> emptyarray = new ArrayList<String>();
             emptyarray.add("Now I am empty, try fill me with fun..");
             main.dataiseverything.StoreData("cmd",this.cmd_register_index,emptyarray);
             main.sys_commander.handle("clc");       
           }  
           else{
             main.sys_commander.setcommands(main.dataiseverything.LoadData("cmd",this.cmd_register_index));
           }         
         }
         
         if(main.parsexml.GetStringValue("current_focus").equals("right")){
           this.add_right_register();
           if(right_register_index>right_register_sum){
             right_register_sum++;
             main.dataiseverything.StoreData("right",this.right_register_index-1,main.listor.get_current_right_list());
             ArrayList<String> emptyarray = new ArrayList<String>();
             emptyarray.add("Now I am empty, try fill me with fun..");
             main.dataiseverything.StoreData("right",this.right_register_index,emptyarray);             
             main.sys_commander.handle("clc");       
           }  
           else{
             main.listor.set_current_right_list(main.dataiseverything.LoadData("right",this.right_register_index));
           }         
         }
         
         if(main.parsexml.GetStringValue("current_focus").equals("left")){
           // first do something with left
           this.add_left_register();
           if(left_register_index>left_register_sum){
             left_register_sum++;
             main.sys_signal.process_watcher.add("false");
             main.sys_commander.handle("clc");       
           }
           else{
             if(main.sys_signal.process_watcher.get(this.left_register_index-1).equals("true")){
                 main.listor.set_current_left_list(main.dataiseverything.LoadData("left",this.left_register_index));
             }
             else{
               if(main.sys_signal.sendout_boolean_signal("offline")==true){
                 File testfile = new File(sketchPath+"/"+"left"+String.valueOf(this.left_register_index));
                 if(testfile.exists()){
                   main.listor.set_current_left_list(main.dataiseverything.LoadData("left",this.left_register_index));
                 }
               }
               else{                
                 main.sys_commander.handle("clc");       
               }
             }
           }
         }       
       }
       if(command.equals("left_key")){
          if(main.parsexml.GetStringValue("current_focus").equals("cmd")){
           // first do something with left
           this.reduce_cmd_register();
            main.sys_commander.setcommands(main.dataiseverything.LoadData("cmd",this.cmd_register_index));
         }    
          if(main.parsexml.GetStringValue("current_focus").equals("right")){
           // first do something with left
           this.reduce_right_register();
            main.listor.set_current_right_list(main.dataiseverything.LoadData("right",this.right_register_index));
         }               
          if(main.parsexml.GetStringValue("current_focus").equals("left")){
           // first do something with left
           this.reduce_left_register();
           if(main.sys_signal.process_watcher.get(this.left_register_index-1).equals("true")){
             main.listor.set_current_left_list(main.dataiseverything.LoadData("left",this.left_register_index));
           }
           else{
                 if(main.sys_signal.sendout_boolean_signal("offline")==true){
                     File testfile = new File(sketchPath+"/"+"left"+String.valueOf(this.left_register_index));
                     if(testfile.exists()){
                     main.listor.set_current_left_list(main.dataiseverything.LoadData("left",this.left_register_index));
                   }
                 }
               else{
                   main.sys_commander.handle("clc");   
               }
           }
         }               
       }
       
       if(command.equals("lsscript")){     
            main.listor.set_current_right_list(main.script.LoadScript());
            main.sys_signal.set_String_signal("handle_info","ls : it goes well"); 
       } 
  }
}




// this class handle for the progress thing
// the example codes implementing this class are as follows:
/*
  this.progress.setValue(j);
  this.progress.draw_me(); 
*/

public class TProgressBar
{
  
  private int x;
  
  private int y;
  
  private int maxWidth;
  
  private int heightProgress;
    
  private float value;
  
  private color backgroundColor;
  
  private color progressColor;
  
  boolean draw = false;
  
  public TProgressBar(int maxWidth,int heightProgress,int x, int y)
  {
    
    this.maxWidth=maxWidth;
    
    this.heightProgress=heightProgress;
    
    this.x=x;
    
    this.y=y;
    
    this.value=x;
   
    this.backgroundColor=color(182,205,250,120);
   
    this.progressColor=color(245,194,31);
   
  }
  
  public void setMaxWidth(int maxWidth)
  {
    this.maxWidth=maxWidth;
  }
  
  public void setHeightProgress(int heightProgress)
  {
    this.heightProgress=heightProgress;
  }
  
  public void setX(int x)
  {
    this.x=x;
  }
  
  public void setY(int y)
  {
    this.y=y;
  }
  
  public void setBackgroundColor(color backgroundColor)
  {
    this.backgroundColor=backgroundColor;
  }
  
  
  public void setProgressColor(color progressColor)
  {
    this.progressColor=progressColor;
  }
  
  public int percentage()
  { 
   return (int)( (  this.value * 100 )/this.maxWidth ) ;  
  }
  
  
  public void setValue(float value)
  {
    if( value <= this.maxWidth )
      {
        this.value=value;
      }
     else
      {
       //  println("valor es mayor que el limite(maxWidth) de la barra de progreso.");
      } 
  }
  
  void begindraw()
  {
    this.draw = true;
  }
  
  void enddraw()
  {
    this.draw = false;
  }
  
 public void draw_me()
 {
  if(draw){   
        fill(this.backgroundColor);
     
        rect(this.x,this.y,this.maxWidth,20);
     
        fill(this.progressColor);
        
        rect(this.x,this.y,this.value,20);
    
        fill(0,0,255);
        
        text("process: "+percentage() + " %",this.x+this.maxWidth/2-40,this.y-30);
  }
 } 

}
