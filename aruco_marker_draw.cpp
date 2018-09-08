// g++ $(pkg-config --cflags eigen3) -o aruco_marker_draw aruco_marker_draw.cpp -lboost_iostreams -lboost_system -lboost_filesystem
// Draw corner points of Acuko Marker by it base point
// Aruco Marker has 11x11 cm size with 1.5 cm frame

#include <Eigen/Dense>
#include "gnuplot-iostream.h"

using DrawPoint = std::tuple<double, double, double>;

DrawPoint eigenToDrawPoint (Eigen::Vector3d &vector) {
    return std::make_tuple( vector.x(), vector.y(), vector.z());
}

void draw_point (std::vector<DrawPoint> &point_vec) {
    Gnuplot gp;

    std::vector <DrawPoint> pv;
    gp << "set style line 1 lc rgb 'black' pt 5\n";
    gp << "splot '-' w p ls 1\n";
    gp.send(point_vec);
}

std::vector<Eigen::Translation3d> marker_t = {
    { 0.01,  0.11, 0.0}, // top left
    {-0.11,  0.11, 0.0}, // top right
    {-0.11, -0.05, 0.0}, // bottom right
    { 0.01, -0.05, 0.0}  // bottom left
};

int main () {
    std::vector <DrawPoint> test_vec;

    Eigen::Vector3d marker_base {0.46, 0.707, 1.209};
    test_vec.push_back( eigenToDrawPoint( marker_base ) );

    for (const auto &t : marker_t) {
        auto v = t * marker_base; // Apply translation to base point
        test_vec.push_back( eigenToDrawPoint( v ) );
        std::cout << "======" << std::endl;
        std::cout << v << std::endl;
    }

    draw_point( test_vec );
}
