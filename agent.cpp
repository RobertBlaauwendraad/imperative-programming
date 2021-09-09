#include "framework/charles.h"
#include "assignments/assignment1.h"

void test_agent() {

}

// Pick up ball and step, repeat until in front of wall then turn right
void get_string_of_balls() {
  while(!in_front_of_wall()) {
    get_ball();
    step();
  }
  turn_right();
}

// get string of balls, repeat until all balls are picked up
void string_agent() {
  while(on_ball()){
    get_string_of_balls();
  }
}

void chaos_agent() {

}

void block_agent() {

}