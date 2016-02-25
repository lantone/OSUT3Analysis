#ifndef PUSCALING_FACTOR_PRODUCER
#define PUSCALING_FACTOR_PRODUCER

#include "OSUT3Analysis/AnaTools/interface/EventVariableProducer.h"
#include "OSUT3Analysis/AnaTools/interface/DataFormat.h"
#include "OSUT3Analysis/AnaTools/interface/ValueLookupTree.h"
#include "DataFormats/Math/interface/deltaR.h"
#include <string>
#include "TH2D.h"
#include "TH2F.h"
#include "TFile.h"
class ObjectScalingFactorProducer : public EventVariableProducer
  {
    public:
        ObjectScalingFactorProducer (const edm::ParameterSet &);
	~ObjectScalingFactorProducer ();
        Collections handles_;

    private:
        string muonFile_; 
        string electronFile_; 
        string electronWp_; 
        string muonWp_; 
        bool doEleSF_; 
        bool doMuSF_; 
        void AddVariables(const edm::Event &);
};
#endif
