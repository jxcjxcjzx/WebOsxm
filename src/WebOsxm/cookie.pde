// this interface handle for all the extra command which meet with dismatch and can do 
// someting as interesting as possible
interface cookie
{
   void get_things_done(String parament);
   String get_handle_result();
}

class www_data_base implements cookie
{
   String for_store = "";
   String save_path = "";
   String handle_result = "";
   String help_info = "";    // provide the help information the users need to do , to make everything clear
   void get_things_done(String parament)
   {
      
   
   }
   
   String get_handle_result()
   {
     String forreturn = "";
     if(this.handle_result.equals("")){
       forreturn = "Well,I didn't do anything.....";
     }   
     else
     {
       forreturn = this.handle_result;
     }
     return forreturn;
   }

}
