#include "framework/charles.h"
#include "assignments/assignment1.h"

void test_agent() {

}

void string_agent() {

}

void walk_to_first_ball(){
    while(!on_ball()){
        step();
    }
}

void traverse(){
    while(true){
        //if Charles is on a ball but not in front of a wall he should
        //get the ball and take a step forward
        if(on_ball() && !in_front_of_wall()){
            get_ball();
            step();

        //if Charles is on a ball and also in front of a wall he should get that ball
        //and move one row down
        } else if(on_ball() && in_front_of_wall()){
            get_ball();
            turn_right();
            step();
            turn_right();

        //if Charles is not on a ball and also not in front of a wall he
        //should turn around and go one row down
        } else if(!on_ball() && !in_front_of_wall()){
            turn_right();
            turn_right();
            while(!in_front_of_wall()){
                step();
            }
            turn_right();
            step();
            turn_right();

            //this only gets triggered when he is done and should return home
            if(!on_ball()){

                while(!north()){
                    turn_right();
                }
                while(!in_front_of_wall()){
                    step();
                }
                turn_left();
                while(!in_front_of_wall()){
                    step();
                }
                turn_left();
                turn_left();
            }
        }
       

    }     
}

void chaos_agent() {

    walk_to_first_ball();
    traverse(); 

}



void block_agent() {

}
