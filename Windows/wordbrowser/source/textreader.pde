//the objects are listed as follows:
//filename,[]wordsrelated,mainword,[]lines
//the []lines are the array that will take the words in
//functions:
//1.datain: get in the data
//2.engineforNJU:analyse the data and get every element filled
//3.getfilename : get the input file name

class textreader
{
   String filename;
   String []wordsrelated;
   String mainword;
   String []lines;
   
   void getfilename(String nameforyou)
   {
     this.filename = nameforyou;
   }
   
   void datain()
   {
      this.lines = loadStrings(this.filename);
   }
   
   void engineforNJU(String require)
   {     
     int i = 0;
     for(i=0;i<this.lines.length;i+=2)
     {
       if(require.equals(this.lines[i]))
       {
         this.mainword = require;
         this.wordsrelated = split(lines[i+1], ',');
         break;
       }
     
     }
     if(this.mainword==null){
      println("Sorry,I can not find your required word,please have a check yourself.");
     }
   }
}
