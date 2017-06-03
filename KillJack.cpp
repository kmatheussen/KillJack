
#include <QThread>
#include <QTime>
#include <QApplication>

#include <QWidget>
#include <QMessageBox>

#include <QtPlugin>
Q_IMPORT_PLUGIN (QWindowsIntegrationPlugin);

#define SHOW_QUOTES_IN_DETAILED_TEXT 1

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

// https://www.rottentomatoes.com/m/kill_bill_vol_1/quotes/
static const char *quotes[] = {
  "The Bride: Those of you lucky enough to still have their lives, take them with you! However, leave the limbs you've lost. They belong to me now...except you Sofie! You stay exactly where you are.",

  "The Bride: This Pasadena homemaker's name is Jeanne Bell. Her husband is Dr. Lawrence Bell. But back when we were acquainted four years ago, her name was Vernita Green. Her code name was Copperhead. Mine, Black Mamba.",

  "The Bride: The bald guy in the black suit and the Kato Mask is Johnny Mo, the head general of O'ren's personaly army,the crazy 88. And just in case you were wondering how could a half breed Japanese-Chinese American become the boss of all bosses in Tokyo, Japan, I'll tell you. The subject of O'ren's blood and nationality came up before the council only once. The night O'ren assumed power over the crime council.",

  "Elle Driver: [to an uncounscious Beatrix] You know, I may have never liked you. Point of fact,I despise you. But that shouldn't suggest I don't respect you. [takes a needle injection from her pocket] Dying in our sleep, a luxuary our kind is rarely afforded.",

  "Vernita Green: So I suppose it's a little late for apologies, huh?<br>"
  "The Bride: You suppose correctly.<br>"
  "Vernita Green: Look bitch... I need to know if you're going to start any more shit around my baby girl.<br>"
  "The Bride: You can relax for now. I'm not going to murder you in front of your child, okay?<br>"
  "The Bride: That's being more rational than Bill lead me to believe you were capable of.<br>"
  "The Bride: It's mercy, compassion and forgiveness I lack. Not rationality.<br>",

  "O-Ren Ishii: As your leader, I encourage you from time to time, and always in a respectful manner, to question my logic. If you're unconvinced that a particular plan of action I've decided is the wisest, tell me so, but allow me to convince you and I promise you right here and now, no subject will ever be taboo. Except, of course, the subject that was just under discussion. The price you pay for bringing up either my Chinese or American heritage as a negative is... I collect your fucking head. Just like this fucker here. Now, if any of you sons of bitches got anything else to say, now's the fucking time!",

  "The Bride: Your name is Buck... right?<br>"
  "Buck: [nods]<br>"
  "The Bride: And you came to FUCK... RIGHT\?\?\?<br>"

  "The Bride: We have unfinished business.",

  "Budd: That woman deserves her revenge...and we deserve to die.",

  "The Bride: I didn't say sell me. I said give me.",

  "The Bride: What are you doing here?<br>"
  "Bill: What am I doing? A moment ago, I was playin' my flute. But this moment, I'm looking at the most beautiful bride these old eyes have ever seen.<br>"
  "The Bride: Why are you here?<br>"
  "Bill: Last look.<br>"
  "Elle Driver: Are you going to be nice?<br>"
  "Bill: I've never been nice my whole life, but I'll do my best... to be sweet.<br>",

  "O-Ren Ishii: Silly rabbit...<br>"
  "The Bride: Tricks are for...<br>"
  "O-Ren Ishii: Kids.<br>",

  "Hattori Hanzo: Funny, you like samurai swords... I like baseball.",

  "O-Ren Ishii: That really was a Hattori Hanzo sword.",

  "Elle Driver: I might never have liked you. Point of fact, I despise you. But that doesn't suggest I don't respect you. Dying in our sleep is a luxury our kind is rarely afforded. My gift to you.",

  "Elle Driver: Thought that was pretty fuckin' funny didn't you? Word of advice, shithead - don't you ever wake up.",

  "The Bride: Is that what I think it is?<br>"
  "O-Ren Ishii: You didn't think it was gonna be that easy, did you?<br>"
  "The Bride: You know, for a second there, Yeah! I kinda did.",

  "The Bride: Bitch! You can stop right there. Just because I have no wish to murder you before the eyes of your daughter does not mean that parading her around in front of me is gonna inspire sympathy. You and I have unfinished business and not a God damn f**king thing you've done in the subsequent four years including getting knocked up is gonna change that.",

  "Vernita Green: Look, I know I f'**k you over. I f**k you over bad, I wished to God I hadn't but I did. You have every right to wanna get even.<br>"
  "The Bride: No, no, no, no... Get even? Even Steven? I would have to kill you, go up to Nikki's room kill her and wait for your husband the good Doctor Bell to come home and kill him. That would be even, Vernita. That would be about square.",

  "Vernita Green: Look bitch, I need to know if you're gonna start any more shit around my baby girl.<br>"
  "The Bride: You can relax for now. I'm not gonna murder you in front of your child, okay.<br>",

  "Vernita Green: So I suppose it's a little late for an apology huh.<br>"
  "The Bride: You suppose correctly.",

  "O-Ren Ishii: The price you pay for bringing up either my Chinese or my American heritage as a negative is, I collect your f**king head. Just like this f**ker here. Now if any of you sons of b**ches got anything else to say, NOW'S THE F**KING TIME! ...I didn't think so.",

  "Vernita Green: Why wasn't I Black Mamba?",

  "The Bride: As I said before, I've allowed you to keep your wicked life for two reasons. And the second reason is so you can tell him in person everything that happened here tonight. I want him to witness the extent of my mercy by witnessing your deformed body. I want you to tell him all the information you just told me. I want him to know what I know. I want him to know I want him to know. And I want them all to know they'll all soon be as dead as O-Ren.",

  "O-Ren Ishii: Silly Caucasian girl likes to play with Samurai swords. You may not be able to fight like a Samurai, but you can at least die like a Samurai.",

  "Hattori Hanzo: [in Japanese] What do you want with Hattori Hanzo?<br>"
  "The Bride: [in Japanese] I need Japanese steel.<br>"
  "Hattori Hanzo: [in Japanese] Why do you need Japanese steel?<br>"
  "The Bride: [in Japanese] I have vermin to kill.<br>"
  "Hattori Hanzo: [in English] You must have big rats if you need Hattori Hanzo's steel.<br>"
  "The Bride: [in English] Huge.",

  "The Bride: [in Japanese] Those of you lucky enough to have your lives, take them with you. However, leave the limbs you've lost. They belong to me now. [in English]<br>"
  "The Bride: Except you, Sofie! You stay right where you are!<br>",

  "The Bride: \"Bitch, you don't have a future!\"<br>"

  "The Bride: I need Japanese steel.<br>"

  "Hattori Hanzo: I am finished doing what I swore an oath to God 28 years ago to never do again. I've created, \"something that kills people.\" And in that purpose, I was a success. I've done this because, philosophically, I am sympathetic to your aim. I can tell you with no ego, this is my finest sword. If on your journey, you should encounter God, God will be cut."

  "The Bride: It was not my intention to do this in front of you. For that I'm sorry. But you can take my word for it, your mother had it comin'. When you grow up, if you still feel raw about it, I'll be waiting.",
  NULL
};

static int get_num_quotes(void){
  int i=0;
  while(quotes[i]!=NULL)
    i++;
  return i;
}

static QString get_random_quote(void){
  QString ret = QString(quotes[qrand() % get_num_quotes()]).replace("Bill", "Jack");
#if !SHOW_QUOTES_IN_DETAILED_TEXT
  QStringList retlist;
  auto spl_a = ret.split("<br>");
  for (auto line : spl_a){
    auto spl_b = line.split(": ");
    auto spl0 = spl_b.takeFirst();  
    retlist.push_back("<b>"+spl0+"</b>: "+spl_b.join(": "));
  }
  return retlist.join("<br>");
#else
  return ret.replace("<br>", "\n\n"); // detailedText doesn't support html, and this info doesn't belong in informativeText.
#endif
}

static void showQtWindowInFront(QWidget *window){
  window->setWindowFlags(window->windowFlags() | Qt::Window | Qt::WindowStaysOnTopHint | Qt::MSWindowsFixedSizeDialogHint);
  window->raise();
  window->activateWindow();
  window->show();
}

static void setNewQuote(QMessageBox *box){
#if SHOW_QUOTES_IN_DETAILED_TEXT
  box->setDetailedText(get_random_quote());
#else
  box->setInformativeText(get_random_quote());
#endif
}

int main(int argc, char **argv){
  QApplication app(argc, argv);

  QTime time = QTime::currentTime();
  qsrand(time.msec());
  
  QMessageBox *box = new QMessageBox();
  //box->setStandardButtons(0);
  box->setText("     Please wait, trying to kill Jack.     ");
  setNewQuote(box);
  
  showQtWindowInFront(box);
  
  auto *kill_thread = new KillThread();
  kill_thread->start();

  time.restart();
  
  while(!kill_thread->isFinished()){
    QCoreApplication::processEvents();
    msleep(10);
    if (time.elapsed() > 1000){
      time.restart();
      //setNewQuote(box);
    }
  }

  box->setText("Jack is probably dead now. Now you can restart Jack and your applications.");
  //setNewQuote(box);
  showQtWindowInFront(box);
  
  app.exec();
  
  return 0;
}

