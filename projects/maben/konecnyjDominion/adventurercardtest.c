// Test adventurerCard Effect function in dominion.c


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

#define TEST_COUNT 1
#define TARGET_FILE "randomtest.out"
#define TEST_FAIL "adventurercardtest FAILED"
#define TEST_PASS "adventurercardtest PASSED"

//make constant for amount of tests

struct TestResults{
  int result_array[TEST_COUNT];
};


void printReport(struct TestResults* test){
  FILE *fp;
  int score = 0;

  fp = fopen(TARGET_FILE, "a");
  for (int i = 0; i < TEST_COUNT; i++) {
    fprintf(fp, "adventurercardtest Test %d : %d\n", i, test->result_array[i]);
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
    for (int i = 0; i < MAX_HAND; i++) {
      if (state.hand[1][i] == copper
        || state.hand[1][i] == silver
        || state.hand[1][i] == gold){
        count1++;
      }
    }

    result2 = adventurerCardEffect(statep,1,1);

    for (int i = 0; i < MAX_HAND; i++) {
      if (state.hand[1][i] == copper
        || state.hand[1][i] == silver
        || state.hand[1][i] == gold){
        count2++;
      }
    }

    //printf("%d  %d\n", count1, count2);

    if(count2 > count1){
      result3 = 1;
    }
  }




  if(result1 == 0 && result2 == 0 && result3 == 1 && result4 == 0){
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
