#include <iostream>
#include <vector>

class PerspectiveTransform {

public:
    PerspectiveTransform(float inA11, float inA21, float inA31,
                         float inA12, float inA22, float inA32,
                         float inA13, float inA23, float inA33);

    static PerspectiveTransform quadrilateralToQuadrilateral(float x0, float y0, float x1, float y1,
                                                             float x2, float y2, float x3, float y3,
                                                             float x0p, float y0p,float x1p, float y1p,
                                                             float x2p, float y2p, float x3p, float y3p);

    static PerspectiveTransform squareToQuadrilateral(float x0, float y0, float x1, float y1,
                                                      float x2, float y2, float x3, float y3);

    static PerspectiveTransform quadrilateralToSquare(float x0, float y0, float x1, float y1,
                                                      float x2, float y2, float x3, float y3);

    PerspectiveTransform buildAdjoint();

    PerspectiveTransform times(PerspectiveTransform other);

    void transformPoints(std::vector<float> &points);

    float a11 = 0.0;
    float a12 = 0.0;
    float a13 = 0.0;
    float a21 = 0.0;
    float a22 = 0.0;
    float a23 = 0.0;
    float a31 = 0.0;
    float a32 = 0.0;
    float a33 = 0.0;
};