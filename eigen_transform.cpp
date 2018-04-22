#include <iostream>
#include <iterator>
#include <vector>
#include <Eigen/Dense>
#include <Eigen/Geometry>

void printAffine3d (Eigen::Affine3d aff, std::string title) {
    std::cout << "==== " << title  << " ====" << std::endl;
    std::cout << aff.matrix() << std::endl;
} 

Eigen::Affine3d createAffine3d (Eigen::Vector3d p, Eigen::Matrix3d r) {
    Eigen::Affine3d aff = Eigen::Affine3d::Identity();

    aff.translate(p);
    aff.rotate(r);
    return aff;

}

int main () {
    Eigen::Matrix3d rot;
    rot << -0.1608419811016002, 0.33677521194330323, -0.9277458238848912,
            0.9869797972615373, 0.05406456660905756, -0.15148565092096872,
           -0.0008584363035787912, -0.9400316373707418, -0.3410861824073128;
    Eigen::Affine3d T_w_c = createAffine3d (Eigen::Vector3d(2.222, 1.118, 1.675), rot); //Eigen::Affine3d::Identity();

    rot << 0.5082498671542095, 0.8566348004037545, -0.0886503879007215,
           0.4950298881214059, -0.37482620620577056, -0.7838690738942943,
          -0.7047180162336117,  0.35451676106865515, -0.6145651989147729;
    Eigen::Affine3d T_w_t = createAffine3d(Eigen::Vector3d(-0.500, 0.500, 1.800), rot);


    rot << 0.40521662852134976, 0.7616089437855711, -0.5057185983485453,
           0.8564534203956082, -0.5097591131287218, -0.08144436920305134,
          -0.3198234241928727, -0.40012181061277585,-0.8588454540890929;
    Eigen::Affine3d T_c_m = createAffine3d(Eigen::Vector3d(-0.463, -0.960, 2.734), rot);

    printAffine3d(T_w_c, "T_w_c");
    printAffine3d(T_w_t, "T_w_t");
    printAffine3d(T_c_m, "T_c_m");

    //Eigen::Affine3d T_t_m = T_w_t.inverse() * T_w_c * T_c_m;
    Eigen::Affine3d T_t_m = T_c_m * T_w_c * T_w_t.inverse();

   printAffine3d(T_t_m, "T_t_m"); 
}
