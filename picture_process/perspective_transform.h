#include <iostream>
#include <vector>

class PerspectiveTransform {
    PerspectiveTransform(float inA11, float inA21, 
                                           float inA31, float inA12, 
                                           float inA22, float inA32, 
                                           float inA13, float inA23, 
                                           float inA33);

    PerspectiveTransform quadrilateralToQuadrilateral(float x0, float y0, float x1, float y1, float x2, float y2,
                                                      float x3, float y3, float x0p, float y0p, float x1p, float y1p,
                                                      float x2p, float y2p, float x3p, float y3p);

    PerspectiveTransform squareToQuadrilateral(float x0, float y0, float x1, float y1, float x2,
    float y2, float x3, float y3);

    PerspectiveTransform quadrilateralToSquare(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3);

    PerspectiveTransform buildAdjoint();

    PerspectiveTransform times(PerspectiveTransform other);

    void transformPoints(std::vector<float> &points);

};