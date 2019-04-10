#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() { }

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : 
	IntensityImage(width, height), 
	_intensityMap(width, std::vector<Intensity>(height)) { }

IntensityImageStudent::~IntensityImageStudent() { }

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	this->_intensityMap.reserve(width);
	for (size_t x = 0; x < width; x++) {
		if (x < this->_intensityMap.size()) {
			this->_intensityMap.at(x) = std::vector<Intensity>(height);
		}
		else {
			this->_intensityMap.push_back(std::vector<Intensity>(height));
		}
	}

}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	this->set(other.getWidth(), other.getHeight());
	for (size_t x = 0; x < other.getWidth(); x++) {
		for (size_t y = 0; y < other.getHeight(); y++) {
			this->_intensityMap.at(x).at(y) = other._intensityMap.at(x).at(y);
		}
	}
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	//int throwError = 0, e = 1 / throwError;
	this->_intensityMap.at(x).at(y) = pixel;
	//TODO: no comment needed :)
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	// int throwError = 0, e = 1 / throwError;
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/

	auto x = i % this->getWidth();
	auto y = i / this->getWidth();
	this->_intensityMap.at(x).at(y) = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return this->_intensityMap.at(x).at(y);
}

Intensity IntensityImageStudent::getPixel(int i) const {
	// int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)
	auto x = i % this->getWidth();
	auto y = i / this->getWidth();
	return this->_intensityMap.at(x).at(y);//this->_bitmap.at(x).at(y);;
}