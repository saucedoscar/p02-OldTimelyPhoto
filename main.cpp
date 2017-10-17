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
    do{
        //ask user for file
        cout<<"Please give me a bmp file to change to black and white."<<endl;
        //store the user's input in a variable
        cin>>file;
        image.open(file);
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
            //override the greyscale image onto the original bmp image
            image.fromPixelMatrix(bmp);
            //Save the file
            image.save("OldTimeyPhoto.bmp");
            loop = false;
        }
        else
        {
        cout<<"I am sorry, the file must be a 24 bit depth Windows BMP file. Would you like to try again with another file?"<<endl;
            do //If the user is not understood, this loop will continue until they are understood
            {   
                
                cout<<"Type Y for yes, N for no."<<endl;
                cin>>response;
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
                    cout<<"Sorry that response is invalid."<<endl;
                    understood = false;
                }
            }while( understood == false);
    
       }
     }while(loop == true); 
return 0;
}
