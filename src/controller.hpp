//CONTROLLER
#ifndef NEUROMAG2MNE_CONTROLLER_HPP
#define NEUROMAG2MNE_CONTROLLER_HPP

#include <iostream>
#include <queue>

#include "neuromag2mne.hpp"
#include "utils/scopedpointer.hpp"
#include "utils/sharedpointer.hpp"
#include "utils/multithreadqueue.hpp"
#include "utils/data.hpp"

class InputArgumentsParser;
namespace neuromag { class NeuromagController; }
namespace randomData { class RandomDataController;}
namespace fiff { class FileController; }
namespace dataSender { class DataSenderController; }

class Controller
{
public:
  Controller();
  ~Controller();
  void start();
  void stop();
  void parseInputArguments(int argc, char* argv[]);

private:
  enum SourceModeType
  {
    NEUROMAG,
    RANDOM_DATA,
    FILE_READ
  };
  void run();
  static void displayHelp(const std::string& helpStr);

  inline bool dataAvailable() const;
  void checkForNewData();

  void configureNeuromagController();
  void configureRandomDataController();
  void configureFileReaderController();

  void configureFileWriterController();
  void configureDataSenderController();
  void sendData();
  void prepareToExitApplication();

  bool mContinueRunning;
  unsigned int muSecondsSleepTime;

  bool mVerboseMode;
  SourceModeType mSourceMode;
  std::string mFileNameToRead;
  bool mSendDataMode;
  bool mSaveToFileMode;
  std::string mFileNameToSave;

  ScopedPointer<InputArgumentsParser> mInputArgumentsController;

  ScopedPointer<neuromag::NeuromagController> mNeuromagController;
  ScopedPointer<randomData::RandomDataController> mRandomDataController;
  ScopedPointer<fiff::FileController> mFileReaderController;

  ScopedPointer<dataSender::DataSenderController> mDataSenderController;
  ScopedPointer<fiff::FileController> mFileWriterController;

  SharedPointer<MultiThreadQueue<SharedPointer<Data> > > mDataQueue;
};

#endif // NEUROMAG2MNE_CONTROLLER_HPP

