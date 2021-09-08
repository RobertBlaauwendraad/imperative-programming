#include "framework/charles.h"
#include "assignments/assignment1.h"

void test_agent() {

}

// First checks if on a ball before picking it up
void safe_get_ball() {
  if(on_ball()) {
    get_ball();
  }
}

// Gets all balls in a straight line until a wall is reached
// Skips last ball because it will be picked after turning
void get_all_balls_until_wall() {
  while (!in_front_of_wall())
  {
    safe_get_ball();
    step();
  }
}

// Picks up all balls in a straight line and rotates.
// Repeats this 4 times for 4 walls
void loop_walls() {
  for (int i = 0; i < 4; i++) {
    get_all_balls_until_wall();
    turn_right();
  }
}

// Calls the loop_walls function as start
void string_agent() {
  loop_walls();
}

void chaos_agent() {

}

void block_agent() {

}