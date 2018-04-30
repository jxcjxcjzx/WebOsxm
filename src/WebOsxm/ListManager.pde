interface List_list
{
   void set_current_left_list(ArrayList<String> for_get);
   void set_current_right_list(ArrayList<String> for_get);
   ArrayList<String> get_current_list();      
}

class ListManager implements List_list
{
   String current_url = "";  
   ArrayList<String> current_list = new ArrayList<String>();
   ArrayList<String> right_current_list = new ArrayList<String>();
   
   ArrayList<String> filtercolons(ArrayList<String> content)
   {
      ArrayList<String> forreturn = new ArrayList<String>();
      if(content.size()>1){
            for(int i=1;i<content.size();i+=2)
            {
              forreturn.add(content.get(i-1));
              forreturn.add(this.filtercolon(content.get(i)));
            }
      }
      return forreturn;
   }
   
   int get_left_list_count()
   {
     return this.current_list.size();  
   }
   
   String filtercolon(String content)
   {
     String forreturn = "http://www.baidu.com";
     while(content.startsWith("\"")){
       content = content.substring(1,content.length());
     }
     for(int i=0;i<content.length();i++)
     {
       if(content.charAt(i)=='"'){
           forreturn = content.substring(0,i-1);     
           break;
       }  
     }
     return forreturn;
   }
   
   String get_current_url()
   {
     return this.current_url;
   }
   void set_current_url(String forset)
   {
     this.current_url = forset;
   }
   void add_to_right(String a){
     if(a.contains("\n")){
       ArrayList<String> foradd = new ArrayList<String>();
       String forsplit[] = a.split("\n");
       for(int i=0;i<forsplit.length;i++){
         foradd.add(forsplit[i]);
       }
       this.add_to_right(foradd);
     }
     else{
          this.right_current_list.add(a);
     }
   }
   void add_to_right(ArrayList<String> foradd){
      for(int i=0;i<foradd.size();i++){
        this.right_current_list.add(foradd.get(i));
      }
   }   
   void add_to_right(String[] foradd){
      for(int i=0;i<foradd.length;i++){
        this.right_current_list.add(foradd[i]);
      }
   }  
   void set_current_left_list(ArrayList<String> for_get){
      this.current_list = for_get;       
   }
   void set_current_right_list(ArrayList<String> for_get){
      this.right_current_list = for_get;       
   }   
   ArrayList<String> get_current_list(){
      return this.current_list;
   }         

}
