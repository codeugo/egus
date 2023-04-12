#include <Servo.h>

const byte numChars = 64;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

      // variables to hold the parsed data
char messageFromPC[numChars] = {0};
int integerFromPC = 0;
float floatFromPC = 0.0;

Servo middle, left, right, claw ;
int middleValue = 0;
int clawValue = 90;
int rightValue = 90;

boolean newData = false;

//============

void setup() {
    Serial.begin(9600);
    Serial.println("This demo expects 3 pieces of data - text, an integer and a floating point value");
    Serial.println("Enter data in this style <HelloWorld, 12, 24.7>  ");
    Serial.println();

    middle.attach(11);  // attaches the servo on pin 11 to the middle object
    left.attach(10);  // attaches the servo on pin 10 to the left object
    right.attach(9);  // attaches the servo on pin 9 to the right object
    claw.attach(8); // attaches the servo on pin 6 to the claw object
}

//============

void loop() {
    recvWithStartEndMarkers();
    if (newData == true) {
        strcpy(tempChars, receivedChars);
            // this temporary copy is necessary to protect the original data
            //   because strtok() used in parseData() replaces the commas with \0
        parseData();
        showParsedData();
        newData = false;
    }
  middle.write(middleValue);
  claw.write(clawValue);
  right.write(rightValue);
}

//============

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

//============

void parseData() {      // split the data into its parts

    char * strtokIndx; // this is used by strtok() as an index

    strtokIndx = strtok(tempChars,",");      // get the first part - the string
    middleValue = atoi(strtokIndx); // copy it to messageFromPC
 
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    clawValue = atoi(strtokIndx); // convert this part to an integer

    strtokIndx = strtok(NULL, ",");
    rightValue = atoi(strtokIndx);   // convert this part to a float

}

//============

void showParsedData() {
    Serial.print("Message ");
    Serial.println(middleValue);
    Serial.print("Integer ");
    Serial.println(clawValue);
    Serial.print("Float ");
    Serial.println(rightValue);
}
