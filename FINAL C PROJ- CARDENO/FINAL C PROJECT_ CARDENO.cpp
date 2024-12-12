#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HISTORY 100
#define MAX_ENTRY_LENGTH 256

char history[MAX_HISTORY][MAX_ENTRY_LENGTH];
int historyCount = 0;


void clearScreen();
void addToHistory(const char *entry);
void displayHistory();
void lengthConverter();
void weightConverter();
void volumeConverter();
void timeConverter();
void currencyConverter();
void temperatureConverter();


void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


void addToHistory(const char *entry) {
    if (historyCount < MAX_HISTORY) {
        strncpy(history[historyCount], entry, MAX_ENTRY_LENGTH - 1);
        history[historyCount][MAX_ENTRY_LENGTH - 1] = '\0'; 
        historyCount++;
    }
}


void displayHistory() {
    printf("\nConversion History:\n");
    if (historyCount == 0) {
        printf("No conversions yet.\n");
    } else {
        for (int i = 0; i < historyCount; i++) {
            printf("%d. %s\n", i + 1, history[i]);
        }
    }
}

// Length Converter
void lengthConverter() {
    float value, result;
    int fromUnit, toUnit;

    printf("\nSelect the unit to convert from:\n");
    printf("1. Meters (m)\n");
    printf("2. Kilometers (km)\n");
    printf("3. Centimeters (cm)\n");
    printf("4. Millimeters (mm)\n");
    printf("5. Miles (mi)\n");
    printf("6. Yards (yd)\n");
    printf("7. Feet (ft)\n");
    printf("8. Inches (in)\n");
    printf("9. Light Years (ly)\n");
    printf("10. Parsecs (pc)\n");
    printf("11. Nanometers (nm)\n");
    printf("12. Micrometers (µm)\n");
    printf("13. Astronomical Units (AU)\n");
    printf("14. Fathoms (ftm)\n");
    printf("15. Chains (ch)\n");

    printf("\nEnter the number of the unit you want to convert from: ");
    scanf("%d", &fromUnit);
    
    printf("Enter the number of the unit you want to convert to: ");
    scanf("%d", &toUnit);

    if (fromUnit < 1 || fromUnit > 15 || toUnit < 1 || toUnit > 15) {
        printf("Invalid unit selection. Please try again.\n");
        return;
    }

    printf("Enter the value to convert: ");
    scanf("%f", &value);

    float conversionFactors[] = {1.0, 0.001, 100.0, 1000.0, 0.000621371, 1.09361, 3.28084, 39.3701, 9.461e+15, 3.24078e-17, 
        1.0e-9, 1.0e-6, 6.68459e-12, 0.5468, 0.00497097};
    const char* units[] = {"Meters", "Kilometers", "Centimeters", "Millimeters", "Miles", "Yards", "Feet", "Inches", 
        "Light Years", "Parsecs", "Nanometers", "Micrometers", "Astronomical Units", "Fathoms", "Chains"};

    result = value * (conversionFactors[toUnit - 1] / conversionFactors[fromUnit - 1]);
    printf("%.4f %s is equal to %.4f %s\n", value, units[fromUnit - 1], result, units[toUnit - 1]);

    char historyEntry[MAX_ENTRY_LENGTH];
    snprintf(historyEntry, sizeof(historyEntry), "%.4f %s to %.4f %s", value, units[fromUnit - 1], result, units[toUnit - 1]);
    addToHistory(historyEntry);
}

// Weight Converter
void weightConverter() {
    float value, result;
    int fromUnit, toUnit;

    printf("\nSelect the unit to convert from:\n");
    printf("1. Kilograms (kg)\n");
    printf("2. Grams (g)\n");
    printf("3. Milligrams (mg)\n");
    printf("4. Pounds (lbs)\n");
    printf("5. Ounces (oz)\n");
    printf("6. Atomic Mass (u)\n");
    printf("7. Metric Ton (t)\n");
    printf("8. Imperial Ton (long ton)\n");
    printf("9. Carat (ct)\n");
    printf("10. Ton (US)\n");
    printf("11. Stone (st)\n");
    printf("12. Quintal (q)\n");
    printf("13. Troy Ounce (ozt)\n");
    printf("14. Pennyweight (dwt)\n");

    printf("\nEnter the number of the unit you want to convert from: ");
    scanf("%d", &fromUnit);

    printf("Enter the number of the unit you want to convert to: ");
    scanf("%d", &toUnit);

    if (fromUnit < 1 || fromUnit > 14 || toUnit < 1 || toUnit > 14) {
        printf("Invalid unit selection. Please try again.\n");
        return;
    }

    printf("Enter the value to convert: ");
    scanf("%f", &value);

    float conversionFactors[] = {1.0, 1000.0, 1000000.0, 2.20462, 35.274, 6.02214179e26, 0.001, 0.000984207, 5000.0, 2204.62,
        157.47, 0.01, 31.1035, 20.0};
    const char* units[] = {"Kilograms", "Grams", "Milligrams", "Pounds", "Ounces", "Atomic Mass", "Metric Ton", 
        "Imperial Ton", "Carat", "Ton (US)", "Stone", "Quintal", "Troy Ounce", "Pennyweight"};

    result = value * (conversionFactors[toUnit - 1] / conversionFactors[fromUnit - 1]);
    printf("%.4f %s is equal to %.4f %s\n", value, units[fromUnit - 1], result, units[toUnit - 1]);

    char historyEntry[MAX_ENTRY_LENGTH];
    snprintf(historyEntry, sizeof(historyEntry), "%.4f %s to %.4f %s", value, units[fromUnit - 1], result, units[toUnit - 1]);
    addToHistory(historyEntry);
}

// Volume Converter
void volumeConverter() {
    float value, result;
    int fromUnit, toUnit;

    printf("\nSelect the unit to convert from:\n");
    printf("1. Cubic Meters (m³)\n");
    printf("2. Liters (L)\n");
    printf("3. Milliliters (mL)\n");
    printf("4. Gallons (US)\n");
    printf("5. Gallons (UK)\n");
    printf("6. Cubic Feet (ft³)\n");
    printf("7. Cubic Inches (in³)\n");
    printf("8. Cubic Yards (yd³)\n");
    printf("9. Fluid Ounces (US)\n");
    printf("10. Fluid Ounces (UK)\n");
    printf("11. Cubic Millimeters (mm³)\n");
    printf("12. Cubic Centimeters (cm³)\n");
    printf("13. Imperial Pints\n");
    printf("14. Imperial Quarts\n");
    printf("15. Imperial Gallons\n");
    printf("16. US Quart\n");
    printf("17. US Pint\n");
    printf("18. US Cup\n");
    printf("19. US Table Spoon\n");
    printf("20. US Tea Spoon\n");
    printf("21. Imperial Fluid Ounce\n");
    printf("22. Imperial Table Spoon\n");
    printf("23. Imperial Tea Spoon\n");
    printf("24. Cubic Mile\n");

    printf("\nEnter the number of the unit you want to convert from: ");
    scanf("%d", &fromUnit);

    printf("Enter the number of the unit you want to convert to: ");
    scanf("%d", &toUnit);

    if (fromUnit < 1 || fromUnit > 24 || toUnit < 1 || toUnit > 24) {
        printf("Invalid unit selection. Please try again.\n");
        return;
    }

    printf("Enter the value to convert: ");
    scanf("%f", &value);

    float conversionFactors[] = {
        1.0, 1000.0, 1000000.0, 264.172, 219.969, 35.3147, 61023.7, 1.30795, 33814.0, 35195.1, 
        1e9, 1e6, 2113.38, 1056.69, 264.172, 1056.69, 2113.38, 4226.77, 67618.0, 202853.0, 33814.0, 
        67618.0, 101427.0, 4.168e-9
    };
    const char* units[] = {
        "Cubic Meters", "Liters", "Milliliters", "Gallons (US)", "Gallons (UK)", "Cubic Feet", 
        "Cubic Inches", "Cubic Yards", "Fluid Ounces (US)", "Fluid Ounces (UK)", 
        "Cubic Millimeters", "Cubic Centimeters", "Imperial Pints", "Imperial Quarts", "Imperial Gallons", 
        "US Quart", "US Pint", "US Cup", "US Table Spoon", "US Tea Spoon", "Imperial Fluid Ounce", 
        "Imperial Table Spoon", "Imperial Tea Spoon", "Cubic Mile"
    };

    result = value * (conversionFactors[toUnit - 1] / conversionFactors[fromUnit - 1]);
    printf("%.4f %s is equal to %.4f %s\n", value, units[fromUnit - 1], result, units[toUnit - 1]);

    char historyEntry[MAX_ENTRY_LENGTH];
    snprintf(historyEntry, sizeof(historyEntry), "%.4f %s to %.4f %s", value, units[fromUnit - 1], result, units[toUnit - 1]);
    addToHistory(historyEntry);
}

// Time Converter
void timeConverter() {
    double value, result;
    int fromUnit, toUnit;

    printf("\nSelect the unit to convert from:\n");
    printf("1. Nanoseconds\n");
    printf("2. Microseconds\n");
    printf("3. Milliseconds\n");
    printf("4. Seconds\n");
    printf("5. Minutes\n");
    printf("6. Hours\n");
    printf("7. Days\n");
    printf("8. Years\n");
    printf("9. Picoseconds\n");

    printf("\nEnter the number of the unit you want to convert from: ");
    scanf("%d", &fromUnit);

    printf("Enter the number of the unit you want to convert to: ");
    scanf("%d", &toUnit);

    if (fromUnit < 1 || fromUnit > 9 || toUnit < 1 || toUnit > 9) {
        printf("Invalid unit selection. Please try again.\n");
        return;
    }

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    double conversionFactors[] = {1e9, 1e6, 1000.0, 1.0, 1.0 / 60, 1.0 / 3600, 1.0 / 86400, 1.0 / 365.25, 1e12};
    const char* units[] = {"Nanoseconds", "Microseconds", "Milliseconds", "Seconds", "Minutes", "Hours", "Days", "Years", "Picoseconds"};

    result = value * (conversionFactors[toUnit - 1] / conversionFactors[fromUnit - 1]);
    printf("%.4f %s is equal to %.4f %s\n", value, units[fromUnit - 1], result, units[toUnit - 1]);

    char historyEntry[MAX_ENTRY_LENGTH];
    snprintf(historyEntry, sizeof(historyEntry), "%.4f %s to %.4f %s", value, units[fromUnit - 1], result, units[toUnit - 1]);
    addToHistory(historyEntry);
}

// Currency Converter
void currencyConverter() {
    double value, result;
    int fromUnit, toUnit;

    printf("\nSelect the currency to convert from:\n");
    printf("1. USD\n");
    printf("2. EUR\n");
    printf("3. GBP\n");
    printf("4. JPY\n");
    printf("5. AUD\n");
    printf("6. INR\n");
    printf("7. PHP (Philippine Peso)\n");
    printf("8. KRW (Korean Won)\n");

    printf("\nEnter the number of the currency you want to convert from: ");
    scanf("%d", &fromUnit);

    printf("Enter the number of the currency you want to convert to: ");
    scanf("%d", &toUnit);

    if (fromUnit < 1 || fromUnit > 8 || toUnit < 1 || toUnit > 8) {
        printf("Invalid currency selection. Please try again.\n");
        return;
    }

    printf("Enter the value to convert: ");
    scanf("%lf", &value);

    
    double conversionRates[8][8] = {
        {1.0, 0.94, 0.82, 134.04, 1.51, 82.85, 56.02, 1319.84}, // USD to others
        {1.06, 1.0, 0.87, 142.37, 1.61, 88.04, 59.43, 1401.43}, // EUR to others
        {1.22, 1.14, 1.0, 163.27, 1.85, 101.27, 68.14, 1605.13}, // GBP to others
        {0.0075, 0.007, 0.0061, 1.0, 0.011, 0.62, 0.43, 9.85}, // JPY to others
        {0.66, 0.62, 0.54, 91.14, 1.0, 55.16, 36.91, 847.35}, // AUD to others
        {0.012, 0.011, 0.0099, 1.61, 0.018, 1.0, 0.63, 14.67}, // INR to others
        {0.018, 0.017, 0.015, 2.20, 0.027, 1.59, 1.0, 23.25}, // PHP to others
        {0.00076, 0.00071, 0.00062, 0.101, 0.0012, 0.068, 0.043, 1.0} // KRW to others
    };

    result = value * conversionRates[fromUnit - 1][toUnit - 1];
    printf("%.4f in selected currency is equal to %.4f in target currency.\n", value, result);

    char historyEntry[MAX_ENTRY_LENGTH];
    snprintf(historyEntry, sizeof(historyEntry), "%.4f in selected currency to %.4f in target currency", value, result);
    addToHistory(historyEntry);
}

// Temperature Converter
void temperatureConverter() {
    float value, result;
    int fromUnit, toUnit;

    printf("\nSelect the unit to convert from:\n");
    printf("1. Celsius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    printf("4. Rankine\n");

    printf("\nEnter the number of the unit you want to convert from: ");
    scanf("%d", &fromUnit);

    printf("Enter the number of the unit you want to convert to: ");
    scanf("%d", &toUnit);

    if (fromUnit < 1 || fromUnit > 4 || toUnit < 1 || toUnit > 4) {
        printf("Invalid unit selection. Please try again.\n");
        return;
    }

    printf("Enter the value to convert: ");
    scanf("%f", &value);

    if (fromUnit == 1) {
        // Celsius to others
        if (toUnit == 2) {
            result = (value * 9 / 5) + 32;
        } else if (toUnit == 3) {
            result = value + 273.15;
        } else if (toUnit == 4) {
            result = (value + 273.15) * 9 / 5;
        }
    } else if (fromUnit == 2) {
        // Fahrenheit to others
        if (toUnit == 1) {
            result = (value - 32) * 5 / 9;
        } else if (toUnit == 3) {
            result = ((value - 32) * 5 / 9) + 273.15;
        } else if (toUnit == 4) {
            result = value + 459.67;
        }
    } else if (fromUnit == 3) {
        // Kelvin to others
        if (toUnit == 1) {
            result = value - 273.15;
        } else if (toUnit == 2) {
            result = ((value - 273.15) * 9 / 5) + 32;
        } else if (toUnit == 4) {
            result = value * 9 / 5;
        }
    } else if (fromUnit == 4) {
        // Rankine to others
        if (toUnit == 1) {
            result = (value - 491.67) * 5 / 9;
        } else if (toUnit == 2) {
            result = value - 459.67;
        } else if (toUnit == 3) {
            result = value * 5 / 9;
        }
    }

    printf("%.2f degrees is equal to %.2f degrees in the selected unit.\n", value, result);

    char historyEntry[MAX_ENTRY_LENGTH];
    snprintf(historyEntry, sizeof(historyEntry), "%.2f degrees to %.2f degrees", value, result);
    addToHistory(historyEntry);
}


int main() {
    int choice;

    while (1) {
        clearScreen();
        printf("\033[1;35m");
        printf("-Unit Converter-\n");
        printf("\033[0m");
        printf("1. Length Converter\n2. Weight Converter\n3. Volume Converter\n4. Time Converter\n");
        printf("5. Currency Converter\n6. Temperature Converter\n7. View Conversion History\n8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lengthConverter();
                break;
            case 2:
                weightConverter();
                break;
            case 3:
                volumeConverter();
                break;
            case 4:
                timeConverter();
                break;
            case 5:
                currencyConverter();
                break;
            case 6:
                temperatureConverter();
                break;
            case 7:
                displayHistory();
                break;
            case 8:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\nPress Enter to continue...\n");
        getchar();  
        getchar();  
    }

    return 0;
}

