void placeAssignment() {
    printf("valid seats:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = i*cols+j;
            if(index == 0) {
                printf("%d", index);
            } else {
                if (strcmp(room[i][j], ":") == 0) {
                    printf(", %d", index);
                }
            }
        }
    }

    printf("\n\nenter student id: ");
    scanf("%s", str);
    if (strcmp(str, "-abort") == 0) {
        exit(0);
    }
}