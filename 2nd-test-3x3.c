#include <assert.h>
#include "connect.h"

int main(void) {
  int col1[9] = {0, 1, 2, 1, 0, 2, 0};
  assert(connect_analysis(col1, 3, 3, 3) == 7);
  
  int col2[9] = {0, 1, 2, 1, 0, 1, 0};
  assert(connect_analysis(col2, 3, 3, 3) == -6);
  
  int col3[9] = {0, 2, 0, 2, 1, 2};
  assert(connect_analysis(col3, 3, 3, 3) == -6);
  
  int row1[9] = {0, 0, 1, 1, 2, 2};
  assert(connect_analysis(row1, 3, 3, 3) == 5);
  
  int row2[9] = {0, 1, 2, 0, 0, 1, 1, 2, 2};
  assert(connect_analysis(row2, 3, 3, 3) == -8);
  
  int row3[9] = {1, 0, 0, 1, 0, 2, 1, 2, 2};
  assert(connect_analysis(row3, 3, 3, 3) == 9);
  
  int diag1[9] = {2, 1, 1, 0, 0, 2, 0};
  assert(connect_analysis(diag1, 3, 3, 3) == 7);
  
  int diag2[9] = {1, 1, 2, 0, 2, 2};
  assert(connect_analysis(diag2, 3, 3, 3) == -6);
}
