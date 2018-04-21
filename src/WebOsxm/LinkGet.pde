interface WebAccess
{
  BufferedReader gethtmltext(String addr,String theway);
  ArrayList<String> TransferBuffer(BufferedReader fortrans);
  void getLinks();
  ArrayList<String> get_link_array();
  ArrayList<String> get_link_name_array();  
  ArrayList<String> get_mixed_array();
  String send_out_info();
  void set_out_info(String info);  
  ArrayList<String> basichandle(BufferedReader br); 
  ArrayList<String> basichandle(ArrayList<String> br);   
  ArrayList<String> get_lines_with(ArrayList<String> target,String keyword);
}

class LinkGet implements WebAccess
{
    String out_info = "";
    ArrayList<String> links = new ArrayList<String>();
    ArrayList<String> links_name = new ArrayList<String>();    
    BufferedReader gethtmltext(String addr,String theway)
    {
       BufferedReader forshow = null;
      try{ 
       URL url = new URL(addr);   
       InputStreamReader isr = new InputStreamReader(url.openStream());
       if(theway.equals("gbk")){       
       isr = new InputStreamReader(url.openStream(),"gbk");
       }
       if(theway.equals("utf-8")){       
       isr = new InputStreamReader(url.openStream(),"utf-8");
       }
       forshow = new BufferedReader(isr);  
        this.set_out_info("Get html source successfully !");       
      }
      catch (IOException e) {            
        this.set_out_info("Sorry, there must be something wrong with net connection or link format...");
      }  
      return forshow;
    }
    
    // this function handle with the data materials to the material without so many tags in html 
    ArrayList<String> basichandle(BufferedReader br)
    {
      ArrayList<String> forreturn = new ArrayList<String>();      
       String str_readin = null;
       Pattern p = Pattern.compile("<.+?>");
       try{
               while ((str_readin = br.readLine() )!= null) {            
                 Matcher m = p.matcher(str_readin);
                  if(m.find())
                  {
                  String resul = m.replaceAll("");  
                  forreturn.add(resul);
                  }
                  }
                    br.close();
                    this.set_out_info("Successfully finish the task of transforming Buffer to ArrayList");  
         }
         catch (IOException e) {            
            this.set_out_info("Sorry, something wrong unfortunatelly happened in process of Buffer -- Array transform");  
         }    
          return forreturn;
        }
        
    // specified the ArrayList -- ArrayList
     ArrayList<String> basichandle(ArrayList<String> br)
    {
      ArrayList<String> forreturn = new ArrayList<String>();      
       String str_readin = null;
       Pattern p = Pattern.compile("<.+?>");
               for(int j=0;j<br.size();j++) 
              {
                  str_readin =  br.get(j);         
                  Matcher m = p.matcher(str_readin);
                      if(m.find())
                      {
                      String resul = m.replaceAll("");  
                      forreturn.add(resul);
                      }
                 }
                  this.set_out_info("Successfully finish the task of transforming ArrayList to ArrayList");                  
          return forreturn;
        }
    
    // this transfer the BufferedReader to the ArrayList object
    ArrayList<String> TransferBuffer(BufferedReader br){
        ArrayList<String> forreturn = new ArrayList<String>();
        try{
            String str_here = null;
            if(br!=null){
                while ((str_here = br.readLine() )!= null) {   
                     forreturn.add(str_here);
                }
               this.set_out_info("Transfer the html source successfully !");           
            }
            else{
            }      
          }
          catch (IOException e) {        
           this.set_out_info("Sorry, there must be something wrong with BufferReader, checking is adviced....");                 
          }    
          return forreturn;
    }
    
    ArrayList<String> get_lines_with(ArrayList<String> target,String keyword){
       ArrayList<String> forreturn = new ArrayList<String>();
       forreturn.add("我是第一个，打酱油的.....");
       for(int i=0;i<target.size();i++){
         if(target.get(i).contains(keyword)){
           forreturn.add(target.get(i));
         }
       }
       return forreturn;
    }
    
    ArrayList<String> get_link_array()
    {       
       return this.links;
    }
    ArrayList<String> get_link_name_array(){
      return this.links_name;
    }
    ArrayList<String> get_mixed_array(){
      ArrayList<String> forreturn = new ArrayList<String>();
      for(int i=0;i<this.links_name.size();i++){
         forreturn.add(this.links_name.get(i));
         forreturn.add(this.links.get(i));         
      } 
      return forreturn;
    }   
    // The function help you collect all the web links that is possesed in a start link
    void getLinks(){
      parseurl urlparse = new parseurl();
      urlparse.handle_buffer(main.listor.get_current_list());
      this.links = (ArrayList<String>)urlparse.webaddr_array.clone();
      this.links_name = (ArrayList<String>)urlparse.title_array.clone();
    }
    
    // out information handle
      String send_out_info(){
        return this.out_info;
      }
      
      void set_out_info(String info){
        this.out_info = info;
      }
}





import java.util.regex.Matcher;
import java.util.regex.Pattern;
class parseurl
{

  ArrayList<String> url_array = new ArrayList<String>();  
  ArrayList<String> title_array = new ArrayList<String>();  
  ArrayList<String> webaddr_array = new ArrayList<String>();  
  final String regex = "<a.*?/a>";
  String url_Content = "";
  final Pattern pt = Pattern.compile(regex);
 // final Matcher mt = pt.matcher(url_Content);  
  int link_count = 0;
  
  void handle_buffer(ArrayList<String> content)
  {
    int j = 0;
    if(!content.isEmpty()){
      StringBuffer is = new StringBuffer();
      for(int i=0;i<content.size();i++)
       {
         is.append(content.get(i));
       }
      url_Content = is.toString();
    }
    Matcher mt = pt.matcher(url_Content);  
    while (mt.find()) {
        url_array.add(mt.group());  // add the original information to the array
        final Matcher title = Pattern.compile(">.*?</a>").matcher(mt.group());
           // 获取标题
        while (title.find()) {
           title_array.add(title.group().replaceAll(">|</a>", ""));  
        }
           // 获取网址
         final Matcher myurl = Pattern.compile("href=.*?>").matcher(mt.group());
         while (myurl.find()) {
            webaddr_array.add(myurl.group().replaceAll("href=|>", ""));
         }             
         j++;
    }
    this.link_count = j;
  }
}
