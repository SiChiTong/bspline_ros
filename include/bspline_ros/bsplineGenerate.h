#include <iostream>
/*we need set the following flag to disable c++11 for linking the tinyspline */
#define TINYSPLINE_DISABLE_CXX11_FEATURES
#include <tinysplinecpp.h>
#include <ros/ros.h>
#include <geometry_msgs/Point32.h>
#include <geometry_msgs/PolygonStamped.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Path.h>

class bsplineGenerate
{
public:
  ts::BSpline* m_spline_ptr;
  ts::BSpline m_spline_derive;
  std::vector<ts::rational> m_controlpts;
  std::vector<ts::rational> m_knotpts;
  int m_n_controlpts;
  int m_n_knots;
  int m_default_deg;
  int m_deg;
  nav_msgs::Path m_spline_path;
  bool m_is_TsNone;
  float m_t0, m_tn;

  ros::NodeHandle m_nh;
  ros::Subscriber m_sub_path_grid_points;
  ros::Publisher m_pub_spline_path;

  /* onInit() for tinyspline_ros_node or bsplineGenerateLibrary. */
  void onInit();
  void onInit(int degree, bool isTsNone, std::string spline_path_pub_topic_name);
  void pathGridPointsCallback(const geometry_msgs::PolygonStampedConstPtr& msg);
  void splinePathDisplay();
  void bsplineParamInput(geometry_msgs::PolygonStamped* msg);
  void getDerive();
  std::vector<double> evaluate(double t);
  std::vector<double> evaluateDerive(double t);
};
