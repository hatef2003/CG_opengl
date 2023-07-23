#include <vector>
#include <math.h>
using namespace std;
class cylandr
{
public:
    cylandr(float _centerx, float _centerz, float _reduis, int _number_of_steps)
    {
        centerx = _centerx;
        centerz = _centerz;
        reduis = _reduis;
        number_of_steps = _number_of_steps;
    }
    float * coordinates()
    {
        float firstx = -reduis, x = firstx;
        float lastx = reduis, reduis2 = reduis * reduis;
        float z, dx = (lastx - firstx) / (float)number_of_steps;
        float *vertices=new float[number_of_steps * 12];
        int index = 0;
        float prevx = x, prevz = 0.0f;
        vertices[index] = x;
        vertices[index + 1] = 0.1f;
        vertices[index + 2] = 0;
        vertices[index = 3] = 0.0;
        vertices[index + 4] = 0.0;
        vertices[index + 5] = 1;
        vertices[index + 6] = x;
        vertices[index + 7] = -0.1;
        vertices[index + 8] = 0;
        vertices[index + 9] = 0.0;
        vertices[index + 10] = 0.0;
        vertices[index + 11] = 1;
        index += 12;
        x += dx;
        for (int i = 0; i < number_of_steps-1; i++)
        {
            z = sqrtf(reduis2 - (x * x));
            vertices[index] = x;
            vertices[index + 1] = 0.1;
            vertices[index + 2] = z;
            vertices[index = 3] = 0.0f;
            vertices[index + 4] = 0.0f;
            vertices[index + 5] = 1.0f;
            index+=6;
            vertices[index] = x;
            vertices[index + 1] = 0.1;
            vertices[index + 2] = z;
            vertices[index = 3] = 0.0f;
            vertices[index + 4] = 0.0f;
            vertices[index + 5] = 1.0f;
            index+=6;
            vertices[index] = prevx;
            vertices[index + 1] = -0.1;
            vertices[index + 2] = prevz;
            vertices[index = 3] = 0.0f;
            vertices[index + 4] = 0.0f;
            vertices[index + 5] = 1.0f;
            index+=6;
            vertices[index] = x;
            vertices[index + 1] =- 0.1;
            vertices[index + 2] = z;
            vertices[index = 3] = 0.0f;
            vertices[index + 4] = 0.0f;
            vertices[index + 5] = 1.0f;
            index+=6;
            vertices[index] = x;
            vertices[index + 1] = 0.1;
            vertices[index + 2] = z;
            vertices[index = 3] = 0.0f;
            vertices[index + 4] = 0.0f;
            vertices[index + 5] = 1.0f;
            index+=6;
            vertices[index] = x;
            vertices[index + 1] = -0.1;
            vertices[index + 2] = z;
            vertices[index = 3] = 0.0f;
            vertices[index + 4] = 0.0f;
            vertices[index + 5] = 1.0f;
            index+=6;
            x += dx;
        }
        return vertices;
    }

private:
    float centerx, centerz, reduis;
    int number_of_steps;
};