#pragma once


// x, y, slider (0 = none), unit
const uint8_t puzzles_details[] = {
  27, 16, 0, 0,   // 5x5
  21, 10, 0, 0,   // 6x6
  15, 4, 0, 0,    // 7x7
  6, 4, 7, 68,    // 8x8
  1, 4, 6, 64,    // 9x9
};

const uint8_t puzzles_5x5_count = 2;

const uint8_t puzzles_5x5[] = {

  0x10, 0x20, 0x40,
  0x00, 0x30, 0x50,
  0x00, 0x00, 0x00,
  0x02, 0x04, 0x00,
  0x01, 0x35, 0x00,
  
  0x10, 0x00, 0x00,
  0x00, 0x00, 0x00,
  0x00, 0x40, 0x00,
  0x24, 0x30, 0x10,
  0x30, 0x00, 0x20,

};

const uint8_t puzzles_6x6_count = 2;

const uint8_t puzzles_6x6[] = {
		  
  0x12, 0x30, 0x46,
  0x00, 0x00, 0x50,
  0x00, 0x30, 0x00,
  0x00, 0x40, 0x00,
  0x10, 0x50, 0x00,
  0x20, 0x60, 0x00,
  
  0x01, 0x20, 0x03,
  0x00, 0x00, 0x00,
  0x00, 0x45, 0x03,
  0x00, 0x06, 0x02,
  0x05, 0x40, 0x61,
  0x00, 0x00, 0x00,

};

const uint8_t puzzles_7x7_count = 2;

const uint8_t puzzles_7x7[] = {
		  
  0x00, 0x00, 0x00, 0x10,
  0x00, 0x00, 0x02, 0x30,
  0x02, 0x00, 0x00, 0x00,
  0x00, 0x04, 0x50, 0x00,
  0x00, 0x40, 0x60, 0x00,
  0x00, 0x00, 0x36, 0x00,
  0x00, 0x00, 0x01, 0x50,
  
  0x01, 0x20, 0x00, 0x00,
  0x00, 0x34, 0x04, 0x00, 
  0x00, 0x50, 0x00, 0x00, 
  0x00, 0x76, 0x05, 0x00, 
  0x00, 0x00, 0x67, 0x00, 
  0x00, 0x00, 0x00, 0x00, 
  0x00, 0x12, 0x00, 0x00, 
  
};

const uint8_t puzzles_8x8_count = 2;

const uint8_t puzzles_8x8[] = {
		  
  0x00, 0x00, 0x10, 0x00,
  0x00, 0x00, 0x20, 0x34,
  0x00, 0x00, 0x34, 0x02,
  0x00, 0x06, 0x50, 0x00,
  0x00, 0x00, 0x60, 0x00,
  0x00, 0x00, 0x50, 0x00,
  0x00, 0x00, 0x00, 0x00,
  0x01, 0x00, 0x00, 0x00,
  
  0x12, 0x30, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x60, 
  0x00, 0x00, 0x00, 0x00, 
  0x40, 0x45, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 
  0x50, 0x00, 0x02, 0x00, 
  0x00, 0x00, 0x00, 0x00, 
  0x16, 0x03, 0x00, 0x00, 
 
};

const uint8_t puzzles_9x9_count = 2;  

const uint8_t puzzles_9x9[] = {
		  
  0x00, 0x00, 0x00, 0x00, 0x00,
  0x01, 0x23, 0x00, 0x00, 0x00, 
  0x00, 0x02, 0x40, 0x43, 0x00, 
  0x00, 0x00, 0x00, 0x05, 0x00, 
  0x06, 0x06, 0x10, 0x00, 0x00, 
  0x75, 0x00, 0x00, 0x09, 0x80, 
  0x08, 0x70, 0x00, 0x00, 0x00, 
  0x09, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 
  
  0x10, 0x00, 0x00, 0x02, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 
  0x20, 0x03, 0x04, 0x01, 0x00, 
  0x00, 0x06, 0x00, 0x05, 0x00, 
  0x08, 0x00, 0x04, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 
  0x08, 0x30, 0x05, 0x00, 0x00, 
  0x00, 0x76, 0x00, 0x00, 0x00, 
  
};
