#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int main() {
    int number = 42;
    int file_descriptor = STDOUT_FILENO; // 1 pour la sortie standard (console)

    printf("Affichage du nombre %d sur la sortie standard :\n", number);
    ft_putnbr_fd(number, file_descriptor);
    printf("\n");

    // Essayons d'écrire le nombre dans un fichier
    file_descriptor = open("output.txt", O_WRONLY | O_CREAT, 0644);
    if (file_descriptor != -1) {
        printf("Affichage du nombre %d dans le fichier 'output.txt' :\n", number);
        ft_putnbr_fd(number, file_descriptor);
        close(file_descriptor);
    } else {
        printf("Erreur lors de l'ouverture du fichier.\n");
    }

    return 0;
}
