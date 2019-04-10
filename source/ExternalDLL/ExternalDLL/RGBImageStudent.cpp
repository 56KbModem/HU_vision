#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {
	
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	// int throwError = 0, e = 1 / throwError;
	this->set(other.getHeight(), other.getWidth());
	for (size_t x = 0; x < other.getWidth(); x++) {
		for (size_t y = 0; y < other.getHeight(); y++) {
			this->_bitmap.at(x).at(y) = other._bitmap.at(x).at(y);
		}
	}
	
}


RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height), _bitmap() {
	// Performance optimization
	this->set(width, height); 
}

RGBImageStudent::~RGBImageStudent() {

}

void RGBImageStudent::set(const int width, const int height) {
	
	this->_bitmap.reserve(width);
	for (size_t x = 0; x < width; x++) {
		if(x < this->_bitmap.size()) {
			this->_bitmap.at(x) = std::vector<RGB>(height);
		}
		else {
			this->_bitmap.push_back(std::vector<RGB>(height));
		}
	}
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	this->set(other.getWidth(), this->getHeight());
	for (unsigned int x = 0; x < other.getWidth(); x++) {
		for (unsigned int y = 0; y < other.getHeight(); y++) {
			this->setPixel(x, y, other.getPixel(x, y));
		}
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	
	this->_bitmap.at(x).at(y) = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	auto x = i % this->getWidth();
	auto y = i / this->getWidth();
	this->_bitmap.at(x).at(y) = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return this->_bitmap.at(x).at(y);
}

RGB RGBImageStudent::getPixel(int i) const {
	auto x = i % this->getWidth();
	auto y = i / this->getWidth();
	return this->_bitmap.at(x).at(y);
}



RGB& RGBImageStudent::operator[] (size_t index) {
	auto x = index % this->getWidth();
	auto y = index / this->getWidth();
	return this->_bitmap.at(x).at(y);
}