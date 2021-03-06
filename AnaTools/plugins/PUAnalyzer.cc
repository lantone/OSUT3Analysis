#include "OSUT3Analysis/AnaTools/plugins/PUAnalyzer.h"

PUAnalyzer::PUAnalyzer (const edm::ParameterSet &cfg) :
  pileUpInfo_ (cfg.getParameter<edm::InputTag> ("pileUpInfos"))
{
  TH1::SetDefaultSumw2 ();
  
  oneDHists_["pileup"] = fs_->make<TH1D> ("pileup",";pileup", 65, 0, 65);
}

PUAnalyzer::~PUAnalyzer ()
{
}

void
PUAnalyzer::analyze (const edm::Event &event, const edm::EventSetup &setup)
{
  edm::Handle<edm::View<PileupSummaryInfo> > pileUpInfos;
  event.getByLabel (pileUpInfo_, pileUpInfos);
  edm::View<PileupSummaryInfo>::const_iterator iterPU;
  double truePV = -1;
  for(iterPU = pileUpInfos->begin(); iterPU != pileUpInfos->end(); ++iterPU)
    {
      { 
        int BX = iterPU->getBunchCrossing();
        if(BX == 0)
          truePV = iterPU->getTrueNumInteractions(); 
      }
    }
  oneDHists_["pileup"]->Fill (truePV);
}

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(PUAnalyzer);
