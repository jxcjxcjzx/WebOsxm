import java.text.SimpleDateFormat;

interface viewFrame
{
  void arrange_right_frame(int beginx,int beginy,int right_width,int right_height);
  void list_for_right(ArrayList<String> obj,int right_up_y,int right_up_x,int brimup,int brimdown);
  void arrange_left_frame(int beginx,int beginy,int left_width,int left_height);
  void list_for_left(ArrayList<String> obj,int left_up_y,int left_up_x);   
  String send_out_info();
  void set_out_info(String info);
}


class InfoView implements viewFrame
{
  String out_info = "";
  int right_x = 0;
  int right_y = 0;
  int right_width = 0;
  int right_height = 0;
  
  int left_x = 0;
  int left_y = 0;
  int left_width = 0;
  int left_height = 0;
  
  void get_left_x(int loc){
    this.left_x = loc;
  }

  void get_left_y(int loc){
    this.left_y = loc;
  }

  void get_right_y(int loc){
    this.right_y = loc;
  }

  void get_right_x(int loc){
    this.right_x = loc;
  }  

  void get_left_width(int loc){
    this.left_width = loc;
  }  

  void get_left_height(int loc){
    this.left_height = loc;
  }  

  void get_right_width(int loc){
    this.right_width = loc;
  }  

  void get_right_height(int loc){
    this.right_height = loc;
  }  

  void arrange_right_frame(int beginx,int beginy,int right_width,int right_height){
    this.get_right_x(beginx);
    this.get_right_y(beginy);
    this.get_right_width(right_width);
    this.get_right_height(right_height);
  }
  void list_for_right(ArrayList<String> obj,int right_up_x,int right_up_y,int brimup,int brimdown){
    fill(236,253,144);
    rect(this.right_x,this.right_y,this.right_width,this.right_height);    
    fill(0,0,0);
    // giving out the grapping result
    if(obj.isEmpty()){
          this.set_out_info("Sorry, I get nothing to show...");
        }
        else{
          // show the result
          int starty = right_up_y;
          int startx = right_up_x;
          for(int i=0;i<obj.size();i++){
            if((starty+i*20>brimup)&&(starty+i*20<brimdown)){
              // show line length control
              if(obj.get(i).length()>95){
                text(String.valueOf(i+1)+". "+obj.get(i).substring(0,94),startx,starty+i*20);
              }
              else{
                text(String.valueOf(i+1)+". "+obj.get(i),startx,starty+i*20);
              }          
            }
          }
        }    
  }
  void arrange_left_frame(int beginx,int beginy,int left_width,int left_height){
    this.get_left_x(beginx);
    this.get_left_y(beginy);
    this.get_left_width(left_width);
    this.get_left_height(left_height);

  }
  void list_for_left(ArrayList<String> obj,int left_up_x,int left_up_y){
    fill(255,223,176);
    rect(this.left_x,this.left_y,this.left_width,this.left_height);
    fill(0,0,0);
    // giving out the grapping result
    if(obj.isEmpty()){
      this.set_out_info("Sorry, I get nothing to show...");
    }
    else{
      // show the result
      int starty = left_up_y;
      int startx = left_up_x;
      for(int i=0;i<obj.size();i++){
        if((starty+i*20>20)&&(starty+i*20<height-40)){
          // show line length control
          if(obj.get(i).length()>65){
            text(String.valueOf(i+1)+". "+obj.get(i).substring(0,64),startx,starty+i*20);
          }
          else{
            text(String.valueOf(i+1)+". "+obj.get(i),startx,starty+i*20);
          }          
        }
      }
    }
  }
  
  String send_out_info(){
    return this.out_info;
  }
  
  void set_out_info(String info){
    this.out_info = info;
  }
  
}


class CommandView extends InfoView   // here this is the basic and the most useful thing for input
{
  String TagPath = "F:/WebOSIndex/WebOSTag/"; 
  ArrayList<String> commands = new ArrayList<String>();
  ArrayList<String> for_execute = new ArrayList<String>();
  String currentcommand = "";
  boolean handled = false;
  int command_count = 0;
  
  String[] command_help = {"geturl","getfile","set","ls","backup","jump","rm","clc","filter","store","geturls","execute","help","find"};

  String[] command_content = {"get content in the url specified \n for emample ; typein geturl www.xxx.com \n if you want to something from the xxx website",
  "open a file \n for example : getfile f:/xxx.xxx.txt(now the txt is the only \n supproted format)",
  "set the display and operate mode things  \n you can do the followings : \n setsearchengine google or baidu or sina or sohu or 163  \n setmode single or multi  \n setfocus left or right or cmd  \n setway gbk or utf-8 or nothing",
  "check the set before  \n you can do the following ls : \n  lsmod(see the mod single or multi)  \n lsway(see the way you get urls)  \n lsfocus(see where the focus is now)  \n lstask(see the tasks you assigned)",
  "copy and make a store in case","like a scroll for view \n for example :   jumpleft 100(jump down in the left window)  \n jumpright 100(well you get it)",
  "used for handle html things \n for example :  \n rmtags(remove the html tags for you)  \n rmblank(blanks are not needed)"
  ,"move things away","leave things only related \n for example : filter xxx(just get lines with xxx)",
  "pick out things useful and important \n here you can do as :  \n storeit \n storeall \n storecmd(store the command for you) \n storescript(store as a script)",
  "get the url links in the page","to repeat the process stored from a script \n  but before that you will need to type in loadscript xxx","provide the help information","use engine to find things you want \n for example : \n fine xxx(get xxx with the searchengine)"};

//  first, we need to rewrite the showing text function

  void list_for_right(ArrayList<String> obj,int right_up_x,int right_up_y,int brimup,int brimdown){
    fill(236,253,144);
    rect(this.right_x,this.right_y,this.right_width,this.right_height);    
    fill(0,0,0);
    // giving out the grapping result
    if(obj.isEmpty()){
          this.set_out_info("Sorry, I get nothing to show...");
        }
        else{
          // show the result
          int starty = right_up_y;
          int startx = right_up_x;
          if(obj.size()<8){
            for(int i=0;i<obj.size();i++){
              text(String.valueOf(i+1)+". "+obj.get(i),startx,starty+i*20); 
            }
          }
          else{
            for(int i=obj.size()-7;i<obj.size();i++){
                  text(String.valueOf(i+1)+". "+obj.get(i),startx,starty+(i-(obj.size()-7))*20);        
            }
          }
        }    
  }



  ArrayList<String> getcommands()
  {
    return this.commands;
  }
  
  void setcommands(ArrayList<String> for_set)
  {
    this.commands = for_set;
  }  
  
  String pre_command(){
    String forreturn = "";
    if(command_count>0&&commands.size()>(command_count-1)){
      forreturn = commands.get(command_count-1);
      command_count--;
    }
    return forreturn;
  }
  String for_command(){
    String forreturn = "";
    if(command_count<this.commands.size()-1){
      forreturn = commands.get(command_count+1);
      command_count++;
    }
    return forreturn;
  }
  void command_count_reset()
  {
    this.command_count = this.commands.size();  
  }
  void add_command(String a){
    this.commands.add(a);
  }
  boolean get_handled()
  {
    return this.handled;
  }
  void set_handle(boolean a){
    this.handled = a;
  }  
  void handle(String command){
    // get function
    // testing point

    // fast execute area
    if(command.length()==1){
      if(command.equals("l")){
        command = "setfocus left";
      }
      if(command.equals("r")){
        command = "setfocus right";
      }    
      if(command.equals("c")){
        command = "setfocus cmd";
      }   
      if(command.equals("e")){
        command  = "execute";
      } 
    }
    // here we provide the test command
    if(command.equals("test")){
       // you can put your test code here, anything you like
    }
    // first we do some judgement for proper use of programming
    if(command.startsWith("geturl ")){
         if(main.parsexml.GetStringValue("mode").equals("single")){
                    if(command.contains(" ")){
                      if(main.sysfunc.checklink()){          
                        String theway = main.parsexml.GetStringValue("url_get_way");
                        String []fenge = command.split(" ");
                        main.sys_signal.set_String_signal("handle_info","geturl: Getting the url address : "+"http://"+fenge[1]+" for you");
                        main.listor.set_current_url("http://"+fenge[1]);
                        loadThread begin_load = new loadThread("left"+main.multi.get_left_index(),fenge[1],theway,"left"+main.multi.get_left_index(),"http://",Integer.parseInt(main.multi.get_left_index())-1);
                        Thread t = new Thread(begin_load,"xiancheng");
                        t.setDaemon(true);
                        t.start();         

                        SimpleDateFormat sdf_geturl = new SimpleDateFormat("yyy_MM_dd_HH_mm_ss");
                        String ss_geturl = sdf_geturl.format(new java.util.Date());                    
                        main.dataiseverything.StoreData("url_"+ss_geturl,fenge[1]);
                      }
                      else{          
                         main.sys_signal.set_String_signal("handle_info","Sorry,net connection unbuilt.....");
                      }
                    } 
         }
         // here we through it to the multi-mode handle function
         else{
                main.multi.handle(command);
         }
      
    }
    if(command.startsWith("getfile ")){
      // testing point
       if(command.contains(" ")){
          String theway = main.parsexml.GetStringValue("url_get_way");
          String []fenge = command.split(" ");
          main.listor.set_current_url("file:///"+fenge[1]);
          loadThread begin_load = new loadThread("left"+main.multi.get_left_index(),fenge[1],theway,"left"+main.multi.get_left_index(),"file:///",Integer.parseInt(main.multi.get_left_index())-1);
          Thread t = new Thread(begin_load,"xiancheng");
          t.setDaemon(true);
          t.start();                  
  
          SimpleDateFormat sdf_getfile = new SimpleDateFormat("yyy_MM_dd_HH_mm_ss");
          String ss_getfile = sdf_getfile.format(new java.util.Date());                    
          main.dataiseverything.StoreData("url_"+ss_getfile,fenge[1]);          
          main.sys_signal.set_String_signal("handle_info","getfile: Successful handled, thank you...");
      }
      else{
        main.sys_signal.set_String_signal("handle_info","get : Sorry, you type in wrong command.....");
      }
    }    
    // set function
    if(command.startsWith("set")){
              if(command.startsWith("setsearchengine ")){
                      if(command.contains(" ")&&(command.contains("baidu")||command.contains("sina")||
                      command.contains("souhu")||command.contains("google")||command.contains("163"))){
                        String []fenge = command.split(" ");
                        main.parsexml.SetStringValue("searchengine",fenge[1]);
                        main.sys_signal.set_String_signal("handle_info","set: Successful handled, thank you...");
                      }
                      else{
                        main.sys_signal.set_String_signal("handle_info","set : Sorry, you type in wrong command or we do not give full support.....");
                      }
              }              
              // set the handleing mode, single or multi
              if(command.startsWith("setmode ")){
                      if(command.contains(" ")){
                        String []fenge = command.split(" ");
                        if(fenge[1].equals("single")){
                            main.parsexml.SetStringValue("mode","single");
                        }                        
                        if(fenge[1].equals("multi")){
                            main.parsexml.SetStringValue("mode","multi");
                        }
                        main.sys_signal.set_String_signal("handle_info","set: Successful handled, thank you...");
                      }
                      else{
                        main.sys_signal.set_String_signal("handle_info","set : Sorry, you type in wrong command.....");
                      }      
              }    
              if(command.startsWith("setfocus ")){
                      if(command.contains(" ")){
                        String []fenge = command.split(" ");
                        main.parsexml.SetStringValue("current_focus",fenge[1]);
                        main.sys_signal.set_String_signal("handle_info","set: Successful handled, thank you...");
                      }
                      else{
                        main.sys_signal.set_String_signal("handle_info","set : Sorry, you type in wrong command.....");
                      }      
              }   
              // set the getting url way , for example: gbk, utf-8 or nothing              
              if(command.startsWith("setway ")){
                      if(command.contains(" ")){
                        String []fenge = command.split(" ");
                        if(!fenge[1].equals("utf-8")&&!fenge[1].equals("gbk")){
                          fenge[1] = "nothing";
                        }
                        main.parsexml.SetStringValue("url_get_way",fenge[1]);
                        main.sys_signal.set_String_signal("handle_info","set: Successful handled, thank you...");
                      }
                      else{
                        main.sys_signal.set_String_signal("handle_info","set : Sorry, you type in wrong command.....");
                      }      
              }  
      }
      if(command.startsWith("ls")){
               // quick ls 
                if(!command.contains(" ")){
                    if(command.equals("lsmod")){
                      main.sys_signal.set_String_signal("handle_info",main.parsexml.GetStringValue("mode"));
                      set_handle(true);
                    }
                    if(command.equals("lsway")){
                      main.sys_signal.set_String_signal("handle_info",main.parsexml.GetStringValue("url_get_way"));
                      set_handle(true);                      
                    }
                    if(command.equals("lsfocus")){
                      main.sys_signal.set_String_signal("handle_info",main.parsexml.GetStringValue("current_focus"));
                      set_handle(true);                      
                    }
                    if(command.equals("lsscript")){
                      main.multi.handle(command);
                      set_handle(true);     
                    }
                    if(!get_handled()){
                       main.sys_signal.set_String_signal("handle_info","ls : Sorry, you type in wrong command.....");
                    }
                }
                if(command.contains(" ")){
                   main.sys_signal.set_String_signal("handle_info","ls: Successful handled, thank you...");
                }
      }   
      if(command.startsWith("tag ")){
         String []fenge = command.split(" ");
         if(fenge.length == 2){
            ArrayList<String> trans = main.listor.get_current_list();
            String resul[] = new String[trans.size()];
            for(int i=0;i<resul.length;i++){
              resul[i] = trans.get(i);
            }
            saveStrings(TagPath+fenge[1],resul);
            main.sys_signal.set_String_signal("handle_info","tag: Successful handled, thank you...");
         }
         else{
           main.sys_signal.set_String_signal("handle_info","tag : Sorry, you type in wrong command.....");
         }
      }
      if(command.startsWith("throw ")){
        String []fenge = command.split(" ");
        if(fenge.length == 2){
           main.listor.remove_from_left(fenge[1]);  
        }
        else{
        }
      }
      if(command.startsWith("differ ")){
         String []fenge = command.split(" ");
         if(fenge.length == 2){
            File judge = new File(TagPath+fenge[1]);
            if(judge.exists()){
              String loadin[] = loadStrings(TagPath+fenge[1]);
              ArrayList<String> bidui = new ArrayList<String>();
              for(int j=0;j<loadin.length;j++){
                bidui.add(loadin[j]);
              }
              ArrayList<String> bidui2 = main.listor.get_current_list();
              ArrayList<String> resul = new ArrayList<String>();
              for(int k=0;k<bidui2.size();k++){
                if(!bidui.contains(bidui2.get(k))){
                  resul.add(bidui2.get(k));
                }
              }              
              main.listor.set_current_left_list(resul);
            }
            main.sys_signal.set_String_signal("handle_info","differ: Successful handled, thank you...");
         }
         else{
           main.sys_signal.set_String_signal("handle_info","differ : Sorry, you type in wrong command.....");
         }
      }            
      if(command.startsWith("variable ")){
         String []fenge = command.split(" ");
          if(fenge.length == 2&&fenge[1].length()==3){
            if((fenge[1].charAt(0)=='j'||fenge[1].charAt(0)=='J')&&
            (fenge[1].charAt(1)=='x'||fenge[1].charAt(1)=='X')&&
            (fenge[1].charAt(2)=='c'||fenge[1].charAt(2)=='C')){
               main.sys_signal.set_String_signal("handle_info","locate : the variable you want : "+main.parsexml.GetStringValue(fenge[1]));
            }
            else{
              main.sys_signal.set_String_signal("handle_info","variable : Sorry, you type in wrong command.....");
            }
         }         
         else{
           if(fenge.length == 3&&fenge[1].length()==3){
             if((fenge[1].charAt(0)=='j'||fenge[1].charAt(0)=='J')&&
              (fenge[1].charAt(1)=='x'||fenge[1].charAt(1)=='X')&&
              (fenge[1].charAt(2)=='c'||fenge[1].charAt(2)=='C')){
                 main.parsexml.SetStringValue(fenge[1],fenge[2]);
                 main.sys_signal.set_String_signal("handle_info","variable: Successful handled, thank you...");
              }
              else{
                main.sys_signal.set_String_signal("handle_info","variable : Sorry, you type in wrong command.....");
              }
           }  
           else{
             main.sys_signal.set_String_signal("handle_info","variable : Sorry, you type in wrong command.....");
           }
         }
      }      
      if(command.startsWith("backup")){
              if(command.contains(" ")){
                
                main.sys_signal.set_String_signal("handle_info","backup: Successful handled, thank you...");
              }
              else{
                main.sys_signal.set_String_signal("handle_info","Sorry, you type in wrong command.....");
              }      
      }      
      if(command.startsWith("jump")){
              if(command.contains(" ")){
                  if(main.parsexml.GetStringValue("current_focus").equals("cmd")){
                       String []fenge = command.split(" ");
                       if(command.startsWith("jumpleft")){
                          main.sys_signal.set_int_signal("left_scroll",main.sys_signal.sendout_int_signal("left_scroll")+3*Integer.parseInt(fenge[1]));
                       }
                       if(command.startsWith("jumpright")){
                          main.sys_signal.set_int_signal("right_scroll",main.sys_signal.sendout_int_signal("right_scroll")+3*Integer.parseInt(fenge[1]));
                       }                       
                  } 
                  main.sys_signal.set_String_signal("handle_info","jump: Successful handled, thank you...");
              }
              else{
                main.sys_signal.set_String_signal("handle_info","Sorry, you type in wrong command.....");
              }      
      }          
      if(command.startsWith("rm")){
              if(!command.contains(" ")){
                  if(command.equals("rmtags")){
                    main.listor.set_current_left_list(main.access.basichandle(main.listor.get_current_list()));
                    set_handle(true);                     
                  }
                  if(command.startsWith("rmblank")){
                    ArrayList<String> handle = main.listor.get_current_list();
                    for(int j=0;j<handle.size();j++){
                      if(handle.get(j).trim().equals("")||handle.get(j).equals("")){
                        handle.remove(j);
                      }                      
                    } 
                    main.listor.set_current_left_list(handle);                   
                    set_handle(true);                     
                  }
                  if(!get_handled()){
                    main.sys_signal.set_String_signal("handle_info","Sorry, you type in wrong command.....");
                  }                          
              }
              if(command.contains(" ")){
                String []fenge = command.split(" ");    
                if(fenge.length==2&&fenge[0].equals("rmscript")){            
                    main.script.DeleteScript(fenge[1]);
                    main.sys_signal.set_String_signal("handle_info","rm: Successful deleted, thank you...");
                }
                else{
                    main.sys_signal.set_String_signal("handle_info","rm: Well, something wrong happened.."); 
                }
              }  
      }   
      if(command.equals("clc")){
                ArrayList<String> empty = new ArrayList<String>();
                empty.add("Now I am empty, try fill me with fun..");
                ArrayList<String> empty2 = new ArrayList<String>();
                empty2.add("Now I am empty, try fill me with fun..");    
                ArrayList<String> empty3 = new ArrayList<String>();
                empty3.add("Now I am empty, try fill me with fun..");                   
          if(main.parsexml.GetStringValue("current_focus").equals("left")){            
                main.listor.set_current_left_list(empty);
          }
          if(main.parsexml.GetStringValue("current_focus").equals("right")){
                main.listor.set_current_right_list(empty2);          
          }
          if(main.parsexml.GetStringValue("current_focus").equals("cmd")){
                this.setcommands(empty3);        
          }          
                main.sys_signal.set_String_signal("handle_info","clear: Successful handled, thank you...");
      }  
      if(command.startsWith("loadscript")){    
               if(!command.contains(" ")){   
                   main.sys_signal.set_String_signal("handle_info","load: Sorry, nothing to be loaded...");
               }
               if(command.contains(" ")){
                   String []fenge = command.split(" ");  
                   this.for_execute = main.script.LoadScript(fenge[1]);
                   main.listor.add_to_right(this.for_execute);
                   main.sys_signal.set_int_signal("step_index",0);
                   main.sys_signal.set_String_signal("handle_info","load: Now, content are in the excuting array for you..");
               }
      
      }
      if(command.startsWith("change ")){
         // handle with some variables needd to be change in xml set file
         
      }      
      if(command.startsWith("filter")){
         if(main.parsexml.GetStringValue("mode").equals("single")){
                if(command.contains(" ")){
                  String []fenge = command.split(" ");            
                  main.listor.set_current_left_list(main.access.get_lines_with(main.listor.get_current_list(),fenge[1]));     
                  main.sys_signal.set_String_signal("handle_info","filter: Successful handled, thank you...");
                }
                if(!command.contains(" ")){
                  main.sys_signal.set_String_signal("handle_info","Sorry, you type in wrong command.....");
                }      
         }
         // here we through it to the multi-mode handle function
         else{
                main.multi.handle(command);
         }
      }  
      if(command.startsWith("open ")){
        String []fenge = command.split(" ");      
        if(fenge.length==2&&main.listor.get_current_right_list().size()>=Integer.parseInt(fenge[1])){
            try{
              URL url = new URL("file:///"+main.listor.get_current_right_list().get(Integer.parseInt(fenge[1])-1));         
              InputStreamReader isr = new InputStreamReader(url.openStream(),main.parsexml.GetStringValue("url_get_way"));
              BufferedReader br = new BufferedReader(isr); 
              String readincontent = "";
              ArrayList<String> forset = new ArrayList<String>();
              while((readincontent = br.readLine())!=null){                   
                      forset.add(readincontent);   
              }
              main.listor.set_current_left_list(forset);
              isr.close();
              br.close();
            }
            catch(Exception e){
            }
          }
          else{            
          }
      }
      if(command.startsWith("find")){
          // the search engine function
              if(!command.contains(" ")){   
                 main.sys_signal.set_String_signal("handle_info","Sorry, I do not know what you want to search for.....");
              }            
              if(command.contains(" ")){   
                        String []fenge = command.split(" ");   
                        if(2==fenge.length){
                         if(main.parsexml.GetStringValue("searchengine").equals("baidu")){
                              main.sys_commander.handle("geturl www.baidu.com/s?wd="+fenge[1]+"&n=2");
                         }                             
                         if(main.parsexml.GetStringValue("searchengine").equals("google")){
                              main.sys_commander.handle("geturl www.google.com.hk/#hl=zh-CN&newwindow=1&safe=strict&site=&source=hp&q="+fenge[1]+"&oq="+fenge[1]);
                         }
                         if(main.parsexml.GetStringValue("searchengine").equals("sina")){
                             main.sys_commander.handle("geturl search.sina.com.cn/?from=home&range=all&c=news&q="+fenge[1]);
                         }                     
                    }                 
              }
      }      
      if(command.startsWith("baike ")){
        String []fenge = command.split(" ");      
        if(fenge.length==2){
          String findaddr = main.find.handle(fenge[1]);  
          if(findaddr!="对不起，你的要求太过分了"&&findaddr.length()>7){
            main.sys_commander.handle("setway gbk");
            main.sys_commander.handle("geturl "+findaddr.substring(7,findaddr.length()));
          }
          else{            
          }
        }
      }
      if(command.startsWith("wiki ")){
        String []fenge = command.split(" ");     
        if(fenge.length==2){
           main.sys_commander.handle("setway utf-8");
           main.sys_commander.handle("geturl "+"zh.wikipedia.org/wiki/"+fenge[1]);
        }        
      }
      if(command.startsWith("locate ")){
        try{
            String []fenge = command.split(" ");     
            if(fenge.length==2){
               main.searchit.search(fenge[1]);
               if(main.searchit.results.isEmpty()){
                 main.searchit.results.add("Sorry, no matches found..");
               }
               main.listor.set_current_left_list(main.searchit.results);
            }        
        }
        catch (Exception e){
        }
      }  
                if(command.startsWith("s ")){
                  // pay enough attention here
                          String []fenge = command.split(" "); 
                          if(!command.contains(" to")){
                            if(main.sysfunc.check_length(main.listor.current_list,Integer.parseInt(fenge[1])-1)){
                              main.listor.add_to_right(main.listor.current_list.get(Integer.parseInt(fenge[1])-1)); 
                            }
                          }  
                         if(command.contains(" to")){
                          if(fenge.length==4){   
                              if(main.listor.current_list.size()>Integer.parseInt(fenge[3])+1){  
                                  for(int j=Integer.parseInt(fenge[1]);j<Integer.parseInt(fenge[3])+1;j++){
                                      main.listor.add_to_right(main.listor.current_list.get(j-1));                     
                                  }
                                 main.sys_signal.set_String_signal("handle_info","store : Successful handled, thank you...");
                              }
                              else{
                                main.sys_signal.set_String_signal("handle_info","store : Sorry, try adjust you script, something happen with the length");   
                              }
                            }  
                         }
                }    
      if(command.startsWith("store")){
              if(!command.contains(" ")){     
               // this store the html text here for user, but the user has to provide a name  
                if(command.equals("storeit")){
                    main.dataiseverything.PackageResult();
                    set_handle(true);                       
                }                  
                if(command.equals("storeall")){
                    main.dataiseverything.PackageAll();
                    set_handle(true);                       
                }   
                if(command.equals("storecmd")){
                    ArrayList<String> toadd = main.sys_commander.getcommands();
                    for(int j=0;j<toadd.size();j++){
                      main.listor.add_to_right(toadd.get(j));    
                    }                      
                    set_handle(true);                       
                }                  
                if(!get_handled()){
                   main.sys_signal.set_String_signal("handle_info","store : Sorry, you type in wrong command.....");
                }  
              }  
              if(command.contains(" ")){
                if(command.startsWith("storescript")){
                    String []fenge = command.split(" ");      
                    switch (fenge.length){
                      case 2:  {
                        if(main.listor.right_current_list.size()>0){
                           main.script.SaveScript(fenge[1],main.listor.right_current_list);
                           main.sys_signal.set_String_signal("handle_info","store : Successful script handled, thank you...");
                        }
                        else{
                          main.sys_signal.set_String_signal("handle_info","store : Sorry, nothing to store");
                        }    
                      } ;break;
                      case 5: {
                          ArrayList<String> newadd = new ArrayList<String>();
                          for(int i=Integer.parseInt(fenge[1]);i<=Integer.parseInt(fenge[3]);i++){
                            newadd.add(main.listor.right_current_list.get(i-1));
                            main.listor.add_to_right(main.listor.right_current_list.get(i-1));
                          }
                          main.script.SaveScript(fenge[4],newadd);
                          main.sys_signal.set_String_signal("handle_info","store : Successful script handled, thank you...");
                      };break;
                      default: main.sys_signal.set_String_signal("handle_info","store : To ambicious, so many variables");
                    }
             
                }                 
                if(command.startsWith("storeline ")){
                  // pay enough attention here
                  if(!command.contains(" to")){
                    String []fenge = command.split(" "); 
                    if(main.sysfunc.check_length(main.listor.current_list,Integer.parseInt(fenge[1])-1)){
                      main.listor.add_to_right(main.listor.current_list.get(Integer.parseInt(fenge[1])-1)); 
                    }
                  }    
                }
                if(command.startsWith("storelines ")){
                      if(command.contains(" to")){
                          String []fenge = command.split(" "); 
                          if(fenge.length==4){   
                              if(main.listor.current_list.size()>Integer.parseInt(fenge[3])+1){  
                                  for(int j=Integer.parseInt(fenge[1]);j<Integer.parseInt(fenge[3])+1;j++){
                                      main.listor.add_to_right(main.listor.current_list.get(j-1));                     
                                  }
                                 main.sys_signal.set_String_signal("handle_info","store : Successful handled, thank you...");
                              }
                              else{
                                main.sys_signal.set_String_signal("handle_info","store : Sorry, try adjust you script, something happen with the length");   
                              }
                          }
                          else{
                             main.sys_signal.set_String_signal("handle_info","store : Sorry, try adjust you script, something happen with the length");   
                          }
                      }
                      
                }
              }     
      }        
      if(command.startsWith("paper")){
        if(command.equals("paper")){
          main.paper.show_converse();
        }
        else{
          if(command.contains(" ")){
             String []fenge = command.split(" ");    
             try{
               if((Integer.parseInt(fenge[1])-1)<=main.listor.current_list.size()){
                 main.paper.setcontent(main.listor.current_list.get(Integer.parseInt(fenge[1])-1));
               }
             }
             catch (NumberFormatException e){
                 main.paper.setcontent(fenge[1]);
             } 
          }
          else{
            if(command.contains("right")){
              main.listor.add_to_right(main.paper.getcontent());
            }
          }
        }
      }    
    
      if(command.startsWith("blow")){
        if(command.equals("blow")){
          main.whiteboard.show_converse();
        }
        else{
          if(command.contains(" ")){
             String []fenge = command.split(" ");    
             if(fenge.length==2&&main.listor.get_current_list().size()>=Integer.parseInt(fenge[1])){
               try{
                 ArrayList<String> newone = new ArrayList<String>();
                 newone.add(main.listor.get_current_list().get(Integer.parseInt(fenge[1])-1));
                 main.whiteboard.getin(newone);
               }
               catch (NumberFormatException e){
               }
             }
          }
          else{
          }
        }
      }            
      if(command.startsWith("pic ")){
        main.pic.mini_bash(command);
      }
      // plugin in component
      if(command.startsWith("addadd ")){
                          // 这个可以做成插件加入的模式
                          String []fenge = command.split(" "); 
                          String tmpadd = "";
                          if(fenge.length==2){  
                              if(main.sys_commander.getcommands().size()-2>=0){
                                tmpadd = main.sys_commander.getcommands().get(main.sys_commander.getcommands().size()-2);
                              }
                              String tmpway = "setway "+main.parsexml.GetStringValue("url_get_way");
                              ArrayList<String> newadd = new ArrayList<String>();
                              newadd.add(tmpway);
                              main.listor.add_to_right(tmpway);
                              newadd.add(tmpadd);
                              main.listor.add_to_right(tmpadd);                              
                              main.script.SaveScript(fenge[1],newadd);
                          }
      }
      
      if(command.startsWith("index ")){
        try{ 
          String []fenge = command.split(" ");     
            if(fenge.length==2){
                  SimpleDateFormat sdf_copy = new SimpleDateFormat("yyyyMMdd");
                  String ss_copy = sdf_copy.format(new java.util.Date());
                  int niceday = Integer.parseInt(ss_copy);
                  main.searchit.index(niceday,Integer.parseInt(fenge[1]),true);
            }
            else{
            }
        }
        catch (Exception e){
        }            
      }      
      if(command.startsWith("indexcn ")){
        try{ 
          String []fenge = command.split(" ");     
            if(fenge.length==2){
                  SimpleDateFormat sdf_copy = new SimpleDateFormat("yyyyMMdd");
                  String ss_copy = sdf_copy.format(new java.util.Date());
                  int niceday = Integer.parseInt(ss_copy);
                  main.searchit.index_smart_cn(niceday,Integer.parseInt(fenge[1]),true);
            }
            else{
            }
        }
        catch (Exception e){
        }            
      }      
      if(command.equals("indexcnnew")){
        try{
          SimpleDateFormat sdf_copy = new SimpleDateFormat("yyyyMMdd");
          String ss_copy = sdf_copy.format(new java.util.Date());
          int niceday = Integer.parseInt(ss_copy);
          main.searchit.index_smart_cn(niceday,9,false);
        }
        catch (Exception e){
        }
      }      
      if(command.equals("indexnew")){
        try{
          SimpleDateFormat sdf_copy = new SimpleDateFormat("yyyyMMdd");
          String ss_copy = sdf_copy.format(new java.util.Date());
          int niceday = Integer.parseInt(ss_copy);
          main.searchit.index(niceday,9,false);
        }
        catch (Exception e){
        }
      }
      if(command.equals("indexcnold")){
        try{
          SimpleDateFormat sdf_copy = new SimpleDateFormat("yyyyMMdd");
          String ss_copy = sdf_copy.format(new java.util.Date());
          int niceday = Integer.parseInt(ss_copy);
          main.searchit.index_smart_cn(niceday,3,true);
        }
        catch (Exception e){
        }
      } 
      if(command.equals("indexold")){
        try{
          SimpleDateFormat sdf_copy = new SimpleDateFormat("yyyyMMdd");
          String ss_copy = sdf_copy.format(new java.util.Date());
          int niceday = Integer.parseInt(ss_copy);
          main.searchit.index(niceday,3,true);
        }
        catch (Exception e){
        }
      }      
      if(command.equals("pic")){
        main.pic.show_converse();
      }
      if(command.equals("forward")){
        main.multi.handle("right_key");
      }      
      if(command.equals("back")){
        main.multi.handle("left_key");
      }      
      if(command.equals("offline")){
         main.sys_signal.set_boolean_signal("offline",true);
      }
      if(command.equals("online")){
         main.sys_signal.set_boolean_signal("offline",false);
      }      
      if(command.equals("geturls")){
         if(main.parsexml.GetStringValue("mode").equals("single")){
           main.access.getLinks();           
           main.listor.set_current_left_list(main.listor.filtercolons(main.access.get_mixed_array()));     
         }
         else{
                main.multi.handle(command);
         }
      }    
      if(command.startsWith("help")){
           String []fenge = command.split(" ");
           if(1==fenge.length){
             main.listor.add_to_right(command_help);   
           }
           if(2==fenge.length){
             for(int j=0;j<command_help.length;j++){
               if(command_help[j].equals(fenge[1])){
                 main.listor.add_to_right(command_content[j]);   
                 break;
               }
             }
           }
      }         
      if(command.equals("refresh")){
         if(main.parsexml.GetStringValue("current_focus").equals("left")){
          main.dataiseverything.StoreData("left",main.multi.left_register_index,main.listor.get_current_list());                                
          main.sys_signal.set_String_signal("handle_info","refresh : Successful handled, thank you...");          
        }
        if(main.parsexml.GetStringValue("current_focus").equals("cmd")){      
          main.dataiseverything.StoreData("cmd",main.multi.cmd_register_index,main.sys_commander.getcommands());
          main.sys_signal.set_String_signal("handle_info","refresh : Successful handled, thank you...");       
        }  
         if(main.parsexml.GetStringValue("current_focus").equals("right")){
          main.dataiseverything.StoreData("right",main.multi.right_register_index,main.listor.get_current_right_list());                                
          main.sys_signal.set_String_signal("handle_info","refresh : Successful handled, thank you...");          
        }        
        
      } 
      if(command.equals("execute")){
          if(!for_execute.isEmpty()){
            for(int i=0;i<this.for_execute.size();i++){
              main.sys_commander.handle(this.for_execute.get(i));
            }
             main.sys_signal.set_String_signal("handle_info","execute : Successful handled, thank you...");
          }    
      }        
      if(command.equals("step")){
         main.sys_signal.set_boolean_signal("stepexecute",!main.sys_signal.sendout_boolean_signal("stepexecute"));
      }
      // this command will not execute actually by menually, but by other commands
      if(command.equals("executestep")){
          if(!for_execute.isEmpty()&&(main.sys_signal.sendout_int_signal("step_index")<for_execute.size()-1)){
              main.sys_commander.handle(this.for_execute.get(main.sys_signal.sendout_int_signal("step_index")));
              main.sys_signal.set_int_signal("step_index",main.sys_signal.sendout_int_signal("step_index")+1);
              main.sys_signal.set_String_signal("handle_info","execute : Current order is "+this.for_execute.get(main.sys_signal.sendout_int_signal("step_index")));
          }          
          else{
              main.sys_signal.set_boolean_signal("stepexecute",false);
          }
      }
      if(command.equals("exit")){
          System.exit(0);
      }    
      
      // after all matching failures, here we handle all dismatches
      if(!command.startsWith("get")&&!command.startsWith("set")&&!command.startsWith("ls")
      &&!command.startsWith("rm")&&!command.startsWith("clear")&&!command.startsWith("")&&!command.startsWith("execute")
      &&!command.startsWith("load")&&!command.startsWith("jump")&&!command.startsWith("store")
      &&!command.startsWith("help")&&!command.startsWith("filter")&&!command.startsWith("backup")){         
         main.sys_signal.set_String_signal("handle_info","Sorry, I can not get what you mean.....");
      }
  }
  
}
