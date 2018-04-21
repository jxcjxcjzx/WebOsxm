interface extend_frame
{
   void show_converse();
   void change_of_show();
}

class BillBoard
{
    boolean whether_show = false;
    int Billadjust = 0;
    ArrayList<String> content = new ArrayList<String>();
    
    
    void handle(String signal)
    {
        if(signal=="up"){
          this.Billadjust+=9;
        }
        if(signal=="down"){
          this.Billadjust-=9;
        }
    }
    void show_converse()
    {      
      this.whether_show = (this.whether_show == true)?false:true;
      if(this.whether_show){
          main.sys_signal.set_boolean_signal("BoardUse",true);
      }
      else{
          main.sys_signal.set_boolean_signal("BoardUse",false);
      }
    }
    void getin(ArrayList<String> input)
    {
       this.Billadjust = 0;
       this.content.clear();
       String readincontent = "";
       for(int k=0;k<input.size();k++){
                    readincontent = input.get(k);
                    if(readincontent.length()>50){
                      int jishu = readincontent.length()/50;
                      int w = 0;
                      for(w=0;w<jishu;w++)
                      content.add(readincontent.substring(0+50*w,50+50*w));       
                      content.add(readincontent.substring(50+50*(w-1),readincontent.length()));           
                    }
                    else{
                      content.add(readincontent);   
                    }
       }
       this.content.add("I am the last but not the least one here....");
     } 
     void change_of_show()
     {
        if(this.whether_show)
        {
          // handling in the show
          fill(167,219,95);
          main.sysfunc.roundrect(width/2+30,20,width-30,400);      
          for(int m=0;m<content.size();m++){
            if((30+m*20+this.Billadjust)<400&&(30+m*20+this.Billadjust)>20){  
              fill(0,0,0);
              text(content.get(m),width/2+40,40+m*20+this.Billadjust);
            }
          }  
        }
        else{        
        }
     }
}

class Baike
{
    String handle(String content)
    {
      return this.addengine(content);
    }
    
    String addengine(String require)
   {
             String strUrl = require;
             URL url=null;
             String find = null;
             String str = null;
        try{
           java.util.regex.Pattern p2 = java.util.regex.Pattern.compile("http...baike.baidu.com.view.([0-9]+?).htm");
           url = new URL("http://www.baidu.com/s?wd="+strUrl);                              
           InputStreamReader isr = new InputStreamReader(url.openStream());
           BufferedReader br = new BufferedReader(isr); 
           while ((str = br.readLine() )!= null) {   
           Matcher m = p2.matcher(str);
           if (m.find()) {
           find = m.group(1);
           find = "http://baike.baidu.com/view/"+find+".htm"; 
           break;
           }
           else{
           continue;
           }              
         }
        } 
        catch (IOException e) {            
              find = "对不起，你的要求太过分了";
        }  
       return find;
   }
}



class PicShow implements extend_frame
{
    boolean whether_show = false;    
    PImage a;
    int left_top_x = 0;
    int left_top_y = 0;
    int picwidth = 0;
    int picheight = 0;
    
    void show_converse()
    {      
      this.whether_show = (this.whether_show == true)?false:true;
    }
    void change_of_show()
    {
      if(this.whether_show)
      {
        fill(255,255,255);
        rect(left_top_x,left_top_y,picwidth,picheight);
        if(a!=null){
          image(a,left_top_x,left_top_y);
        }
      }
    }
    void mini_bash(String handle)
    {
      if(handle.startsWith("pic ")){
         String []fenge = handle.split(" ");
         if(fenge.length==2){
           try{
             this.a = loadImage(fenge[1]);
           }
           catch (NumberFormatException e){
           }            
         }         
         if(fenge.length==5){
           try{
             this.left_top_x = Integer.parseInt(fenge[1]);
             this.left_top_y = Integer.parseInt(fenge[2]);
             this.picwidth = Integer.parseInt(fenge[3]);
             this.picheight = Integer.parseInt(fenge[4]);
           }
           catch (NumberFormatException e){
           } 
         }
      }
    }
}


class DashBoard implements extend_frame
{
    boolean whether_show = false;
    String content = "";
    String getcontent()
    {
      return this.content;
    }
    void setcontent(String con)
    {
        this.content = con;
    }
    void show_converse()
    {      
      this.whether_show = (this.whether_show == true)?false:true;
    }
     
     void change_of_show()
     {
        if(this.whether_show)
        {
          // handling in the show
          fill(255,255,255);
          rect(0,height/2+90,width-30,20);          
          fill(0,0,0);
          text(this.content,20,height/2+103);
        }
        else{        
        }
     }
}




