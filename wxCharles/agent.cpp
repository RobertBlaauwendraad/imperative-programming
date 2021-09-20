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

// Place balls until in front of a wall, keep track of how many balls placed
int placeBalls() {
  int ballsPlaced = 0;
  while(!in_front_of_wall()) {
    if (!on_ball()) {
      put_ball();
    }
    step();
    ballsPlaced++;
  }
  put_ball();
  return ballsPlaced;
}

// Walk amount of steps
void walkAmountOfSteps(int steps)
{
  for (int i = 0; i < steps; i++)
  {
    step();
  }
}

void find_center_agent() {
  // Do the same for x and y axis
  for (int i = 0; i < 2; i++)
  {
    // Define how many steps needed until the middle is reached
    int length = placeBalls();
    int stepsUntilMiddle = ceil(length / 2);
    // Return to the middle of current axis
    turn_left();
    turn_left();
    walkAmountOfSteps(stepsUntilMiddle);
    // Prepare for next axis
    turn_left();
  }
  // Finish oriented east
  rotate_east();
}

// Pick up balls until wall and keep track of how many balls are picked up
int ballsUntilWall() {
  int ballsPickedUp = 0;
  while (!in_front_of_wall())
  {
    step();
    get_ball();
    ballsPickedUp++;
  }
  return ballsPickedUp;
}

// Get a line of balls but keep the middle one there
// This can be done because Charles starts at the middle of the line
int getLineOfBallsExpectMiddle() {
  turn_right();
  int halfLength = ballsUntilWall();
  turn_left();
  turn_left();
  walkAmountOfSteps(halfLength);
  ballsUntilWall();
  return halfLength;
}

// Walk to a certain amount of steps in the x and y directions (both positive)
void walkToPoint(int x, int y) {
  rotate_east();
  walkAmountOfSteps(x);
  turn_right();
  walkAmountOfSteps(y);
}

// Clean the y and x axes and return to the middle then rotate east
void clean_up_agent() {
  int y = getLineOfBallsExpectMiddle();
  int x = getLineOfBallsExpectMiddle();
  walkToPoint(x, y);
  rotate_east();
}
