String[] permutation;
int center,h,w;
int bottom;
float Pvalues[],
      Ivalues[],
      Fvalues[],
      FiValues[],
      FRDvalues[],
      FRSvalues[],
      TFvalues[],
      TRvalues[];

void setup(){
  
  String[] permutation = loadStrings("tri permutation.txt");
  String[] insertion = loadStrings("tri insertion.txt");
  String[] factoriel = loadStrings("factoriel.txt");
  String[] fibonacci = loadStrings("fibonacci.txt");
  String[] rechercheDichotomique = loadStrings("recherche dichotomique.txt");
  String[] rapide = loadStrings("tri rapide.txt");
  String[] fusion = loadStrings("tri fusion.txt");
  
  size(1024,800);
  w=1024;
  h=800;
  println("there are " + permutation.length + " values");
  Pvalues = new float[permutation.length];
  Ivalues = new float[insertion.length];
  Fvalues = new float[factoriel.length];
  FiValues = new float[fibonacci.length];
  FRDvalues = new float[rechercheDichotomique.length];
  TFvalues =  new float[fusion.length];
  TRvalues = new float[rapide.length];
  
  for (int i = 0 ; i < fusion.length-1; i++) { 
    TFvalues[i] = Float.parseFloat(fusion[i]) * 1000;
    println(Float.parseFloat(fusion[i]));
  }
  for (int i = 0 ; i < rapide.length-1; i++) { 
    TRvalues[i] = Float.parseFloat(rapide[i]) * 1000;
    println(Float.parseFloat(rapide[i]));
  }
  for (int i = 0 ; i < rechercheDichotomique.length-1; i++) { 
    FRDvalues[i] = Float.parseFloat(rechercheDichotomique[i]) * 1000;
    println(Float.parseFloat(rechercheDichotomique[i]));
  } 
  for (int i = 0 ; i < fibonacci.length-1; i++) { 
    FiValues[i] = Float.parseFloat(fibonacci[i]) * 1000;
    println(Float.parseFloat(fibonacci[i]));
  } 
  for (int i = 0 ; i < factoriel.length-1; i++) { 
    Fvalues[i] = Float.parseFloat(factoriel[i]) * 1000;
    println(Float.parseFloat(factoriel[i]));
  }
  for (int i = 0 ; i < permutation.length-1; i++){ 
    Pvalues[i] = Float.parseFloat(permutation[i]) * 1000;
    println(Float.parseFloat(permutation[i]));
  }
  for (int j = 0 ; j < insertion.length-1; j++) {
   
    Ivalues[j] = Float.parseFloat(insertion[j]) * 1000;
    println(Float.parseFloat(insertion[j]));
  }
  
  
  center = w/2;
  bottom= h - h/10;



}

void draw(){
  background(0,0,0);
  drawAxes();
  stroke(255,255,0);
  drawGraph(Pvalues);
  stroke(0,255,255);
  drawGraph(Ivalues);
  stroke(255,0,255);
  drawGraph(Fvalues);
  stroke(150,100,170);
  drawGraph(FiValues);
  stroke(0,100,150);
  drawGraph(FRDvalues);
  

save("graphe.jpg");


}

void drawGraph(float Tab[]){
  
  beginShape(LINES);
  for (int i = 1 ; i < Tab.length; i++) {
  vertex( i+10 ,(bottom - (int(Tab[i])) )  );
  }
  endShape();
  

}

void drawAxes(){
  stroke(10);
  beginShape(LINES);
  strokeWeight(1);
  stroke(255,255,255);
  vertex(0,0);
  vertex(0,h);
  stroke(255,255,255);
  vertex(0,bottom);
  vertex(w,bottom);
  endShape();
  
  //for (int i = 1 ; i < width; i++) {
  //beginShape(LINES);
  //vertex(i+10,bottom-15);
  //vertex(i+10,bottom-10);
  //endShape();
  //} 
  
  


}
