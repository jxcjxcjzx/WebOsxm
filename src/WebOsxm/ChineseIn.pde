// typicle use of this class are coded as follows
// if(zhong.jiexi().equals("success")){
//          show+=zhong.getvalue();
//         }
import java.net.*;
import java.io.*;

class ChineseIn{

String Ch_chaxun = "";
int Ch_printindex = 0;
int Ch_choosecount = 0;
int Ch_returnvalue = 0;
boolean Ch_printit = false;
boolean Ch_xianshi = false;
boolean Ch_pageback = false;
boolean Ch_pageforward = false;
String []Ch_currentword = new String[6];
ArrayList<String> Ch_jieguo = new ArrayList();
ArrayList<String> Ch_zifuchuan = new ArrayList();
boolean Ch_chushi = false;
String Ch_returnvalue2 = "";

void paint()
{
   fill(222,197,197); 
   rect(main.parsexml.GetIntValue("command_frame_x"),
   main.parsexml.GetIntValue("command_frame_y")
   +main.parsexml.GetIntValue("command_frame_height")/3,
   main.parsexml.GetIntValue("command_frame_width")/2,
   main.parsexml.GetIntValue("command_frame_height")/3);  
   showindex();
}

String getvalue()
{
  return this.Ch_returnvalue2;  
}

String jiexi()
{
   String forreturn = "";
   readChar();
   if(!Ch_chushi){
     loadmaterial();
     Ch_chushi = true;
   } 
   if(Ch_chaxun!=""&&Ch_xianshi&&Ch_returnvalue==0){
       handle(Ch_chaxun);                    
   }
   else{
       Ch_xianshi = false;
   }
         // get the choosing result
       if(Ch_printit){
          // giving out the result
           Ch_returnvalue2 = forreturn = Ch_currentword[Ch_printindex-1];
           Ch_printit = false;
       } 
   if(forreturn!=""){
     forreturn = "success";
   } 
   else{
     forreturn = "failure";
   }
   return forreturn;
}

void handle(String chaxun)
{
                String []fenge = new String[2];
                for(int i=0;i<Ch_zifuchuan.size();i++)
                 {
                       fenge = Ch_zifuchuan.get(i).split(",");
                       if(fenge[1].startsWith(chaxun)&&fenge[0].length()==1){
                         Ch_jieguo.add(fenge[0]);
                       }
                       else{
                             if(fenge[1].startsWith(chaxun)&&fenge[0].length()>1){
                                Ch_jieguo.add(fenge[0].substring(0,fenge[0].length()-1));
                             } 
                             else{
                             }
                       }
                  }
}


int loadmaterial()
{
       try{
            String readincontent = "";
            URL url = new URL("file:///C:/Users/Administrator/Desktop/WebOsxm/data/ziku3.txt");         
            InputStreamReader isr = new InputStreamReader(url.openStream(),"gbk");
            BufferedReader br = new BufferedReader(isr); 
            while((readincontent = br.readLine())!=null){
             Ch_zifuchuan.add(readincontent);
            }
            return 0;
     }
     catch (IOException e){
           return -1;
     }  
}

void readChar()
{
  if((key>='a'&&key<='z')||(key>='A'&&key<='Z'))
  {
    Ch_chaxun+=key;
    Ch_jieguo.clear();
    Ch_xianshi = true;
  }
  if(keyCode==39){
  Ch_pageforward = true;
  Ch_choosecount++;
  }
  if(keyCode==37&&Ch_choosecount>0){
  Ch_pageback = true;
  Ch_choosecount--;
  }
  if(key=='\b'&&Ch_chaxun.length()>0){
  Ch_chaxun = Ch_chaxun.substring(0,Ch_chaxun.length()-1);
  Ch_jieguo.clear();
  Ch_xianshi = true;
  }
  if(key=='\n')
  {
    Ch_chaxun="";
    Ch_jieguo.clear();
    Ch_choosecount = 0;
  }
  if(key>='1'&&key<='6'){
    Ch_printit = true;
    Ch_printindex = key-'0';
    Ch_chaxun="";
    Ch_jieguo.clear();
    Ch_choosecount = 0;
  }
  if(keyCode==32){
    Ch_printindex = 1;
    Ch_printit = true;
    Ch_chaxun="";
    Ch_jieguo.clear();
    Ch_choosecount = 0;
  }
}


void showindex()
{
  int roundcount = 0;
  fill(0,0,0);  
  if(!Ch_jieguo.isEmpty()){
      roundcount = Ch_jieguo.size()/6-1;
      text(Ch_chaxun,main.parsexml.GetIntValue("command_frame_x")+10,
      main.parsexml.GetIntValue("command_frame_y")+130);
      if(Ch_jieguo.size()>6){
        // the choosing bar for user
        // providing the function of choosing Chinese words
        if(Ch_choosecount<=roundcount){
                for(int choose1=0+6*Ch_choosecount;choose1<3+6*Ch_choosecount;choose1++){
                  text(choose1-6*Ch_choosecount+1+".",20+80*(choose1-6*Ch_choosecount)-9+30+width/2,485+110);
                  text(Ch_jieguo.get(choose1),20+80*(choose1-6*Ch_choosecount)+30+width/2,485+110);
                  Ch_currentword[choose1-6*Ch_choosecount] = Ch_jieguo.get(choose1);
                }
                for(int choose2=3+6*Ch_choosecount;choose2<6+6*Ch_choosecount;choose2++){
                  text(choose2-6*Ch_choosecount+1+".",20+80*(choose2-3-6*Ch_choosecount)-9+30+width/2,500+110);
                  text(Ch_jieguo.get(choose2),20+80*(choose2-3-6*Ch_choosecount)+30+width/2,500+110);
                  Ch_currentword[choose2-6*Ch_choosecount] = Ch_jieguo.get(choose2);
                }
                
                
        }
        else{
          if(Ch_choosecount==roundcount+1&&Ch_jieguo.size()%6!=0){
              for(int choose3=(roundcount+1)*6;choose3<Ch_jieguo.size();choose3++){
                Ch_currentword[choose3-(roundcount+1)*6] = Ch_jieguo.get(choose3);
              }  
              for(int choose4=Ch_jieguo.size()%6;choose4<6;choose4++){
                Ch_currentword[choose4] = "";
              }
              
                for(int choose5=0;choose5<3;choose5++){
                  text(choose5+1+".",20+80*choose5+30-9+width/2,485+110);
                  text(Ch_currentword[choose5],20+80*choose5+30+width/2,485+110);
                }
                for(int choose6=3;choose6<6;choose6++){
                  text(choose6+1+".",20+80*(choose6-3)+30-9+width/2,500+110);
                  text(Ch_currentword[choose6],20+80*(choose6-3)+30+width/2,500+110);
                }
                
          }
          else{
           Ch_choosecount--;
          }  
        }
      }
      else{
           for(int j=0;j<Ch_jieguo.size();j++){
            text(j+1+".",20+40*j+30-9+width/2,500+110);
            text(Ch_jieguo.get(j),20+40*j+30+width/2,500+110);
            Ch_currentword[j] = Ch_jieguo.get(j);
           }
      }
  }
  else{
  Ch_chaxun="";
  }
  
}



}
