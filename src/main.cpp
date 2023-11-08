#include <Arduino.h>
#include <Wire.h>
#include <SD.h>    // Inclure la bibliothèque SD
#include "ATH20.h"

ATH20 ATH;

File logFile;  // Déclaration d'une variable de fichier pour le journal

void setup()
{
    Serial.begin(115200);
    Serial.println("ATH20 DEMO");
    ATH.begin();

    // Initialisation de la carte SD
    if (SD.begin(10)) {
        Serial.println("SD card is ready.");
    } else {
        Serial.println("SD card initialization failed.");
    }
}

void loop()
{
    float humi, temp;
    
    int ret = ATH.getSensor(&humi, &temp);
    
    if(ret)     // GET DATA OK
    {
        Serial.print("humidity: ");
        Serial.print(humi*100);
        Serial.print("%\t temerature: ");
        Serial.println(temp);

    
        // Ouvrir le fichier en mode écriture (créer le fichier s'il n'existe pas)
        File logFile = SD.open("C:\\Users\\Aymeric Barbot\\Documents\\PlatformIO\\Projects\\humidex\\log\\data.txt", FILE_WRITE);

        // Écrire les données dans le fichier
        logFile.print("humidity: ");
        logFile.print(humi * 100);
        logFile.print("%\t temperature: ");
        logFile.println(temp);

        // Fermer le fichier
        logFile.close();
    }
    else        // GET DATA FAIL
    {
        Serial.println("GET DATA FROM ATH20 FAIL");
    }
    
    delay(1000);
}