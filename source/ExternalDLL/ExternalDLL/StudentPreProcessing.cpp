#include <iostream>
#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	std::cout << "converting RGB to Intensity image...\n";
	RGB current_pixel;
	// allocate a new IntensityImage on the heap so we can return its pointer
	IntensityImageStudent *intensity_image_ptr = new IntensityImageStudent(image.getHeight(), image.getWidth());

	for (int i = 0; i < intensity_image_ptr->getHeight(); ++i) {
		for (int j = 0; j < intensity_image_ptr->getWidth(); ++j) {
			current_pixel = image.getPixel(i, j);
			// converting the R, G and B channels to grayscale with the weighted method
			intensity_image_ptr->setPixel(i, j, ((current_pixel.r * 0.30)
												+ (current_pixel.g * 0.59)
												+ (current_pixel.b * 0.77)) / 3);
		}
	}
	return intensity_image_ptr;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}