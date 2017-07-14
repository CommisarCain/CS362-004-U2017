// Test getCost function in dominion.c


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


  int result1 = getCost(curse);
  int result2 = getCost(100);
  int result3 = getCost(-1);
  int result4 = getCost(province);

  if(result1 == 0 && result2 == -1 && result3 == -1 && result4 == 8){
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
