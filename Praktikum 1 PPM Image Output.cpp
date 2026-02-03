#include <iostream>
#include <fstream>

// 3198964 Irshad Haqqi Almukarimy
// 3105991 Bizhan Madannotgh
// 3200061 Vivegenanthan Ragupathi
// 3191494 Vasundhra Vythilingam

int Width = 255, Height = 255;

struct Pixel {
    double r, g, b;
};

void Header(std::ofstream& Output, int Width, int Height) {
    Output << "P3\n" << Width << " " << Height << "\n255\n";
}

void Color(Pixel* Display, int x, int y, Pixel color) {
    Display[y * Width + x] = color;
}

void Circle(Pixel* Display, int xcircle, int ycircle, int rad, Pixel color) {
    for (int y = 0; y < Height; ++y) {
        for (int x = 0; x < Width; ++x) {
            int Draw = (x - xcircle) * (x - xcircle) + (y - ycircle) * (y - ycircle);
            if (Draw <= rad * rad) {
                Color(Display, x, y, color);
            }
        }
    }
}

void PPM( Pixel* Display, std::ofstream& Output, int Width, int Height) {
    Header(Output, Width, Height);
    for (int y = 0; y < Height; ++y) {
        for (int x = 0; x < Width; ++x) {
            Output << static_cast<int>(Display[y * Width + x].r) << " "
                   << static_cast<int>(Display[y * Width + x].g) << " "
                   << static_cast<int>(Display[y * Width + x].b) << " ";
        }
        Output << "\n";
    }
}

int main() {
    Pixel Display[Width * Height];

    std::ofstream Output("Output.ppm");

    for (double y = 0; y < Height; ++y) {
        for (double x = 0; x < Width; ++x) {
            Color(Display, x, y, {y, 0, x});
        }
    }

    Circle(Display, 55, 200, 10, {0, 255, 0});

    PPM(Display, Output, Width, Height);
    Output.close();

    std::cout << "Image saved to Output.ppm" << std::endl;
    return 0;
}