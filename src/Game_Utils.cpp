#include "Game.h"

using PC = Pokitto::Core;
using PD = Pokitto::Display;
using PS = Pokitto::Sound;


/* ----------------------------------------------------------------------------
 *  Return the upper 4 bits of a byte.
 */
uint8_t Game::leftValue(uint8_t val) {

  return val >> 4; 
      
}


/* ----------------------------------------------------------------------------
 *  Return the lower 4 bits of a byte.
 */
uint8_t Game::rightValue(uint8_t val) {

  return val & 0x0F; 
      
}


/* ----------------------------------------------------------------------------
 *  Initialise the board.
 */
void Game::initBoard(uint8_t puzzleType, uint8_t puzzleNumber) {

  uint8_t x = 0;
  uint8_t y = 0;
  uint8_t byteRead = 0;
  
  uint8_t bytesToRead = (puzzleType % 2 == 0 ? (puzzleType / 2) * puzzleType : ((puzzleType + 1) / 2) * puzzleType);

  puzzle.maximum.x = puzzle.maximum.y = puzzleType;
  puzzle.offset.x = puzzles_details[(puzzleType - 5) * 4];
  puzzle.offset.y = puzzles_details[((puzzleType - 5) * 4) + 1];
  puzzle.slider.unit = puzzles_details[((puzzleType - 5) * 4) + 2];
  puzzle.slider.overall = puzzles_details[((puzzleType - 5) * 4) + 3];

  for (uint8_t i = (puzzleNumber * bytesToRead); i < ((puzzleNumber + 1) * bytesToRead); i++) {

  	switch (puzzleType) {
      
  	  case PUZZLE_5X5:
  		  byteRead = puzzles_5x5[i];
  		  break;
        
      case PUZZLE_6X6:
        byteRead = puzzles_6x6[i];
        break;
        
      case PUZZLE_7X7:
        byteRead = puzzles_7x7[i];
        break;
        
      case PUZZLE_8X8:
        byteRead = puzzles_8x8[i];
        break;
  		  
  	  case PUZZLE_9X9:
  		  byteRead = puzzles_9x9[i];
  		  break;
  
  	}


    // Load up the left hand value ..

    puzzle.board[y][x] = 0;
    if (leftValue(byteRead) > 0) {
      puzzle.board[y][x] = 0xF0 | leftValue(byteRead);
    }
    x++;

  
    // Are we still in the confines of the board?

    if (x <= puzzle.maximum.x) {         
      puzzle.board[y][x] = 0;
      if (rightValue(byteRead) > 0) {
        puzzle.board[y][x] = 0xF0 | rightValue(byteRead);
      }
    }

      
    x++;
      
    if (x >= puzzle.maximum.x) { y++; x = 0; }
        
		  
  }

}


/* ----------------------------------------------------------------------------
 *  Has the node already been played?
 */
bool Game::nodeAlreadyPlayed(uint8_t value) { 

  for (uint8_t y = 0; y < puzzle.maximum.y; y++) {
    
    for (uint8_t x = 0; x < puzzle.maximum.x; x++) {
      
      if (getNodeValue(x, y) == value && !isNode(x, y)) {
        
        return true;
        
      }
      
    }
      
  }
    
  return false;
    
}


/* ----------------------------------------------------------------------------
 *  Clear the board of pipes for a certain node value.
 */
void Game::clearBoard(uint8_t nodeValue) {

  for (uint8_t y = 0; y < puzzle.maximum.y; y++) {
    
    for (uint8_t x = 0; x < puzzle.maximum.x; x++) {
      
      if (getNodeValue(x, y) == nodeValue && !isNode(x, y)) {
        
        puzzle.board[y][x] = NOTHING;
        
      }
      
    }
    
  }
  
}


/* ----------------------------------------------------------------------------
 *  Is the position nominated a node?
 */
bool Game::isNode(uint8_t x, uint8_t y) {

  return (puzzle.board[y][x] & 0xF0) == 0xF0;
  
}


/* ----------------------------------------------------------------------------
 *  Get the node value for the position.
 */
uint8_t Game::getNodeValue(uint8_t x, uint8_t y) {
  
  return (puzzle.board[y][x] & 0x0F);

}


/* ----------------------------------------------------------------------------
 *  Is the position nominated a pipe?
 */
bool Game::isPipe(uint8_t x, uint8_t y) {

  return (puzzle.board[y][x] & 0xF0) > 0x00 && (puzzle.board[y][x] & 0xF0) != 0xF0;
  
}


/* ----------------------------------------------------------------------------
 *  Get the pipe value for the position.
 */
uint8_t Game::getPipeValue(uint8_t x, uint8_t y) {
  
  return (puzzle.board[y][x] & 0xF0) >> 4;

}


/* ----------------------------------------------------------------------------
 *  Set the pipe value for the position.
 */
void Game::setCellValue(uint8_t x, uint8_t y, uint8_t pipeValue, uint8_t nodeValue) {
  
  puzzle.board[y][x] = (pipeValue << 4) | nodeValue;
  
}


/* ----------------------------------------------------------------------------
 *  Clear the player's selection.
 */
void Game::clearSelection() {

  player.selectedNode.value = 0;
  player.selectedNode.x = 0;
  player.selectedNode.y = 0;

}


/* ----------------------------------------------------------------------------
 *  Clear the player's highlight and selection.
 */
void Game::clearHighlightAndSelection() {

  player.selectedNode.value = 0;
  player.selectedNode.x = 0;
  player.selectedNode.y = 0;
  player.highlightedNode.x = 0;
  player.highlightedNode.y = 0;

}


/* ----------------------------------------------------------------------------
 *  Is the puzzle complete?  All cells should have a 'node' value.
 */
bool Game::isPuzzleComplete() {

  for (uint8_t y = 0; y < puzzle.maximum.y; y++) {
    
    for (uint8_t x = 0; x < puzzle.maximum.x; x++) {
      
      if (getNodeValue(x, y) == 0) {
        
        return false;
        
      }
      
    }
    
  }

  return true;
  
}


/* ----------------------------------------------------------------------------
 *  Return the number of puzzles for a nominated level.
 */
uint8_t Game::getNumberOfPuzzles(uint8_t puzzleLevel) {

  switch (puzzleLevel) {
    
    case PUZZLE_5X5:
      return puzzles_5x5_count;
    
    case PUZZLE_6X6:
      return puzzles_6x6_count;
    
    case PUZZLE_7X7:
      return puzzles_7x7_count;
    
    case PUZZLE_8X8:
      return puzzles_8x8_count;
    
    case PUZZLE_9X9:
      return puzzles_9x9_count;

  }

  return 0;
  
}

