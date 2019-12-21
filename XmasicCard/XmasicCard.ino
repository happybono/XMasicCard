//
//    FILE: XmasicCard.ino
//  AUTHOR: Jaewoong Mun (happybono@outlook.com)
// CREATED: December 18, 2019
//
// Released to the public domain
//

#include "pitches.h"
#define PIEZO 5

/* 징글벨 음계 : 알기 쉽게 다장조의 음계로 변환하여 처리. */
int jingleBell_Notes [ ] = { NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_G4, 0, // 솔미레도솔(쉼표)
NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4, 0,                              // 솔미레도라(쉼표)
NOTE_A4, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_B4, 0,                              // 라파미레시(쉼표)
NOTE_G5, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_E5, NOTE_C5, 0,                     // 솔솔파레미도(쉼표)
NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_G4, 0,                              // 솔미레도솔(쉼표)
NOTE_G4, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4, 0,                              // 솔미레도라(쉼표)
NOTE_A4, NOTE_F5, NOTE_E5, NOTE_D5,                                          // 라파미레
NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,                                          // 솔솔솔솔
NOTE_A4, NOTE_G4, NOTE_F5, NOTE_D5, NOTE_C5, NOTE_G4, 0,                     // 라솔파레도솔(쉼표)
NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,                        // 미미미미미미
NOTE_E5, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E5, 0,                              // 미솔도레미(쉼표)
NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,                                          // 파파파파
NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5,                                          // 파미미미
NOTE_E5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_D5, NOTE_G4, 0,                     // 미레레도레솔(쉼표)
NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,                        // 미미미미미미
NOTE_E5, NOTE_G4, NOTE_C5, NOTE_D5, NOTE_E5, 0,                              // 미솔도레미(쉼표)
NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,                                          // 파파파파
NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5,                                          // 파미미미
NOTE_G4, NOTE_G4, NOTE_F5, NOTE_D5, NOTE_C5, 0 };                            // 솔솔파레도(쉼표) 

/* 징글벨 소절 연주 시간 */
int jingleBell_Rhythm [ ] = { 250, 250, 250, 250, 750, 250,                    // 8 분 음표 (quaver) = 250 ms (milliseconds)
250, 250, 250, 250, 750, 250,
250, 250, 250, 250, 750, 250,
250, 250, 250, 250, 500, 250, 250,
250, 250, 250, 250, 750, 250,
250, 250, 250, 250, 750, 250,
250, 250, 250, 250,
750, 250, 250, 250,
250, 250, 250, 250, 500, 250, 250,
250, 250, 250, 250, 250, 250, 
250, 250, 750, 250, 750, 250,
250, 250, 750, 250,
250, 250, 250, 250,
250, 250, 250, 250, 250, 250, 250,
250, 250, 250, 250, 250, 250,
250, 250, 750, 250, 750, 250,
250, 250, 750, 250,
250, 250, 250, 250,
250, 250, 250, 250, 750, 250 };

/* Kristen Bell - Do you want to build a snowman 음계 */
int snowman_Notes [ ] = {NOTE_F4, NOTE_AS4, NOTE_DS5, NOTE_G4, NOTE_AS4, NOTE_DS5, NOTE_GS4, NOTE_AS4,
                        NOTE_F4, NOTE_AS4, NOTE_DS5, NOTE_G4, NOTE_AS4, NOTE_DS5, NOTE_GS4, NOTE_AS4,
                        NOTE_F4, NOTE_AS4, NOTE_DS5, NOTE_G4, NOTE_AS4, NOTE_DS5, NOTE_GS4, NOTE_AS4,
                        NOTE_F4, NOTE_AS4, NOTE_DS5, NOTE_G4, NOTE_AS4, NOTE_DS5, NOTE_GS4, NOTE_AS4, 0,
                        NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS4, NOTE_DS4, NOTE_G4,
                        NOTE_F4, NOTE_G4, 0, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_G4, NOTE_F4,
                        0, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_G4, NOTE_GS4, NOTE_G4, NOTE_DS4, 0,
                        NOTE_AS3, NOTE_GS4, NOTE_G4, NOTE_DS4, 0, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_G4, NOTE_AS4,
                        NOTE_AS4, 0, NOTE_AS4, NOTE_AS4, NOTE_GS4, NOTE_G4, NOTE_GS4, NOTE_AS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, 0,
                        NOTE_F4, NOTE_G4, NOTE_DS4, NOTE_DS4, 0, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_DS4, NOTE_F4, NOTE_G4, NOTE_C5, 0,
                        NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_AS3, NOTE_DS4, NOTE_G4, NOTE_F4, NOTE_G4, 0,
                        NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_DS4, NOTE_G4, NOTE_F4, NOTE_DS4, 0,
                        NOTE_DS4, NOTE_D4, NOTE_DS3
                       };

int snowman_Rhythm [ ] = {250, 250, 250, 250, 250, 250, 250, 250,
                         250, 250, 250, 250, 250, 250, 250, 250,
                         250, 250, 250, 250, 250, 250, 250, 250,
                         250, 250, 250, 250, 250, 250, 250, 250, 250,
                         250, 250, 250, 250, 250, 250,
                         250, 500, 500, 250, 250, 250, 250, 250, 250, 500,
                         250, 250, 250, 250, 250, 250, 250, 250, 250, 250,
                         250, 250, 250, 250, 350, 250, 250, 250, 250, 250, 750,
                         250, 300, 250, 250, 250, 250, 250, 250, 500, 500, 250,
                         250, 250, 250, 350, 300, 500, 350, 250, 250, 400, 500, 500, 250,
                         250, 250, 250, 250, 250, 250, 250, 500, 250, 500,
                         250, 250, 250, 250, 250, 250, 250, 500, 2000,
                         250, 250, 400
                        };


void setup()                                                                 // 한 번만 연주하게 하기 위하여,
                                                                             // 실행 프로그램을 setup() 에서 처리.
{
int i;
pinMode(PIEZO, OUTPUT);                                                      // PIEZO 버저핀은 출력 모드로 설정.
delay(3000);                                                                 // 카드를 열고 3 초 후에 연주 시작. 
for (i=0; i<105; i++)                                                        // 연주 길이만큼 숫자 조정.
{
tone(PIEZO, jingleBell_Notes[i], jingleBell_Rhythm[i]);                      // 배열 순으로 노래 재생
delay(time[i]);
}
}
void loop()                                                                  // 한 번만 연주하게 하기 위하여
{                                                                            // loop()에서는 아무 것도 처리하지 않음
}
