interface datahandle
{
  void StoreData(String register,int index,ArrayList<String> content);
  void GetData(String describe);
  void StoreData(String category,String content);
  ArrayList<String> LoadData(String register_key,int index);
}


class Dator implements datahandle
{
    BookCaseManager datamanager = new BookCaseManager();
    String datafolder = "C:/Users/Administrator/Desktop/WebOsxm2.0/data";
    String databackfolder = "F:/DFJ/WebOsbase";
    int basecount = 0;
    int currentindex = 0;
    boolean Baseloaded = false;
    
    void StoreData(String category,String content)
    {
      if(this.Baseloaded){
        datamanager.addOneNode(category,content,this.datafolder+"/DataBase"+String.valueOf(basecount)+".xml");
        datamanager.addOneNode(category,content,this.databackfolder+"/DataBase"+String.valueOf(basecount)+".xml");
        if(this.currentindex>999){
          // create a new one
          this.basecount++;
          BuildNewBase(this.basecount,this.datafolder);
          BuildNewBase(this.basecount,this.databackfolder);
          main.parsexml.SetIntValue("basecount",this.basecount);
        }
        else{
          this.currentindex++;
          main.parsexml.SetIntValue("currentindex",this.currentindex);
        }
      }
      else{
      }
    }
    
    void BuildNewBase(int num,String addr)
    {
       String a[] = {"<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?><set></set>"};
       saveStrings(addr+"/DataBase"+String.valueOf(num)+".xml",a);
    }
    
    void initial()
    {
       loadbasecount();
       loadcurrentindex();   
       try{
         datamanager.loadXML(this.datafolder+"/DataBase"+String.valueOf(basecount)+".xml");     
         datamanager.loadXML(this.databackfolder+"/DataBase"+String.valueOf(basecount)+".xml"); 
       }
       catch(Exception e){      
       }       
       this.Baseloaded = true;    
    }
    
    void loadbasecount()
    {
        this.basecount = main.parsexml.GetIntValue("basecount");
    }
    
    void loadcurrentindex()
    {
        this.currentindex = main.parsexml.GetIntValue("currentindex");        
    }
    
    void StoreData(String register_key,int index,ArrayList<String> content) // to save large bolck for temp use afterwards
    {
      String a[] = new String[content.size()];
      for(int i=0;i<a.length;i++)
      {
        a[i] = content.get(i);
      }
      saveStrings(register_key+"_"+String.valueOf(index),a);
    }
    
    ArrayList<String> LoadData(String register_key,int index)
    {
      ArrayList<String> forreturn = new ArrayList<String>();
      String b[] = loadStrings(register_key+String.valueOf(index));
      for(int i=0;i<b.length;i++)
      {
        forreturn.add(b[i]);
      }
      return forreturn;
    }
    
    void GetData(String describe)
    {
    
    }

}



class loadThread extends Thread {
    String webaddr = "";
    String name = "";
    String getway = "";
    String mytag = "";
    int index = 0;

    public loadThread(String threadName,String addr,String theway,String filename,String tag,int index) {
        super(threadName);
        this.webaddr = addr;
        this.name = filename;
        this.getway = theway;
        this.index = index;
        if(tag.equals("file:///")||tag.equals("http://")){
          this.mytag = tag;
        }
        else{
          this.mytag = "http://";
        }
    }
    public void run() {
        downfile();
        
    }
    
    void downfile(){
       try {
           ArrayList<String> newone = main.access.TransferBuffer(main.access.gethtmltext(this.mytag+this.webaddr,this.getway));
           String a[] = new String[newone.size()];
           for(int i=0;i<newone.size();i++)
           {
             a[i] = newone.get(i);
           }
           saveStrings(this.name,a);
           main.sys_signal.set_process(this.index,"true");
        } catch (Exception e) {
        }        
    }

}
