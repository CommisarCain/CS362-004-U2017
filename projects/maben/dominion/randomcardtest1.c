// Test smithyCardEffect function in dominion.c


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

#define TEST_COUNT 1
#define TARGET_FILE "randomtest.out"
#define TEST_FAIL "randomcardtest1 FAILED"
#define TEST_PASS "randomcardtest2 PASSED"

//make constant for amount of tests

struct TestResults{
  int result_array[TEST_COUNT];
};


void printReport(struct TestResults* test){
  FILE *fp;
  int score = 0;

  fp = fopen(TARGET_FILE, "a");
  for (int i = 0; i < TEST_COUNT; i++) {
    fprintf(fp, "randomcardtest2 Test %d : %d\n", i, test->result_array[i]);
    score = score + test->result_array[i];
  }
  fclose(fp);

  if(score==TEST_COUNT){
    printf("%s\n",TEST_PASS);
  }else{
    printf("%s\n",TEST_FAIL);
  }
}

int testInt(){

  struct gameState state;
  struct gameState* statep = &state;
  int numPlayers = 2;
  int kingdomCards[10] = {adventurer, //7
    smithy, //13
    great_hall,//16
    outpost,//23
    5,
    6,
    minion,
    8,
    9,
    10};
  int* kingdomCardsp = kingdomCards;
  int seed = 10;
  int count1 = 0;
  int count2 = 0;
  int result1 = 0;
  int result2 = -1;
  int result3 = -1;
  int result4 = 0;
  int finalresult = 1;
  SelectStream(2);
  PutSeed(3);
  int p;

  for (int n = 0; n < 2000; n++) {
    for (int i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&state)[i] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
    state.deckCount[p] = floor(Random() * MAX_DECK);
    state.discardCount[p] = floor(Random() * MAX_DECK);
    state.handCount[p] = floor(Random() * MAX_HAND);


    result1 = initializeGame(numPlayers, kingdomCardsp, seed, statep);
    count1 = state.handCount[1];

    result2 = smithyCardEffect(statep,1,1);

    count2 = state.handCount[1];

    //printf("%d  %d\n", count1, count2);

    if(count2 == count1+3){
      result3 = 1;
    }




    if(result1 != 0 || result2 != 0 || result3 != 1 || result4 != 0){
      finalresult = 0;
      break;
    }
  }
  if(finalresult == 1){
    return 1;
  }

  return 0;
}


int main () {
  struct TestResults tester;
  //tester.result_array[0] = 1;
  tester.result_array[0] =  testInt();

  printReport(&tester);
}


















//eof
