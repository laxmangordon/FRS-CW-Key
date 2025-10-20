#include "tone.h"

void sendTone(int T1, int T2, int T3, int T4){
  digitalWrite(T2, LOW);
  digitalWrite(T3, LOW);
  digitalWrite(T1, HIGH);
  digitalWrite(T4, HIGH);
  delayMicroseconds(2000);

  digitalWrite(T1, LOW);
  digitalWrite(T4, LOW);
  digitalWrite(T2, HIGH);
  digitalWrite(T3, HIGH);
  delayMicroseconds(2000);

}

void sendSubTone(int T1, int T2, int T3, int T4){
  digitalWrite(T2, LOW);
  digitalWrite(T3, LOW);
  digitalWrite(T1, HIGH);
  digitalWrite(T4, HIGH);
  delayMicroseconds(50);

  digitalWrite(T1, LOW);
  digitalWrite(T4, LOW);
  digitalWrite(T2, HIGH);
  digitalWrite(T3, HIGH);
  delayMicroseconds(50);

}

void endTone(int T1, int T2, int T3, int T4){
  digitalWrite(T2, LOW);
  digitalWrite(T3, LOW);
  digitalWrite(T1, LOW);
  digitalWrite(T4, LOW);
}