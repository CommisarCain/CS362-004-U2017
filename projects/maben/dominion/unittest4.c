// Test initializeGame function in dominion.c


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define TEST_COUNT 1
#define TARGET_FILE "unittestresults.out"
#define TEST_FAIL "unittest4 FAILED"
#define TEST_PASS "unittest4 PASSED"

//make constant for amount of tests

struct TestResults{
  int result_array[TEST_COUNT];
};


void printReport(struct TestResults* test){
  FILE *fp;
  int score = 0;

  fp = fopen(TARGET_FILE, "a");
  for (int i = 0; i < TEST_COUNT; i++) {
    fprintf(fp, "unittest4 Test %d : %d\n", i, test->result_array[i]);
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

  int* point = kingdomCards(0,1,2,3,4,5,6,7,8,9);
  struct gameState game;
  struct gameState* gamep = &game;
  int players = 2;
  int seed = 55;
  int result1 = initializeGame(players, point, seed, gamep);
  players = 1;
  int result2 = initializeGame(players, point, seed, gamep);
  point = kingdomCards(0,0,0,0,0,0,0,0,0,0);
  players = 2;
  int result3 = initializeGame(players, point, seed, gamep);
  players = 4;
  point = kingdomCards(0,1,2,3,4,5,6,7,8,9);
  int result4 = initializeGame(players, point, seed, gamep);
  players = 2;
  if(result1 == 0 && result2 == -1 && result3 == -1, result4 == 0){
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
