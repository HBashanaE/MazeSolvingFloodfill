#include <iostream>
#include <fstream> 
#include <iomanip>
#include <string>
#include "stack.h"

void floodFill(int ** map, int **hWalls, int **vWalls, int x, int y)
{

    Stack stack;
    int val;
    int pushArray;
    int i1[3] = {x + 1, y + 1, 0};
    int i2[3] = {x + 1, y, 0};
    int i3[3] = {x, y + 1, 0};
    int i4[3] = {x, y, 0};
    stack.push(i1);
    stack.push(i2);
    stack.push(i3);
    stack.push(i4);

    while (Stack::size > 0)
    {

        int *stackVal = stack.pop();
        x = stackVal[0];
        y = stackVal[1];
        val = stackVal[2];

        if (map[y][x] < val)
        {
            continue;
        }

        map[y][x] = val;

        if (vWalls[y][x] != 1)
        {
            int arr1[3] = {x - 1, y, val + 1};
            stack.push(arr1);
        }
        if (hWalls[y][x] != 1)
        {
            int arr1[3] = {x, y - 1, val + 1};
            stack.push(arr1);
        }
        if (vWalls[y][x + 1] != 1)
        {
            int arr1[3] = {x + 1, y, val + 1};
            stack.push(arr1);
        }
        if (hWalls[y + 1][x] != 1)
        {
            int arr1[3] = {x, y + 1, val + 1};
            stack.push(arr1);
        }
    }
}

void printMap(int **map, int h, int w , int ** hWalls, int ** vWalls)
{
    for (int j = 0; j < w; j++)
        {

            if (hWalls[0][j] == 1)
            {
                std::cout << "_____";
            }
            else
            {
                std::cout << "     ";
            }
        }
        std::cout<<std::endl;
    for (int i = 0; i < h; i++)
    {
        if (vWalls[i][0] == 1)
        {
            std::cout << "|"
                      << " ";
        }
        else
        {
            std::cout << " "
                      << " ";
        }
        for (int j = 0; j < w; j++)
        {
            std::cout << std::setw(3)<< map[i][j] ;

            if (vWalls[i][j + 1] == 1)
            {
                std::cout << "|"
                          << " ";
            }
            else
            {
                std::cout << " "
                          << " ";
            }
        }
        std::cout<<std::endl;
        for (int j = 0; j < w; j++)
        {

            if (hWalls[i+1][j] == 1)
            {
                std::cout << "_____";
            }
            else
            {
                std::cout << "     ";
            }
        }
        std::cout << std::endl;
    }
}

void printArray(int ** array, int h, int w){
    for(int i = 0; i< h; i++){
        for(int j = 0; j<w; j++){
            std::cout<<array[i][j]<<" ";
        }
        std::cout << std::endl;
    }
}

void inputToArray(int ** array, int row, std::string inp, std::string delim){
    size_t pos = 0;
    std::string token;
    int i = 0;
    
    while ((pos = inp.find(delim)) != std::string::npos)
    {
        token = inp.substr(0, pos);
        array[row][i++] = std::stoi(token);
        inp.erase(0, pos + delim.length());
    }
    array[row][i++] = std::stoi(inp);
}

// int * readConfig(){
//     static int hw[2];

//     return hw;
// }

main()
{

    int h;
    int w;
    
    int **map;
    int **hWalls;
    int **vWalls;
    
    std::string ldata;
    std::ifstream infile; 
    infile.open("config.txt"); 

    infile >> ldata;
    h = std::stoi(ldata);
    
    infile >> ldata;
    w = std::stoi(ldata);
    
    infile >> ldata; //breaker

    map = new int *[h];
    hWalls = new int *[h+1];
    vWalls = new int *[h];

    for(int i = 0; i <h; i++)
        map[i] = new int[w];
    
    for(int i = 0; i <h+1; i++)
        hWalls[i] = new int[w];

    for(int i = 0; i <h; i++)
        vWalls[i] = new int[w+1];

    int row = 0;
    for (row; row<h;row++){
        infile >> ldata;
        inputToArray(map, row, ldata, ",");
    }
    infile >> ldata; //breaker
    row = 0;
    for (row; row<h+1;row++){
        infile >> ldata;
        inputToArray(hWalls, row, ldata, ",");
    }
    infile >> ldata; //breaker
    row = 0;
    for (row; row<h;row++){
        infile >> ldata;
        inputToArray(vWalls, row, ldata, ",");
    }
    infile.close();

    floodFill(map, hWalls, vWalls, 2, 2);
    printMap(map, h, w, hWalls, vWalls);

    delete[] map;
    delete[] hWalls;
    delete[] vWalls;
    return 0;
}