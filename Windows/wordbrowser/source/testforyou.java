import processing.core.*; 
import processing.xml.*; 

import java.applet.*; 
import java.awt.Dimension; 
import java.awt.Frame; 
import java.awt.event.MouseEvent; 
import java.awt.event.KeyEvent; 
import java.awt.event.FocusEvent; 
import java.awt.Image; 
import java.io.*; 
import java.net.*; 
import java.text.*; 
import java.util.*; 
import java.util.zip.*; 
import java.util.regex.*; 

public class testforyou extends PApplet {

float x1;
float y1;
int i = 0;
int ceshix;
int ceshiy;
int top = 200;
int current = 0;
float newposx;
float newposy;
String []reading;
int leftedge = 10;
String []text = {"ballad","barrel","barren","beast","bed","bend","benefit","bestow","verse","via","vibrant","wagon","vow","vote","volume"};
node []noderel = new node[60];
String requireword = "abandon";
String inputfile = "wordnet2.txt";
ArrayList Nodes = new ArrayList();

public void setup()
{
  size(1320,630);
  smooth();
  reading = posgene(requireword);
  background(55,182,219);
  node nodeexp = (node)Nodes.get(0);
  nodeexp.getradius(random(100.0f,120.0f));
  newposx = width/2+random(80.0f);
  newposy = height/2+random(20.0f);
  nodeexp.paintme();
   for(i=1;i<nodeexp.wordsrelated.length;i++)
   {
    noderel[i] = (node)Nodes.get(i);
    noderel[i].getradius(random(70.0f,90.0f));
    noderel[i].posx = nodeexp.posx+cos(PI/6*i)*((i*10)+220);
    noderel[i].posy = nodeexp.posy+sin(PI/6*i)*((i*10)+220);
    noderel[i].paintme();
    line(nodeexp.posx,nodeexp.posy,noderel[i].posx,noderel[i].posy);
   }
   PFont cli = loadFont("Corbel-Italic-29.vlw");  //here we load the font
   textFont(cli);
    for(int i=0;i<reading.length;i+=2)
   {
      text(reading[i],leftedge,i*20+top);
   }   
}

public void draw()
{   
    background(55,182,219);
    node nodeexp = (node)Nodes.get(0);
    nodeexp.paintme();
    for(i=1;i<nodeexp.wordsrelated.length;i++)
   {
    noderel[i] = (node)Nodes.get(i);
    if((mouseX-noderel[i].posx)*(mouseX-noderel[i].posx)+(mouseY-noderel[i].posy)*(mouseY-noderel[i].posy)<noderel[i].radius*noderel[i].radius)
    {
      noderel[i].altercolor = true;
    }
    else
    {
      noderel[i].altercolor = false;
    }
    noderel[i].paintme();
    line(nodeexp.posx,nodeexp.posy,noderel[i].posx,noderel[i].posy);
   }
  listwords(leftedge,reading,70,2000);
}


public String [] posgene(String require)  //the position generator
{
  textreader reader = new textreader();
  reader.getfilename(inputfile);
  reader.datain();
  reader.engineforNJU(require);
  node nodeforjxc = new node();
  nodeforjxc.getword(reader.mainword);
  nodeforjxc.getrelwords(reader.wordsrelated);
  nodeforjxc.getradius(random(120.0f));
  nodeforjxc.getpos(width/2+random(80.0f),height/2+random(20.0f));
  Nodes.add(nodeforjxc);
  for(int i = 1;i<nodeforjxc.wordsrelated.length;i++)
  {
    node alsoforjxc = new node();
    alsoforjxc.getword(nodeforjxc.wordsrelated[i]);
    Nodes.add(alsoforjxc);
  }
  return reader.lines;
}

public void listwords(int leftedge,String []results,int rate,int secondrate)
 {
   top-=10;
   for(int i=0;i<results.length;i+=2)
   {
     text(results[i],leftedge,i*20+top); 
   }
     if((results.length*20+top)<height/10){
      top = 200;
     }
     if(mouseX<100){
      delay(secondrate);
      textinitial(results,top);
      }
   else{
   delay(rate);
     }  
 }

public void mousePressed()
{
   x1 = mouseX;
   y1 = mouseY;
   if(mouseButton==LEFT&&mouseX<100){
   int index = mouseY/(height/15);
   reading = gettextandpaint(index);
   }
   else{
}
}

public String[] gettextandpaint(int indexoflist)
 {
   String[] success;
   Nodes = new ArrayList();
   success =posgene(text[indexoflist]);
   initial(success,(node)Nodes.get(0));
   return success;
 }


public void initial(String []relshuzu,node nodeexp)
{
  nodeexp.getradius(random(100.0f,120.0f));
  newposx = width/2+random(80.0f);
  newposy = height/2+random(20.0f);
  for(int i=1;i<nodeexp.wordsrelated.length;i++)
   {
    noderel[i] = (node)Nodes.get(i);
    noderel[i].getradius(random(70.0f,90.0f));
    noderel[i].posx = nodeexp.posx+cos(PI/6*i)*((i*10)+220);
    noderel[i].posy = nodeexp.posy+sin(PI/6*i)*((i*10)+220);
    noderel[i].paintme();
    line(nodeexp.posx,nodeexp.posy,noderel[i].posx,noderel[i].posy);
   }

}


public void textinitial(String []succeed,int high)
{
  int forjudge;
  for(int i=0;i<succeed.length;i+=2)
   {
     forjudge = (i*20+high)*15/height;
     if(forjudge>=0&&forjudge<15){
       text[forjudge] = succeed[i];
     }
   }
}
//the class node has several functions as listed down:
// node object: posx,posy,mainword,[]wordsrelated
//1.getpos  : get the position of the node ,return the node object,isclicked
//2.getradius:get the radius for bubble
//3.getword : get the text content to be shown 
//4.getwords: get the related words
//5.paintme : draw the picture you want
class node
{
   float posx=1;
   float posy=1;
   String []wordsrelated;
   String mainword;
   float radius;
   boolean isclicked = false;
   boolean altercolor = false;
   public void getpos(float x1,float y1)
   {
     this.posx = x1;
     this.posy = y1;
   }
   
   public void getradius(float x)
   {
     this.radius = x;
   }
   
   public void getword(String word)
   {
     this.mainword = word;   
   }
   
   public void getrelwords(String []wordsrel)
   {
     this.wordsrelated = wordsrel;
   }
   
   public void paintme()
   {
     if(!altercolor){
     fill(190,245,54);
     }
     else{
     fill(31,206,102);
     }
     ellipse(this.posx+10,this.posy,this.radius,this.radius);
     fill(245,56,22);
     if(this.mainword!=null){
     text(this.mainword,this.posx-24,this.posy+9);
   }
   }
   
   public void moveself(float posx,float posy)
   {
     float shitx = (posx - this.posx)/10;
     float shity = (posy - this.posy)/10;
     for(int i = 0;i<10;i++)
     {
       this.posx+=shitx;
       this.posy+=shity;
       background(247,75,150);
       this.paintme();
       delay(20);
     }
   }

}
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
   
   public void getfilename(String nameforyou)
   {
     this.filename = nameforyou;
   }
   
   public void datain()
   {
      this.lines = loadStrings(this.filename);
   }
   
   public void engineforNJU(String require)
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
  static public void main(String args[]) {
    PApplet.main(new String[] { "--present", "--bgcolor=#666666", "--stop-color=#cccccc", "testforyou" });
  }
}
