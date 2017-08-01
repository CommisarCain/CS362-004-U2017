// Test compare function in dominion.c


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define TEST_COUNT 1
#define TARGET_FILE "unittestresults.out"
#define TEST_FAIL "unittest1 FAILED"
#define TEST_PASS "unittest1 PASSED"

//make constant for amount of tests

struct TestResults{
  int result_array[TEST_COUNT];
};


void printReport(struct TestResults* test){
  FILE *fp;
  int score = 0;

  fp = fopen(TARGET_FILE, "a");
  for (int i = 0; i < TEST_COUNT; i++) {
    fprintf(fp, "unittest1 Test %d : %d\n", i, test->result_array[i]);
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
  char* a = "a";
  char* b = "b";
  int* c;
  int* d;
  int add = 2;
  int add2 = 3;
  int result = 0;

  c = &add;
  d = &add2;

  result = result + compare(d,c);
  result = result + compare(c,d);
  result = result + compare(d,c);
  result = result + compare(a,b);
  result = result + compare(b,a);

  if(result == 1){
    return result;
  }else{
    return 0;
  }

}


int main () {
  struct TestResults tester;
  //tester.result_array[0] = 1;
  tester.result_array[0] =  testInt();

  printReport(&tester);
}


















//eof
