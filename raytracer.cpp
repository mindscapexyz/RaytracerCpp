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

double  dot(Vec v, Vec b){
    return (v.x*b.x+v.y*b.y+v.z*b.z);
}

class Sphere {
    Vec c;
    double r;
    Sphere(Vec i, double j){c=i, r=j;};
    bool intersect(Ray ray, double &t){
        Vec o = ray.o;
        Vec d = ray.d;
        Vec oc = o-c;
        double b = 2*dot(oc,d);
        double c = dot(oc, oc)-r*r;
        double disc = b*b-4*c;
        if(disc<0) return false;
        else{
            disc = sqrt(disc);
            double t0 = -b-disc;
            double t1 = -b+disc;

            return 
        }
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