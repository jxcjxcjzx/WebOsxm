/*class Point {
  float x,y,xv = 0, yv = 0;
  float maxSpeed = 3000000;

  Boolean finished = false;

  Point(float x, float y){
    this.x = x;
    this.y = y;
  } 

  void update(){
    stroke(0,16);
    float r = random(1);
    this.xv = cos(  noise(this.x*.01,this.y*.01)*TWO_PI  );
    this.yv = -sin(  noise(this.x*.01,this.y*.01)*TWO_PI  );

    if(this.x>width){
      //this.x = 1;
      this.finished = true;
    }
    else if(this.x<0){
      //this.x = width-1;
      this.finished = true;
    }
    if(this.y>height){
      //this.y = 1;
      this.finished = true;
    }
    else if(this.y<0){
      //this.y = height-1;
      this.finished = true;
    } 

    if(this.xv>maxSpeed){
      this.xv = maxSpeed;
    }
    else if(this.xv<-maxSpeed){
      this.xv = -maxSpeed;
    }
    if(this.yv>maxSpeed){
      this.yv = maxSpeed;
    }
    else if(this.yv<-maxSpeed){
      this.yv = -maxSpeed;
    }

    this.x += this.xv;
    this.y += this.yv;

    line(this.x+this.xv, this.y+this.yv,this.x,this.y );
  }

}


*/
