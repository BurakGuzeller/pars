#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

// Örnek veri (örneğin, GPS verisi ya da sensör ölçümleri veya mesaj listesi gibi)
char sampleData[] = "data1,data2,data3,data4,data5,data6,data7,data8";
char *delimiter = ",";

/**
 * @brief Belirtilen bir string içindeki tokenları ayırır ve istenen indeksteki tokenı kopyalar.
 *
 * @param inputString   İşlenecek giriş stringi.
 * @param separator     Tokenları ayırmak için kullanılan ayraç (delimiter).
 * @param resultField   İstenen tokenın kopyalanacağı çıkış alanı.
 * @param tokenIndex    Alınmak istenen tokenın 1 tabanlı indeksi.
 */
void extractToken(const char *inputString, const char *separator, char *resultField, uint8_t tokenIndex) {
    uint8_t currentIndex = 0;
    size_t inputSize = strlen(inputString);


    char *tempString = malloc(inputSize + 1);
    if (tempString == NULL) {
        printf("Memory allocation error!\n");
        return;
    }


    memcpy(tempString, inputString, inputSize + 1);

    char *token = strtok(tempString, separator);
    while (token != NULL) {

        currentIndex++;


        if (currentIndex == tokenIndex) {
            strcpy(resultField, token); // Tokenı çıkış alanına kopyala  burada enlem boylam gibi degislkenler ilgili alana kopyalanabilir.
            printf("Extracted token = %s\n", resultField);
            break;
        }

        token = strtok(NULL, separator);
    }

    free(tempString);


    if (currentIndex < tokenIndex) {
        printf("Token at index %d not found.\n", tokenIndex);
    }
}

int main() {

    char extractedField1[100];
    char extractedField2[100];
    char extractedField3[100];
    char extractedField4[100];


    extractToken(sampleData, delimiter, extractedField1, 3);
    extractToken(sampleData, delimiter, extractedField2, 2);
    extractToken(sampleData, delimiter, extractedField3, 5);
    extractToken(sampleData, delimiter, extractedField4, 4);

    return 0;
}
