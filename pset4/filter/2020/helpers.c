#include "helpers.h"
#include <math.h>
#include <limits.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through rows
    for (int i = 0, h = height; i < h; i++)
    {
        //iterate through each pixel in i'th row
        for (int j = 0, w = width; j < w; j++)
        {
            //copy RGB values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            
            //calculate average
            float average = (round(red) + round(blue) + round(green)) / 3;
            average = round(average);
            
            //re-print new values int image
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //iterate through rows
    for (int i = 0, h = height; i < h; i++)
    {
        //iterate through each pixel from i'th row
        for (int j = 0, w = width; j < w; j++)
        {
            //copy sepia RGB values into new variables
            int s_red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int s_green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int s_blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            
            //check RGB values and re-atribute them
            if (s_red > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = s_red;
            }
            
            if (s_green > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = s_green;
            }
            
            if (s_blue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = s_blue;
            }
            
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temporary;
    //iterate with i through rows
    for (int i = 0, h = height; i < h; i++)
    {
        //iterate with j through the left half
        for (int j = 0, w = width / 2; j < w; j++)
        {
            //change pixels around
            temporary = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temporary;
        }
        
    }
    
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    
    //make a copy of the image
    for (int i = 0, h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    
    //iterate through each row
    for (int i = 0, h = height; i < h; i++)
    {
        //iterate through each pixel of i'th row
        for (int j = 0, w = width; j < w; j++)
        {
            float sum_red = 0;
            float sum_green = 0;
            float sum_blue = 0;
            int pixel_count = 0; //count pixels that have already been blurred
            
            //checks pixels -1 and +1 to the current pixel (left and right)
            for (int k = -1; k < 2; k++)
            {
                //checks pixels -1 and +1 to the current pixel (up and down)
                for (int l = -1; l < 2; l++)
                {
                    //check corners and walls
                    if (i + k >= 0  && j + l >= 0 && i + k <= height - 1 && j + l <= width - 1) 
                    {
                        sum_red = copy[i + k][j + l].rgbtRed + sum_red;
                        sum_green = copy[i + k][j + l].rgbtGreen + sum_green;
                        sum_blue = copy[i + k][j + l].rgbtBlue + sum_blue;
                        pixel_count++;
                    }
                }
            }
            
            
            image[i][j].rgbtRed = round(sum_red / pixel_count);
            image[i][j].rgbtGreen = round(sum_green / pixel_count);
            image[i][j].rgbtBlue = round(sum_blue / pixel_count);
        }
    }
    return;
}
