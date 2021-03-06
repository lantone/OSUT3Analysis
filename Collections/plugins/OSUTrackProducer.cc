#include "OSUT3Analysis/Collections/plugins/OSUTrackProducer.h"

#if IS_VALID(tracks)

#include "OSUT3Analysis/AnaTools/interface/CommonUtils.h"

OSUTrackProducer::OSUTrackProducer (const edm::ParameterSet &cfg) :
  collections_ (cfg.getParameter<edm::ParameterSet> ("collections")),
  cfg_ (cfg)
{
  collection_ = collections_.getParameter<edm::InputTag> ("tracks");

  produces<vector<osu::Track> > (collection_.instance ());
}

OSUTrackProducer::~OSUTrackProducer ()
{
}

void
OSUTrackProducer::produce (edm::Event &event, const edm::EventSetup &setup)
{
  edm::Handle<vector<TYPE (tracks)> > collection;
  if (!anatools::getCollection (collection_, collection, event, false))
    return;
  edm::Handle<vector<osu::Mcparticle> > particles;
  anatools::getCollection (edm::InputTag ("", ""), particles, event);

  pl_ = auto_ptr<vector<osu::Track> > (new vector<osu::Track> ());
  for (const auto &object : *collection)
    {
      const osu::Track track (object, particles, cfg_);
      pl_->push_back (track);
    }

  event.put (pl_, collection_.instance ());
  pl_.reset ();
}

#include "FWCore/Framework/interface/MakerMacros.h"
DEFINE_FWK_MODULE(OSUTrackProducer);

#endif
