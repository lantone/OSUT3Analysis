#!/usr/bin/env python

# to be run with submitToCondor.py -l protoBatchConfig.py

# import the definitions of all the datasets on the T3
from OSUT3Analysis.Configuration.configurationOptions import *

# specify which config file to pass to cmsRun
config_file = "protoConfig_cfg.py"

# choose luminosity used for MC normalization
#intLumi = 19700 # from 8 TeV MuEG dataset
intLumi = 2460 # from 13 TeV silver json file

# create list of datasets to process
datasets = [
    'MuonEG_2015D_v4',
    'WJetsToLNu',
    'SingleTop_tW',
    'DYJetsToLL_50'
    'TTJets_DiLept'
]

InputCondorArguments = {}
