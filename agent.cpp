#include "framework/charles.h"
#include "assignments/assignment1.h"

void test_agent() {

}

void safe_get_ball() {
  if(on_ball()) {
    get_ball();
  }
}

void get_all_balls_until_wall() {
  while (!in_front_of_wall())
  {
    safe_get_ball();
    step();
  }
}

void loop_walls() {
  for (int i = 0; i < 4; i++) {
    get_all_balls_until_wall();
    turn_right();
  }
}

void string_agent() {
  loop_walls();
}

void chaos_agent() {

}

void block_agent() {

}