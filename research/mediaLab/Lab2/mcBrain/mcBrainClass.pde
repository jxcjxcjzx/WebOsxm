class mcBrainClass {
  public int numInputs  = 2+1; //inputs, including extra input bias
  public int numHidden  = 5; //number of hidden units
  public int numPatterns=400; //number of training patterns
  public double LR_IH = 0.15; //learning rate
  public double LR_HO = 0.015; //learning rate

  //process variables
  public int patNum;
  public double errThisPat;
  public double[] outPred; // = new double[numPatterns];
  public double RMSerror;

  //training data
  public double[][] trainInputs; //  = new double[numPatterns][numInputs];
  public double[] trainOutput; // = new double[numPatterns];

  //the outputs of the hidden neurons
  public double[] hiddenVal  = new double[numHidden];

  public double[][] hiddenValPRES = new double[numPatterns][numHidden]; //for presentation only

  //the weights
  public double[][] weightsIH = new double[numInputs][numHidden];
  public double[] weightsHO = new double[numHidden];
  
  //predicted outputs
  int epoch;
  boolean initDone=false;
  boolean trainingDataSet=false;
  
  boolean debug=true;
  
  public mcBrainClass() {
  }

  public void init() {
    initWeights();
    epoch=0;
    initDone=true;
  }

  public void setTrainingData(int tAO, double[][] tTI, double[] tTO) {
    this.numPatterns = tAO;
    trainInputs=tTI;
    trainOutput=tTO;
    outPred=new double[tAO];
    
    hiddenValPRES=new double[tAO][numHidden];
    for (int i=0;i<tAO;i+=1) {
      for (int j=0;j<numHidden;j+=1) {
        hiddenValPRES[i][j]=0; //tTO;
      }
    }
    trainingDataSet=true;
  }
  
  public double step() {
    RMSerror=-1;
    if (trainingDataSet && initDone) {
      epoch+=1;
      for(int i = 0;i<numPatterns;i++) {
        //select a pattern at random
        patNum = i; //(int)((Math.random()*numPatterns)-0.001);
        //calculate the current network output
        //and error for this pattern
        calcNet();
        //change network weights
        WeightChangesHO();
        WeightChangesIH();
      }
      //display the overall network error
      //after each epoch
      calcOverallError();
      if (debug) System.out.println("epoch = " + epoch + "  RMS Error = " + RMSerror);
    }
    return RMSerror;
  }
  
  private void calcNet() {
    //calculate the outputs of the hidden neurons
    //the hidden neurons are tanh
    for(int i = 0;i<numHidden;i++) {
      hiddenVal[i] = 0.0;
      for(int j = 0;j<numInputs;j++)
        hiddenVal[i] = hiddenVal[i] + (trainInputs[patNum][j] * weightsIH[j][i]);
      hiddenVal[i] = tanh(hiddenVal[i]);
      hiddenValPRES[patNum][i]=hiddenVal[i];
    }
    //calculate the output of the network
    //the output neuron is linear
    outPred[patNum] = 0.0;

    for(int i = 0;i<numHidden;i++)
      outPred[patNum] = outPred[patNum] + hiddenVal[i] * weightsHO[i];
      //calculate the error
      errThisPat = outPred[patNum] - trainOutput[patNum];
  }

  private void WeightChangesHO() {
    for(int k = 0;k<numHidden;k++) {
      double weightChange = LR_HO * errThisPat * hiddenVal[k];
      weightsHO[k] = weightsHO[k] - weightChange;
      //regularisation on the output weights
      if (weightsHO[k] < -1)
        weightsHO[k] = -1;
      else if (weightsHO[k] > 1)
        weightsHO[k] = 1;
    }
  }


  private void WeightChangesIH() {
    for(int i = 0;i<numHidden;i++) {
      for(int k = 0;k<numInputs;k++) {
        double x = 1 - (hiddenVal[i] * hiddenVal[i]);
        x = x * weightsHO[i] * errThisPat * LR_IH;
        x = x * trainInputs[patNum][k];
        double weightChange = x;
        weightsIH[k][i] = weightsIH[k][i] - weightChange;
      }
    }
  }

  private void initWeights() {
    for(int j = 0;j<numHidden;j++) {
      weightsHO[j] = (Math.random() - 0.5)/2;
      for(int i = 0;i<numInputs;i++)
        weightsIH[i][j] = (Math.random() - 0.5)/5;
    }
  }

  private double tanh(double x) {
    if (x > 20)
      return 1;
    else if (x < -20)
      return -1;
    else {
      double a = Math.exp(x);
      double b = Math.exp(-x);
      return (a-b)/(a+b);
    }
  }

  private void calcOverallError() {
    RMSerror = 0.0;
    for(int i = 0;i<numPatterns;i++) {
      patNum = i;
      calcNet();
      RMSerror = RMSerror + (errThisPat * errThisPat);
    }
    RMSerror = RMSerror/numPatterns;
    RMSerror = java.lang.Math.sqrt(RMSerror);
  }
}
