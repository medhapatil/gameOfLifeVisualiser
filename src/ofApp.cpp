#include "ofApp.h"

void ofApp::setup(){
    setInitValues();
}

//--------------------------------------------------------------
void ofApp::update(){
    if (ofGetElapsedTimeMillis() > 100) {
        updateGrid();
        ofResetElapsedTimeCounter();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawGrid();
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
//    //OPTION TO CHANGE GENERATION WITH SPACE BAR
//    if (key == 32) {
//        updateGrid();
//    }
}

//--------------------------------------------------------------
void ofApp::setInitValues() {
    for (int i = 0; i < kDIMENSION; ++i) {
        vector<ofxGPoint> rowVector;
        for (int j = 0; j < kDIMENSION; ++j) {
            ofxGPoint columnPoint;
            columnPoint.setXY(i * kSCALE, j * kSCALE);
            if (rand() % 10 >= 5) {
                columnPoint.setLabel("live");
            } else {
                columnPoint.setLabel("dead");
            }
            rowVector.push_back(columnPoint);
        }
        points_grid.push_back(rowVector);
    }
}

//--------------------------------------------------------------
void ofApp::updateGrid() {
    for (int i = 0; i < kDIMENSION; ++i) {
        for (int j = 0; j < kDIMENSION; ++j) {
            string currentLabel = points_grid[i][j].getLabel();
            string evaluatedLabel = evaluate(i, j);
            if (currentLabel != evaluatedLabel) {
                if (evaluatedLabel == "dead") {
                    points_grid[i][j].setLabel("dead");
                } else {
                    points_grid[i][j].setLabel("live");
                }
            }
        }
    }
}

//--------------------------------------------------------------
string ofApp::evaluate(int x, int y) {
    int dead_cell_live_neighbours = 0;
    int live_cell_live_neighbours = 0;
    bool is_live_cell = (points_grid[x][y].getLabel() == "live");
    if (x == 0 && y == 0) {
        if (points_grid[x + 1][y].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
    } else if (x == 0 && y == kDIMENSION - 1) {
        if (points_grid[x][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
    } else if (x == kDIMENSION - 1 && y == 0) {
        if (points_grid[x - 1][y].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x - 1][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
    } else if (x == kDIMENSION - 1 && y == kDIMENSION - 1) {
        if (points_grid[x - 1][y].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x - 1][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
    } else if (x == 0) {
        if (points_grid[x][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
    } else if (x == kDIMENSION - 1) {
        if (points_grid[x - 1][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x - 1][y].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x - 1][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
    } else if (y == 0) {
        if (points_grid[x - 1][y].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x - 1][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
    } else if (y == kDIMENSION - 1) {
        if (points_grid[x - 1][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x - 1][y].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
    } else {
        if (points_grid[x - 1][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y - 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x - 1][y].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x - 1][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
        if (points_grid[x + 1][y + 1].getLabel() == "live") {
            is_live_cell ? live_cell_live_neighbours++ : dead_cell_live_neighbours++;
        }
    }
    return evaluateNeighbours(live_cell_live_neighbours, dead_cell_live_neighbours, is_live_cell);
}

//--------------------------------------------------------------
string ofApp::evaluateNeighbours(int live_cell_live_neighbours, int dead_cell_live_neighbours, bool is_live_cell) {
    //Births: Each dead cell adjacent to exactly three live neighbors will become live in the next generation.
    if (dead_cell_live_neighbours == 3 && !is_live_cell) {
        return "live";
    }
    //Death by isolation: Each live cell with one or fewer live neighbors will die in the next generation.
    if (live_cell_live_neighbours <= 1 && is_live_cell) {
        return "dead";
    }
    //Death by overcrowding: Each live cell with four or more live neighbors will die in the next generation.
    if (live_cell_live_neighbours >= 4 && is_live_cell) {
        return "dead";
    }
    //Survival: Each live cell with either two or three live neighbors will remain alive for the next generation.
    if (is_live_cell) {
        return "live";
    } else {
        return "dead";
    }
}

//--------------------------------------------------------------
void ofApp::drawGrid() {
    for (int i = 1; i <= kDIMENSION; i++) {
        for (int j = 1; j <= kDIMENSION; j++) {
            if (points_grid[i - 1][j - 1].getLabel() == "live") {
                ofSetColor(255);
                ofDrawCircle(i * kSCALE, j * kSCALE, kSCALE/2);
            } else {
                ofSetColor(0);
                ofDrawCircle(i * kSCALE, j * kSCALE, kSCALE/2);
            }
        }
    }
}
