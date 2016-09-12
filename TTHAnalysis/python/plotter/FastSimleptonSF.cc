
#include <cmath>
#include "TH2F.h"
#include "TFile.h"

using namespace std;

TFile *_file_fastsim_el = NULL;
TFile *_file_fastsim_mu = NULL;
TH2F *_histo_fastsim_leptonSF_mu = NULL;
TH2F *_histo_fastsim_leptonSF_el = NULL;

float leptonSF_2lss_ewk_FS(int pdgid, float pt, float eta, int var=0){
  
  if (!_histo_fastsim_leptonSF_mu) {
    _file_fastsim_mu = new TFile("/mnt/t3nfs01/data01/shome/cheidegg/d/CMSSW_8_0_11/src/CMGTools/TTHAnalysis/data/leptonSF/SF2016_muon_lepMVAveryTight_FS.root", "read");
    _file_fastsim_el = new TFile("/mnt/t3nfs01/data01/shome/cheidegg/d/CMSSW_8_0_11/src/CMGTools/TTHAnalysis/data/leptonSF/SF2016_electron_lepMVAmedium_FS.root","read");
    _histo_fastsim_leptonSF_mu = (TH2F*)(_file_fastsim_mu->Get("histo2D"));
    _histo_fastsim_leptonSF_el = (TH2F*)(_file_fastsim_el->Get("histo2D"));
   }
   float out = 0.;
   TH2F *hist(0);
   int ptbin(0),etabin(0);
   if (abs(pdgid)==13){
     hist = _histo_fastsim_leptonSF_mu;
     ptbin  = std::max(1, std::min(hist->GetNbinsX(), hist->GetXaxis()->FindBin(pt)));
     etabin = std::max(1, std::min(hist->GetNbinsY(), hist->GetYaxis()->FindBin(fabs(eta))));
     out = hist->GetBinContent(ptbin,etabin);
     return out + out*0.02*var;
   }
   if (abs(pdgid)==11){
     hist = _histo_fastsim_leptonSF_el;
     ptbin  = std::max(1, std::min(hist->GetNbinsX(), hist->GetXaxis()->FindBin(pt)));
     etabin = std::max(1, std::min(hist->GetNbinsY(), hist->GetYaxis()->FindBin(fabs(eta))));
     out = hist->GetBinContent(ptbin,etabin);
     return out + out*0.02*var;
   }
   //cout << "[ERROR]!!!! SF UnKNOWN!!! PLEASE CHECK" << endl;
   return 1.;
 }


float leptonSF_3l_ewk_FS(int pdgid, float pt, float eta, int var=0){
  if (!_histo_fastsim_leptonSF_mu) {
    _file_fastsim_mu = new TFile("/afs/cern.ch/work/f/folguera/SUS/EWKino/CMSSW_8_0_11/src/CMGTools/TTHAnalysis/data/leptonSF/sf_mu_LepMVAM_FS_ICHEP.root","read");
    _file_fastsim_el = new TFile("/afs/cern.ch/work/f/folguera/SUS/EWKino/CMSSW_8_0_11/src/CMGTools/TTHAnalysis/data/leptonSF/sf_el_LepMVAM_FS_ICHEP.root","read");
    _histo_fastsim_leptonSF_mu = (TH2F*)(_file_fastsim_mu->Get("histo2D"));
    _histo_fastsim_leptonSF_el = (TH2F*)(_file_fastsim_el->Get("histo2D"));
   }
   float out = 0.;
   TH2F *hist(0);
   int ptbin(0),etabin(0);
   if (abs(pdgid)==13){
     hist = _histo_fastsim_leptonSF_mu;
     ptbin  = std::max(1, std::min(hist->GetNbinsX(), hist->GetXaxis()->FindBin(pt)));
     etabin = std::max(1, std::min(hist->GetNbinsY(), hist->GetYaxis()->FindBin(fabs(eta))));
     out = hist->GetBinContent(ptbin,etabin);
     return out + out*0.02*var;
   }
   if (abs(pdgid)==11){
     hist = _histo_fastsim_leptonSF_el;
     ptbin  = std::max(1, std::min(hist->GetNbinsX(), hist->GetXaxis()->FindBin(pt)));
     etabin = std::max(1, std::min(hist->GetNbinsY(), hist->GetYaxis()->FindBin(fabs(eta))));
     out = hist->GetBinContent(ptbin,etabin);
     return out + out*0.02*var;
   }
   //cout << "[ERROR]!!!! SF UnKNOWN!!! PLEASE CHECK" << endl;
   return 1.;
 }

