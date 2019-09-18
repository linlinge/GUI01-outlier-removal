#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/io/ply_io.h>
#include <pcl/kdtree/kdtree_flann.h>
#include <pcl/surface/mls.h>
typedef pcl::PointXYZRGBA PointType;

int main (int argc, char** argv)
{
	// Load input file into a PointCloud<T> with an appropriate type
	pcl::PointCloud<PointType>::Ptr cloud (new pcl::PointCloud<PointType> ());
	if (pcl::io::loadPLYFile<PointType>(argv[1], *cloud) == -1) 
	{
		PCL_ERROR("Couldn't read file test_pcd.pcd \n");
		return (-1);
	}

	// Create a KD-Tree
	pcl::search::KdTree<PointType>::Ptr tree (new pcl::search::KdTree<PointType>);

	// Output has the PointNormal type in order to store the normals calculated by MLS
	pcl::PointCloud<pcl::PointNormal> mls_points;

	// Init object (second point type is for the normals, even if unused)
	pcl::MovingLeastSquares<PointType, pcl::PointNormal> mls;

	mls.setComputeNormals (true);

	// Set parameters
	mls.setInputCloud (cloud);
	mls.setPolynomialOrder (2);
	mls.setSearchMethod (tree);
	mls.setSearchRadius (0.03);
 
	// Reconstruct
	mls.process (mls_points);

	// Save output
	pcl::io::savePLYFileASCII(argv[2],*cloud);
	//pcl::io::savePCDFile ("mid-mls.pcd", mls_points);
}