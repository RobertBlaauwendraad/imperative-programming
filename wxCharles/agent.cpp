#include "framework/charles.h"  
#include "assignments/assignment2.h"

void test_agent() {

}

void back_to_path() {
  turn_right();
  turn_right();
  step();
}

// Follows string of balls and ends on last ball reverted
void follow_string_of_balls()
{
  while (on_ball() && !in_front_of_wall())
  {
    step();
  }
  // If stopped because string of ball ended return to last ball
  if(!on_ball()) {
    back_to_path();
    // Else revert Charles for same ending
  } else {
    turn_right();
    turn_right();
  }
}

// Travel to beginning of next string or stop no ball or stop in front of wall
void rotate_next_direction() {
  turn_right();
  // If not in front of wall check on ball
  if(!in_front_of_wall()) {
    step();
    // If wrong direction walk back
    if(!on_ball()) {
      turn_right();
      turn_right();
      step();
      // If not in front of wall step to new string
      if(!in_front_of_wall()) {
        step();
      }
    }
  // If in front of wall walk to opposite direction
  } else {
    turn_right();
    turn_right();
    if(!in_front_of_wall()) {
      step();
    }
  }
}

// Rotate to the east
void rotate_east()
{
  while (!north())
  {
    turn_right();
  }
  turn_right();
}

void path_agent() {
  // End of path if either Charles is not on ball or in front of wall
  while (on_ball() && !in_front_of_wall())
  {
    follow_string_of_balls();
    rotate_next_direction();
  }
  // If not on ball walk back to path
  if(!on_ball()) {
    back_to_path();
  }
  // Make sure Charles always ends up facing east
  rotate_east();
}


// step until in front of wall
void travel_to_wall() {
  while (!in_front_of_wall()) {
    step();
  }
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
  // Step to first column
  step();
  // While not in last column put fill it with balls and travel to next
  while(!in_front_of_wall()) {
    turn_right();
    fill_column_with_balls();
    return_start_column();
    turn_right();
    step();
  }
  // Travel to next floor/grounds
  turn_right();
  travel_to_wall();
  turn_right();
}

void find_center_agent() {

}

void clean_up_agent() {

}
