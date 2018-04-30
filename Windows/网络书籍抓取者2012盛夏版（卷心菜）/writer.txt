package writer;
import java.io.*;

public class Addresswriter2012{ 

	/** 
	 * @param args 
	 */ 
	public static void main(String[] args){ 
		// TODO Auto-generated method stub 

		 try { 
			    int start =165381;     //开始的页面
			    int end =  165431;     //结束的位置
			    int i=0;
			    File   file=new   File( "D:/Program Files/Smith/Bookgrap/shuku.txt "); 
	            BufferedWriter   out=new   BufferedWriter( new   FileWriter(file,true)); 
	            String content = "http://vip.book.sina.com.cn/book/chapter_195934_"+start+".html";
	            for(i=0;i<=end-start;i++)
			    {
					    content =  "http://vip.book.sina.com.cn/book/chapter_195934_"+start+".html";
		                out.write(content);
					    out.newLine();
					    start++;
			    }
			    
			    
			    out.close(); 
	            out=null; 
	            file=null; 
	            System.out.println("success write in!");

			} catch (IOException e) { 
				e.printStackTrace(); 
			} 
	                             
			 
		 
	
	}
}