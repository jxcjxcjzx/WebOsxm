package modes;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class searchmode {
	/**
	 * variables: String fileUrl (the file address to be read in)
	 * functions: String[] getwords() (to get the key words for searchmode)
	 */
   	
	private String fileUrl = "searchmode.txt";
	public String[] getwords()
	{
		String []a = null;
		String duchu = null;
		try{
			   int lengthofrecord = 0;
			   BufferedReader store = new BufferedReader(new FileReader(fileUrl)); 
			   while((duchu = store.readLine())!=null)
			   {
				   lengthofrecord ++;
			   }
			   a = new String[lengthofrecord];
			   store.close();
			   store = new BufferedReader(new FileReader(fileUrl)); 
			   for(int i = 0;i<lengthofrecord;i++){
			     a[i] = store.readLine();
			   }
		}
		catch (IOException e){           
		        e.printStackTrace();    
		}   
		return a;
	}
}
