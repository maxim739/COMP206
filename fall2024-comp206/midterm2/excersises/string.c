#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
	    if (argc != 2) {
		            fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
			            return 1;
				        }

	        FILE *file = fopen(argv[1], "r");
		    if (!file) {
			            perror("Error opening file");
				            return 1;
					        }

		        char line[MAX_LINE_LENGTH];
			    int field1;
			        float field2;
				    char field3[50];

				        while (fgets(line, sizeof(line), file)) {
						        // Remove newline character if present
						         line[strcspn(line, "\n")] = '\0';
							//
							//                 // Parse the line using fscanf
							                         if (sscanf(line, "%d,%f,%49s", &field1, &field2, field3) == 3) {
							                                     printf("Field 1: %d, Field 2: %.2f, Field 3: %s\n", field1, field2, field3);
							                                             } else {
							                                                         fprintf(stderr, "Error parsing line: %s\n", line);
							                                                                 }
							                                                                     }
							
							                                                                         fclose(file);
							                                                                             return 0;
							                                                                             }
