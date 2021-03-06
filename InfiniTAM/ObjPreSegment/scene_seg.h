#pragma once

#include "../Common/common_func.h"
#include "../Common/common_type.h"
#include "../Common/visualizer.h"

#include <iostream>

#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/ModelCoefficients.h>
#include <pcl/sample_consensus/method_types.h>
#include <pcl/sample_consensus/model_types.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <pcl/segmentation/extract_clusters.h>
#include <pcl/visualization/cloud_viewer.h>
#include "pcl/filters/extract_indices.h"
#include <pcl/filters/voxel_grid.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/project_inliers.h>
#include <pcl/features/normal_3d.h>
#include <pcl/kdtree/kdtree.h>
#include <pcl/common/transforms.h>

#include <math.h>

#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

typedef struct TriFace{
  Point p0;
  Point p1;
  Point p2;
}Face;

using namespace std;

//detect table
void detect_table(PointCloudPtr_RGB_NORMAL sourceCloud, pcl::ModelCoefficients& plane_coefficients, PointCloudPtr_RGB_NORMAL planeCloud, PointCloudPtr rect_cloud, PointCloudPtr_RGB_NORMAL remainingCloud);
//get transform matrix between plane and x_y plane 
void getTemTransformMatrix(pcl::ModelCoefficients& coefficients, Eigen::Matrix4f& matrix_transform, Eigen::Matrix4f& matrix_transform_r);
//detect table plane
void detect_table_plane(PointCloudPtr_RGB_NORMAL sourceCloud, PointCloudPtr_RGB_NORMAL planeCloud, PointCloudPtr_RGB_NORMAL remainCloud);
//Euclidean Cluster Extraction
void object_seg_ECE(PointCloudPtr_RGB_NORMAL cloud, std::vector<MyPointCloud_RGB_NORMAL> &cluster_points);
//find a minimum bounding rect
void find_min_rect(PointCloudPtr_RGB_NORMAL cloud, cv::Point2f &p0,cv::Point2f &p1,cv::Point2f &p2,cv::Point2f &p3);
//VCCS over-segmentation
void VCCS_over_segmentation(PointCloudPtr_RGB_NORMAL cloud, float voxel_resolution,float seed_resolution,float color_importance,float spatial_importance,float normal_importance,vector<MyPointCloud_RGB_NORMAL>& patch_clouds, PointCloudT::Ptr colored_cloud, PointNCloudT::Ptr normal_cloud);
