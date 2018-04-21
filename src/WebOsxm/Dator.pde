interface datahandle
{
  void StoreData(String register,int index,ArrayList<String> content);
  void StoreData(String category,String content);
  ArrayList<String> LoadData(String register_key,int index);
}


class Dator implements datahandle
{
    BookCaseManager datamanager = new BookCaseManager();
    String datafolder = "C:/Users/Administrator/Desktop/WebOsxm2.0/data";
    String databackfolder = "F:/DFJ/WebOsbase";
    String FirstDataPlace = "F:/DFJ/WebOsbase/Main";
    String SecondDataPlace = "C:/Users/Administrator/Desktop/WebOsxm2.0/DataBase/Main";
    int basecount = 0;
    int currentindex = 0;
    boolean Baseloaded = false;
    ArrayList<String> filelist = new ArrayList<String>();
    
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
          main.parsexml.SetIntValue("currentindex",0);
          this.currentindex = 0;
        }
        else{
          this.currentindex++;
          main.parsexml.SetIntValue("currentindex",this.currentindex);
        }
      }
      else{
      }
    }
    
    void AddOneFile(String filename)
    {
      this.filelist.add(filename);
    }
    
    ArrayList<String> GetFileList()
    {
      return this.filelist;
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
      saveStrings(register_key+String.valueOf(index),a);
      main.dataiseverything.AddOneFile(register_key+String.valueOf(index));
    }
    
    void PackageAll()
    {
       SimpleDateFormat sdf_gettime = new SimpleDateFormat("yyy_MM_dd_HH_mm_ss");
       String ss_gettime = sdf_gettime.format(new java.util.Date());   
       try{
         File myfile = new File(this.FirstDataPlace+"/"+ss_gettime);
         File myfile2 = new File(this.SecondDataPlace+"/"+ss_gettime);
         if(!myfile.exists()){
           myfile.mkdir();
         }
         if(!myfile2.exists()){
           myfile2.mkdir();
         }         
         for(int i=0;i<this.filelist.size();i++){
           String a[] = loadStrings(this.filelist.get(i));
           saveStrings(this.FirstDataPlace+"/"+ss_gettime+"/"+this.filelist.get(i),a); 
           saveStrings(this.SecondDataPlace+"/"+ss_gettime+"/"+this.filelist.get(i),a); 
         }
       }
       catch (Exception e){
         
       }
    }
    
    void PackageResult()
    {
       SimpleDateFormat sdf_gettime = new SimpleDateFormat("yyy_MM_dd_HH_mm_ss");
       String ss_gettime = sdf_gettime.format(new java.util.Date());   
       try{
         File myfile = new File(this.FirstDataPlace+"/"+ss_gettime);
         File myfile2 = new File(this.SecondDataPlace+"/"+ss_gettime);
         if(!myfile.exists()){
           myfile.mkdir();
         }
         if(!myfile2.exists()){
           myfile2.mkdir();
         }         
         for(int i=0;i<this.filelist.size();i++){
           if(this.filelist.get(i).startsWith("right")){
             String a[] = loadStrings(this.filelist.get(i));
             saveStrings(this.FirstDataPlace+"/"+ss_gettime+"/"+this.filelist.get(i),a); 
             saveStrings(this.SecondDataPlace+"/"+ss_gettime+"/"+this.filelist.get(i),a); 
           }
         }
       }
       catch (Exception e){
         
       }
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
           String a[] = new String[newone.size()+1];
           a[0]="地址是???<jxclzdy>???(正则防御) ："+this.webaddr+"，获取方法是 ："+this.getway;
           
           for(int i=0;i<newone.size();i++)
           {
             a[i+1] = newone.get(i);
           }
           saveStrings(this.name,a);
           main.dataiseverything.AddOneFile(this.name);
           main.sys_signal.set_process(this.index,"true");
        } catch (Exception e) {
        }        
    }

}
