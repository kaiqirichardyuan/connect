#include <assert.h>
#include "connect.h"
#include "cs136-trace.h"

int main(void) {

  int player1_wins_move_7[42] = {1, 2, 1, 2, 1, 2, 1};
  int player2_wins_move_8[42] = {0, 1, 0, 1, 0, 1, 3, 1};
  int invalid_game1[42] = {0};
  int invalid_game2[42] = {-1};
  int tie1[42] = {0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 6, 6,
                  2, 3, 2, 3, 3, 2, 3, 2, 2, 3, 2, 3, 6, 6,
                  4, 5, 4, 5, 5, 4, 5, 4, 4, 5, 4, 5, 6, 6};

  assert(connect_analysis(player1_wins_move_7, 7, 6, 4) == 7);
  assert(connect_analysis(player2_wins_move_8, 7, 6, 4) == -8);
  assert(connect_analysis(invalid_game1, 7, 6, 4) == INVALID_GAME);
  assert(connect_analysis(invalid_game2, 7, 6, 4) == INVALID_GAME);
  assert(connect_analysis(tie1, 7, 6, 4) == TIE);
}
