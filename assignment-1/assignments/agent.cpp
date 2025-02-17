#include "framework/charles.h"
#include "assignments/assignment1.h"

void test_agent() {

}

// Pick up ball and step, repeat until in front of wall then turn right
void get_string_of_balls() {
  while(!in_front_of_wall() && on_ball()) {
    get_ball();
    step();
  }
}

// Get string of balls, repeat until all balls are picked up
void string_agent() {
  while(on_ball()){
    get_string_of_balls();
    turn_right();
  }
}

// Step until on ball
void travel_to_first_ball(){
    while(!on_ball()){
        step();
    }
}

// step until in front of wall
void travel_to_wall() {
    while (!in_front_of_wall())
    {
        step();
    }
}

// Prepare Charles to pick up next string of balls
void travel_to_next_row() {
    if(in_front_of_wall() && on_ball()) {
        get_ball();
        turn_right();
        step();
        turn_right();
        // Skip first ball to keep loop going
        step();
    }
}

// After picking up string of balls, return to wall
void return_to_wall() {
    if(!in_front_of_wall() && !on_ball()) {
        turn_right();
        turn_right();
        travel_to_wall();
    }
}

// Rotates Charles facing north
void rotate_north() {
    while (!north())
    {
        turn_right();
    }
}

// Return back to starting position
void return_to_starting_position() {
    rotate_north();
    travel_to_wall();
    turn_left();
    travel_to_wall();
    turn_left();
    turn_left();
}

// Main agent
void chaos_agent() {
    // First string of balls is picked up from left to right
    // After that the same order of functions can be used
    travel_to_first_ball();
    get_string_of_balls();
    // Repeat functions until all balls are picked up
    while (on_ball())
    {
        travel_to_next_row();
        get_string_of_balls();
        return_to_wall();
    }
    return_to_starting_position();
}

// Travel to middle rectangle
void travel_to_middle() {
    travel_to_first_ball();
    turn_right();
    travel_to_wall();
    turn_left();
}

// Checks if Charles is next to a wall
bool is_next_to_wall() {
    turn_right();
    return in_front_of_wall();
}

// Puts a ball in corner and steps forward so Charles is in same position as
// when he started the first loop
void prepare_next_loop() {
    put_ball();
    step();
}

// Main agent
void block_agent() {
    // First travel to middle rectangle
    travel_to_middle();
    // Loops 4 times because rectangle has 4 walls
    for (int i = 0; i < 4; i++)
    {
        // When next to wall turn back, put a ball and step forward
        while (is_next_to_wall())
        {
            turn_left();
            put_ball();
            step();
        }
        prepare_next_loop();
    }
    // Return to the starting position
    return_to_starting_position();
}
