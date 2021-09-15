#include "framework/charles.h"
#include "assignments/assignment2.h"

void test_agent() {

}

void path_agent() {

}

// step until in front of wall
void travel_to_wall() {
  while (!in_front_of_wall()) {
    step();
  }
}

// travel to start of first column
void prepare_first_column() {
  step();
  turn_right();
}

// put ball until in front of wall
void fill_column_with_balls() {
  while (!in_front_of_wall()) {
    put_ball();
    step();
  }
  put_ball();  
}

// return to the start of column
void return_start_column() {
  turn_left();
  turn_left();
  travel_to_wall();
}

void cave_agent() {
  prepare_first_column();
  // Keeps track if Charles is in last row
  bool last_row = false;
  while(!last_row) {
    fill_column_with_balls();
    return_start_column();
    // Walk to next column, also check if is in last column
    turn_right();
    step();
    last_row = in_front_of_wall();
    turn_right();
  }
  // return to starting position
  travel_to_wall();
  turn_right();
}

void find_center_agent() {

}

void clean_up_agent() {

}