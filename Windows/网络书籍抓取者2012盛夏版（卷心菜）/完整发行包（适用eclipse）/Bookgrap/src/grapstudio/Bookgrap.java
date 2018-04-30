package grapstudio;
import java.io.*; 
import java.net.*; 
import java.util.regex.*;


public class Bookgrap { 

	/** 
	 * @param args 
	 */ 
	public static void main(String[] args) { 
		// TODO Auto-generated method stub 
		   String strUrl = null;
	   try { 
		   BufferedReader store = new BufferedReader(new FileReader("D:/Program Files/Smith/Bookgrap/shuku.txt ")); 
		   strUrl=store.readLine();
	    	while((strUrl=store.readLine())!=null)
	    	{ 		
	    		
				   boolean kaishi = false;    //标记左括号的出现
				   boolean jieshu = false;    //标记右括号的出现
				   String zuo = "<div id=.contTxt. class=.contTxt1.>";
				   String you = " <div style=.width.99%.text-align.center.>";
				   Pattern p = Pattern.compile("<.+?>");     //去除标签杂物等
				   Pattern bracket1 = Pattern.compile(zuo);   //开始括号（包围内容）
				   Pattern bracket2 = Pattern.compile(you);    //收括号 
			             
				   
				   URL url = new URL(strUrl);                              
				   InputStreamReader isr = new InputStreamReader(url.openStream());    //打开链接
		
			       BufferedReader br = new BufferedReader(isr); 
			       String str = null;      //str用来读取具体的内容
			       String string = null;
			     while ((str = br.readLine() )!= null) {   
			    	 
						Matcher m2 = bracket1.matcher(str);
						if(m2.find())
						{
							kaishi = true;
						
						}
						if(kaishi)
						{
							Matcher m1 = p.matcher(str);
							if(m1.find())
							{
								string = m1.replaceAll("");
							}
						 System.out.println(string);
						
						}
						Matcher m3 = bracket2.matcher(str);
						if(m3.find())
						{
							jieshu = true;
						}
						if(jieshu)
						{
							break;
						}
					}
				            
	             br.close();        
	    	}
	 } catch (IOException e) 
	 {            
	        e.printStackTrace();    
	      }    
	  } 
		 
	} 

