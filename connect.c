///////////////////////////////////////////////////////////////////////////// 
// INTEGRITY STATEMENT (v3)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement:a
// https://student.cs.uwaterloo.ca/~cs136/current/assignments/integrity.shtml
/////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with: 

// CS 136
//  
// Name: Richard Yuan
// login ID: kqyuan
///////////////////////////////////////////////////////////////////////////// 

#include "trace-2d.h"
#include <stdbool.h>
#include "cs136-trace.h"
#include <assert.h>

/////////////////////////////////////////////////////////////////////////////
// DO NOT MODIFY THESE CONSTANTS
const int INVALID_GAME = -1;
const int TIE = 1;
const int MAX_BOARD_SIZE = 1024;
/////////////////////////////////////////////////////////////////////////////

// win(board, move, width, height, length) checks if a player wins by 
// checking each piece horizontally, vertically, and diagonally. 
// requires: board is valid
//           2 < width, height
//           width x height <= MAX_BOARD_SIZE
//           2 < length <= max(width, height)
static bool win(int board[], int move, int width, int height, int length) {
  assert(board);
  assert(width > 2);
  assert(height > 2);
  assert(width * height <= MAX_BOARD_SIZE);
  bool cond = false;
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      cond = true;
      if (board[(i * width) + j] != 0) {
        if (j + length < width) {
          for (int k = 1; k < length; ++k) {
            if (board[(i * width) + j] != board[(i * width) + j + k]) {
              cond = false;
              break;
            }
          }
          if (cond == true) {
            return true;
          }
        }
      }
      cond = true;
      if (board[(i * width) + j] != 0) {
        if (i + length < height) {
          for (int k = 1; k < length; ++k) {
            if (board[(i * width) + j] != board[(k * width) + j]) {
              cond = false;
              break;
            }
          }
          if (cond == true) {
            return true;
          }
        }
      }
      cond = true;
      if (board[(i * width) + j] != 0) {
        if (j + length < width && i + length < height) {
          for (int k = 1; k < length; ++k) {
            if (board[(i * width) + j] != board[(k * width) + j + k]) {
              cond = false;
              break;
            }
          }
          if (cond == true) {
            return true;
          }
        }
      }
      cond = true;
      if (board[(i* width) + j] != 0) {
        if (j - length >= 0 && i + length < height) {
          for (int k = 1; k < length; ++k) {
            if (board[(i * width) + j] != board[(k * width) + j - k]) {
              cond = false;
              break;
            }
          }
          if (cond == true) {
            return true;
          }
        }
      }
    }
  }
  return false;
}

int connect_analysis(const int moves[], int width, int height, int length) {
  int board[1024];
  assert(moves);
  assert(width > 2);
  assert(height > 2);
  assert(length <= width);
  width * height ? assert(length <= width) : assert(length <= height);
  assert(width * height <= MAX_BOARD_SIZE);
  assert(width * height <= 1024);
  for (int i = 0; i < width * height; ++i) {
    int move = moves[i];
    if (move < 0 || move >= width) {
      return INVALID_GAME;
    }
    if (board[(height - 1) * width + move] != 0) {
      return INVALID_GAME;
    }
    for (int j = 0; j < height; ++j) {
      if (board[j * width + move] == 0) {
        board[j * width + move] = i % 2 + 1;
        break;
      }
    }
    if (win(board, move, width, height, length)) {
      if (i % 2 == 0) {
        return i + 1;
      } else {
        return -i - 1;
      }
    }
  }
  return TIE;
}
