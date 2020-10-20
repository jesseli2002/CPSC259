/*
File:         tide_analyzer.c
Purpose:      Consumes a semi-formatted tide measurement file and
determines if the corresponding tide is once- or
twice-daily using a fast discrete Fourier transformation.
The tide measurement file is a txt file whose name
corresponds to the name defined in the preprocessor
directive.  It is a series of NUMBER_OF_READINGS tidal
readings (in mm) taken hourly.

   Authors: Jesse Li, James Wang
 Student #: 61066156, 31693740
CS Account: e3w1b   , u6i3b
Date: 2020-09-15
*/

/******************************************************************
PLEASE EDIT THIS FILE

Sections of code in this file are missing.  You must fill them in.
Comments that start with // should be replaced with code
Comments that are surrounded by * are hints
******************************************************************/

/* Preprocessor directives */
#include "tide_analyzer.h"
#include "discrete_fourier_transform.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NOISE_FILTER 0.01         // Used to eliminate noise from observation
#define EXPONENT 17               // Can be used for call to fft
#define LINESIZE 128              // Maximum line length in data file
#define SAMPLING_FREQUENCY 24     // Number of tidal readings taken day
#define FFT_ALGOR_BUFFER 4        // Prevents Run Time Check Failure #2
#define NUMBER_OF_READINGS 131072 /* This = 2^17 (hint!) */
#define FILE_NAME "puddlejump.txt"
#define RESULT_FILE_NAME "result.txt"

/**
 * Helper function for run_analysis - actually does all the work, while
 * run_analysis manages memory to avoid memory leaks. After running this
 * function, contents of all three input parameters are undefined. \param
 * readings Pointer to uninitialized array of size NUMBER_OF_READINGS +
 * FFT_ALGOR_BUFFER \param complex_component Pointer to uninitialized array of
 * size NUMBER_OF_READINGS + FFT_ALGOR_BUFFER \param omega Pointer to
 * uninitialized array of size NUMBER_OF_READINGS + FFT_ALGOR_BUFFER \return 0
 * if the there were no errors, 1 otherwise
 */
int run_analysis_helper(double *readings, double *complex_component,
                        double *omega);

/*
Function contains all the steps of analysis.
PRE:       NULL (no pre-conditions)
POST:      NULL (no side-effects)
RETURN:    IF the program exits correctly THEN 0 ELSE 1
*/
int run_analysis() {
    /* Variables */
    double *readings = (double *)malloc(
        (NUMBER_OF_READINGS + FFT_ALGOR_BUFFER) * sizeof(double));
    double *complex_component = (double *)malloc(
        (NUMBER_OF_READINGS + FFT_ALGOR_BUFFER) * sizeof(double));
    double *omega = (double *)malloc((NUMBER_OF_READINGS + FFT_ALGOR_BUFFER) *
                                     sizeof(double));

    int result = run_analysis_helper(readings, complex_component, omega);
    free(readings);
    free(complex_component);
    free(omega);
    return result;
}

int run_analysis_helper(double *readings, double *complex_component,
                        double *omega) {
    if (readings == NULL || complex_component == NULL || omega == NULL) {
        printf("Insufficient memory!"); // malloc failed
        return 1;
    }
    for (unsigned long int i = 0; i < NUMBER_OF_READINGS; i++) {
        omega[i] = (double)i * SAMPLING_FREQUENCY / NUMBER_OF_READINGS;
    }

    // Opens the input file
    FILE *file_pointer = NULL;
    file_pointer = fopen(FILE_NAME, "r");
    if (file_pointer == NULL) {
        printf("Error - file not found");
        return 1;
    }
    process_file(readings, file_pointer); // Parse the file
    fclose(file_pointer);                 // cleanup

    fft(1, EXPONENT, readings, complex_component);

    double frequency = 0.0;
    double amplitude = 0.0;

    for (int i = 0; i < NUMBER_OF_READINGS / 2; i++) {
        if (omega[i] < NOISE_FILTER) {
            continue;
        }
        double new_amp = pow(readings[i] * readings[i] +
                                 complex_component[i] * complex_component[i],
                             0.5);
        if (new_amp > amplitude) {
            frequency = omega[i];
            amplitude = new_amp;
        }
    }
    // Output results to console and file
    printf("Max Frequency = %f Max Amplitude = %f\n", frequency, amplitude);
    file_pointer = fopen(RESULT_FILE_NAME, "w");
    if (file_pointer == NULL) {
        printf("Error: Result file not found");
        return 1;
    }
    /* Writes the result to the file */
    fprintf(file_pointer, "Puddlejump tidal frequency: %f per day\n",
            frequency);
    fclose(file_pointer);
    printf("Analysis complete, result.txt created\n");
    return 0;
}

/*
 * Processes the data file
 * PARAM:     readings is an array which is at least large enough
 *            to contain the data in the specified file
 * PARAM:     file_pointer is a valid and open file pointer
 * PRE:       The file pointer is a reference to an open file
 * PRE:       The file is a text file which contains between 1 and
 *            5 real integers per line
 * POST:      The contents of the file have been copied to the
 *            specified array
 * RETURN:    VOID
 */
void process_file(double readings[], FILE *file_pointer) {
    // // Alternative implementation that I think is more elegant
    // while (fscanf(file_pointer, "%lf", readings++) != EOF)
    //    ;
    // return;
    char line[LINESIZE];
    while (fgets(line, LINESIZE, file_pointer) != NULL) {
        // Exits loop when all vallues are read
        int read_count = sscanf(line, "%la%la%la%la%la", readings, readings + 1,
                                readings + 2, readings + 3, readings + 4);
        readings += read_count;
    }
    return;
}
