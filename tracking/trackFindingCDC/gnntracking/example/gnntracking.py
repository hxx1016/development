#!/usr/bin/env python3

#################################################################
# basf2 (Belle II Analysis Software Framework)                           #
# Author: The Belle II Collaboration                                     #
#                                                                        #
# See git log for contributors and copyright holders.                    #
# This file is licensed under LGPL-3.0, see LICENSE.md.                  #
##########################################################################

from basf2 import set_log_level, register_module, process, LogLevel, \
    set_random_seed, print_params, create_path, statistics

# suppress messages and warnings during processing:
set_log_level(LogLevel.WARNING)

# to run the framework the used modules need to be registered
Gnntracking = register_module('gnntracking')
#a.readAndPrintTXT("/sdufs/home/huxx/data/1.txt")
print(type(Gnntracking))
#Gnntracking.param(0)
# Create Event information
eventinfosetter = register_module('EventInfoSetter')
# generate one event
eventinfosetter.param('expList', [0])
eventinfosetter.param('runList', [1])
eventinfosetter.param('evtNumList', [1])
eventinfoprinter = register_module('EventInfoPrinter')
# Show progress of processing
progress = register_module('Progress')
# Load parameters
gearbox = register_module('Gearbox')
# Create geometry
geometry = register_module('Geometry')
# simulate CDC only; B-field outside CDC = 0
geometry.param('components', ['MagneticFieldConstant4LimitedRCDC', 'CDC'])

# Save output of simulation
main = create_path()
#main.add_module()
main.add_module(eventinfosetter)
main.add_module(eventinfoprinter)
#main.add_module(eventinfosetter)
main.add_module(gearbox)
main.add_module(geometry)
main.add_module(progress)
main.add_module(Gnntracking)
# Process events
process(main)
print(111)
# Print call statistics
#print(statistics)
