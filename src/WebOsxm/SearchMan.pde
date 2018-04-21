import org.apache.lucene.document.*;
import org.apache.lucene.index.DirectoryReader;
import org.apache.lucene.index.IndexReader;
import org.apache.lucene.index.IndexWriter;
import org.apache.lucene.index.IndexWriterConfig;
import org.apache.lucene.index.Term;
import org.apache.lucene.queryparser.surround.parser.ParseException;
import org.apache.lucene.queryparser.surround.parser.QueryParser;
import org.apache.lucene.queryparser.surround.query.SrndQuery;
import org.apache.lucene.search.IndexSearcher;
import org.apache.lucene.search.PhraseQuery;
import org.apache.lucene.search.Query;
import org.apache.lucene.search.ScoreDoc;
import org.apache.lucene.search.TermQuery;
import org.apache.lucene.store.Directory;
import org.apache.lucene.store.FSDirectory;
import org.apache.lucene.store.RAMDirectory;
import org.apache.lucene.util.Version;
import org.apache.lucene.analysis.*;
import org.apache.lucene.analysis.standard.StandardAnalyzer;
import org.apache.lucene.analysis.cn.*;
import org.apache.lucene.analysis.cn.smart.SmartChineseAnalyzer;
import java.awt.FileDialog; 
import java.text.SimpleDateFormat;
import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.io.File;
import java.sql.Date;

class SearchMan
{  
  ArrayList<String> results = new ArrayList<String>();
  String PathBase = "F:/WebOSIndex/";
  ArrayList<File> indexarray = new ArrayList<File>();
  String dirpath = "";
  
  
  boolean Judge_For_Index(String fileaddr,int bidui,int datahold){
    boolean forreturn =false;
    try{
      File a = new File(fileaddr);
      Date b = new Date(a.lastModified());     
      SimpleDateFormat sdf_copy = new SimpleDateFormat("yyyyMMdd");
      String ss_copy = sdf_copy.format(b);
      int ss_bidui = Integer.parseInt(ss_copy);
      int one = (ss_bidui/10000)*365+((ss_bidui-((ss_bidui/10000)*10000))/100)*30+(ss_bidui-((ss_bidui/100)*100));
      int two = (bidui/10000)*365+((bidui-((bidui/10000)*10000))/100)*30+(bidui-((bidui/100)*100));
      if((two-one)<datahold){
         forreturn = true;
      }    
    }
    catch(Exception e){
    }
    return forreturn;
  }

  void search(String KeyWord) throws IOException
  {
    this.results.clear();
    File path = new File(PathBase+"WebOSindex/");
    DirectoryReader ireader = null;
    for(int j=0;j<path.listFiles().length;j++){
        Directory directory = FSDirectory.open(path.listFiles()[j]);
        ireader = DirectoryReader.open(directory);
          IndexSearcher isearcher = new IndexSearcher(ireader);
          TermQuery tq = new TermQuery(new Term("filecontent", KeyWord));
          PhraseQuery parser = new PhraseQuery();
          ScoreDoc[] hits = isearcher.search(tq, 999).scoreDocs;
          for (int i = 0; i < hits.length; i++) {
              org.apache.lucene.document.Document hitDoc = isearcher.doc(hits[i].doc);
              this.results.add(hitDoc.get("filepath"));
          }
    }
      ireader.close();
  }    
  
  void IndexDir(String dirpath) throws UnsupportedEncodingException, MalformedURLException, IOException{    
        File directory = new File(dirpath);
        File[] files = directory.listFiles();
        for (int i = 0; i < files.length; i++) {
        File f = files[i];
        if (f.isDirectory()) {
          IndexDir(f.toString());
        } else if (f.getName().endsWith(".txt")) {
          indexarray.add(f);    
        }
        }
  }
  
  void index_smart_cn(int bidui,int datahold,boolean indexed) throws UnsupportedEncodingException, MalformedURLException, IOException{ 
    new FileOpen();
    if(this.dirpath!=null){
          this.indexarray.clear();
          SimpleDateFormat sdf_gettime = new SimpleDateFormat("yyyy_MM_dd_HH_mm_ss");
          String ss_gettime = sdf_gettime.format(new java.util.Date());    
          this.IndexDir(this.dirpath);
          Analyzer analyzer = new SmartChineseAnalyzer(Version.LUCENE_CURRENT);
          File path = new File(PathBase+"WebOSindex/"+ss_gettime);
          // if you only need temparel use, try the following one:
          //Directory directory = new RAMDirectory();
          Directory directory = FSDirectory.open(path);
          IndexWriterConfig config = new IndexWriterConfig(Version.LUCENE_CURRENT, analyzer);
          IndexWriter iwriter = new IndexWriter(directory, config);  
          for(int i=0;i<indexarray.size();i++){
            if(indexed){
              if(this.Judge_For_Index(indexarray.get(i).toString(),bidui,datahold)){
                IndexFile_smart_cn(indexarray.get(i).toString(),iwriter);
              }
              else{
              }
            }
            else{
              IndexFile(indexarray.get(i).toString(),iwriter);
            }
          }
          iwriter.close();
          directory.close();
    }
  }
  
  
  void index(int bidui,int datahold,boolean indexed) throws UnsupportedEncodingException, MalformedURLException, IOException{ 
    new FileOpen();
    if(this.dirpath!=null){
          this.indexarray.clear();
          SimpleDateFormat sdf_gettime = new SimpleDateFormat("yyyy_MM_dd_HH_mm_ss");
          String ss_gettime = sdf_gettime.format(new java.util.Date());    
          this.IndexDir(this.dirpath);
          Analyzer analyzer = new StandardAnalyzer(Version.LUCENE_CURRENT);
          File path = new File(PathBase+"WebOSindex/"+ss_gettime);
          // if you only need temparel use, try the following one:
          //Directory directory = new RAMDirectory();
          Directory directory = FSDirectory.open(path);
          IndexWriterConfig config = new IndexWriterConfig(Version.LUCENE_CURRENT, analyzer);
          IndexWriter iwriter = new IndexWriter(directory, config);  
          for(int i=0;i<indexarray.size();i++){
            if(indexed){
              if(this.Judge_For_Index(indexarray.get(i).toString(),bidui,datahold)){
                IndexFile(indexarray.get(i).toString(),iwriter);
              }
              else{
              }
            }
            else{
              IndexFile(indexarray.get(i).toString(),iwriter);
            }
          }
          iwriter.close();
          directory.close();
    }
  }
  
  void IndexFile(String filepath,IndexWriter iwriter) throws UnsupportedEncodingException, MalformedURLException, IOException{
    if(filepath.endsWith(".txt")){  
      main.sys_signal.set_String_signal("handle_info","index: Indexing the file : "+filepath+" for you");
      StringBuffer a = new StringBuffer();
      InputStreamReader b = new InputStreamReader(new URL("file:///"+filepath).openStream(),"utf-8");
      String readin = "";
      BufferedReader br = new BufferedReader(b); 
      while((readin=br.readLine())!=null){
        a.append(readin);
      }
      org.apache.lucene.document.Document doc = new org.apache.lucene.document.Document();
      doc.add(new Field("filepath",filepath, TextField.TYPE_STORED));
      doc.add(new Field("filecontent",a.toString(), TextField.TYPE_STORED));
      iwriter.addDocument(doc);      
    }
  }
  
 void IndexFile_smart_cn(String filepath,IndexWriter iwriter) throws UnsupportedEncodingException, MalformedURLException, IOException{
    if(filepath.endsWith(".txt")){  
      main.sys_signal.set_String_signal("handle_info","index: Indexing the file : "+filepath+" for you");
      StringBuffer a = new StringBuffer();
      InputStreamReader b = new InputStreamReader(new URL("file:///"+filepath).openStream(),"gbk");
      String readin = "";
      BufferedReader br = new BufferedReader(b); 
      while((readin=br.readLine())!=null){
        a.append(readin);
      }
      org.apache.lucene.document.Document doc = new org.apache.lucene.document.Document();
      doc.add(new Field("filepath",filepath, TextField.TYPE_STORED));
      doc.add(new Field("filecontent",a.toString(), TextField.TYPE_STORED));
      iwriter.addDocument(doc);      
    }
  }  
  
  ArrayList<String> getresults()
  {
    if(this.results.isEmpty()){
      this.results.add("This one is Empty");
    }
    else{ 
    }
    return this.results;
  } 
}





class FileOpen
{
  FileDialog fileopen;
  String filename;
  
    FileOpen()
  {
   fileopen = new FileDialog(new Frame(),"打开文件对话框",FileDialog.LOAD);   
   fileopen.addWindowListener(new WindowAdapter()
   {
     public void windowClosing(WindowEvent e)
     {
       fileopen.setVisible(false);
     }
   });
   open();
  }
    public void open()
  {
    fileopen.setVisible(true);
    main.searchit.dirpath = fileopen.getDirectory();
  } 

}
