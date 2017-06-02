
#include <QThread>

#include <QApplication>

#include <QWidget>
#include <QMessageBox>


void msleep(int64_t ms){
  QThread::msleep(ms);
}


static void kill_jackd(void){
  
  for(int i=0;i<20;i++){
#if defined(FOR_LINUX) || defined(FOR_MACOSX)
    const char *command2 = "killall -9 jackd";
    const char *command3 = "killall -9 jackdmp";    
#elif defined(FOR_WINDOWS)
    const char *command2 = "taskkill /F /T /IM jackd.exe";
    const char *command3 = "taskkill /F /T /IM jackdmp.exe";
#endif
    
    fprintf(stderr, "Executing\n   \"%s\"\n   \"%s\"\n", command2, command3);

    msleep(1);
    
    if (system(command2)==0){
      //return;
    }
    
    if (system(command3)==0){
      //return;
    }

#if defined(FOR_MACOSX)
    const char *command4 = "killall -9 JackPilot"; // On OSX, jack pilot needs to be restarted after jackd has been killed. (if not, it shows a message about needing to restart the system)
    system(command4);
#endif
    
    msleep(250);
  }
}

namespace{
  
class KillThread : public QThread
{
  void run() override {
    kill_jackd();
  }
};

}


int main(int argc, char **argv){
  QApplication app(argc, argv);

  QMessageBox *progressBox = new QMessageBox();
  //progressBox->setStandardButtons(0);
  progressBox->setText("Please wait, trying to kill Jack.");
  progressBox->show();

  auto *kill_thread = new KillThread();
  kill_thread->start();
  
  while(!kill_thread->isFinished()){
    QCoreApplication::processEvents();
    msleep(10);
  }

  progressBox->setText("Jack is probably dead now. Now you can restart Jack and your applications.");
  progressBox->show();
  app.exec();
  
  return 0;
}

