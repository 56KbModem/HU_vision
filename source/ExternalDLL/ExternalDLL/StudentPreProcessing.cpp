#include <iostream>
#include<unordered_map>
#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"
#include <cstdint>
#include <array>
#include<unordered_map>




constexpr double r_weight = 0.30 * 2.55;
constexpr double g_weight = 0.59 * 2.55;
constexpr double b_weight = 0.11 * 2.55;


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	std::cout << "converting RGB to Intensity image...\n";
	// allocate a new IntensityImage on the heap so we can return its pointer
	IntensityImageStudent *intensity_image_ptr = new IntensityImageStudent(image.getWidth(), image.getHeight());
	
	std::unordered_map<uint32_t, Intensity> lookup = std::unordered_map<uint32_t, Intensity>();
	unsigned int totalCounter = 0;
	unsigned int mismatchCounter = 0;
	// Calculating black and white is useless
	lookup[0x000000] = 0;
	lookup[0xFFFFFF] = 255;
	
	for (int x = 0; x < intensity_image_ptr->getWidth(); ++x) {
		for (int y = 0; y < intensity_image_ptr->getHeight(); ++y) {
			totalCounter++;
			RGB current_pixel = image.getPixel(x, y);
			uint32_t lookup_key = current_pixel.r | current_pixel.g << 8 | current_pixel.b << 16;
			auto value = lookup.find(lookup_key);
			Intensity pixelValue;
			if (value == lookup.end()) {
				mismatchCounter++;
				pixelValue = ((current_pixel.r * r_weight)
					+ (current_pixel.g * g_weight)
					+ (current_pixel.b * b_weight)) / 3;
				lookup[lookup_key] = pixelValue;
			}
			else {
				pixelValue = value->second;
			}
			intensity_image_ptr->setPixel(x, y, pixelValue);
			// converting the R, G and B channels to grayscale with the weighted method
		}
	}
	std::cout << "Total loops " << totalCounter << " - Mis: " << mismatchCounter << std::endl;
	std::cout << "Saved by lookup: " << totalCounter - mismatchCounter << std::endl;
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