import krister.Ess.*;
 
FFT myfft;
AudioInput myinput;
 
int bufferSize=512;
int x, y, s;
int gap = 60;
 
void setup() {
  size(800, 600);
  stroke(0);
  frameRate(5);
  reset();
 
  Ess.start(this);
  myinput=new AudioInput(bufferSize);
  myfft=new FFT(bufferSize*2);
  myinput.start();
 
  myfft.damp(0.1);
  myfft.equalizer(true);
  myfft.limits(.01, .01);
}
 
void reset() {
  background(255);
  x = 0;
  y = 0;
}
 
void draw() {
 
  for (int i=0; i<bufferSize;i++) {
 
     myfft.spectrum[i] = myfft.spectrum[i]*1000;
    float yValue = constrain(myfft.spectrum[i], 1, 3);
 
    point(x++, myfft.spectrum[i]);
 
    println(myfft.spectrum[i]);
  }
 
 
  //point(x++, y);
  if (x>=width) { 
    y+=gap; 
    x=0;
  }
  if (y>=height) reset();
}
 
public void audioInputData(AudioInput theInput) {
  myfft.getSpectrum(myinput);
}