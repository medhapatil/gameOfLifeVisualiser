#pragma once

#include "ofMain.h"
#include "ofxGrafica.h"

//Program to visualize Conway's Game of Life in OpenFrameworks window

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyReleased(int key);
    
    vector<vector<ofxGPoint>> points_grid;       //Grid of cells
    const int kDIMENSION = 100;       //Dimention of grid - kDIMENSION^2 is number of cells
    const int kSCALE = 10;       //Spacing between cells
    
    void setInitValues();       //Setting up initial state randomly
    void updateGrid();       //Updating values on cell grid
    string evaluate(int x, int y);       //Evaluating each cell at x,y position on grid
    string evaluateNeighbours(int live_cell_live_neighbours, int dead_cell_live_neighbours, bool is_live_cell);       //Evaluating neighbours and using rules to determine state of cell in next generation
    void drawGrid();       //Drawing grid at each generation
    
};
