/*typedef struct tagBITMAPINFOHEADER {
  DWORD biSize;
  LONG  biWidth;
  LONG  biHeight;
  WORD  biPlanes;
  WORD  biBitCount;
  DWORD biCompression;
  DWORD biSizeImage;
  LONG  biXPelsPerMeter;
  LONG  biYPelsPerMeter;
  DWORD biClrUsed;
  DWORD biClrImportant;
} BITMAPINFOHEADER, *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;
*/
#include <stdio.h>
#include <stdlib.h>
const int FILEHEADERSIZE=14,FILEHEADERINFO=40,PIXELS=3;//Bytes
int width,height;
void takeInput();
unsigned char* createFIleHeader(int s,int h);
unsigned char* createFIleHeaderInfo(int w,int h);
void createBitmap(unsigned char *image,int w,int h);
int main(){
   takeInput();
   unsigned char img[width][height][PIXELS];
}
void takeInput(){
   FILE *fptr;
   if((fptr=fopen("bitimg.txt", "r"))==NULL){
         printf("Error! The file doesnt exist!");
         exit(1);
   }
   fscanf(fptr,"%d",&width);
   fscanf(fptr,"%d",&height);
}
unsigned char* createFileHeader(int s,int h){
   int fileSize=FILEHEADERSIZE+FILEHEADERINFO+(s*h);
   static unsigned char fileHeader[]={'B','M',0,0,0,0, 0,0,0,0, 54,0,0,0};
   fileHeader[2]=(unsigned char)fileSize;
   fileHeader[3]=(unsigned char)(fileSize>>8);
   fileHeader[4]=(unsigned char)(fileSize>>16);
   fileHeader[5]=(unsigned char)(fileSize>>24);
   fileHeader[10]=(unsigned char)(FILEHEADERINFO);
   return fileHeader;
}
unsigned char* createFIleHeaderInfo(int w,int h){
   static unsigned char fileHeaderInfo[]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
   fileHeaderInfo[0]=(unsigned char)FILEHEADERINFO;
   fileHeaderInfo[4]=(unsigned char)w;
   fileHeaderInfo[5]=(unsigned char)(w>>8);
   fileHeaderInfo[6]=(unsigned char)(w>>16);
   fileHeaderInfo[7]=(unsigned char)(w>>24);
   fileHeaderInfo[8]=(unsigned char)(h);
   fileHeaderInfo[9]=(unsigned char)(h>>8);
   fileHeaderInfo[10]=(unsigned char)(h>>16);
   fileHeaderInfo[11]=(unsigned char)(h>>24);
   fileHeaderInfo[12]=1;
   fileHeaderInfo[14]=(unsigned char)(PIXELS*8);
   return fileHeaderInfo;
}
