#include <iostream>
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

class Queen_Coordinate  //using this class to store location of queens
{
    public:
      int column;
      int row;
};

struct sort_overload  //Overloading vector sort function to work with Queen_Coordinate
{
  inline bool operator() (const Queen_Coordinate& c1, const Queen_Coordinate& c2)
  {
    return (c1.column < c2.column);
  }

};

void read_stack(stack<Queen_Coordinate> stacks) /* This function takes a stack and prints out the contents of it to the console.
                                                    Used for debugging purposes. */
{   
  Queen_Coordinate stacktop;
  while(!stacks.empty())
  {
    stacktop = stacks.top();
    stacks.pop();
    cout << "The Stack contains " << stacktop.column << " " << stacktop.row << endl;
  }

}

bool isSafe(stack<Queen_Coordinate> stacks, Queen_Coordinate c) /*This function takes a stack and a Queen_Coordinate and tells you
                                                                  whether or not the Queen_Coordinate is a valid place to put a queen.*/
{
  Queen_Coordinate stacktop;
  while(!stacks.empty())
  {
    stacktop = stacks.top();
    stacks.pop();
    if(c.column == stacktop.column) // checks if in same column
    {
      return false;
    }
    if(c.row == stacktop.row) // checks if in same row
    {
      return false;
    }
    if(c.row + c.column == stacktop.row + stacktop.column) // positive diagonal check
    {
      return false;
    }
    if(c.row - c.column == stacktop.row - stacktop.column) // negative diagonal check
    {
      return false;
    }
  }
  return true;  //if it does not enter any of the if conditions and exits while loop then return true since it is a valid spot to place queen
}


bool queen_there(stack<Queen_Coordinate> stacks, int column) //This function checks if a queen is in the same column given to the function
{
  Queen_Coordinate stacktop;
  while(!stacks.empty())
  {
    stacktop = stacks.top();
    stacks.pop();
    if(column == stacktop.column)
    {
      return true;  //if true it means queen is already in this column
    }
  }
  return false; //if false it means that there is no queen in this column

}

vector<string> tokenize(string input) //this function takes in a string input and makes it into a vector of strings and returns that vector
{ 
  vector<string> output;
  stringstream tokenizer(input);
  string token;
  while (getline(tokenizer, token, ' ')) 
  {
    output.push_back(token);
  }
  return output;
}


int main(int argc, char** argv)
{

  ifstream input; //used to read the file
  ofstream output; // used to open a file to write to
  input.open(argv[1]);
  output.open(argv[2]);

  string each_line; //where each line of file we are reading will be stored

  stack<Queen_Coordinate> queen_stack; // this stack will contain all the coordinates of the queens on the chess board

  int board_size; // this variable stores the size of the board

  Queen_Coordinate push_c; // this is used to push coordinates of the queens given to us onto the stack
  
  bool solution = false; // boolean flag to identify when to stop double for loop

  bool no_solution = false; /* boolean flag to identify when to stop double for loop and also to identify when to write no solution
                                to the output file. */

  while(getline(input, each_line)) // this while loop iterates over everyline in file until there is no more
  {
    solution = false; //beginning of loop so reset to false

    no_solution = false; // beginning of loop so reset flags to false

    if(each_line == " ") // if the line we are reading is empty there is nothing to solve so continue to next line
    {
      continue;
    }
    
    vector<string> input_line = tokenize(each_line); /*takes the contents of each line in file and uses tokenize function to 
                                                          turn it into a vector of strings */

    board_size = stoi(input_line[0]); //using stoi to turn first item in vector into a int

    int counter = 0; //counter to be able to identify how many queens were given to us

    for(int i = 1; i < input_line.size(); i += 2) // loop to push each given queen coordinate to stack
    {
      push_c.column = stoi(input_line[i]);

      if((i+1) < input_line.size()) // safeguard to make sure we don't use illegal index
      {
        push_c.row = stoi(input_line[i+1]);
      }

      if(push_c.row > board_size || push_c.column > board_size)
      {
        no_solution = true;
        break;
      }
      if(push_c.row <= 0 || push_c.column <=0)
      {
        no_solution = true;
        break;
      }
      
      if(counter >= 1) /* we push one coordinate to stack and then before pushing the other coordinates we call isSafe to make sure 
                          the queens given to us is valid input */
      {
        if(isSafe(queen_stack, push_c) == false) // this means one of the queens collides with the other
        {
          no_solution = true; // this means that there is no solution
        }
      }

      queen_stack.push(push_c); // push all coordinates to stack
      counter++; // increment counter so we know how many queens we start with
    }

    //input check
    if(no_solution == true) // if out no solution flag is true there is no solution and we need to empty the stack 
    {
      while(!queen_stack.empty())
      {
        queen_stack.pop();
      }
    }

    //simple if condition to check if input gives us a solution as well
    if(queen_stack.size() == board_size)
    {
      solution = true;
      vector<Queen_Coordinate> solution_coordinates;
      while(!queen_stack.empty())
      {
        Queen_Coordinate stacktop;
        stacktop = queen_stack.top();
        queen_stack.pop();
        solution_coordinates.push_back(stacktop);
      }
      sort(solution_coordinates.begin(), solution_coordinates.end(), sort_overload());
      for(int f = 0; f < solution_coordinates.size(); f++)
      {
        output << solution_coordinates[f].column << " " << solution_coordinates[f].row << " ";
      }
      output << endl;
    }


    

    Queen_Coordinate current_coordinate; // represents the current place we are in the chessboard
    
    for(int column = 1; column <= board_size; column++) //this loop iterates over the columns in chess board
    {
      
      if(solution == true) /* exit condition -  when we find a solution we set solution to true and break from inner for loop and this
                                condition allows us to break from outer loop as well */
      {
        break;
      }

      if(no_solution == true) /* exit condition - when we cannot find a solution, we set no_solution to true and break from inner for loop
                                  and this condition allows us to break from outer loop as well */
      {
        break;
      }
      for(int row = 1; row <= board_size; row++) // this loop iterates over the rows in the chess board
      {
        
        if(queen_there(queen_stack, column)) /* first we check if current column we are in contains a queen, if it does we can move to next
                                                  column */ 
        {
          if((column + 1) <= board_size) /* safeguard to make sure if we find a queen in last column, we don't increment column to be bigger
                                            than board size */
          {
            column++; // if queen is found we can move to next column and start there
            row = 1; // need to reset row back to 0
          }
        }
        current_coordinate.column = column; // store current column we are on in current_coordinate
        current_coordinate.row = row; // store current row we are on in current_coordinate

        if(isSafe(queen_stack, current_coordinate)) // call isSafe function to identify if current space we are in is valid to place a queen
        {
          queen_stack.push(current_coordinate); // if so, push this coordinate to the stack
          if((column + 1) <= board_size) /* safeguard to make sure we don't place a queen in last column and increment column to be 
                                            bigger than the board size */
          {
            column++; // since we placed a queen in this column we can move to next column
            row = 0; // here we set row to 0 since we know the for loop will increment row to 1 before next iteration
          }  
          if(queen_stack.size() == board_size) //check to see if we placed the right amount of queens
          {
            
            solution = true; // since we did we set solution to true so we can break out of both for loops
            vector<Queen_Coordinate> solution_coordinates; // we store the coordinates from stack here
            while(!queen_stack.empty()) // we empty the stack and store the coordinates in the vector solution_coordinates
            {
              Queen_Coordinate stacktop;
              stacktop = queen_stack.top();
              queen_stack.pop();
              solution_coordinates.push_back(stacktop);
            }
            sort(solution_coordinates.begin(), solution_coordinates.end(), sort_overload()); /* use overlaoded sort function to sort values
                                                                                                based on column value */
            for(int f = 0; f < solution_coordinates.size(); f++) // this loop writes all the coordinates to the output file
            {
              output << solution_coordinates[f].column << " " << solution_coordinates[f].row << " ";
            }
            output << endl; // add a newline at very end
            break; // break out of inner for loop
          }
          //need to implement backtracking here as well in case we can't find a solution
          if(row == board_size) //similar implementation to else condition: This is the scenario where we push a queen but dont have a solution
          {
            if(queen_stack.size() > counter)
            {
              queen_stack.pop(); // Since we just pushed a queen onto the stack, we must pop it 
              column = queen_stack.top().column;
              row = queen_stack.top().row;
              queen_stack.pop();
            }
            else
            {
              no_solution = true;
              break;
            }
          }
        }
        else // if we enter here it means that the current spot we are at is not a valid spot to place a queen
        {
          if(row == board_size) // check to see if row equals boardsize so we can backtrack
          {
            if(queen_stack.size() > counter) // safeguard to make sure we don't pop off the queens given to us off the stack
            {
              column = queen_stack.top().column;
              row = queen_stack.top().row;
              queen_stack.pop();
            }
            else // if we cannot pop from stack it means there is no solution and we are finished
            {
              no_solution = true; // this way we can break from both loops
              break; // break from inner loop
            }
          }
        }
      }
    }
    if(no_solution == true) // checks to see whether or not we found a solution 
    {
      output << "No solution" << endl; //if we did not, then writes no solution to output file
    }

    while(!queen_stack.empty()) // emptys the stack before we move to the next line in the file
    {
      queen_stack.pop();
    }
        
  }

}