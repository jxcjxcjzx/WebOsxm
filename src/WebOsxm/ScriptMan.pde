interface Scriptchannel
{
  void SaveScript(String name,ArrayList<String> info);
  ArrayList<String> LoadScript(String name);
}

class SrciptMan implements Scriptchannel
{
  void SaveScript(String name,ArrayList<String> info)
  {
    main.parsexml.SetBlock(name,info);
  }
  
  ArrayList<String> LoadScript(String name)
  {
     ArrayList<String> forreturn = new ArrayList<String>();
     forreturn = main.parsexml.LoadBlock(name);
     return forreturn;
  }  

}
