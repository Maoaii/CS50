#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Pixel's RGB average
    int avgPixel = 0;
    
    //Cycle through the image's height
    for (int row = 0; row < height; row++)
    {
        //Cycle through the image's width
        for (int column = 0; column < width; column++)
        {
            //Get RGB average
            avgPixel = round((image[row][column].rgbtBlue + image[row][column].rgbtGreen + image[row][column].rgbtRed) / 3.0);
            
            //Assign new grayscale to the pixel's RGB
            image[row][column].rgbtBlue = avgPixel;
            image[row][column].rgbtGreen = avgPixel;
            image[row][column].rgbtRed = avgPixel;
        }
    }
    
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //Declare and initialize sepia filter
    int sepiaBlue = 0;
    int sepiaGreen = 0;
    int sepiaRed = 0;
    
    //Cycle through the image's height
    for (int row = 0; row < height; row++)
    {
        //Cycle through the image's width
        for (int column = 0; column < width; column++)
        {
            //Convert image's blue to sepia
            sepiaBlue = round(
                            .272 * image[row][column].rgbtRed + 
                            .534 * image[row][column].rgbtGreen + 
                            .131 * image[row][column].rgbtBlue);
            
            //Convert image's green to sepia
            sepiaGreen = round(
                             .349 * image[row][column].rgbtRed + 
                             .686 * image[row][column].rgbtGreen + 
                             .168 * image[row][column].rgbtBlue);
            
            //Convert image's red to sepia
            sepiaRed = round(
                           .393 * image[row][column].rgbtRed + 
                           .769 * image[row][column].rgbtGreen + 
                           .189 * image[row][column].rgbtBlue);
            
            //Make sure that the filter's color is within 24-bit range
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            
            //Assign filter to the actual pixel
            image[row][column].rgbtBlue = sepiaBlue;
            image[row][column].rgbtGreen = sepiaGreen;
            image[row][column].rgbtRed = sepiaRed;
        }
    }
    
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Create a temporary "pixel"
    RGBTRIPLE tmp;
    
    //Cycle through the image's height
    for (int row = 0; row < height; row++)
    {
        //Cycle through half of the image's width
        for (int column = 0; column < width / 2; column++)
        {
            //Copy rightmost pixel to the temporary pixel
            tmp = image[row][column];
            //Copy rightmost pixel to the leftmost pixel
            image[row][column] = image[row][width - 1 - column];
            //Copy the temporary pixel to the rightmost pixel
            image[row][width - 1 - column] = tmp;
        }
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Declare image copy
    RGBTRIPLE copy[height][width];
    
    //Copy image
    for (int row = 0; row < height; row++)
    {
        for (int column = 0; column < width; column++)
        {
            copy[row][column] = image[row][column];
        }
    }

    for (int row = 0; row < height; row++)
    {
        //Declare RGB for the average and a pixel counter
        int red, green, blue;
        float pixelcounter;
        
        for (int column = 0; column < width; column++)
        {
            red = green = blue = 0;
            pixelcounter = 0.0;
            
            //Add middle pixel
            if (row >= 0 && column >= 0)
            {
                red += copy[row][column].rgbtRed;
                green += copy[row][column].rgbtGreen;
                blue += copy[row][column].rgbtBlue;
                pixelcounter++;
            }
            //Add middle left pixel
            if (row >= 0 && column - 1 >= 0)
            {
                red += copy[row][column - 1].rgbtRed;
                green += copy[row][column - 1].rgbtGreen;
                blue += copy[row][column - 1].rgbtBlue;
                pixelcounter++;
            }
            //Add middle right pixel
            if ((row >= 0 && column + 1 >= 0) && (row >= 0 && column + 1 < width))
            {
                red += copy[row][column + 1].rgbtRed;
                green += copy[row][column + 1].rgbtGreen;
                blue += copy[row][column + 1].rgbtBlue;
                pixelcounter++;
            }
            //Add top middle pixel
            if (row - 1 >= 0 && column >= 0)
            {
                red += copy[row - 1][column].rgbtRed;
                green += copy[row - 1][column].rgbtGreen;
                blue += copy[row - 1][column].rgbtBlue;
                pixelcounter++;
            }
            //Add top left pixel
            if (row - 1 >= 0 && column - 1 >= 0)
            {
                red += copy[row - 1][column - 1].rgbtRed;
                green += copy[row - 1][column - 1].rgbtGreen;
                blue += copy[row - 1][column - 1].rgbtBlue;
                pixelcounter++;
            }
            //Add top right pixel
            if ((row - 1 >= 0 && column + 1 >= 0) && (row - 1 >= 0 && column + 1 < width))
            {
                red += copy[row - 1][column + 1].rgbtRed;
                green += copy[row - 1][column + 1].rgbtGreen;
                blue += copy[row - 1][column + 1].rgbtBlue;
                pixelcounter++;
            }
            //Add bot middle pixel
            if ((row + 1 >= 0 && column >= 0) && (row + 1 < height && column >= 0))
            {
                red += copy[row + 1][column].rgbtRed;
                green += copy[row + 1][column].rgbtGreen;
                blue += copy[row + 1][column].rgbtBlue;
                pixelcounter++;
            }
            //Add bot left pixel
            if ((row + 1 >= 0 && column - 1 >= 0) && (row + 1 < height && column - 1 >= 0))
            {
                red += copy[row + 1][column - 1].rgbtRed;
                green += copy[row + 1][column - 1].rgbtGreen;
                blue += copy[row + 1][column - 1].rgbtBlue;
                pixelcounter++;
            }
            //Add bot right pixel
            if ((row + 1 >= 0 && column + 1 >= 0) && (row + 1 < height && column + 1 < width))
            {
                red += copy[row + 1][column + 1].rgbtRed;
                green += copy[row + 1][column + 1].rgbtGreen;
                blue += copy[row + 1][column + 1].rgbtBlue;
                pixelcounter++;
            }

            //Average them all out (the pixels) and assign to the image to create the blur effect
            image[row][column].rgbtRed = round(red / pixelcounter);
            image[row][column].rgbtGreen = round(green / pixelcounter);
            image[row][column].rgbtBlue = round(blue / pixelcounter);
        }
    }

    return;
}

