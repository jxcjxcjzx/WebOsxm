interface Scriptchannel
{
  void SaveScript(String name,ArrayList<String> info);
  ArrayList<String> LoadScript(String name);
  ArrayList<String> LoadScript();    // get all the scipt stored
}

class SrciptMan implements Scriptchannel
{
  void SaveScript(String name,ArrayList<String> info)
  {
    main.parsexml.SetBlock(name,info);
  }
  
  void DeleteScript(String name)
  {
    main.parsexml.DeleteBlock(name);
  }
  
  ArrayList<String> LoadScript(String name)
  {
     ArrayList<String> forreturn = new ArrayList<String>();
     forreturn = main.parsexml.LoadBlock(name);
     return forreturn;
  }  
  
  ArrayList<String> LoadScript()
  {
     ArrayList<String> forreturn = new ArrayList<String>();
     forreturn = main.parsexml.loadList();
     return forreturn;      
  }  

}
