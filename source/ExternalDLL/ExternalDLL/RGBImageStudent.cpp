#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	int throwError = 0, e = 1 / throwError;
	
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height), _bitmap() {
	// Performance optimization
	this->set(width, height); 
}

RGBImageStudent::~RGBImageStudent() {

}

void RGBImageStudent::set(const int width, const int height) {
	this->_bitmap.reserve(height);
	for (size_t y = 0; y < height; y++) {
		this->_bitmap.push_back(std::vector<RGB>(width));
	}
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	int throwError = 0, e = 1 / throwError;
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	
	this->_bitmap.at(x).at(y) = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	auto x = i % this->getWidth();
	auto y = i - x;
	this->_bitmap.at(x).at(y) = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return this->_bitmap.at(x).at(y);
}

RGB RGBImageStudent::getPixel(int i) const {
	auto x = i % this->getWidth();
	auto y = i - x;
	return this->_bitmap.at(x).at(y);
}



RGB& RGBImageStudent::operator[] (size_t index) {
	auto x = index % this->getWidth();
	auto y = index - x;
	return this->_bitmap.at(x).at(y);
}