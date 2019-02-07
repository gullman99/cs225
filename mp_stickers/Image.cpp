#include "Image.h"


namespace cs225{
  void Image::lighten(){
    //private member variables must be accessed by using member functions
    for (unsigned i = 0; i < width(); i++) {
      for (unsigned j = 0; j < height(); j++) {
        //check if l is greater than .9
        HSLAPixel & pixelInput = getPixel(i, j);
        if(pixelInput.l>.9){
          pixelInput.l=1.0;
        }
        else{
          pixelInput.l =  pixelInput.l + .1;
        }
      }
    }
  }
  void 	Image::lighten (double amount){
    for (unsigned i = 0; i < width(); i++) {
      for (unsigned j = 0; j < height(); j++) {
        //check if l is greater than .9
        HSLAPixel & pixelInput = getPixel(i, j);
        if((pixelInput.l+amount)>1.0){
          pixelInput.l=1.0;
        }
        else{
          pixelInput.l =  pixelInput.l + .1;
        }
      }
    }
  }
  void 	Image::darken (){
    for (unsigned i = 0; i < width(); i++) {
      for (unsigned j = 0; j < height(); j++) {
        //check if l is greater than .9
        HSLAPixel & pixelInput = getPixel(i, j);
        if((pixelInput.l)<.1){
          pixelInput.l = 0;
        }
        else{
          pixelInput.l =  pixelInput.l - .1;
        }
      }
    }
  }
  void 	Image::darken (double amount){
    for (unsigned i = 0; i < width(); i++) {
      for (unsigned j = 0; j < height(); j++) {
        //check if l is greater than .9
        HSLAPixel & pixelInput = getPixel(i, j);
        if((pixelInput.l-amount)<0.0){
          pixelInput.l = 0.0;
        }
        else{
          pixelInput.l =  pixelInput.l - amount;
        }
      }
    }
  }
  void 	Image::saturate (){
    for (unsigned i = 0; i < width(); i++) {
      for (unsigned j = 0; j < height(); j++) {
        //check if l is greater than .9
        HSLAPixel & pixelInput = getPixel(i, j);
        if(pixelInput.s>.9){
          pixelInput.s=1.0;
        }
        else{
          pixelInput.s =  pixelInput.s + .1;
        }
      }
    }
  }
  void 	Image::saturate (double amount){
    for (unsigned i = 0; i < width(); i++) {
      for (unsigned j = 0; j < height(); j++) {
        //check if l is greater than .9
        HSLAPixel & pixelInput = getPixel(i, j);
        if((pixelInput.s+amount)>1.0){
          pixelInput.s=1.0;
        }
        else{
          pixelInput.s =  pixelInput.s + .1;
        }
      }
    }
  }
  void 	Image::desaturate() {
    for (unsigned i = 0; i < width(); i++) {
      for (unsigned j = 0; j < height(); j++) {
        //check if l is greater than .9
        HSLAPixel & pixelInput = getPixel(i, j);
        if((pixelInput.s)<.1){
          pixelInput.s = 0;
        }
        else{
          pixelInput.s =  pixelInput.s - .1;
        }
      }
    }
  }
  void 	Image::desaturate (double amount){
    for (unsigned i = 0; i < width(); i++) {
      for (unsigned j = 0; j < height(); j++) {
        //check if l is greater than .9
        HSLAPixel & pixelInput = getPixel(i, j);
        if((pixelInput.s-amount)<0.0){
          pixelInput.s = 0.0;
        }
        else{
          pixelInput.s =  pixelInput.s - amount;
        }
      }
    }
  }
  void 	Image::grayscale (){
    for (unsigned i = 0; i < width(); i++) {
      for (unsigned j = 0; j < height(); j++) {
        HSLAPixel & pixel = getPixel(i, j);

        // `pixel` is a pointer to the memory stored inside of the PNG `image`,
        // which means you're changing the image directly.  No need to `set`
        // the pixel since you're directly changing the memory of the image.
        pixel.s = 0;
      }
    }

  }
  void 	Image::rotateColor (double degrees){}
  void 	Image::illinify (){
    for (unsigned i = 0; i < width(); i++) {
      for (unsigned j = 0; j < height(); j++) {
        HSLAPixel & pixel = getPixel(i, j);
        if(pixel.h<=113.5||pixel.h>=293.5){
          pixel.h=11.0;
        }
        else{
          pixel.h=216.0;
        }
      }
    }

  }
  void 	Image::scale (double factor){}
  void 	Image::scale (unsigned w, unsigned h){

  }
}
