//  Copyright (C) 2012, Juan Camilo Mejia, https://github.com/camilosw/ofxVideoMapping
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef QUAD_H
#define QUAD_H

#include "ofMain.h"
#include "ofxQuadSource.h"

class ofxQuad
{
  public:
    /** Default constructor */
    ofxQuad();
    ofxQuad(ofPoint inputPoint1, ofPoint inputPoint2, ofPoint inputPoint3, ofPoint inputPoint4, 
            ofPoint outputPoint1, ofPoint outputPoint2, ofPoint outputPoint3, ofPoint outputPoint4);
    void setSource(ofxQuadSource* value) { source = value; }
    void beginDraw();
    void endDraw();
    void update();
    void draw();
    void draw(ofFbo fbo);
    void drawInputConfig();
    void drawOutputConfig();
    
    void setInputPoints(ofPoint point1, ofPoint point2, ofPoint point3, ofPoint point4);
    void setInputPoint(int index, float x, float y);
    void setInputPoint(int index, ofPoint point);
    ofPoint getInputPoint(int index) { return input[(int)ofClamp(index, 0, 3)]; }    
    
    void setOutputPoints(ofPoint point1, ofPoint point2, ofPoint point3, ofPoint point4);
    void setOutputPoint(int index, float x, float y);
    void setOutputPoint(int index, ofPoint point);
    ofPoint getOutputPoint(int index) { return output[(int)ofClamp(index, 0, 3)]; }
    
    void setLineColor(ofColor value) { lineColor.set(value); }
    void setHexLineColor(int value) { lineColor.setHex(value); }
    
  protected:
  private:
    void drawConfig(ofPoint* points);
    
    GLfloat transformMatrix[16];
    ofPoint input[4];
    ofPoint output[4];
    ofColor lineColor;    
    ofxQuadSource* source;
};

#endif // QUAD_H
