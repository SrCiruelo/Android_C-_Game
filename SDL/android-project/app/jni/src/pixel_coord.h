//
// Created by migue on 18/01/2020.
//

#ifndef ANDROID_PROJECT_PIXEL_COORD_H
#define ANDROID_PROJECT_PIXEL_COORD_H

struct pixel_coord{
    int x;
    int y;
    pixel_coord():x{0},y{0}{};
    pixel_coord(int x,int y):x{x},y{y}{};
    pixel_coord(const pixel_coord& ) = default;
    pixel_coord(pixel_coord&&) = default;
    pixel_coord& operator=(const pixel_coord&) = default;
    pixel_coord& operator=( pixel_coord&&) = default;
};

#endif //ANDROID_PROJECT_PIXEL_COORD_H
