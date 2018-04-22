package Analysor;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * variables :  oneline (one line of String from the context)
 * functions:   String get() , (boolean)whethercontain(String), String replaceblank()
 * @author jxc
 *
 */

public class stringline {
  
	private String oneline = null;
	
	stringline(String a)
	{
		this.oneline = a;		
	}
	
	public String replaceblank()
	{
		 String backstring = null;
		 Matcher match = null;
		 Pattern pipei = null;
		 pipei = Pattern.compile(" ");   
		 match = pipei.matcher(this.oneline);   
	     if(match.find()){
			   backstring = match.replaceAll("");
		}
		 return backstring;
	}
	public String get()
	{ 
	  return this.oneline;
	}

	public boolean whethercontain(String b)
	{    
		if(this.oneline==null)
			this.oneline = "¿ÕµÄÄÚÈÝ";
	 return this.oneline.contains(b);
	}
	
	public void replace(String b)
	{
	  this.oneline = b;	
	}
	
}
