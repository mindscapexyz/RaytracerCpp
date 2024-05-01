#include <fstream>
#include <cmath>

struct Vec {
    double x,y,z;
    Vec(){x=y=z=0;}
    Vec(double a, double b, double c){x=a,y=b,z=c;}
    Vec operator + (Vec v){return Vec(x+v.x, y+v.y,z+v.z);}
    Vec operator - (Vec v){return Vec(x-v.x, y-v.y,z-v.z);}
    Vec operator * (double d){return Vec(x*d, y*d, z*d);}
    Vec operator / (double d){return Vec(x/d, y/d, z/d);}
    Vec normalize(){double mg = sqrt(x*x+y*y+z*z); return Vec(x/mg, y/mg, z/mg);}
};

struct Ray{
    Vec o; // Origin
    Vec d; // Direction
    Ray(Vec i, Vec j){o=i,d=j;}
};

double dot(Vec v, Vec b){
    return (v.x*b.x+v.y*b.y+v.z*b.z);
};

struct Sphere {
    Vec c;
    double r;
    Sphere(Vec i, double j){c=i, r=j;};
    Vec getNormal(Vec pi){return (c-pi)/r;}
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

            t = (t0 < t1) ? t0 : t1;
            return true;

        }
    }
};

struct Color {
    double r,g,b;
    Color(){r=g=b=0;}
    Color(double i, double j, double k){r=i,g=j,b=k;}
    Color operator * (double d){return Color(r*d, g*d, b*d);}
    Color operator + (Color c){return Color(r+c.r, g+c.g, b+c.b);}
};

int main(){
    const int W{500};
    const int H{500};

    std::ofstream out("ppm");
    out << "P3\n" << W << '\n' << H << '\n' << "255\n";

    Color pixel_col[H][W];

    Color white(255,255,255);
    Color red(255,0,0);
    Sphere sphere(Vec(W/2, H/2, 50), 20);
    Sphere light(Vec(W/2, 0, 50), 1);


    for(int y= 0; y<H; y++){
        for(int x=0; x<W; x++){
            // Send ray through each pixel
            Ray ray(Vec(x,y,0), Vec(0,0,1));

            double t = 20000;

            // Check for intersections
            if(sphere.intersect(ray, t)){
                // Point of intersection
                Vec pi = ray.o + ray.d*t;

                // Color the pixel
                // pixel_col[y][x] = white;
                Vec L = light.c - pi;
                Vec N = sphere.getNormal(pi);
                double dt = dot(L.normalize(), N.normalize());

                pixel_col[y][x] = red + (white * dt);


            }

            out << pixel_col[y][x].r << std::endl;
            out << pixel_col[y][x].g << std::endl;
            out << pixel_col[y][x].b << std::endl;

        }
    }

    return 0;
}