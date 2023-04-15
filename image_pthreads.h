#ifndef ___IMAGE
#define ___IMAGE
#include <stdint.h>

#define Index(x,y,width,bit,bpp) y*width*bpp+bpp*x+bit

typedef struct{
    uint8_t* data;
    int width;
    int height;
    int bpp;
} Image;

enum KernelTypes{EDGE=0,SHARPEN=1,BLUR=2,GAUSE_BLUR=3,EMBOSS=4,IDENTITY=5};

typedef double Matrix[3][3];

uint8_t getPixelValue(Image* srcImage,int x,int y,int bit,Matrix algorithm);
void *convolute(void* arguments);
int Usage();
enum KernelTypes GetKernelType(char* type);
int min(int a, int b);

//Making a struct to make passing arguments to pthread_create much easier (just pass args instead)
typedef struct{
    Image* srcImage;
    Image* destImage;
    enum KernelTypes type;
    long rank;
    int num_threads;
} thread_args_struct;

#endif