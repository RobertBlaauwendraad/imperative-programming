#include "framework/charles.h"
#include "assignments/assignment2.h"

void test_agent() {

}

//go to the location left of the previous ball
void look_left(){
    turn_left();
    step();
}

//go to the location right of the previous ball
void look_right(){
    turn_right();
    turn_right();
    step();
    step();
}

//go back to previous ball's location
void to_origin(){
    turn_right();
    turn_right();
    step();
    turn_right();
    turn_right();
}

//as long as Charles is on a ball it picks it up and step forward
void get_balls(){
    while(on_ball()){
        get_ball();
        step();
    }
}

bool done = false;

//tries to find the next direction of the ball trail
//by going back to previous ball and looking left and right of it
void find_direction(){
    to_origin();
    look_left();
    if(on_ball()){
        get_balls();
    } else {
        look_right();        
        if(on_ball()){
            get_balls();
        } else {
            while(!north()){
                turn_right();
            }
            turn_right();
            //only true when there is no ball neither left or right
            //from the last ball, so when the trail is done
            done = true;
        }
    }
}



void path_agent() {
    while(!done){
        if(on_ball()){
            get_balls();
        } 
        find_direction();
    } 
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
