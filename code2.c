#include <stdio.h>
#include <stdlib.h>

float c_to_f(float celsius);
float f_to_c(float fahrenheit);
float c_to_k(float celsius);
float k_to_c(float kelvin);
float f_to_k(float fahrenheit);
float k_to_f(float kelvin);
void categorize_temperature(float celsius);

int main() {
    float input_temp, converted_temp;
    int in_scale, out_scale;
    while(1){
        
        printf("Enter the temperature: "); //user temperature
        scanf("%f", &input_temp);

        printf("Choose the current scale: (1) Celsius, (2) Fahrenheit, (3) Kelvin: "); //user scale
        scanf("%d", &in_scale);

        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: "); //user conversion scale
        scanf("%d", &out_scale);

        if (in_scale == out_scale) { //checking input validity
            printf("Conversion not available. Please use differing scales.\n");
            continue;
        }

        if (in_scale == 3 && input_temp < 0) { // kelvin input validation 
            printf("Choose a different temperature. Kelvin cannot be negative.\n");
            continue;
        }

        switch(in_scale) { 
            case 1: //if user inputs celsius
                if (out_scale == 2)
                    converted_temp = c_to_f(input_temp);
                else if (out_scale == 3)
                    converted_temp = c_to_k(input_temp);
                break;
            
            case 2: // if user inputs fahrenheit
                if (out_scale == 1)
                    converted_temp = f_to_c(input_temp);
                else if (out_scale == 3)
                    converted_temp = f_to_k(input_temp);
                break;
            
            case 3: // if user inputs kelvin
                if (out_scale == 1)
                    converted_temp = k_to_c(input_temp);
                else if (out_scale == 2)
                    converted_temp = k_to_f(input_temp);
                break;
            
            default:
                printf("Invalid scale.\n");
                continue;
        }

        switch(out_scale) { //showing the converted temperatures
            case 1:
                printf("Converted temp: %.2fC\n", converted_temp); // celsius conversion
                break;
            case 2:
                printf("Converted temp: %.2fF\n", converted_temp); // fahrenheit conversion
                break;
            case 3:
                printf("Converted temp: %.2fK\n", converted_temp); // kelvin conversion
                break;
        }

        if (out_scale == 1) { // categorizing temperatures
            categorize_temperature(converted_temp);
        } else if (out_scale == 2) {
            categorize_temperature(f_to_c(converted_temp));
        } else if (out_scale == 3) {
            categorize_temperature(k_to_c(converted_temp));
        }

        return 0;
    }
}
// conversion formulas
float c_to_f(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

float f_to_c(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

float c_to_k(float celsius) {
    return celsius + 273.15;
}

float k_to_c(float kelvin) {
    return kelvin - 273.15;
}

float f_to_k(float fahrenheit) {
    return c_to_k(f_to_c(fahrenheit));
}

float k_to_f(float kelvin) {
    return c_to_f(k_to_c(kelvin));
}

void categorize_temperature(float celsius) { //categorizing temps and outputting messages
    if (celsius < 0.0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Try your best to stay inside.\n");
    } else if (celsius >= 0.0 && celsius < 10.0) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10.0 && celsius < 25.0) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25.0 && celsius <= 35.0) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Remember to drink water and stay cool.\n");
    } else {
        printf("Temperature category: Extreme heat.\n");
        printf("Weather advisory: Extremely high temperatures. Stay cool.\n");
    }
}