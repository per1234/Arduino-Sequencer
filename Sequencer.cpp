#include "Arduino.h"
#include "Sequence.h"

Sequence::Sequence() {}
void Sequence::setFuse(int Fuse) {
_Fuse = Fuse;
}
void Sequence::start(int Steps) {
unsigned long TimeCurrent = millis();
if (paused == false) {
if(TimeCurrent - TimeLast >= _Fuse) {
TimeLast = TimeCurrent;
Step++;
if (Step > Steps) {
Step = 1;
   }
  }
 } else {
 TimePaused = TimeCurrent - TimeLast;
 }
}
void Sequence::pause() {
paused = true;
}
void Sequence::unpause() {
TimeLast = TimePaused;
paused = false;
}
void Sequence::gotoStep(int StepNum) {
Step = StepNum;
}
int Sequence::getStep() {
return Step;
}