#ifndef KRAnal_h
#define KRAnal_h
//#include "mktreedstchain_sct_fitABC.hxx"
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1.h>
#include <TH2.h>
#include <TH3.h>
#include <TEventList.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include "TCanvas.h"
#include "ClassName.h"
#include "utility.h"
#include "TLorentzVector.h"
#include "TCutG.h"


class KRAnal: public InheritClass {

  TFile *theOut;
  Char_t theOutFileName[64];
  Bool_t WriteTree;
  Int_t Pen;
  TFile *f;
  
  Int_t OpenGeometry(); // Gets the geometry information
  void CreateHistos();
  void WriteHistos();
  //void WriteTGraphs();
  

 public:
  KRAnal(TTree *tree=0);
  ~KRAnal();
  void   Init();
  void   Loop(Char_t *file);
  Int_t  ReadLine(FILE *fID, char *line);
  void SetWriteTree(Bool_t f) {WriteTree = f;}
  void SetEnergy(int en) {Pen = en;}

  float a0_1,a1_1,a2_1,tls0_1,p14_1,p04_1,p24_1;
  float p10_1,p12_1,p13_1,p20_1,p22_1,p23_1;
  float tm1_1, tm2_1;

  float a0_2,a1_2,a2_2,tls0_2,p14_2,p04_2,p24_2;
  float p10_2,p12_2,p13_2,p20_2,p22_2,p23_2;
  float tm1_2, tm2_2;

  Int_t mod_1,evnb_1;
  Int_t mod_2,evnb_2;
  
  TH2F *htm1tm2_1, *htm1tm2_2;
  TH2F *htm1Ltm1R, *htm2Ltm2R;
  TH2F *henLenR, *henLenRcut;

  float p0_1[20], p1_1[20], p2_1[20];
  float p0_2[20], p1_2[20], p2_2[20];
  float enCsI1, enCsI2, en_1, en_2;
  float enCsI1_1, enCsI2_1;
  float enCsI1_2, enCsI2_2;
  
 
  TCutG *cutg[16];
  TCutG *cutg1[16];
  TCutG *cutg2[16];


 TCutG *fcut1_mod14;
 TCutG *fcut2_mod5;

 TGraph *gr[5];
 TCanvas *c1;

 float p14min[20],p14max[20];
 float p24min[20],p24max[20];


};



R__EXTERN KRAnal *gKRA; // external pointer to KRAnal.

#endif


