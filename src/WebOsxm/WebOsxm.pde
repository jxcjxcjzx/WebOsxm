// system starts from here
OS_main main = new OS_main();

// one pic variable for special use
PImage newyear;

void setup()
{
    // basic system showframe
   smooth();
   noStroke(); 
   size(1280,640);
   frameRate(60);
   main.setup();
   
   // special use in special days
    newyear = loadImage("yaan.jpg");
    
}

void draw()
{
  main.draw();
}

void keyPressed()
{
  main.sys_signal.set_boolean_signal("w_keyPressed",true);
}
/**
testing tips:
// when you want to do some testing work, we provided you with 
// the awesome tool : sys_remind,and the typical use of that will
// be as the following: 
//   sys_remind.set_reminder("hello");  here the "hello" will be the info 
// you get interested in, and in each frame we provided the 
// send_out_info() function, and this acts as the bridge between
// this two things, all for testing
**/

class OS_main
{
  // try to give a management of the whole system
      ArrayList<String> left_pre = new ArrayList<String>();
      ArrayList<String> right_pre = new ArrayList<String>();          
      InfoView sys_viewer = new InfoView();
      CommandView sys_commander = new CommandView();     
      XmlChannel parsexml = new XmlChannel(); 
      SrciptMan script = new SrciptMan();
      sys_reminder_drawer sys_remind = new sys_reminder_drawer();
      sys_signal_manager sys_signal = new sys_signal_manager(); 
      sys_func sysfunc = new sys_func();
      LinkGet access = new LinkGet();
      StringBuilder forshow = new StringBuilder();  // this String is responsible for the input management
      ListManager listor = new ListManager();
      Multi_exe multi = new Multi_exe(); // multi-handle class, the most valuable one
      DashBoard paper = new DashBoard();
      PicShow pic = new PicShow();
      SearchMan searchit = new SearchMan();
      Baike find = new Baike();
      BillBoard whiteboard = new BillBoard();
      ChineseIn zhong = new ChineseIn();
      Dator dataiseverything = new Dator();
      
      void setup()
      {        
        //testing point       
        // get set info through .xml file access
        // initial work
        sys_signal.initial();
        sysfunc.initial();
        dataiseverything.initial();
        sys_viewer.arrange_left_frame(parsexml.GetIntValue("left_frame_x"),parsexml.GetIntValue("left_frame_y"),
        parsexml.GetIntValue("left_frame_width"),parsexml.GetIntValue("left_frame_height"));
        sys_viewer.arrange_right_frame(parsexml.GetIntValue("right_frame_x"),parsexml.GetIntValue("right_frame_y"),
        parsexml.GetIntValue("left_frame_width"),parsexml.GetIntValue("left_frame_height")-parsexml.GetIntValue("result_frame_height_adapt"));    
        sys_commander.arrange_right_frame(parsexml.GetIntValue("command_frame_x"),parsexml.GetIntValue("command_frame_y"),
        parsexml.GetIntValue("command_frame_width"),parsexml.GetIntValue("command_frame_height"));   
        
        // set the background color info
        sys_signal.set_int_signal("back_r",parsexml.GetIntValue("backcolor_red"));
        sys_signal.set_int_signal("back_g",parsexml.GetIntValue("backcolor_green"));
        sys_signal.set_int_signal("back_b",parsexml.GetIntValue("backcolor_blue"));
        sys_signal.set_int_signal("left_list_x",parsexml.GetIntValue("left_list_x"));
        sys_signal.set_int_signal("left_list_y",parsexml.GetIntValue("left_list_y"));        
        sys_signal.set_int_signal("right_list_x",parsexml.GetIntValue("right_list_x"));
        sys_signal.set_int_signal("right_list_y",parsexml.GetIntValue("right_list_y")); 
        sys_signal.set_int_signal("command_list_x",parsexml.GetIntValue("command_list_x"));
        sys_signal.set_int_signal("command_list_y",parsexml.GetIntValue("command_list_y"));         
        sys_signal.set_int_signal("right_up_brim",parsexml.GetIntValue("right_up_brim"));    
        sys_signal.set_int_signal("right_down_brim",parsexml.GetIntValue("right_down_brim"));      
        sys_signal.set_int_signal("cmd_up_brim",parsexml.GetIntValue("cmd_up_brim"));    
        sys_signal.set_int_signal("cmd_down_brim",parsexml.GetIntValue("cmd_down_brim"));              
        // testing ArrayList area
        right_pre.add("hello,jxc, ncie meeting you...");
        
        // testing point
        left_pre.add("hello，I am WebOS_xm，now begin with your nice journey!");
//        sys_remind.set_reminder(access.send_out_info());
      }
      
      void draw()
      {
        
        // testing point
        // the background
        background(sys_signal.sendout_int_signal("back_r"),sys_signal.sendout_int_signal("back_g"),
        sys_signal.sendout_int_signal("back_b"));   
        
        if(listor.current_list.isEmpty()){
          sys_viewer.list_for_left(left_pre,sys_signal.sendout_int_signal("left_list_x")
          ,sys_signal.sendout_int_signal("left_list_y"));   
        }
        else{
          sys_viewer.list_for_left(listor.get_current_list(),sys_signal.sendout_int_signal("left_list_x")
          ,sys_signal.sendout_int_signal("left_list_y")-sys_signal.sendout_int_signal("left_scroll"));             
        }
        if(listor.current_list.isEmpty()){
          sys_viewer.list_for_right(right_pre,sys_signal.sendout_int_signal("right_list_x")
          ,sys_signal.sendout_int_signal("right_list_y"),sys_signal.sendout_int_signal("right_up_brim")
          ,sys_signal.sendout_int_signal("right_down_brim"));   
        }
        else{
          sys_viewer.list_for_right(listor.get_current_right_list(),sys_signal.sendout_int_signal("right_list_x")
          ,sys_signal.sendout_int_signal("right_list_y")-sys_signal.sendout_int_signal("right_scroll")
          ,sys_signal.sendout_int_signal("right_up_brim"),sys_signal.sendout_int_signal("right_down_brim"));             
        }     
        sys_commander.list_for_right(sys_commander.getcommands(),sys_signal.sendout_int_signal("command_list_x")
        ,sys_signal.sendout_int_signal("command_list_y")+30,sys_signal.sendout_int_signal("cmd_up_brim")
        ,sys_signal.sendout_int_signal("cmd_down_brim"));              
        sys_remind.draw_bar();
        
        fill(0,0,0);
        text(forshow.toString(),sys_signal.sendout_int_signal("command_list_x")
        ,sys_signal.sendout_int_signal("command_list_y"));
        
        // testing point
        
        // here manage the progress line showing task
        if(sys_signal.sendout_boolean_signal("draw_progress")){
            sysfunc.bar.setValue(multi.get_count());
            sysfunc.bar.draw_me(); 
        }
        
        multi.draw_hint();
        paper.change_of_show();
        whiteboard.change_of_show();
        pic.change_of_show();
        //here is the main ordering handle process       
        
        if(sys_signal.sendout_boolean_signal("w_keyPressed")){
          // handle with key in case:
          // the 'Alt' key controls the Chinese Input and English Input alter work
          if(!sys_signal.sendout_boolean_signal("ChineseNow")){
                    if(key>='a'&&key<='z'||key>='A'&&key<='Z'||key>='0'&&key<='9'||key==' '||key=='.'
                    ||key==':'||key=='/'||key=='\\'||key=='-'||key=='?'||key=='<'||key=='>'||key=='|'
                    ||key=='+'||key=='-'||key=='_'||key==';'||key=='='||key=='{'||key=='}'||key=='['
                    ||key==']'||key=='~'||key=='@'||key=='!'||key=='#'||key=='$'||key=='%'||key=='^'
                    ||key=='&'||key=='*'||key=='('||key==')'||key=='\''||key=='"'){
                       forshow.append(key);
                    }          
                    // set the Chinese In
                    if(keyCode==17){         
                         sys_signal.set_boolean_signal("ChineseNow",true);             
                    }                    
                    if(key=='\n'){
                       sys_commander.add_command(forshow.toString());
                       for(int program_count=0;program_count<sys_signal.program_table.length;program_count++){
                         if(forshow.toString().contains(sys_signal.program_table[program_count])){
                           String newone = forshow.toString().replaceAll(sys_signal.program_table[program_count],parsexml.GetStringValue(sys_signal.program_table[program_count].substring(1,4)));
                           forshow.delete(0,forshow.length());
                           forshow.append(newone);
                         }
                       }
                       sys_commander.handle(forshow.toString());
                       sys_remind.set_reminder(sys_signal.sendout_String_signal("handle_info"));
                       forshow.delete(0,forshow.length());
                       sys_commander.set_handle(false); 
                       sys_commander.command_count_reset();
                    }          
                    if(key=='\b'){
                      if(forshow.length()>0){
                        forshow.deleteCharAt(forshow.length()-1);
                      }
                    }
                    // left arrow key
                    if(keyCode==37){     
                      // left key        
                      // here lies the biggest matter                      
                      multi.handle("left_key");
                    }
                    // up arrow key
                    if(keyCode==38){
                      if(sys_signal.sendout_boolean_signal("BoardUse")){
                         main.whiteboard.handle("up");
                      }
                      else{
                        if(parsexml.GetStringValue("current_focus").equals("left")){
                          sys_signal.set_int_signal("left_scroll",sys_signal.sendout_int_signal("left_scroll")-9);
                        }          
                        if(parsexml.GetStringValue("current_focus").equals("cmd")){
                          forshow = new StringBuilder(sys_commander.pre_command());
                        }         
                        if(parsexml.GetStringValue("current_focus").equals("right")){
                          sys_signal.set_int_signal("right_scroll",sys_signal.sendout_int_signal("right_scroll")-9);
                        }    
                      }
                    }
                    // right arrow key
                    if(keyCode==39){
                      // right key
                      if(sys_signal.sendout_boolean_signal("stepexecute")){
                        sys_commander.handle("executestep");
                      }
                      else{
                        multi.handle("right_key");
                      }   
                    }
                    // down arrow key , get more view of it
                    if(keyCode==40){       
                      if(sys_signal.sendout_boolean_signal("BoardUse")){
                          main.whiteboard.handle("down");
                      }
                      else{      
                          if(parsexml.GetStringValue("current_focus").equals("left")){
                            sys_signal.set_int_signal("left_scroll",sys_signal.sendout_int_signal("left_scroll")+9);
                          }
                          if(parsexml.GetStringValue("current_focus").equals("cmd")){
                            forshow = new StringBuilder(sys_commander.for_command());
                          } 
                          if(parsexml.GetStringValue("current_focus").equals("right")){
                            sys_signal.set_int_signal("right_scroll",sys_signal.sendout_int_signal("right_scroll")+9);
                          }   
                      }           
                    }          
          }
          else{ 
              // deal with Chinese Input case
              if(keyCode==17){         
                  sys_signal.set_boolean_signal("ChineseNow",false);             
              }                
              if(zhong.jiexi().equals("success")){
                  forshow.append(zhong.getvalue());
              }
          }
          sys_signal.set_boolean_signal("w_keyPressed",false);
        }
        
        
        if(sys_signal.sendout_boolean_signal("ChineseNow")){     
             zhong.paint();  
        }
        
        // special show of images
         image(newyear,width/2-newyear.width/2,0);

      }
     

}
