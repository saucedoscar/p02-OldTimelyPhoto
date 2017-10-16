#include<string>
#include<vector>
#include<iostream>
#include"bitmap.h"
using namespace std;
int main()
{
    Bitmap image;
    Pixel rgb;
    char response;
    string file;
    bool loop;
    bool understood;
    bool validImage ;
    string OldTimeyPhoto;
    vector < vector <Pixel> > bmp;
    //ask user for file
    cout<<"Please give me a bmp file to change to black and white."<<endl;
    //store the user's ipute in a variable.
    cin>>file;
    image.open(file);
    
    do{
        if(image.isImage() == true)//if image isImage();
        {
            bmp = image.toPixelMatrix();
            //go through all pixels and change to greyscale based off of their rgb.
            for(int r = 0; r < bmp.size(); r++)
            {
                for(int c = 0; c < bmp[r].size(); c++)
                {
                    rgb = bmp[r][c];
                    if(rgb.green >= rgb.red && rgb.green >= rgb.blue)
                    {
                    rgb.red = rgb.green;
                    rgb.blue = rgb.blue;
                    bmp[r][c] = rgb;
                    }
                    if(rgb.red >= rgb.green && rgb.red >= rgb.blue)
                    {
                    rgb.green = rgb.red;
                    rgb.blue = rgb.red;
                    bmp[r][c] = rgb;
                    }
                    if(rgb.blue >= rgb.red && rgb.blue >= rgb.green)
                    {
                    rgb.red = rgb.blue;
                    rgb.green = rgb.blue;
                    bmp[r][c] = rgb;
                    }
                }
            }
            image.fromPixelMatrix(bmp);
            image.save("OldTimeyPhoto.bmp");
            //override the greyscale image onto the original bmp image

            //save the bmp file
            loop = false;
        }
        else
        {
        cout<<"I am sorry, the file must be a 24 bit depth Windows BMP file. Would you like to try again with another file?"<<endl;
        cin>>response;
            do
            {   
                if(response == 'Y'|| response == 'y')
                {

                    understood = true;
                    loop = true;
                }
                else if(response == 'N'|| response == 'n')
                {
                    understood = true;
                    loop = false;
                }
                else
                {
                    cout<<"Sorry that response is invalid. Please type'y' for yes and 'n' for no."<<endl;
                    understood = false;
                }
            }while( understood = false);
    
          }
       }while(loop == true); 
return 0;
}
