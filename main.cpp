#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "tissue.hpp"

using namespace std;

int lecInput(string inFile, int &numAct, int &numQuie, double &p,
	     double &alpha, double &beta, double &GammaAct,
	     double &GammaQuie);


int main(){
  string inFile("in.dat"), outFile("out.res");
  int numAct, numQuie;
  double p, alpha, beta, GammaAct, GammaQuie;

  lecInput(inFile, numAct, numQuie, p, alpha, beta, GammaAct,
	   GammaQuie);
  Tissue tissue(numAct, numQuie, p, alpha, beta, GammaAct,
		GammaQuie);
  
  cout << "Initial number of cells : " << tissue.getNumCells()
       << endl;
  cout << "Initial number of active cells : " << tissue.getNumAct()
       << endl;
  cout << "Initial number of quiescent cells : " <<
    tissue.getNumQuie() << endl;
  
  ofstream stream(outFile.c_str());
  stream << tissue.getNumCells() << " " << tissue.getNumAct() <<
    " " << tissue.getNumQuie() << endl;
  
  int numIter(10);
  srand(time(NULL));
  for(int k(0); k < numIter; k++){
    tissue.updateTissue();
    stream << tissue.getNumCells() << " " << tissue.getNumAct() <<
      " " << tissue.getNumQuie() << endl;
  }

  stream.close();
  cout << "Final number of cells : " << tissue.getNumCells()
       << endl;
  cout << "Final number of active cells : " << tissue.getNumAct()
       << endl;
  cout << "Final number of quiescent cells : " <<
    tissue.getNumQuie() << endl;

  return 0;
}


int lecInput(string inFile, int &numAct, int &numQuie, double &p,
	     double &alpha, double &beta, double &GammaAct,
	     double &GammaQuie){
  ifstream stream(inFile.c_str());
  stream >> numAct >> numQuie >> p >> alpha >> beta >> GammaAct >>
    GammaQuie;
  stream.close(); 
}
