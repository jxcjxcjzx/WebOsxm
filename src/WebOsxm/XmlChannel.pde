import java.io.File;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.Stack;
 
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
 
import org.dom4j.Element;
import org.dom4j.io.OutputFormat;
import org.dom4j.io.SAXReader;
import org.dom4j.io.XMLWriter;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

interface xmlinterface
{
  int GetIntValue(String valuename);
  String GetStringValue(String valuename);
  void SetIntValue(String valuename,int value);
  void SetStringValue(String valuename,String value);
  void SetBlock(String name,ArrayList<String> info);
  ArrayList<String> LoadBlock(String name);
}


class XmlChannel implements xmlinterface
{
    BookCaseManager setmanage = new BookCaseManager();
    ScriptManager scriptmanage = new ScriptManager();
    String fileaddr = "C:/Users/Administrator/Desktop/WebOsxm/data/setfile.xml";
    String fileaddr2 = "C:/Users/Administrator/Desktop/WebOsxm/data/scriptfile.xml";
    
    // all functions passed
    int GetIntValue(String valuename){
       int forreturn = 0;
       forreturn = Integer.parseInt(setmanage.lookForOneNode(valuename,fileaddr));
       return forreturn;
    }
    String GetStringValue(String valuename){
       String forreturn = "";
       forreturn = setmanage.lookForOneNode(valuename,fileaddr);
       return forreturn;
    }
    void SetIntValue(String valuename,int value){
       setmanage.changeOneNode(valuename,String.valueOf(value),fileaddr);
    }
    void SetStringValue(String valuename,String value){
       setmanage.changeOneNode(valuename,value,fileaddr);
    }
  
    void SetBlock(String blockname,ArrayList<String> block)
    {
       scriptmanage.addOneBlock(blockname,block,fileaddr2);
    }
    
    ArrayList<String> LoadBlock(String blockname)
    {
      ArrayList<String> forreturn = new ArrayList<String>();
      forreturn = scriptmanage.loadOneBlock(blockname,fileaddr2);      
      main.sys_signal.set_String_signal("handle_info",scriptmanage.getState());      
      return forreturn;
    }
    
    void DeleteBlock(String name)
    {
       scriptmanage.deleteOneBlock(name,fileaddr2);
    }
    
     ArrayList<String> loadList()
     {
       ArrayList<String> forreturn = new ArrayList<String>();
       forreturn = scriptmanage.LoadBlockList(fileaddr2);    
       main.sys_signal.set_String_signal("handle_info",scriptmanage.getState());          
       return forreturn;           
     }    

  
  
}





// classes used

// This is a open interface built for the easy access
// to the XML files.
// The XML files can be viewed as a database for datas
// The function are listed as follows:
//1.Document loadXML(String fileaddr)   :  to load an XML  file
//2. void addOnenode(String name,String process,String fileaddr)   :  to add a record
//3.void deleteOneNode(String name,String fileaddr)   : to delete one record
//4.String lookForOneNode(String name,String fileaddr)   :  to find a set record
//5. void updateOnenode(String name,String process,String fileaddr)    :  to update a record
//6.  void saveXML(Document doc,String fileaddr)  :  to save a XML file , this one is usually not used
// in addition, we provide perfect support for Chiniese in, thank you!
// And for you to keep in mind 
// follows are the provided example set for our bookstore
/*
<?xml version="1.0" encoding="UTF-8" standalone="no"?><bookcase>
  <book>
    <name>李华</name>
    <process>14</process>
  </book>
  <book>
    <name>张三</name>
    <process>16</process>
  </book>
</bookcase>
*/




class BookCaseManager
{   
  String handlestate = "success";
  
  String getState(){
    return this.handlestate;
  }
  
  void setState(String a){    
    this.handlestate = a;
  }
  
  Document loadXML(String fileaddr) throws Exception{   
     Document document = null;
     try{
      DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
      DocumentBuilder builder = factory.newDocumentBuilder();
      document = builder.parse(new File(fileaddr));
     }catch(Exception e){
       this.setState("对不起，无法载入相应的文件");
     }    
    return document;
  }
  
  void addOneNode(String name,String process,String fileaddr)
  {
    try{
      Document document = this.loadXML(fileaddr);
      NodeList nodeList = document.getElementsByTagName("set");
      Node nameNode = document.createElement(name);
      nameNode.appendChild(document.createTextNode(process));
      nodeList.item(0).appendChild(nameNode);
      this.saveXML(document,fileaddr);
       // tip area
       this.setState("已成功增加一条记录！");
    }
    catch(Exception e){
       this.setState("增加记录失败.....");     
    } 

  }
  
  String lookForOneNode(String name,String fileaddr){
     String forreturn = "";
        try{
               Document document = this.loadXML(fileaddr);
               NodeList nodeList = document.getElementsByTagName(name);
               forreturn = nodeList.item(0).getTextContent();    // if error occur this may be something wrong with getNodeValue() function, then try getTextContent()
        }
        catch(Exception e){
          this.setState("查找记录失败.....");    
       }
     return forreturn;
  }
  
  void changeOneNode(String name,String process,String fileaddr)
  {
        
        try{
               Document document = this.loadXML(fileaddr);
               NodeList nodeList = document.getElementsByTagName(name);
               nodeList.item(0).setTextContent(process);
               this.setState("已成功更新一条记录！");   
               this.saveXML(document,fileaddr);
        }
        catch(Exception e){
        this.setState("更新记录失败.......");   
       }   
  }
  
  void saveXML(Document doc,String fileaddr) throws Exception
  {
       try{
          TransformerFactory tf = TransformerFactory.newInstance();
          Transformer tfer = tf.newTransformer();
          DOMSource dsource = new DOMSource(doc);
          StreamResult sr = new StreamResult(new File(fileaddr));
          tfer.transform(dsource, sr);
         }catch(Exception e){
          e.printStackTrace();
         }
   
  }

}



// this class is the main class we use to interface with the xml file

class ScriptManager extends BookCaseManager
{
  
      String handlestate = "success";
      
      String getState(){
        return this.handlestate;
      }
      
      void setState(String a){    
        this.handlestate = a;
      }  
      
     Node newNodeWithContent(String content,Document one)
     {
        Node newNode = one.createElement("sentence");
        newNode.setTextContent(content);
        return newNode;
     }
     
     void addOneBlock(String name,ArrayList<String> toadd,String fileaddr)
     {
        try{
          if(!toadd.isEmpty()){
              Document document = this.loadXML(fileaddr);
              NodeList nodeList = document.getElementsByTagName("Scripts");
              Node nameNode = document.createElement(name);
              for(int i=0;i<toadd.size();i++){
                nameNode.appendChild(newNodeWithContent(toadd.get(i),document));
                nodeList.item(0).appendChild(nameNode);
              }
              this.saveXML(document,fileaddr);
               // tip area
                 this.setState("已成功增加一条记录！");
          }
          else{
                 this.setState("不好意思，没有可以添加的脚本");
          }
        }
        catch(Exception e){
           this.setState("增加记录失败.....");     
        } 
     }
     
      void deleteOneBlock(String name,String fileaddr)
      {
         try{
             Document document = this.loadXML(fileaddr);        
             NodeList nodeList = document.getElementsByTagName("Scripts").item(0).getChildNodes();
             for(int i=0;i<nodeList.getLength();i++){
              String value = nodeList.item(i).getNodeName();
              if(name!=null && name.equalsIgnoreCase(value)){
               //nodeList.item(i).removeChild(parentNode);
               nodeList.item(i).getParentNode().removeChild(nodeList.item(i));
               this.setState("已成功删除一条记录！");    
               break;
              }
             }
             this.saveXML(document,fileaddr);
          }
          catch(Exception e){
             this.setState("删除记录失败.....");          
          } 
        
      }     
     
     ArrayList<String> loadOneBlock(String name,String fileaddr)
     {
       ArrayList<String> forreturn = new ArrayList<String>();
        try{
          Document document = this.loadXML(fileaddr);
          NodeList nodeList = document.getElementsByTagName(name);
          if(nodeList.getLength()!=0){
              NodeList blocklist = nodeList.item(0).getChildNodes();
              //testing point                                       
              for(int i=0;i<blocklist.getLength();i++){
                forreturn.add(blocklist.item(i).getTextContent());
              }
          }
          else{
            this.setState("抱歉，不存在该模块....");    
          }
        }
          catch(Exception e){
            this.setState("查找记录失败.....");    
         }
       return forreturn;
     }

     ArrayList<String> LoadBlockList(String fileaddr)
     {
       ArrayList<String> forreturn = new ArrayList<String>();
      try{
          Document document = this.loadXML(fileaddr);
          NodeList nodeList = document.getElementsByTagName("Scripts");
          for(int i=0;i<nodeList.item(0).getChildNodes().getLength();i++){
            forreturn.add(nodeList.item(0).getChildNodes().item(i).getNodeName());  
          }
        }
          catch(Exception e){
            this.setState("查找记录失败.....");    
         }       
       return forreturn;           
     }

  
}
