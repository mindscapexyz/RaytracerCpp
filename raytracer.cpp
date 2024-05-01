#include <fstream>

class Vec {
    double x,y,z;
    Vec(){x=y=z=0;}
    Vec(double a, double b, double c){x=a,y=b,z=c;}
};

class Ray{
    Vec o; // Origin
    Vec d; // Direction
    Ray(Vec i, Vec j){o=i,d=j;}
};

class Sphere {
    Vec c;
    double r;
    Sphere(Vec i, double j){c=i, r=j;};
    bool intersect(Ray ray, double &t){
        Vec o = ray.o;
        Vec d = ray.d;
        Vec oc = o-c;
        double b = 2*dot(oc,d);
    }
}

int main(){
    const int W{500};
    const int H{500};

    for(int y= 0; y<H; y++){
        for(int x=0; x<W; x++){
            // Send ray through each pixel
            Ray ray(Vec(x,y,0), Vec(0,0,1));

            // Check for intersections

        }
    }
}