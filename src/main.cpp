// neuromag2mne application

#include "neuromag2mne.hpp"

int main (int argc, char* argv[])
{
  ScopedPointer<Controller> controller;
  controller->parseInputArguments(argc, argv);
  controller->start();
  return 0;
}

//todo consistency in the way include guards are created
//todo logging mechanism
//todo licensing. candidate mozilla public license.
//todo testing must include coverage
//todo profiling
//todo documentation
//todo standardize use of namespace in the project
//todo think about bundling together mCommandWatcher and mDataWatcher and abstract them within a specific controller
//todo try to go through all the problems in the project and solve them.
//todo add mechanism to track version, build time and github hash, etc... you know what i mean... :)

